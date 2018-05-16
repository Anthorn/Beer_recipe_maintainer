#pragma once

#include <string>
#include "parsable.h"

class Water {
  public:
    void print();
    void populate(std::map<std::string, std::string> rawWater);
    void insertValue(std::string attribute, std::string value);

  private:
    std::string name, version, notes;
    double amount, calcium, bicarbonate, sulfate, chloride, sodium, magnesium, ph;
};
