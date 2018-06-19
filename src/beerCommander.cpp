#include "beerCommander.h"

BeerCommander::BeerCommander(std::shared_ptr<Parsable> parsable, std::string cmd)
    : parsable(parsable)
    , cmd(cmd)
{
}

void BeerCommander::execute()
{
    if (cmd == "PRINT")
    {
        parsable->print();
    }
    else if (cmd == "HELP")
    {
        std::cout << "The following options are available: \n" <<
            "task: [ PRINT, HELP ]\n" <<
            "resource: [ BEERDATA, EQUIPMENT, FERMENTABLES, HOPS, MASHSCHEDULE, RECIPE, WATERPROFILES, YEASTS ] \n" <<
            "Example: PRINT|EQUIPMENT\n";
    }
}
