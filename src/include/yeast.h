#pragma once

#include <string>
#include "parsable.h"


using namespace std;




class Yeast {
  public:
    void print();
    void populate(map<string, string> rawYeast);

  private:
    string name, version, type, form, productID, laboratory, notes, cultureDate, flocculation;
    double attenuation, minTemp, maxTemp, amount;
    bool amountIsWeight;
    void insertValue(string attribute, string value);
};

