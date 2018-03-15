#include <string>


using namespace std;




class Yeast{
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
