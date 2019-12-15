#ifndef SOS_PLAYER_H
#define SOS_PLAYER_H

class c_player
{
private:
	Vector2 _pos;

public:
	c_player();
	~c_player();

	void draw(class c_game_engine *engine);

	void move(Vector2 target);

	void set_pos(Vector2 p_pos){_pos = p_pos;}
	Vector2 pos(){return (_pos);}
};

#endif
