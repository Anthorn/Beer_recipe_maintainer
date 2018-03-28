#ifndef DEF_EQUIPMENT
#define DEF_EQUIPMENT
#include <string>
#include <parsable.h>

using namespace std;


class Equipment : public Parsable {
  public:
    void populate(map<string, string> parsedMap);
    void parse(BeersmithXMLParser* parser);
    void print();
    void insertValue(string attribute, string value);

    string getName();
    string getNotes();
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
    void setNotes(string notes);
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
    string name, version, notes;
    double batchSize, boilSize, boilTime, efficency, tunVolume, trubChillerLoss, evaporationRate,
        hopUtil, lauterDeadspace;
};

#endif

