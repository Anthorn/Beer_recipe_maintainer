#pragma once
#include <memory>
#include <string>
#include "parsable.h"


using namespace std;


/*
 * This class represent a hop addition in a beer recipe. Not to
 * be confused with an ordinary Hop.
 */

class Hop : public Parsable {
  public:
    void print() override;
    void populate(map<string, string> rawHop) override;
    void insertValue(string attribute, string value);

  private:
    string name, version, origin, use, notes, type, form;
    double alphaAcid, amount, time;
};

