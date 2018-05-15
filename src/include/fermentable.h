#pragma once
#include <string>
#include "parsable.h"

using namespace std;

class Fermentable{
  public:
    void print();
    void populate(map<string, string> rawFermentable);
    void insertValue(string attribute, string value);

  private:
    string name, version, type, origin, supplier, notes;
    double amount, yield, color;
    bool addAfterBoil;
    bool recommendedMash;
};

