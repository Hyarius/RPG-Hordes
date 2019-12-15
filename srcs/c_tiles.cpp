#include "sos.h"

c_tile::c_tile(tile_type p_type, tile_state p_discovered)
{
	_type = p_type;
	_discovered = p_discovered;
	_nb_zombie = 2;
}

c_tile::~c_tile()
{

}
