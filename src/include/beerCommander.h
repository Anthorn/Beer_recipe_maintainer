#pragma once
#include "parsable.h"


class BeerCommander
{
    public :
        BeerCommander(std::shared_ptr<Parsable> parsable, std::string cmd);
        void execute();

    private:
        std::shared_ptr<Parsable>    parsable;
        std::string                  cmd;
};