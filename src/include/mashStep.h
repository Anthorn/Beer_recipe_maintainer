#pragma once
#include "parsable.h"

#include <string>


class MashStep : Parsable {

  public:
    void                    populate(std::map<std::string, std::string> rawMashStep);
    void                    insertValue(std::string attribute, std::string value);
    friend std::ostream&    operator<<(std::ostream &out, const MashStep step);

  private:
    std::string name, version, notes, type;
    double infuseAmount, stepTime, stepTemp,
           waterGrainRatio, infuseTemp, endTemp;

};
