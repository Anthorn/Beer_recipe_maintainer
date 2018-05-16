#pragma once
#include <memory>
#include <string>
#include "parsable.h"

class Hop : public Parsable
{
public:
    void print() override;
    void populate(std::map<std::string, std::string> rawHop) override;
    void insertValue(std::string attribute, std::string value);

private:
    std::string name, version, origin, use, notes, type, form;
    double alphaAcid, amount, time;
};

