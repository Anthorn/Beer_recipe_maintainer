using namespace std;

/*
 * This class hold the malt bill
 * Use this to calculate original gravity,
 * and SRM.
 *
 *
 */

class Malt_Bill {
	int batch_volume;
	array Malt malts;
	public:
	int get_original_gravity();
	int get_srm();


};

/*
 * Calculates and returns the
 * original gravity this malt bill
 * will produce
 */
int Malt_Bill:get_original_gravity(){
	return 0;
}

/*
 *	Returns the srm, e.g. the colour of
 *	the beer that this malt bill will
 *	result in.
 */

int Malt_Bill:get_srm(){
	return 0;
}

