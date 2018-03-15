#include <beerData.h>
#include <map>

using namespace std;

const char* attributes[] =  {
  "NAME",
  "VERSION",
  "TYPE",
  "BREWER",
  "BATCH_SIZE",
  "BOIL_SIZE",
  "BOIL_TIME",
  "EFFICENCY",
  "ABV",
  "EST_ABV" };


void BeerData::parse(BeersmithXMLParser parser)
{
  map<string, string> current = parser.parseBeerData();
  current["a"] = "b";
  this->populate(current);
}


 void BeerData::populate(map<string, string> parsedMap)
{
  //*loop through a predefined set of attributes, and populate each attribute in BeerData.
}
