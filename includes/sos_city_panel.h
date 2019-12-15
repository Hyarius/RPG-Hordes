#ifndef SOS_CITY_PANEL_H
#define SOS_CITY_PANEL_H

class c_city_panel : public c_widget
{
private:
	c_city *_city;
	c_frame *_frame;

	// - City name part
	c_text_label *_city_name;

	// - City info part
	c_text_label *_city_defense_label; // --> draw "City defense :"
	c_value_label *_city_defense_value; // --> draw la valeur

	c_text_label *_city_population_label; // --> draw "City defense :"
	c_value_label *_city_population_value; // --> draw la valeur

public:
	c_city_panel(c_widget *parent = nullptr);
	~c_city_panel();

	void parse_city();
	void set_city(c_city *p_city);

	void set_geometry_imp(Vector2 p_anchor, Vector2 p_area);
	void render();
	void update();
};

#endif
