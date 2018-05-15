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

    string getName();
    string getVersion();
    string getNotes();
    double getAmount();
    double getCalcium();
    double getBicarbonate();
    double getSulfate();
    double getChlorides();
    double getSodium();
    double getMagnesium();
    double getPH();
  private:
    string name, version, notes;
    double amount, calcium, bicarbonate, sulfate, chloride, sodium, magnesium, ph;
};
