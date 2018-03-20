#include <list>
#include <fermentable.h>

using namespace std;

class Fermentables {

  public:
    list<Fermentable*> getFermentables();
    void parse(BeersmithXMLParser* parser);
    void populate(list<map<string, string>> rawFermentables);
    void print();


  private:
    list<Fermentable*> fermentables;

};


