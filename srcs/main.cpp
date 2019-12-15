#include "sos.h"

Vector2 g_board_size = Vector2(13, 13);
Vector2 neighbour[5] = {
	Vector2(0, 0),
	Vector2(1, 0),
	Vector2(0, 1),
	Vector2(-1, 0),
	Vector2(0, -1),
};

int main(int argc, char**argv)
{
	Vector2 tile_size = Vector2(64, 64);

	Vector2 board_screen_size = g_board_size * tile_size + 60;
	Vector2 panel_screen_size = Vector2(450.0f, board_screen_size.y);
	Vector2 screen_size = Vector2(board_screen_size.x + panel_screen_size.x, board_screen_size.y);

	c_application win("RPG Hordes (c)", screen_size, Color(30, 30, 30));

	c_game_engine engine;
	engine.set_geometry(0, screen_size);
	engine.activate();

	return (win.run());
}
