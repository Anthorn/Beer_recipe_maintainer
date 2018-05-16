#include <equipment.h>
#include <string>
#include <iostream>

using namespace std;

void Equipment::print()
{
    cout << "##### EQUIPMENT #####"                   << endl;
    cout << "Name              : " << name            << endl;
    cout << "Version           : " << version         << endl;
    cout << "BoilSize          : " << boilSize        << endl;
    cout << "BatchSize         : " << batchSize       << endl;
    cout << "Tun Volume        : " << tunVolume       << endl;
    cout << "Trub loss to chill: " << trubChillerLoss << endl;
    cout << "Evaporation rate  : " << evaporationRate << endl;
    cout << "Boil time         : " << boilTime        << endl;
    cout << "Lauter deadspace  : " << lauterDeadspace << endl;
    cout << "Hop Util          : " << hopUtil         << endl;
    cout << "Notes             : " << notes           << endl;
    cout << "####################################"    << endl;
}

void Equipment::insertValue(string attribute, string value)
{
    if (equipmentAttributes[0].compare(attribute) == 0)
    {
        name = value;
    }
    else  if (equipmentAttributes[1].compare(attribute) == 0)
    {
        version = value;
    }
    else  if (equipmentAttributes[2].compare(attribute) == 0)
    {
        boilSize = stod(value);
    }
    else  if (equipmentAttributes[3].compare(attribute) == 0)
    {
        batchSize = stod(value);
    }
    else  if (equipmentAttributes[4].compare(attribute) == 0)
    {
        tunVolume = stod(value);
    }
    else  if (equipmentAttributes[5].compare(attribute) == 0)
    {
        trubChillerLoss = stod(value);
    }
    else  if (equipmentAttributes[6].compare(attribute) == 0)
    {
        evaporationRate = stod(value);
    }
    else  if (equipmentAttributes[7].compare(attribute) == 0)
    {
        boilTime = stod(value);
    }
    else  if (equipmentAttributes[8].compare(attribute) == 0)
    {
        lauterDeadspace = stod(value);
    }
    else  if (equipmentAttributes[9].compare(attribute) == 0)
    {
        hopUtil = stod(value);
    }
    else  if (equipmentAttributes[10].compare(attribute) == 0)
    {
        notes = value;
    }

}

void Equipment::populate(map<string, string> parsedMap)
{
    string currentValue;
    for (const auto& attribute : equipmentAttributes)
    {
        currentValue = parsedMap[attribute];
        insertValue(attribute, currentValue);
    }
}

void Equipment::parse(shared_ptr<BeersmithXMLParser> parser)
{
    map<string, string> current = parser->parseEquipment();
    populate(current);
}
