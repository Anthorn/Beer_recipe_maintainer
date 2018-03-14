#include <string.h>


using namespace std;




class BeerData{


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

  private:
    string name, version, type, brewer;
    int batchSize, boilSize, boilTime, efficency;
    double abv, estAbv;

};

