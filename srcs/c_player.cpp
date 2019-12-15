#include "sos.h"

c_player::c_player()
{
	_pos = 0;
	_draw_pos = 0;
	_nb_frame = 0;
	_delta = 0;
}

c_player::~c_player()
{

}

void c_player::draw(c_game_engine *engine)
{
	engine->tileset().draw(12, draw_pos() * engine->tile_size() + 30, engine->tile_size());

	if (is_moving() == false)
	{
		if (engine->is_inside(pos() + neighbour[DOWN]) == true)
			engine->tileset().draw(16, pos() * engine->tile_size() + 30 + Vector2(0.0f, engine->tile_size().y / 2.0f), engine->tile_size());

		if (engine->is_inside(pos() + neighbour[LEFT]) == true)
			engine->tileset().draw(17, pos() * engine->tile_size() + 30 - Vector2(engine->tile_size().x / 2.0f, 0.0f), engine->tile_size());

		if (engine->is_inside(pos() + neighbour[UP]) == true)
			engine->tileset().draw(18, pos() * engine->tile_size() + 30 - Vector2(0.0f, engine->tile_size().y / 2.0f), engine->tile_size());

		if (engine->is_inside(pos() + neighbour[RIGHT]) == true)
			engine->tileset().draw(19, pos() * engine->tile_size() + 30 + Vector2(engine->tile_size().x / 2.0f, 0.0f), engine->tile_size());
	}
	else
	{
		_draw_pos += _delta;
		_nb_frame--;
	}
}

void c_player::move(Vector2 target, int nb_frame)
{
	set_delta((target - pos()) / nb_frame);
	set_old_pos(pos());
	set_pos(target);
	set_nb_frame(nb_frame);
}
