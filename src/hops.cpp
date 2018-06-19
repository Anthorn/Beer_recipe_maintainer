#include <hops.h>

using namespace std;

void Hops::print() const
{
    cout << "###### HOPS ######" << endl;
    for (const auto& hop : this->hops)
    {
        hop->print();
    }
}



void Hops::populate(list<map<string, string>> rawHops)
{
    shared_ptr<Hop> hop;
    for (const auto& rawHop : rawHops)
    {
        hop.reset(new Hop());
        hop->populate(rawHop);
        hops.push_back(hop);
    }
}

list<shared_ptr<Hop>> Hops::getHops()
{
    return list<shared_ptr<Hop>>();
}

void Hops::parse(shared_ptr<BeersmithXMLParser> parser)
{
    list<map<string, string>> rawHops = parser->parseHops();
    populate(rawHops);
}
