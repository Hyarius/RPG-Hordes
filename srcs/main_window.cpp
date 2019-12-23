#include "rpg_hordes.h"

c_main_window::c_main_window()
{
	board_frame = new c_frame();
	board_frame->activate();
	player_frame = new c_frame();
	player_frame->activate();
	info_frame = new c_frame();
	info_frame->activate();

	set_size();

}

void c_main_window::set_size()
{
	float space;
	Vector2 pos;
	Vector2 win_size;
	Vector2 size;

	win_size = g_application->size();
	space = win_size.x / 100;
	pos = Vector2(space, space);
	size = Vector2(win_size.x - 2 * space, win_size.y / 12);
	player_frame->set_geometry(pos, size);
	pos.y += space + size.y;
	size = Vector2(((win_size.x / 10) * 7), win_size.y - size.y - 3 * space);
	board_frame->set_geometry(pos, size);

	pos.x += size.x + space;
	size = win_size - pos - space;
	//
	info_frame->set_geometry(pos, size);
}
