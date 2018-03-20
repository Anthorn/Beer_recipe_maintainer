#include <fermentables.h>

using namespace std;

void Fermentables::print()
{
  cout << "###### FERMENTABLES ######" << endl;
  for(const auto& fermentable : this->fermentables)
  {
    fermentable->print();
  }
}

void Fermentables::populate(list<map<string, string>> rawFermentables)
{
  Fermentable* fermentable;
  for(const auto& rawFermentable : rawFermentables)
  {
    fermentable = new Fermentable();
    fermentable->populate(rawFermentable);
    this->fermentables.push_back(fermentable);
  }
}


void Fermentables::parse(BeersmithXMLParser* parser)
{
  list<map<string, string>> rawFermentables = parser->parseFermentables();
  populate(rawFermentables);
}
