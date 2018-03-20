#ifndef DEF_FERMENTABLE
#define DEF_FERMENTABLE
#include <string>
#include <parsable.h>

using namespace std;

class Fermentable{
  public:
    void print();
    void populate(map<string, string> rawFermentable);
    void insertValue(string attribute, string value);


    string getName();
    string getVersion();
    string getType();
    string getOrigin();
    string getSupplier();
    string getNotes();

    double getAmount();
    double getYield();
    double getColor();

    bool shouldAddAfterBoil();
    bool isRecommendedInMash();

  private:
    string name, version, type, origin, supplier, notes;
    double amount, yield, color;
    bool addAfterBoil;
    bool recommendedMash;
};

#endif

