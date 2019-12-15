#ifndef SOS_CITY_H
#define SOS_CITY_H

class c_city
{
private:
	string _name;
	size_t _defense;
	size_t _population;

public:
	c_city();
	~c_city();

	void set_name(string p_name){_name = p_name;}
	string name(){return (_name);}

	void set_defense(size_t p_defense){_defense = p_defense;}
	size_t defense(){return (_defense);}

	void set_population(size_t p_population){_population = p_population;}
	size_t population(){return (_population);}
};

#endif
