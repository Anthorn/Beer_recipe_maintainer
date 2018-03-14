#include <string.h>


using namespace std;


/*
 * This class represent a hop addition in a beer recipe. Not to
 * be confused with an ordinary Hop.
 */

class {
  public:
    string getName();
    string getVersion();
    string getUsage();
    string getNotes();
    string getType();
    string getForm();
    double getAlphaAcid();
    double getAmount();
    double getAdditionTime();

  private:
    string name, version, use, notes, type, form;
    double aplhaAcid, amount, time;
}
