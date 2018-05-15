#pragma once
#include "parsable.h"

#include <string>


using namespace std;


class MashStep {

  public:
    void print();
    void populate(map<string, string> rawMashStep);
    void insertValue(string attribute, string value);

  private:
    string name, version, notes, type;
    double infuseAmount, stepTime, stepTemp,
           waterGrainRatio, infuseTemp, endTemp;

};
