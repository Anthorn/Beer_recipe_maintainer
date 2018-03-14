#include <beerData.h>
#include <hop.h>
#include <fermentable.h>
#include <water.h>
#include <yeast.h>
#include <style.h>
#include <equipment.h>
#include <mash.h>

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


class Recipe {

  public:
    BeerData getBeerData();
    list<Hop> getHops();
    list<Fermentable> getFermentables();
    list<Water> getWaterProfiles();
    list<Yeast> getYeasts();
    Style getStyle();
    Equipment getEquipment();
    Mash getMashSchedule();


  private:
    BeerData beerData;
    list<Hop> hops;
    list<Fermentable> fermentables;
    list<Yeast> yeasts;
    list<Water> waterProfiles;
    Style style;
    Equipment equipment;
    Mash mash;
};
