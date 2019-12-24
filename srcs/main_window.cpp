#include "rpg_hordes.h"

c_main_window::c_main_window()
{
	board_frame = new c_frame();
	board_frame->set_front(Color(100, 80, 60));
	board_frame->set_back(Color(90, 65, 50));
	board_frame->activate();
	player_frame = new c_frame();
	player_frame->set_front(Color(100, 80, 60));
	player_frame->set_back(Color(90, 65, 50));
	player_frame->activate();
	info_frame = new c_frame();
	info_frame->set_front(Color(100, 80, 60));
	info_frame->set_back(Color(90, 65, 50));
	info_frame->activate();
	text_box_frame = new c_frame();
	text_box_frame->set_front(Color(100, 80, 60));
	text_box_frame->set_back(Color(90, 65, 50));
	text_box_frame->activate();

	board = new c_board();
	board->activate();

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
	size = win_size.y - size.y - 3 * space;
	board_frame->set_geometry(pos, size);
	board->set_geometry(pos + 5, size - 10);

	pos.x += size.x + space;
	size = win_size - pos - space;
	size.y -= size.y / 8 * 3;
	size.y -= space / 2;
	info_frame->set_geometry(pos, size);

	pos.y += size.y + space;
	size = win_size - pos - space;
	text_box_frame->set_geometry(pos, size);
}
