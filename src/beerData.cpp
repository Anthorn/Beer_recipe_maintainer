#include <beerData.h>
#include <map>
#include <array>


void BeerData::insertValue(string attribute, string value)
{
    if (beerDataAttributes[0].compare(attribute) == 0)
    {
        this->name = value;
    }
    else  if (beerDataAttributes[1].compare(attribute) == 0)
    {
        this->version = value;
    }
    else if (beerDataAttributes[2].compare(attribute) == 0)
    {
        this->type = value;
    }
    else if (beerDataAttributes[3].compare(attribute) == 0)
    {
        this->brewer = value;
    }
    else if (beerDataAttributes[4].compare(attribute) == 0)
    {
        this->batchSize = stof(value);
    }
    else if (beerDataAttributes[5].compare(attribute) == 0)
    {
        this->boilSize = stof(value);
    }
    else if (beerDataAttributes[6].compare(attribute) == 0)
    {
        this->boilTime = stof(value);
    }
    else if (beerDataAttributes[7].compare(attribute) == 0)
    {
        this->efficiency = stof(value);
    }
    else if (beerDataAttributes[8].compare(attribute) == 0)
    {
        this->abv = stod(value);
    }
    else if (beerDataAttributes[9].compare(attribute) == 0)
    {
        this->estAbv = stod(value);
    }
}


void BeerData::parse(std::shared_ptr<BeersmithXMLParser> parser)
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
    cout << "Name: "                        << this->name       << endl;
    cout << "Version: "                     << this->version    << endl;
    cout << "Type: "                        << this->type       << endl;
    cout << "brewer: "                      << this->brewer     << endl;
    cout << "BatchSize: "                   << this->batchSize  << endl;
    cout << "BoilSize: "                    << this->boilSize   << endl;
    cout << "BoilTime: "                    << this->boilTime   << endl;
    cout << "Efficency: "                   << this->efficiency << endl;
    cout << "Alcohol by volume: "           << this->abv        << endl;
    cout << "Estimated alcohol by volume: " << this->estAbv     << endl;
    cout << "##########################################"        << endl;
}
