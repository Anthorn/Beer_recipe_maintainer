#pragma once
#include <string>
#include "parsable.h"
#include <memory>



class BeerData : public Parsable {

  public:
    BeerData() {};

    void populate(map<string, string> parsedMap);
    void parse(std::shared_ptr<BeersmithXMLParser> parser);
    void print();
    void insertValue(string attribute, string value);
  private:
    string name, version, type, brewer;
    float batchSize, boilSize, boilTime;
    double abv, estAbv, efficiency;
};

