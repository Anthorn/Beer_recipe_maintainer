#ifndef DEF_STYLE
#define DEF_STYLE

#include <string>
#include <parsable.h>


using namespace std;




class Style : Parsable {


  public:
    string getName();
    string getVersion();
    string getType();
    string getCategory();
    string getNotes();
    double getAbvMin();
    double getAbvMax();
    double getColorMax();
    double getColorMin();
    double getIBUMin();
    double getIBUMax();

  private:
    string name, version, type, category, notes;
    double minAbv, maxAbv, colorMax, colorMin, IBUMin, IBUMax;
};

#endif

