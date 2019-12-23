#include "rpg_hordes.h"

int main(int argc, char**argv)
{
	c_application win("RPG Hordes (c)", Vector2(0.85f, 0.85f), Color(30, 30, 30));

	c_main_window window;

	return (win.run());
}
