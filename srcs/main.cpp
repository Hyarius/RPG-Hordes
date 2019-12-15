#include "rpg_hordes.h"

enum class tile_type
{
	empty = 0,
	city = 1,
	forest = 2,
	cave = 3,
	building = 4,
	water = 5,
	small_building = 6,
	medium_building = 7,
};

enum class tile_state
{
	active = 9,
	seen = 10,
	unknown = 11,
	reveal = 9
};

int nb_elem[8] = {0, 0, 16, 5, 4, 8, 5, 3};

class c_tile
{
private:
	tile_type _type;
	tile_state _state;
public:
	c_tile(tile_type p_type = tile_type::empty, tile_state p_state = tile_state::unknown)
	{
		_type = p_type;
		_state = p_state;
	}

	~c_tile()
	{

	}

	void draw(c_tileset *tile, Vector2 pos, Vector2 size, Vector2 start_pos)
	{
		tile->draw(static_cast<int>(_type), pos * size + start_pos, size);
		tile->draw(static_cast<int>(_state), pos * size + start_pos, size);
	}

	void set_type(tile_type p_type){_type = p_type;}
	tile_type type(){return (_type);}

	void set_state(tile_state p_state){_state = p_state;}
	tile_state state(){return (_state);}
};

class c_board : public c_widget
{
private:
	c_tileset _tile;
	Vector2 _board_size;
	Vector2 _tile_size;
	map<Vector2, c_tile> _tile_map;

public:
	c_board(c_widget *parent = nullptr) : c_widget(parent)
	{
		_tile = c_tileset("ressources/tileset/base_tileset.png", Vector2(4, 5));
		_board_size = Vector2(13, 13);
		_tile_size = Vector2(64, 64);

		populate_board();
	}

	~c_board()
	{

	}

	Vector2 size()
	{
		return (_board_size * _tile_size + 60);
	}

	Vector2 generate_coord(tile_type p_type)
	{
		Vector2 result;
		int i = 0;

		result.x = generate_nbr(0, _board_size.x);
		result.y = generate_nbr(0, _board_size.y);
		while (_tile_map[result].type() != p_type && i < 100)
		{
			result.x = generate_nbr(0, _board_size.x);
			result.y = generate_nbr(0, _board_size.y);

			i++;
		}

		if (i == 100)
			return (-1);
		return (result);
	}

	void populate_board()
	{
		Vector2 center = (_board_size / 2).floor();
		_tile_map[center].set_type(tile_type::city);
		_tile_map[center].set_state(tile_state::reveal);

		Vector2 coord;
		for (coord.x = 0; coord.x < _board_size.x; coord.x++)
			for (coord.y = 0; coord.y < _board_size.y; coord.y++)
			{
				if (coord != center)
				{
					_tile_map[coord] = c_tile();
					float dist = center.distance(coord);
					if (dist <= 1.414f)
						_tile_map[coord].set_state(tile_state::reveal);
					else if (dist <= 2.6f)
					 	_tile_map[coord].set_state(tile_state::seen);
				}
			}

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < nb_elem[i]; j++)
			{
				coord = generate_coord(tile_type::empty);

				if (coord != -1)
					_tile_map[coord].set_type(static_cast<tile_type>(i));
			}
		}
	}

	void set_geometry_imp(Vector2 p_anchor, Vector2 p_area)
	{
		viewport()->set_anchor(p_anchor);

		_tile_size = (p_area - 60) / _board_size;
	}

	void render()
	{
		viewport()->use();
		Vector2 pos;

		for (pos.x = 0; pos.x < _board_size.x; pos.x++)
			for (pos.y = 0; pos.y < _board_size.y; pos.y++)
				_tile_map[pos].draw(&_tile, pos, _tile_size, 30);
	}
};

class c_player
{
private:
	int health;
public:
	c_player()
	{
		health = 100;
	}

	~c_player()
	{

	}
};

class c_player_panel : public c_widget
{
private:
	c_player *_player;
	c_frame *_frame;

public:
	c_player_panel(c_player *p_player, c_widget *parent = nullptr) : c_widget(parent)
	{
		_player = p_player;
		_frame = new c_frame(this);
		_frame->box().set_back(Color(75, 60, 40));
		_frame->box().set_front(Color(100, 80, 60));
		_frame->activate();
	}
	~c_player_panel()
	{

	}

	void set_geometry_imp(Vector2 p_anchor, Vector2 p_area)
	{
		_frame->set_geometry(Vector2(10, 10), p_area - Vector2(20, 20));
	}

	void render()
	{
		viewport()->use();
	}
};

int main(int argc, char**argv)
{
	c_application win("RPG Hordes (c)", Vector2(0.85f, 0.85f), Color(30, 30, 30));

	c_board board = c_board();
	board.activate();

	c_player player;

	c_player_panel panel(&player);
	panel.set_geometry(Vector2(0, 0), Vector2(win.size().x, (win.size().y / 100.0f) * 10.0f));
	board.set_geometry(Vector2(0.0f, panel.area().y), win.size().y - panel.area().y);
	panel.activate();

	return (win.run());
}
