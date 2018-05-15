#pragma once

#include <string>
#include "parsable.h"


using namespace std;




class Style : Parsable {


  public:
    void parse(std::shared_ptr<BeersmithXMLParser> parser);
    void populate(map<string, string> rawStyle);
    void print();
    void insertValue(string attribute, string value);

  private:
    string name, version, type, category, notes;
    double minAbv, maxAbv, colorMax, colorMin, IBUMin, IBUMax;
};
