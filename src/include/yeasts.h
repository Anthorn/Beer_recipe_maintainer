#pragma once

#include <list>
#include "yeast.h"


class Yeasts {

  public:
    list<std::shared_ptr<Yeast>> getYeastList();
    void parse(std::shared_ptr<BeersmithXMLParser> parser);
    void populate(list<map<string, string>> rawYeastList);
    void print();


  private:
    list<std::shared_ptr<Yeast>> yeastList;

};
