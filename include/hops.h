#ifndef DEF_HOPS_H
#define DEF_HOPS_H

#include <hop.h>
#include <list>


using namespace std;

class Hops  {

  public:
    list<Hop*> getHops;
    void parse(BeersmithXMLParser* parser);
    void populate(list<map<string, string>> rawHops);
    void print();

  private:
    list<Hop*> hops;
};

#endif

