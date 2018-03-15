#ifndef DEF_YEAST
#define DEF_YEAST

#include <string>
#include <parsable.h>


using namespace std;




class Yeast : Parsable {
  public:
    string getName();
    string getVersion();
    string getType();
    string getForm();
    string getProductID();
    string getLaboratory();
    int getTimesCultured();
    int getMaxReuse();
    double getAttenuation();
    double getMinTemp();
    double getMaxTemp();
    bool getShouldAddToSecondary();

  private:
    string name, version, type, form, productID, laboratory;
    int timesCultured, maxReuse;
    double attenuation, minTemp, maxTemp;
    bool addToSecondary;
};

#endif

