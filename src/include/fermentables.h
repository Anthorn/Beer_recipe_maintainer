#pragma once
#include <list>
#include "fermentable.h"

using namespace std;

class Fermentables : public Parsable{

  public:
    void                                parse(std::shared_ptr<BeersmithXMLParser> parser);
    void                                populate(list<map<string, string>> rawFermentables);
    void                                print();
    list<std::shared_ptr<Fermentable>>  getFermentables();


  private:
    list<std::shared_ptr<Fermentable>> fermentables;

};


