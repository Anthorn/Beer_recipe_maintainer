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
#include "beerCommander.h"


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
    void                                loadBeerData();
    void                                loadHops();
    void                                loadFermentables();
    void                                loadWaterProfiles();
    void                                loadYeasts();
    void                                loadStyle();
    void                                loadEquipment();
    void                                loadMashSchedule();
    void                                printRecipe();
    void                                issueCommand(std::string cmd);

    std::shared_ptr<Parsable>           pickResource(std::string resource);

    std::shared_ptr<BeersmithXMLParser> getParser();
    std::shared_ptr<BeerData>           getBeerData();
    std::shared_ptr<Hops>               getHops();
    std::shared_ptr<Fermentables>       getFermentables();
    std::shared_ptr<Yeasts>             getYeasts();
    std::shared_ptr<WaterProfiles>      getWaterProfiles();
    std::shared_ptr<MashSchedule>       getMashSchedule();
    std::shared_ptr<Style>              getStyle();
    std::shared_ptr<Equipment>          getEquipment();

  private:
    std::shared_ptr<BeersmithXMLParser> parser;
    std::shared_ptr<BeerData>           beerData;
    std::shared_ptr<Hops>               hops;
    std::shared_ptr<Fermentables>       fermentables;
    std::shared_ptr<Yeasts>             yeasts;
    std::shared_ptr<WaterProfiles>      waterProfiles;
    std::shared_ptr<MashSchedule>       mash;
    std::shared_ptr<Style>              style;
    std::shared_ptr<Equipment>          equipment;
};

