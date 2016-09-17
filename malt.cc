using namespace std;

/**
 *
 * This class represent a malt variety
 *
 */


class Malt {
	string Name;
	int loviblond;
	string description;
	public:
	string get_name();
	int get_loviblond();
	string get_description();

};



string Malt::get_name(){

	return Name;
};

int Malt::get_loviblond(){

	return loviblond;
};


string Malt::get_description(){

	return description;
};

