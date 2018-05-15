#ifndef DEF_EQUIPMENT
#define DEF_EQUIPMENT
#include <string>
#include "parsable.h"

using namespace std;


class Equipment : public Parsable {
  public:
    void populate(map<string, string> parsedMap);
    void parse(std::shared_ptr<BeersmithXMLParser> parser);
    void print();
    void insertValue(string attribute, string value);


  private:
    string name, version, notes;
    double batchSize, boilSize, boilTime, efficency, tunVolume, trubChillerLoss, evaporationRate,
        hopUtil, lauterDeadspace;
};

#endif

