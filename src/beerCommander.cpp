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
        std::cout << " The following options are available: \n task: [ PRINT|HELP ] , resource: [ BEER_DATA | EQUIPMENT | FERMENTABLES | HOPS | MASHSCHEDULE | RECIPE | WATER_PROFILE | YEASTS ] \n";
    }
}
