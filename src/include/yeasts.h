#pragma once

#include <list>
#include "yeast.h"


class Yeasts {

  public:
    std::list<std::shared_ptr<Yeast>>   getYeastList();
    void                                parse(std::shared_ptr<BeersmithXMLParser> parser);
    void                                populate(std::list<std::map<std::string, std::string>> rawYeastList);
    void                                print();


  private:
    std::list<std::shared_ptr<Yeast>> yeastList;

};
