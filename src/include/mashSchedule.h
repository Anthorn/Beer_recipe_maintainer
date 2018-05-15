#pragma once

#include "mashStep.h"

using namespace std;

class MashSchedule {
  public:

    void                            print();
    list<std::shared_ptr<MashStep>> getMashSteps();
    void                            parse(shared_ptr<BeersmithXMLParser> parser);
    void                            insertValue(string attribute, string value);
    void                            populate(list<map<string, string>> rawMashSteps);
    void                            populateMetaData(map<string, string> rawMashMetaData);

  private:
    string                          name, version;
    double                          spargeTemp, ph;
    list<std::shared_ptr<MashStep>> mashSteps;


};
