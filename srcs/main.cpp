#include "sos.h"

Vector2 g_board_size = Vector2(13, 13);

int main(int argc, char**argv)
{
	Vector2 tile_size = Vector2(64, 64);

	Vector2 board_screen_size = g_board_size * tile_size + 60;
	Vector2 panel_screen_size = Vector2(450.0f, board_screen_size.y);
	Vector2 screen_size = Vector2(board_screen_size.x + panel_screen_size.x, board_screen_size.y);

	c_application win("RPG Hordes (c)", screen_size, Color(30, 30, 30));

	c_game_engine engine;
	engine.set_geometry(0, g_board_size * tile_size + 60);
	engine.activate();

	Vector2 panel_coord = Vector2(board_screen_size.x, 15.0f);
	Vector2 panel_size = panel_screen_size - Vector2(15.0f, 30.0f);
	c_city_panel city_panel = c_city_panel(panel_coord, panel_size);
	city_panel.activate();

	c_city tmp_city;
	tmp_city.set_name("Epic city name !");

	city_panel.set_city(&tmp_city);

	return (win.run());
}
