#include "sos.h"

extern Vector2 g_board_size;

size_t nb_elem[6] = {24, 6, 2, 5, 4, 6};

c_game_engine::c_game_engine() : c_widget()
{
	_tileset = c_tileset("ressources/tileset/base_tileset.png", Vector2(4, 4));
	_board_size = g_board_size;
	_tile_size = Vector2(64, 64);
	_board.resize(_board_size.x);
	int target_x = (_board_size.x / 2);
	int target_y = (_board_size.x / 2);
	for (size_t i = 0; i < _board_size.x; i++)
	{
		_board[i].resize(_board_size.y);
		for (size_t j = 0; j < _board_size.y; j++)
		{
			_board[i][j] = c_tile(tile_type::empty);
		}
	}
	populate_board();
}
c_game_engine::~c_game_engine()
{

}

int generate_zombie(float distance)
{
	int value = generate_nbr(0, 20) + distance * 10;
	if (value < 30)
		return (0);
	else if (value < 45)
		return (1);
	else if (value < 60)
		return (2);
	else if (value < 70)
		return (3);
	else if (value < 78)
		return (4);
	else if (value < 83)
		return (5);
	else if (value < 100)
		return (6);
}

void c_game_engine::populate_board()
{
	Vector2 city_pos;

	city_pos.x = _board_size.x / 2.0f;
	city_pos.y = _board_size.y / 2.0f;

	_board[city_pos.x][city_pos.y].set_type(static_cast<tile_type>(1));
	_board[city_pos.x][city_pos.y].set_discovered(tile_state::seen);

	for (int i = 0; i < _board_size.x; i++)
		for (int j = 0; j < _board_size.y; j++)
		{
			Vector2 tmp = Vector2(i + 0.5f, j + 0.5f);
			if (city_pos.distance(tmp) < 1.414f && _board[i][j].discovered() != tile_state::seen)
				_board[i][j].set_discovered(tile_state::discovered);
			_board[i][j].set_nb_zombie(generate_zombie(city_pos.distance(tmp)));
		}

	for (size_t i = 0; i < 6; i++)
	{
		for (size_t count = 0; count < nb_elem[i]; count++)
		{
			int nb_try = 0;
			int x = generate_nbr(0, _board_size.x);
			int y = generate_nbr(0, _board_size.y);
			while (_board[x][y].type() != tile_type::empty && nb_try < 100)
			{
				x = generate_nbr(0, _board_size.x);
				y = generate_nbr(0, _board_size.y);
				nb_try++;
			}
			if (nb_try < 100)
			{
				_board[x][y].set_type(static_cast<tile_type>(i + 2));
			}
		}
	}
}

Vector2 c_game_engine::screen_size()
{
	return (_tile_size * _board_size);
}

void c_game_engine::set_geometry_imp(Vector2 p_anchor, Vector2 p_area)
{
	viewport()->set_viewport(p_anchor, p_area);
}

void c_game_engine::render()
{
	for (int x = 0; x < _board_size.x; x++)
	{
		for (int y = 0; y < _board_size.y; y++)
		{
			_tileset.draw(static_cast<int>(_board[x][y].type()), Vector2(x, y) * _tile_size + 30, _tile_size);
			if (_board[x][y].discovered() == tile_state::unknown)
				_tileset.draw(11, Vector2(x, y) * _tile_size + 30, _tile_size);
			if (_board[x][y].discovered() == tile_state::discovered)
				_tileset.draw(10, Vector2(x, y) * _tile_size + 30, _tile_size);
			if (_board[x][y].discovered() == tile_state::seen && _board[x][y].nb_zombie() != 0)
			{
				if (_board[x][y].nb_zombie() < 3)
					draw_point(Color(0, 0, 255, 110), Vector2(x, y) * _tile_size + 40, 15);
				else if (_board[x][y].nb_zombie() < 5)
					draw_point(Color(0, 255, 0, 110), Vector2(x, y) * _tile_size + 40, 15);
				else
					draw_point(Color(255, 0, 0, 110), Vector2(x, y) * _tile_size + 40, 15);
			}
		}
	}
}

bool c_game_engine::handle_keyboard()
{
	if (g_keyboard->get_key(SDL_SCANCODE_ESCAPE))
	{
		g_application->quit();
		return (true);
	}

	return (false);
}
