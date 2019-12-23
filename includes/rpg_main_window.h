#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

class c_main_window
{
private:
	c_frame *board_frame;
	c_frame *player_frame;
	c_frame *info_frame;

public:
	c_main_window();

	void set_size();
};

#endif
