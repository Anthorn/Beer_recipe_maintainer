#pragma once

#include <string>
#include "parsable.h"

class Yeast : Parsable{
  public:
    void        print() const override;
    void        populate(std::map<std::string, std::string> rawYeast);
    friend std::ostream& operator<<(std::ostream &out, const Yeast yeast);

  private:
    std::string name, version, type, form, productID, laboratory, notes, cultureDate, flocculation;
    double      attenuation, minTemp, maxTemp, amount;
    bool        amountIsWeight;
    void        insertValue(std::string attribute, std::string value);
};



