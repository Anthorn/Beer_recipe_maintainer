#ifndef DEF_BEERDATA
#define DEF_BEERDATA
#include <string>
#include <parsable.h>




using namespace std;




class BeerData : public Parsable {

  private:
    string name, version, type, brewer;
    float batchSize, boilSize, boilTime;
    double abv, estAbv, efficiency;

  public:
    string getName();
    string getVersion();
    string getType();
    string getBrewer();
    double getBatchSize();
    double getBoilSize();
    double getBoilTime();
    double getEfficency();
    double getAbv();
    double getEstAbv();
    void populate(map<string, string> parsedMap);
    void parse(BeersmithXMLParser* parser);
    void print();
    void insertValue(string attribute, string value);
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

