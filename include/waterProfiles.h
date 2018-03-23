
#include <list>
#include <water.h>

using namespace std;

class WaterProfiles {

  public:
    void parse(BeersmithXMLParser* parser);
    void populate(list<map<string, string>> rawWaterList);
    void print();

  private:
    list<Water*> waterProfiles;

};
