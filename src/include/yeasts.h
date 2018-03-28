
#include <list>
#include <yeast.h>

using namespace std;

class Yeasts {

  public:
    list<Yeast*> getYeastList();
    void parse(BeersmithXMLParser* parser);
    void populate(list<map<string, string>> rawYeastList);
    void print();


  private:
    list<Yeast*> yeastList;

};
