#pragma once
#include "parsable.h"

#include <string>


class MashStep {

  public:
    void print();
    void populate(std::map<std::string, std::string> rawMashStep);
    void insertValue(std::string attribute, std::string value);

  private:
    std::string name, version, notes, type;
    double infuseAmount, stepTime, stepTemp,
           waterGrainRatio, infuseTemp, endTemp;

};
