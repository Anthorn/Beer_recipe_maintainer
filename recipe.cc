#include <recipe.h>

using namespace std;

/*
 *	The class representing the
 *	actual recipe of a beer.
 *	Contains:
 *		- Malt bill
 *		- Hop schedule
 *		- Yeast
 *	More attributes will be added,
 *	such as water additions, mash schedule
 *	fermentation profile and so on..
 *
 */

Recipe::Recipe(const char* fileName)
{
  cout << "Inside recipe constructor" << endl;
  this->parser = new BeersmithXMLParser(fileName);
}


BeerData* Recipe::getBeerData()
{
 this->beerData = new BeerData();
 this->beerData->parse(this->parser);
 return this->beerData;
}

