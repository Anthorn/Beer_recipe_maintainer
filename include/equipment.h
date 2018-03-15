#include <string>

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

    void setName(string name);
    void setVersion(string version);
    void setBatchSize(double batchSize);
    void setBoilSize(double boilSize);
    void setBoilTime(double boilTime);
    void setEfficency(double efficency);
    void setTunVolume(double tunVolume);
    void setTrubChillerLoss(double trubLoss);
    void setEvaporationRate(double evapRate);
    void setHopUtilization(double hopUtil);
    void setLauterDeadspace(double lauterDeadspace);

  private:
    string name, version;
    double batchSize, boilSize, boilTime, efficency, tunVolume, trubChillerLoss, evaporationRate,
        hopUtil, lauterDeadspace;
};
