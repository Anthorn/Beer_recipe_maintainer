#pragma once
#include <list>
#include "water.h"


class WaterProfiles : public Parsable {

  public:
    void parse(std::shared_ptr<BeersmithXMLParser> parser);
    void populate(list<map<string, string>> rawWaterList);
    void print();

  private:
    list<Water*> waterProfiles;

};
