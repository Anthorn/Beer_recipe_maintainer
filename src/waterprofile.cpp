#include <waterProfile.h>

using namespace std;

void WaterProfiles::parse(shared_ptr<BeersmithXMLParser> parser)
{
    list<map<string, string>> rawWaterProfiles = parser->parseWaterProfiles();
    populate(rawWaterProfiles);
}

void WaterProfiles::populate(list<map<string, string>> rawWaterList)
{
    shared_ptr<Water> water;

    for (const auto& rawWater : rawWaterList)
    {
        water.reset(new Water());
        water->populate(rawWater);
        waterProfiles.push_back(water);
    }
}

void WaterProfiles::print() const
{
    cout << "####### WATERPROFILE ######" << endl;

    for (const auto& water : this->waterProfiles)
    {
        water->print();
    }

}

