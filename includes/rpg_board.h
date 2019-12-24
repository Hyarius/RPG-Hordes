#ifndef RPG_BOARD_H
#define RPG_BOARD_H

class c_board : public c_widget
{
private:
	c_tileset *tileset;
	map<Vector2, int> tile_index;

	int player_vision;
	Vector2 center;
	Vector2 tile_size;

public:
	c_board();

	void generate_tile(int x, int y);
	void generate_tile(Vector2 pos);
	void generate_area(Vector2 target);
	bool check_tile(Vector2 pos);

	void set_geometry_imp(Vector2 p_anchor, Vector2 p_area);
	void render();
};

#endif
