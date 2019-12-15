#include "sos.h"

c_city_panel::c_city_panel(c_widget *p_parent) : c_widget(p_parent)
{
	_frame = new c_frame(this);
	_frame->box().set_back(Color(75, 60, 45));
	_frame->box().set_front(Color(100, 80, 60));
	_frame->activate();

	_city_name = new c_text_label("City name", _frame);
	_city_name->box().set_back(Color(95, 80, 65));
	_city_name->box().set_front(Color(120, 100, 80));
	_city_name->label().set_align(alignment::centred);
	_city_name->label().set_color(text_color::dark_grey);
	_city_name->activate();

	_city = nullptr;

	_city_defense_label = new c_text_label("City defense :", _frame);
	_city_defense_label->box().set_back(Color(95, 80, 65));
	_city_defense_label->box().set_front(Color(120, 100, 80));
	_city_defense_label->label().set_align(alignment::left);
	_city_defense_label->label().set_color(text_color::dark_grey);
	_city_defense_label->activate();

	_city_defense_value = new c_value_label(-1.0f, _frame);
	_city_defense_value->box().set_back(Color(95, 80, 65));
	_city_defense_value->box().set_front(Color(120, 100, 80));
	_city_defense_value->label().set_align(alignment::centred);
	_city_defense_value->activate();

	_city_population_label = new c_text_label("City population :", _frame);
	_city_population_label->box().set_back(Color(95, 80, 65));
	_city_population_label->box().set_front(Color(120, 100, 80));
	_city_population_label->label().set_align(alignment::left);
	_city_population_label->label().set_color(text_color::dark_grey);
	_city_population_label->activate();

	_city_population_value = new c_value_label(-1.0f, _frame);
	_city_population_value->box().set_back(Color(95, 80, 65));
	_city_population_value->box().set_front(Color(120, 100, 80));
	_city_population_value->label().set_align(alignment::centred);
	_city_population_value->activate();
}
c_city_panel::~c_city_panel()
{

}

void c_city_panel::set_geometry_imp(Vector2 p_anchor, Vector2 p_area)
{
	_frame->set_geometry(0, p_area);
	_city_name->set_geometry(Vector2(10, 10), Vector2(_frame->area().x - 20, 40.0f));
	_city_defense_label->set_geometry(Vector2(10, 60), Vector2(_frame->area().x - 120, 30.0f));
	_city_defense_value->set_geometry(Vector2(15 + _city_defense_label->box().area().x, 60.0f), Vector2(90, 30));
	_city_population_label->set_geometry(Vector2(10, 95), Vector2(_frame->area().x - 120, 30.0f));
	_city_population_value->set_geometry(Vector2(15 + _city_population_label->box().area().x, 95.0f), Vector2(90, 30));
}

void c_city_panel::render()
{

}

void c_city_panel::parse_city()
{
	if (_city == nullptr)
	{
		_city_name->label().set_text("No city");
		return ;
	}
	if (_city_name->text() != _city->name())
		_city_name->label().set_text(_city->name());
	if (_city_defense_value->value() != _city->defense())
		_city_defense_value->label().set_value(_city->defense());
	if (_city_population_value->value() != _city->population())
		_city_population_value->label().set_value(_city->population());
}

void c_city_panel::update()
{
	parse_city();
}

void c_city_panel::set_city(c_city *p_city)
{
	_city = p_city;
	parse_city();
}
