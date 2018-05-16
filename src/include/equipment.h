#pragma once
#include <string>
#include "parsable.h"

class Equipment : public Parsable {
  public:
    void parse(std::shared_ptr<BeersmithXMLParser> parser);
    void print();
    void populate(std::map<std::string, std::string> parsedMap);
    void insertValue(std::string attribute, std::string value);


  private:
    std::string name, version, notes;
    double batchSize, boilSize, boilTime, efficency, tunVolume, trubChillerLoss, evaporationRate,
           hopUtil, lauterDeadspace;
};


