#include <string.h>

using namespace std;

class Fermentable {
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
    bool recommendedMash();

  private:
    string name, version, type, origin, supplier;
    double amount, yield, color;
    bool addAfterBoil, recommendedMash;
};
