#include <hops.h>


using namespace std;

void Hops::print()
{
  cout << "###### HOPS ######" << endl;
  for(const auto& hop : this->hops)
  {
    hop->print();
  }
}



void Hops::populate(list<map<string, string>> rawHops)
{
  Hop* hop;
  for(const auto& rawHop : rawHops)
  {
    hop = new Hop();
    hop->populate(rawHop);
    this->hops.push_back(hop);
  }
}

void Hops::parse(BeersmithXMLParser* parser)
{
  list<map<string, string>> rawHops = parser->parseHops();
  populate(rawHops);
}
