#ifndef DEF_RECIPE
#define DEF_RECIPE
#include <beerData.h>
#include <hops.h>
#include <fermentables.h>
#include <waterProfiles.h>
#include <yeasts.h>
#include <style.h>
#include <equipment.h>
#include <mashSchedule.h>
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
    WaterProfiles* getWaterProfiles();
    Yeasts* getYeasts();
    Style* getStyle();
    Equipment* getEquipment();
    MashSchedule* getMashSchedule();

  private:
    BeersmithXMLParser* parser;
    BeerData* beerData;
    Hops* hops;
    Fermentables* fermentables;
    Yeasts* yeasts;
    WaterProfiles* waterProfiles;
    MashSchedule* mash;
    Style* style;
    Equipment* equipment;
};

#endif

