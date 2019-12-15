#ifndef SOS_GAME_ENGINE_H
#define SOS_GAME_ENGINE_H

class c_game_engine : public c_widget
{
private:
	c_player _player;
	c_city _city;

	c_city_panel *_city_panel;

	c_tileset _tileset;
	Vector2 _board_size;
	Vector2 _tile_size;
	vector<vector<c_tile>>	_board;

public:
	c_game_engine();
	~c_game_engine();

	void set_tileset(c_tileset &p_tileset){_tileset = p_tileset;}
	c_tileset &tileset(){return (_tileset);}

	void set_board_size(Vector2 p_board_size){_board_size = p_board_size;}
	Vector2 board_size(){return (_board_size);}

	void set_tile_size(Vector2 p_tile_size){_tile_size = p_tile_size;}
	Vector2 tile_size(){return (_tile_size);}

	void populate_board();
	Vector2 calc_pos(Vector2 mouse_pos);
	bool can_move(Vector2 target);
	void move_player(Vector2 target, int nb_frame = 12);
	bool try_move(Vector2 delta);
	void set_tile_status(int x, int y, tile_state p_state);
	void set_tile_status(Vector2 tile_pos, tile_state p_state);
	void actualize_tile(Vector2 target, tile_state p_state);

	bool is_inside(int x, int y);
	bool is_inside(Vector2 target);

	tile_state tile_status(int x, int y);
	tile_state tile_status(Vector2 tile_pos);

	void set_geometry_imp(Vector2 p_anchor, Vector2 p_area);
	void render();
	bool handle_keyboard();
	bool handle_mouse();
};

#endif
