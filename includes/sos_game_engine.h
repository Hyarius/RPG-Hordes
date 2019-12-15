#ifndef SOS_GAME_ENGINE_H
#define SOS_GAME_ENGINE_H

class c_game_engine : public c_widget
{
private:
	c_player _player;
	c_tileset _tileset;
	Vector2 _board_size;
	Vector2 _tile_size;
	vector<vector<c_tile>>	_board;

public:
	c_game_engine();
	~c_game_engine();

	void populate_board();

	Vector2 screen_size();
	void set_geometry_imp(Vector2 p_anchor, Vector2 p_area);
	void render();
	bool handle_keyboard();
};

#endif
