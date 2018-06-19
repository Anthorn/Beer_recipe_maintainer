#pragma once
#include <list>
#include "fermentable.h"


class Fermentables : public Parsable
{

public:
    void                                     parse(std::shared_ptr<BeersmithXMLParser> parser);
    void                                     print() const override;
    void                                     populate(std::list<std::map<std::string, std::string>> rawFermentables);
    std::list<std::shared_ptr<Fermentable>>  getFermentables();
private:
    std::list<std::shared_ptr<Fermentable>> fermentables;

};


