#include "sos.h"

c_player::c_player()
{
	_pos = 0;
}

c_player::~c_player()
{

}

void c_player::draw(c_game_engine *engine)
{
	engine->tileset().draw(12, pos() * engine->tile_size() + 30, engine->tile_size());

	if (engine->is_inside(pos() + neighbour[DOWN]) == true)
		engine->tileset().draw(16, pos() * engine->tile_size() + 30 + Vector2(0.0f, engine->tile_size().y / 2.0f), engine->tile_size());

	if (engine->is_inside(pos() + neighbour[LEFT]) == true)
		engine->tileset().draw(17, pos() * engine->tile_size() + 30 - Vector2(engine->tile_size().x / 2.0f, 0.0f), engine->tile_size());

	if (engine->is_inside(pos() + neighbour[UP]) == true)
		engine->tileset().draw(18, pos() * engine->tile_size() + 30 - Vector2(0.0f, engine->tile_size().y / 2.0f), engine->tile_size());

	if (engine->is_inside(pos() + neighbour[RIGHT]) == true)
		engine->tileset().draw(19, pos() * engine->tile_size() + 30 + Vector2(engine->tile_size().x / 2.0f, 0.0f), engine->tile_size());
}

void c_player::move(Vector2 target)
{
	set_pos(target);
}
