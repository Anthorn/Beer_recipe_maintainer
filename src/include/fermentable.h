#pragma once
#include <string>
#include "parsable.h"


class Fermentable : public Parsable
{
public:
    void print();
    void populate(std::map<std::string, std::string> rawFermentable);
    void insertValue(std::string attribute, std::string value);

private:
    std::string  name, version, type, origin, supplier, notes;
    double  amount, yield, color;
    bool    addAfterBoil;
    bool    recommendedMash;
};

