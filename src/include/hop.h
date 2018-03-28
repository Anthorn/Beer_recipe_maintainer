#ifndef DEF_HOP
#define DEF_HOP
#include <string>
#include <parsable.h>


using namespace std;


/*
 * This class represent a hop addition in a beer recipe. Not to
 * be confused with an ordinary Hop.
 */

class Hop {
  public:
    void print();
    void populate(map<string, string> rawHop);
    void insertValue(string attribute, string value);
    string getName();
    string getVersion();
    string getOrigin();
    string getNotes();
    string getUsage();
    string getType();
    string getForm();
    double getAlphaAcid();
    double getAmount();
    double getAdditionTime();

  private:
    string name, version, origin, use, notes, type, form;
    double alphaAcid, amount, time;
};

#endif

