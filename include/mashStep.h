#ifndef DEF_MASHSTEP
#define DEF_MASHSTEP
#include <parsable.h>

#include <string>


using namespace std;


class MashStep : Parsable {

  public:
    string getName();
    string getVersion();
    string getNotes();
    string getDescription();
    double getInfuseAmount();
    double getStepTime();
    double getStepTemp();
    double getRampTime();
    double getWaterGrainRation();
    double getInfuseTemp();

  private:
    string name, version, notes, description;
    double infuseAmount, stepTime, stepTemp, rampTime,
           waterGrainRatio, infuseTemp;

};

#endif

