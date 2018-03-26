
#ifndef DEF_MASH_SCHED_H
#define DEF_MASH_SCHED_H

#include <mashStep.h>

using namespace std;

class MashSchedule {
  public:

    void print();
    list<MashStep*> getMashSteps();
    void parse(BeersmithXMLParser* parser);
    void insertValue(string attribute, string value);
    void populate(list<map<string, string>> rawMashSteps);
    void populateMetaData(map<string, string> rawMashMetaData);

  private:
    string name, version;
    double spargeTemp, ph;
    list<MashStep*> mashSteps;


};

#endif

