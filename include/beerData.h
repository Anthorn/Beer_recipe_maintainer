#ifndef DEF_BEERDATA
#define DEF_BEERDATA
#include <string>
#include <parsable.h>


using namespace std;




class BeerData : public Parsable {


  public:
    string getName();
    string getVersion();
    string getType();
    string getBrewer();
    int getBatchSize();
    int getBoilSize();
    int getBoilTime();
    int getEfficency();
    double getAbv();
    double getEstAbv();
    void populate(map<string, string> parsedMap);
    void parse(BeersmithXMLParser parser);

  private:
    string name, version, type, brewer;
    int batchSize, boilSize, boilTime, efficency;
    double abv, estAbv;

};
#endif

