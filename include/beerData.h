#ifndef DEF_BEERDATA
#define DEF_BEERDATA
#include <string>
#include <parsable.h>


#define ATTRIBUTE_SIZE 10


using namespace std;


static string attributes[ATTRIBUTE_SIZE] =  {
  "NAME",
  "VERSION",
  "TYPE",
  "BREWER",
  "BATCH_SIZE",
  "BOIL_SIZE",
  "BOIL_TIME",
  "EFFICENCY",
  "ABV",
  "EST_ABV" };


class BeerData : public Parsable {

  private:
    string name, version, type, brewer;
    int batchSize, boilSize, boilTime, efficency;
    double abv, estAbv;

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
    void insertValue(string attribute, string value);
    void toString();
    void setName();
    void setVersion();
    void setType();
    void setBrewer();
    void setBatchSize();
    void setBoilSize();
    void setBoilTime();
    void setEfficency();
    void setAbv();
    void setEstAbv();


#endif
};

