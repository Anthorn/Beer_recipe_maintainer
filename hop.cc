using namespace std;

/*
 *
 * This class represent a hop variety
 *
 */

class Hop {
	int alpha_acid;
	string name;
	string description;
	public:
	int get_alpha_acid();
	string get_name();
	string get_description();

};


int Hop::get_alpha_acid(){
	return alpha_acid;
};

string Hop::get_name(){
	return name;
};

string Hop:get_description(){
	return description;
};
