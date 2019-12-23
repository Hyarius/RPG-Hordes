#include "rpg_hordes.h"

int main(int argc, char**argv)
{
	c_application win("RPG Hordes (c)", Vector2(0.85f, 0.85f), Color(30, 30, 30));


	c_frame main_frame = c_frame();
	main_frame.set_geometry(Vector2(50, 50), Vector2(1200, 850));
	main_frame.box().set_tileset(new c_tileset("ressources/tileset/frame_border.png", Vector2(3, 3)));
	main_frame.activate();

	c_frame frame_1 = c_frame(&main_frame);
	frame_1.set_geometry(50, Vector2(150, 50));
	frame_1.set_back(Color(255, 0, 0));
	frame_1.set_front(Color(0, 255, 0));
	frame_1.box().set_tileset(new c_tileset("ressources/tileset/frame_border.png", Vector2(3, 3)));
	frame_1.activate();

	c_frame frame_2 = c_frame(&main_frame);
	frame_2.set_geometry(Vector2(200, 50), Vector2(150, 50));
	frame_1.set_back(Color(120, 120, 0));
	frame_1.set_front(Color(0, 120, 120));
	frame_2.activate();

	return (win.run());
}
