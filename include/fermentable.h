#ifndef DEF_FERMENTABLE
#define DEF_FERMENTABLE
#include <string>
#include <parsable.h>

using namespace std;

class Fermentable : Parsable{
  public:
    string getName();
    string getVersion();
    string getType();
    string getOrigin();
    string getSupplier();

    double getAmount();
    double getYield();
    double getColor();

    bool shouldAddAfterBoil();
    bool isRecommendedInMash();

  private:
    string name, version, type, origin, supplier;
    double amount, yield, color;
    bool addAfterBoil;
    bool recommendedMash;
};

#endif

