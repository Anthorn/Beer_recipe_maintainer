#pragma once

#include <string>
#include "parsable.h"

/*
 * This class represents the water profile for a recipe.
 * All the mineral additions are represented in ppm
 */

using namespace std;


class Water {
  public:
    void print();
    void populate(map<string, string> rawWater);
    void insertValue(string attribute, string value);

  private:
    string name, version, notes;
    double amount, calcium, bicarbonate, sulfate, chloride, sodium, magnesium, ph;
};
