#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

class c_main_window
{
private:
	c_frame *board_frame;
	c_frame *player_frame;
	c_frame *info_frame;
	c_frame *text_box_frame;

	c_board *board;

public:
	c_main_window();

	void set_size();
};

#endif
