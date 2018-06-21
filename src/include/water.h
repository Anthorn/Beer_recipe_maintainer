#pragma once

#include <string>
#include "parsable.h"

class Water : Parsable {
  public:
    void                    populate(std::map<std::string, std::string> rawWater);
    void                    insertValue(std::string attribute, std::string value);
    friend std::ostream&    operator<<(std::ostream &out, const Water water);

  private:
    std::string name, version, notes;
    double amount, calcium, bicarbonate, sulfate, chloride, sodium, magnesium, ph;
};
