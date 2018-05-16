#pragma once

#include <string>
#include <iostream>
#include <memory>
#include "beerParser.h"




class Parsable
{
public:
    virtual void parse(std::shared_ptr<BeersmithXMLParser> parser) {};
    virtual void print() {};
    virtual void populate(std::map<std::string, std::string> parsedMap) {};
    virtual void populate(std::list<std::map<std::string, std::string>> parsedList) {};

    static bool convertStringToBool(std::string value)
    {
        if (value.compare("TRUE") == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    static std::string printBool(bool value)
    {
        if (value)
        {
            return "true";
        }
        else
        {
            return "false";
        }
    }
protected:

};
