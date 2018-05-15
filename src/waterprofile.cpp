#include <waterProfile.h>


void WaterProfiles::parse(std::shared_ptr<BeersmithXMLParser> parser)
{
    list<map<string, string>> rawWaterProfiles = parser->parseWaterProfiles();
    populate(rawWaterProfiles);
}

void WaterProfiles::populate(list<map<string, string>> rawWaterList)
{
    std::shared_ptr<Water> water;

    for (const auto& rawWater : rawWaterList)
    {
        water.reset(new Water());
        water->populate(rawWater);
        waterProfiles.push_back(water);
    }
}

void WaterProfiles::print()
{
    cout << "####### WATERPROFILE ######" << endl;

    for (const auto& water : this->waterProfiles)
    {
        water->print();
    }

}

