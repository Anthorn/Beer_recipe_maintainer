#pragma once
#include "hop.h"
#include <list>


class Hops : public Parsable {

  public:
    list<std::shared_ptr<Hop>> getHops();
    void parse(std::shared_ptr<BeersmithXMLParser> parser) override;
    void populate(list<map<string, string>> rawHops) override;
    void print();

  private:
    list<std::shared_ptr<Hop>> hops;
};
