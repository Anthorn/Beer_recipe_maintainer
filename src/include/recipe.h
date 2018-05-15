#pragma once
#define __STDAFX_INCLUDED__
#include "beerData.h"
#include "hops.h"
#include "fermentables.h"
#include "waterProfile.h"
#include "yeasts.h"
#include "style.h"
#include "equipment.h"
#include "mashSchedule.h"
#include <list>
#include <memory>
#include "parsable.h"


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
    void  loadBeerData();
    void  loadHops();
    void  loadFermentables();
    void  loadWaterProfiles();
    void  loadYeasts();
    void  loadStyle();
    void  loadEquipment();
    void  loadMashSchedule();
    void  printRecipe();

  private:
    std::shared_ptr<BeersmithXMLParser>  parser;
    std::shared_ptr<BeerData>            beerData;
    std::shared_ptr<Hops>                hops;
    std::shared_ptr<Fermentables>        fermentables;
    std::shared_ptr<Yeasts>              yeasts;
    std::shared_ptr<WaterProfiles>       waterProfiles;
    std::shared_ptr<MashSchedule>        mash;
    std::shared_ptr<Style>               style;
    std::shared_ptr<Equipment>           equipment;
};

