#include "recipe.h"

Recipe::Recipe(const char* fileName)
{
    parser.reset(new BeersmithXMLParser(fileName));
}

void Recipe::loadBeerData()
{
    if (!beerData) beerData.reset(new BeerData());

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

void Recipe::printRecipe() const
{
    if (beerData)       beerData->print();
    if (hops)           hops->print();
    if (fermentables)   fermentables->print();
    if (yeasts)         std::cout << yeasts;
    if (waterProfiles)  waterProfiles->print();
    if (style)          style->print();
    if (equipment)      equipment->print();
    if (mash)           mash->print();
}

void Recipe::issueCommand(std::string cmd)
{
    std::stringstream ss(cmd);
    std::string task, resource;

    std::getline(ss, task, '|');
    std::getline(ss, resource, '|');

    bool validTask(std::find(supportedTask.begin(), supportedTask.end(), task) != supportedTask.end());
    if (validTask == false)
    {
        std::cout << "Unsupported Task: " << task << " exiting...\n";
        return;
    }

    if (task != "HELP")
    {
        bool validResource(std::find(supportedResources.begin(), supportedResources.end(), resource) != supportedResources.end());

        if (validResource == false)
        {
            std::cout << "Unsupported Resource: " << resource << " exiting...\n";
            return;
        }
    }
    std::shared_ptr<BeerCommander> commander;

    commander.reset(new BeerCommander(pickResource(resource), task));
    commander->execute();
}

std::shared_ptr<Parsable> Recipe::pickResource(std::string resource)
{
    if (resource == "BEERDATA")
    {
        return Recipe::getBeerData();
    }
    else if(resource == "EQUIPMENT")
    {

        return Recipe::getEquipment();
    }
    else if(resource == "FERMENTABLES")
    {

        return Recipe::getFermentables();
    }
    else if(resource == "HOPS")
    {
        return Recipe::getHops();

    }
    else if(resource == "MASHSCHEDULE")
    {
        return Recipe::getMashSchedule();

    }
    else if(resource == "RECIPE")
    {
        //unimplemented
        std::cout << "No commander inmplemented for an entire recipe yet... Pick a piece of a recipe to print for now.. \n";
    }
    else if(resource == "WATERPROFILES")
    {
        return Recipe::getWaterProfiles();

    }
    else if(resource == "YEASTS")
    {
        return Recipe::getYeasts();

    }
    else if (resource == "")
    {
        //nop
    }
    else
    {
        std::cout << "Did not recognize resource " << resource << "\n";
    }
}

std::shared_ptr<BeersmithXMLParser> Recipe::getParser()
{
    return parser;
}

std::shared_ptr<BeerData> Recipe::getBeerData()
{
    return beerData;
}

std::shared_ptr<Hops> Recipe::getHops()
{
    return hops;
}

std::shared_ptr<Fermentables> Recipe::getFermentables()
{
    return fermentables;
}

std::shared_ptr<Yeasts> Recipe::getYeasts()
{
    return yeasts;
}

std::shared_ptr<WaterProfiles> Recipe::getWaterProfiles()
{
    return waterProfiles;
}

std::shared_ptr<MashSchedule> Recipe::getMashSchedule()
{
    return mash;
}

std::shared_ptr<Style> Recipe::getStyle()
{
    return style;
}

std::shared_ptr<Equipment> Recipe::getEquipment()
{
    return equipment;
}
