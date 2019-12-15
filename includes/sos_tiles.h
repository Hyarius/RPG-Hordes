#ifndef SOS_TILES_H
#define SOS_TILES_H


enum class tile_type
{
	empty = 0,
	city = 1,
	forest = 2,
	mine = 3,
	building = 4,
	water = 5
};

enum class tile_state
{
	error = -1,
	unknown = 0,
	discovered = 1,
	seen = 2,
	reveal = 3
};

class c_tile
{
private:
	tile_type _type;
	tile_state _status;
	int _nb_zombie;

public:
	c_tile(tile_type p_type = tile_type::empty, tile_state p_status = tile_state::unknown);
	~c_tile();

	void set_type(tile_type p_type){_type = p_type;}
	tile_type type(){return (_type);}

	void set_status(tile_state p_status){_status = p_status;}
	tile_state status(){return (_status);}

	void set_nb_zombie(int p_nb_zombie){_nb_zombie = p_nb_zombie;}
	int nb_zombie(){return (_nb_zombie);}
};

#endif
