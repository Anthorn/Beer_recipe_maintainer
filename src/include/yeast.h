#pragma once

#include <string>
#include "parsable.h"


using namespace std;




class Yeast {
  public:
    void print();
    void populate(map<string, string> rawYeast);

    string getName();
    string getVersion();
    string getType();
    string getForm();
    string getProductID();
    string getLaboratory();
    string getNotes();
    string getCultureDate();
    string getFlocculation();
    double getAttenuation();
    double getMinTemp();
    double getMaxTemp();
    double getAmount();
    bool isAmountInWeight();

  private:
    string name, version, type, form, productID, laboratory, notes, cultureDate, flocculation;
    double attenuation, minTemp, maxTemp, amount;
    bool amountIsWeight;
    void insertValue(string attribute, string value);
};

