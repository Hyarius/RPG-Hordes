#include "rpg_hordes.h"

int percent[] = {30, 25, 20, 0, 8, 3, 6, 5, 2};

c_board::c_board()
{
	tileset = new c_tileset("ressources/tileset/base_tileset.png", Vector2(10, 6));
	center = 0;
	player_vision = 6;
	generate_area(center);
}

void c_board::generate_tile(int x, int y)
{
	generate_tile(Vector2(x, y));
}

void c_board::generate_tile(Vector2 pos)
{
	int tmp = generate_nbr(0, 100);
	int type = 0;
	for (type = 0; type < 9 && tmp > percent[type] ; type++)
		tmp -= percent[type];

	tile_index[pos] = type % 9;
}

bool c_board::check_tile(Vector2 pos)
{
	auto it = tile_index.find(pos);
	if (it != tile_index.end())
		return (true);
	return (false);
}

void c_board::generate_area(Vector2 target)
{
	Vector2 pos;
	for (pos.x = -player_vision; pos.x <= player_vision; pos.x++)
		for (pos.y = -player_vision; pos.y <= player_vision; pos.y++)
			generate_tile(pos + target);
	tile_index[0] = 3;
}

void c_board::set_geometry_imp(Vector2 p_anchor, Vector2 p_area)
{
	tile_size = p_area / (player_vision * 2 + 1);
}

void c_board::render()
{
	viewport()->use();
	Vector2 pos;
	for (pos.x = -player_vision; pos.x <= player_vision; pos.x++)
		for (pos.y = -player_vision; pos.y <= player_vision; pos.y++)
			tileset->draw(tile_index[pos + center], (pos + center + player_vision) * tile_size, tile_size, viewport());
}
