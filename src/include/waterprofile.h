#pragma once
#include <list>
#include "water.h"


class WaterProfiles : public Parsable {

  public:
    void parse(std::shared_ptr<BeersmithXMLParser> parser);
    void populate(std::list<std::map<std::string, std::string>> rawWaterList);
    void print();

  private:
    std::list<std::shared_ptr<Water>> waterProfiles;

};
