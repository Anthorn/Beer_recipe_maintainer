#include <yeasts.h>

using namespace std;

void Yeasts::print()
{

  cout << "###### YEASTS ######" << endl;
  for(const auto& yeast : this->yeastList)
  {
    yeast->print();
  }
}

void Yeasts::populate(list<map<string, string>> rawYeastList)
{
  Yeast* yeast;

  for(const auto& rawYeast : rawYeastList)
  {
    yeast = new Yeast();
    yeast->populate(rawYeast);
    this->yeastList.push_back(yeast);
  }
}

void Yeasts::parse(BeersmithXMLParser* parser)
{
  list<map<string, string>> rawYeastList = parser->parseYeasts();
  populate(rawYeastList);
}
