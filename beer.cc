using namespace std;
/**
 *	The main class holding a beer.
 *
 *	The intention of this class is to act as the
 *	actual representation of the beer the user wants information about
 *	It holds its recipie and the attributes of the beer.
 *
 */

class Beer {
	int ABV;
	int IBU;
	int SRM;
	int orig_gravity;
	int final_gravity;
	Beer_recipe br;
  public:
	int get_abv();
	int get_ibu();
	int get_srm();
};


int Beer::get_abv(){
	if (ABV == NULL){
		ABV = ((orig_gravity - final_gravity) / 0.00753);
	}
	return ABV;
}


int Beer::get_ibu(){
	if (IBU == NULL){
		IBU = br.get_ibu();
	}

	return IBU;

};
