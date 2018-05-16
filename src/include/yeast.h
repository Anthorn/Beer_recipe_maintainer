#pragma once

#include <string>
#include "parsable.h"

class Yeast {
  public:
    void print();
    void populate(std::map<std::string, std::string> rawYeast);

  private:
    std::string name, version, type, form, productID, laboratory, notes, cultureDate, flocculation;
    double attenuation, minTemp, maxTemp, amount;
    bool amountIsWeight;
    void insertValue(std::string attribute, std::string value);
};

