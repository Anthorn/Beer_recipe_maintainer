#include <beerData.h>
#include <map>
#include <array>

using namespace std;


void BeerData::insertValue(string attribute, string value)
{
    if (beerDataAttributes[0].compare(attribute) == 0)
    {
        name = value;
    }
    else  if (beerDataAttributes[1].compare(attribute) == 0)
    {
        version = value;
    }
    else if (beerDataAttributes[2].compare(attribute) == 0)
    {
        type = value;
    }
    else if (beerDataAttributes[3].compare(attribute) == 0)
    {
        brewer = value;
    }
    else if (beerDataAttributes[4].compare(attribute) == 0)
    {
        batchSize = stof(value);
    }
    else if (beerDataAttributes[5].compare(attribute) == 0)
    {
        boilSize = stof(value);
    }
    else if (beerDataAttributes[6].compare(attribute) == 0)
    {
        boilTime = stof(value);
    }
    else if (beerDataAttributes[7].compare(attribute) == 0)
    {
        efficiency = stof(value);
    }
    else if (beerDataAttributes[8].compare(attribute) == 0)
    {
        abv = stod(value);
    }
    else if (beerDataAttributes[9].compare(attribute) == 0)
    {
        estAbv = stod(value);
    }
}


void BeerData::parse(shared_ptr<BeersmithXMLParser> parser)
{
    map<string, string> current = parser->parseBeerData();
    populate(current);
}


void BeerData::populate(map<string, string> parsedMap)
{
    string currentValue;
    for (const auto& attribute : beerDataAttributes)
    {
        currentValue = parsedMap[attribute];
        insertValue(attribute, currentValue);
    }
}

void BeerData::print()
{
    cout << "############   BeerData     #############"         << endl;
    cout << "Name                       : " << name             << endl;
    cout << "Version                    : " << version          << endl;
    cout << "Type                       : " << type             << endl;
    cout << "brewer                     : " << brewer           << endl;
    cout << "BatchSize                  : " << batchSize        << endl;
    cout << "BoilSize                   : " << boilSize         << endl;
    cout << "BoilTime                   : " << boilTime         << endl;
    cout << "Efficency                  : " << efficiency       << endl;
    cout << "Alcohol by volume          : " << abv              << endl;
    cout << "Estimated alcohol by volume: " << estAbv           << endl;
    cout << "##########################################"        << endl;
}
