#include "recipe.h"


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
    parser.reset(new BeersmithXMLParser(fileName));
}


void Recipe::loadBeerData()
{
    if (!beerData)
        beerData.reset(new BeerData());

    beerData->parse(parser);
}

void Recipe::loadHops()
{
    if (!hops) hops.reset(new Hops());

    hops->parse(parser);
}

void Recipe::loadFermentables()
{
    if (!fermentables) fermentables.reset(new Fermentables());

    fermentables->parse(parser);

}


void Recipe::loadYeasts()
{
    if (!yeasts) yeasts.reset(new Yeasts());

    yeasts->parse(parser);
}

void Recipe::loadWaterProfiles()
{
    if (!waterProfiles) waterProfiles.reset(new WaterProfiles());

    waterProfiles->parse(parser);
}


void Recipe::loadStyle()
{
    if (!style) style.reset(new Style);

    style->parse(parser);

}

void Recipe::loadEquipment()
{
    if (!equipment) equipment.reset(new Equipment);
    equipment->parse(parser);

}


void Recipe::loadMashSchedule()
{
    if (!mash) mash.reset(new MashSchedule());

    mash->parse(parser);

}

void Recipe::printRecipe()
{
    if (beerData)       beerData->print();
    if (hops)           hops->print();
    if (fermentables)   fermentables->print();
    if (yeasts)         yeasts->print();
    if (waterProfiles)  waterProfiles->print();
    if (style)          style->print();
    if (equipment)      equipment->print();
    if (mash)           mash->print();
}



