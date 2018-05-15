#include <hops.h>



void Hops::print()
{
    std::cout << "###### HOPS ######" << std::endl;
    for (const auto& hop : this->hops)
    {
        hop->print();
    }
}



void Hops::populate(list<map<string, string>> rawHops)
{
    std::shared_ptr<Hop> hop;
    for (const auto& rawHop : rawHops)
    {
        hop.reset(new Hop());
        hop->populate(rawHop);
        hops.push_back(hop);
    }
}

list<std::shared_ptr<Hop>> Hops::getHops()
{
    return list<std::shared_ptr<Hop>>();
}

void Hops::parse(std::shared_ptr<BeersmithXMLParser> parser)
{
    list<map<string, string>> rawHops = parser->parseHops();
    populate(rawHops);
}
