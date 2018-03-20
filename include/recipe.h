#ifndef DEF_RECIPE
#define DEF_RECIPE
#include <beerData.h>
#include <hops.h>
#include <fermentables.h>
#include <water.h>
#include <yeast.h>
#include <style.h>
#include <equipment.h>
#include <mashStep.h>
#include <list>
#include <parsable.h>

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


class Recipe{

  public:
    Recipe(const char* fileName);
    BeerData* getBeerData();
    Hops* getHops();
    Fermentables* getFermentables();
//    list<Water> getWaterProfiles();
//    list<Yeast> getYeasts();
//    Style getStyle();
//    Equipment getEquipment();
//    list<MashStep> getMashSchedule();

  private:
    BeersmithXMLParser* parser;
    BeerData* beerData;
    Hops* hops;
    Fermentables* fermentables;
//    list<Yeast> yeasts;
//    list<Water> waterProfiles;
//    list<MashStep> mash;
//    Style style;
//    Equipment equipment;
};

#endif

