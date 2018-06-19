#pragma once
#include "hop.h"
#include <list>


class Hops : public Parsable
{

public:
    void                        parse(std::shared_ptr<BeersmithXMLParser> parser) override;
    void                        print() const override;
    void                        populate(std::list<std::map<std::string, std::string>> rawHops) override;
    std::list<std::shared_ptr<Hop>>  getHops();

private:
    std::list<std::shared_ptr<Hop>> hops;
};
