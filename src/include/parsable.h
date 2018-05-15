#pragma once

#include <string>
#include <iostream>
#include <memory>
#include "beerParser.h"




class Parsable
{
public:
    virtual void parse(std::shared_ptr<BeersmithXMLParser> parser) {};
    virtual void populate(map<string, string> parsedMap) {};
    virtual void populate(list<map<string, string>> parsedList) {};
    virtual void print() {};

    static bool convertStringToBool(string value)
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
    static string printBool(bool value)
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
