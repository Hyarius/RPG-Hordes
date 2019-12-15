#ifndef SOS_H
#define SOS_H


#include "sos_includes.h"

#include "sos_city.h"
#include "sos_player.h"
#include "sos_tiles.h"
#include "sos_city_panel.h"
#include "sos_game_engine.h"

#define SELF 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define UP 4

extern Vector2 g_board_size;
extern Vector2 neighbour[5];

using namespace std;

#endif
