
#include <string.h>

using namespace std;


class Equipment{
  public:
    string getName();
    string getVersion();
    double getBatchSize();
    double getBoilSize();
    double getBoilTime();
    double getEfficency();
    double getTunVolume();
    double getTrubChillerLoss();
    double getEvaporationRate();
    double getHopUtilization();
    double getLauterDeadspace();

  private:
    string name, version;
    double batchSize, boilSize, boilTime, efficency, tunVolume, trubChillerLoss, evaporationRate,
        hopUtil, lauterDeadspace;
};
