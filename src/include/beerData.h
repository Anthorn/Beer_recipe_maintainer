#pragma once
#include <string>
#include "parsable.h"
#include <memory>


class BeerData : public Parsable {

  public:
    BeerData() {};

    void parse(std::shared_ptr<BeersmithXMLParser> parser);
    void print();
    void populate(std::map<std::string, std::string> parsedMap);
    void insertValue(std::string attribute, std::string value);

  private:
    std::string  name, version, type, brewer;
    float   batchSize, boilSize, boilTime;
    double  abv, estAbv, efficiency;
};

