#include <waterProfiles.h>


using namespace std;

void WaterProfiles::parse(BeersmithXMLParser* parser)
{
  list<map<string, string>> rawWaterProfiles = parser->parseWaterProfiles();
  populate(rawWaterProfiles);

}

void WaterProfiles::populate(list<map<string, string>> rawWaterList)
{
  Water* water;

  for(const auto& rawWater : rawWaterList)
  {
    water = new Water();
    water->populate(rawWater);
    this->waterProfiles.push_back(water);
  }
}

void WaterProfiles::print()
{
  cout << "####### WATERPROFILE ######" << endl;

  for(const auto& water : this->waterProfiles)
  {
    water->print();
  }

}

