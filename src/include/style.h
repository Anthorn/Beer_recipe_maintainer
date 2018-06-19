#pragma once

#include <string>
#include "parsable.h"

class Style : Parsable {


  public:
    void        parse(std::shared_ptr<BeersmithXMLParser> parser);
    void        populate(std::map<std::string, std::string> rawStyle);
    void        print() const override;
    void        insertValue(std::string attribute, std::string value);

  private:
    std::string name, version, type, category, notes;
    double minAbv, maxAbv, colorMax, colorMin, IBUMin, IBUMax;
};
