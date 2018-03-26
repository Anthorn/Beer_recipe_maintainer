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
  this->parser = new BeersmithXMLParser(fileName);
}


BeerData* Recipe::getBeerData()
{
 this->beerData = new BeerData();
 this->beerData->parse(this->parser);

 return this->beerData;
}

Hops* Recipe::getHops()
{
  this->hops = new Hops();
  this->hops->parse(this->parser);

  return this->hops;
}

Fermentables* Recipe::getFermentables()
{
  this->fermentables = new Fermentables();
  this->fermentables->parse(this->parser);

  return this->fermentables;
}


Yeasts* Recipe::getYeasts(){
  this->yeasts = new Yeasts();
  this->yeasts->parse(this->parser);

  return this->yeasts;
}

WaterProfiles* Recipe::getWaterProfiles() {
  this->waterProfiles = new WaterProfiles();
  this->waterProfiles->parse(this->parser);

  return this->waterProfiles;
}


Style* Recipe::getStyle()
{
 this->style = new Style();
 this->style->parse(this->parser);

 return this->style;
}

Equipment* Recipe::getEquipment()
{
 this->equipment = new Equipment();
 this->equipment->parse(this->parser);

 return this->equipment;
}


MashSchedule* Recipe::getMashSchedule()
{
  this->mash = new MashSchedule();
  this->mash->parse(this->parser);

  return this->mash;
}



