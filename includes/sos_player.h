#ifndef SOS_PLAYER_H
#define SOS_PLAYER_H

class c_player
{
private:
	Vector2 _pos;
	Vector2 _old_pos;
	Vector2 _draw_pos;
	int _nb_frame;
	Vector2 _delta;

public:
	c_player();
	~c_player();

	void draw(class c_game_engine *engine);

	void move(Vector2 target, int nb_frame = 30);

	bool is_moving(){return (_nb_frame > 0 ? true : false);}
	bool is_active(){return (false);}

	void set_pos(Vector2 p_pos){_pos = p_pos;}
	Vector2 pos(){return (_pos);}

	void set_old_pos(Vector2 p_old_pos){_old_pos = p_old_pos;}
	Vector2 old_pos(){return (_old_pos);}

	void set_draw_pos(Vector2 p_draw_pos){_draw_pos = p_draw_pos;}
	Vector2 draw_pos(){return (_draw_pos);}

	void set_delta(Vector2 p_delta){_delta = p_delta;}
	Vector2 delta(){return (_delta);}

	void set_nb_frame(int p_nb_frame){_nb_frame = p_nb_frame;}
	int nb_frame(){return (_nb_frame);}
};

#endif
