#include "sos.h"

c_tile::c_tile(tile_type p_type, tile_state p_status)
{
	_type = p_type;
	_status = p_status;
	_nb_zombie = 2;
}

c_tile::~c_tile()
{

}
