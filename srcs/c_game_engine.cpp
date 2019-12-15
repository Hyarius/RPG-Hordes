#include "sos.h"

extern Vector2 g_board_size;

size_t nb_elem[6] = {24, 6, 2, 5, 4, 6};
#define SELF 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define UP 4
Vector2 neighbour[5] = {
	Vector2(0, 0),
	Vector2(1, 0),
	Vector2(0, 1),
	Vector2(-1, 0),
	Vector2(0, -1),
};

c_game_engine::c_game_engine() : c_widget()
{
	_tileset = c_tileset("ressources/tileset/base_tileset.png", Vector2(4, 5));
	_board_size = g_board_size;
	_tile_size = Vector2(64, 64);
	_board.resize(_board_size.x);
	for (size_t i = 0; i < _board_size.x; i++)
	{
		_board[i].resize(_board_size.y);
		for (size_t j = 0; j < _board_size.y; j++)
			_board[i][j] = c_tile(tile_type::empty);
	}

	_city = c_city("Epic city name !");
	_player = c_player();
	_city_panel = new c_city_panel(this);
	_city_panel->set_city(&_city);
	_city_panel->activate();

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
	return (7);
}

void c_game_engine::populate_board()
{
	Vector2 city_pos;

	city_pos.x = _board_size.x / 2.0f;
	city_pos.y = _board_size.y / 2.0f;

	_board[city_pos.x][city_pos.y].set_type(static_cast<tile_type>(1));
	_board[city_pos.x][city_pos.y].set_status(tile_state::reveal);
	_player.set_pos(Vector2(static_cast<int>(city_pos.x), static_cast<int>(city_pos.y)));

	for (int i = 0; i < _board_size.x; i++)
		for (int j = 0; j < _board_size.y; j++)
		{
			Vector2 tmp = Vector2(i + 0.5f, j + 0.5f);
			if (city_pos.distance(tmp) < 1.414f && _board[i][j].status() != tile_state::seen)
				set_tile_status(i, j, tile_state::reveal);
			else if (city_pos.distance(tmp) < 3.414f && _board[i][j].status() != tile_state::seen)
				set_tile_status(i, j, tile_state::discovered);
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

void c_game_engine::set_geometry_imp(Vector2 p_anchor, Vector2 p_area)
{
	viewport()->set_viewport(p_anchor, p_area);

	Vector2 panel_coord = Vector2(_board_size.x * _tile_size.x + 60, 15.0f);
	Vector2 panel_size = Vector2(450.0f, _board_size.y * _tile_size.y + 60) - Vector2(15.0f, 30.0f);
	_city_panel->set_geometry(panel_coord, panel_size);
}

bool c_game_engine::is_inside(int x, int y)
{
	if (x < 0 || x >= _board_size.x || y < 0 || y >= _board_size.y)
		return (false);
	return (true);
}


bool c_game_engine::is_inside(Vector2 target)
{
	if (target.x < 0 || target.x >= _board_size.x || target.y < 0 || target.y >= _board_size.y)
		return (false);
	return (true);
}

void c_game_engine::set_tile_status(Vector2 tile_pos, tile_state p_state)
{
	if (is_inside(tile_pos.x, tile_pos.y) == false)
		return ;

	_board[tile_pos.x][tile_pos.y].set_status(p_state);
}

void c_game_engine::set_tile_status(int x, int y, tile_state p_state)
{
	if (is_inside(x, y) == false)
		return ;

	_board[x][y].set_status(p_state);
}

tile_state c_game_engine::tile_status(int x, int y)
{
	if (is_inside(x, y) == false)
		return tile_state::error;

	return (_board[x][y].status());
}
tile_state c_game_engine::tile_status(Vector2 tile_pos)
{
	if (is_inside(tile_pos.x, tile_pos.y) == false)
		return tile_state::error;

	return (_board[tile_pos.x][tile_pos.y].status());
}

void c_game_engine::render()
{
	for (int x = 0; x < _board_size.x; x++)
	{
		for (int y = 0; y < _board_size.y; y++)
		{
			_tileset.draw(static_cast<int>(_board[x][y].type()), Vector2(x, y) * _tile_size + 30, _tile_size);
			if (_board[x][y].status() == tile_state::unknown)
				_tileset.draw(11, Vector2(x, y) * _tile_size + 30, _tile_size);
			if (_board[x][y].status() == tile_state::discovered)
				_tileset.draw(10, Vector2(x, y) * _tile_size + 30, _tile_size);
			if (_board[x][y].status() == tile_state::seen && _board[x][y].nb_zombie() != 0)
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
	_tileset.draw(12, _player.pos() * _tile_size + 30, _tile_size);

	//Down
	if (is_inside(_player.pos() + neighbour[DOWN]) == true)
		_tileset.draw(16, _player.pos() * _tile_size + 30 + Vector2(0.0f, _tile_size.y / 2.0f), _tile_size);

	//Left
	if (is_inside(_player.pos() + neighbour[LEFT]) == true)
		_tileset.draw(17, _player.pos() * _tile_size + 30 - Vector2(_tile_size.x / 2.0f, 0.0f), _tile_size);

	//Up
	if (is_inside(_player.pos() + neighbour[UP]) == true)
		_tileset.draw(18, _player.pos() * _tile_size + 30 - Vector2(0.0f, _tile_size.y / 2.0f), _tile_size);

	// Right
	if (is_inside(_player.pos() + neighbour[RIGHT]) == true)
		_tileset.draw(19, _player.pos() * _tile_size + 30 + Vector2(_tile_size.x / 2.0f, 0.0f), _tile_size);
}

Vector2 c_game_engine::calc_pos(Vector2 mouse_pos)
{
	mouse_pos -= 30;
	mouse_pos /= _tile_size;
	mouse_pos = mouse_pos.floor();
	cout << "Mouse coord : " << mouse_pos << endl;
	return (mouse_pos);
}

bool c_game_engine::can_move(Vector2 target)
{
	if (is_inside(target) == false || _player.pos().distance(target) > 1)
		return (false);
	return (true);
}

void c_game_engine::move_player(Vector2 target)
{
	for (int i = 0; i < 5; i++)
	{
		if (tile_status(_player.pos() + neighbour[i]) != tile_state::reveal)
			set_tile_status(_player.pos() + neighbour[i], tile_state::discovered);
	}
	_player.set_pos(target);
	for (int i = 0; i < 5; i++)
		if (tile_status(_player.pos() + neighbour[i]) != tile_state::reveal)
			set_tile_status(_player.pos() + neighbour[i], tile_state::seen);
}

bool c_game_engine::try_move(Vector2 delta)
{
	if (can_move(_player.pos() + delta))
	{
		move_player(_player.pos() + delta);
		return (true);
	}
	return (false);
}

bool c_game_engine::handle_keyboard()
{
	if (g_keyboard->get_key(SDL_SCANCODE_ESCAPE))
	{
		g_application->quit();
		return (true);
	}

	if (g_keyboard->get_key(SDL_SCANCODE_W))
		return (try_move(neighbour[UP]));

	if (g_keyboard->get_key(SDL_SCANCODE_S))
		return (try_move(neighbour[DOWN]));

	if (g_keyboard->get_key(SDL_SCANCODE_A))
		return (try_move(neighbour[LEFT]));

	if (g_keyboard->get_key(SDL_SCANCODE_D))
		return (try_move(neighbour[RIGHT]));

	return (false);
}

bool c_game_engine::handle_mouse()
{
	if (g_mouse->get_button(mouse_button::left) == mouse_state::down)
	{
		Vector2 target = calc_pos(g_mouse->pos);
		return (try_move(target - _player.pos()));
	}
	return (false);
}
