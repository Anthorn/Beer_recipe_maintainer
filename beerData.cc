#include <beerData.h>
#include <map>
#include <array>


using namespace std;


void BeerData::insertValue(string attribute, string value)
{
   if (beerData[0].compare(attribute) == 0) {
      this->name = value;
    }
    else  if (beerData[1].compare(attribute) == 0) {
       this->version = value;
    }
    else if ( beerData[2].compare(attribute) == 0) {
      this->type = value;
    }
    else if ( beerData[3].compare(attribute) == 0) {
      this->brewer = value;
    }
    else if ( beerData[4].compare(attribute) == 0) {
      this->batchSize = stof(value);
    }
    else if ( beerData[5].compare(attribute) == 0) {
      this->boilSize = stof(value);
    }
    else if ( beerData[6].compare(attribute) == 0) {
      this->boilTime = stoi(value);
    }
    else if ( beerData[7].compare(attribute) == 0) {
      this->efficiency = stof(value);
    }
    else if ( beerData[8].compare(attribute) == 0) {
      this->abv = stod(value);
    }
    else if ( beerData[9].compare(attribute) == 0) {
      this->estAbv = stod(value);
    }
}


void BeerData::parse(BeersmithXMLParser* parser)
{
  map<string, string> current = parser->parseBeerData();
  this->populate(current);
}


 void BeerData::populate(map<string, string> parsedMap)
{
  string currentValue;
  for(const auto& attribute : beerData)
  {
    currentValue = parsedMap[attribute];
    insertValue(attribute, currentValue);
  }
}

void BeerData::print()
{
  cout << "##### Parsed BeerData #####" << endl;

  cout << "Name: " << this->name << endl;

  cout << "Version: " << this->version << endl;
  cout << "Type: " << this->type << endl;
  cout << "brewer: " << this->brewer << endl;
  cout << "BatchSize: " << this->batchSize << endl;
  cout << "BoilSize: " << this->boilSize << endl;
  cout << "BoilTime: " << this->boilTime << endl;
  cout << "Efficency: " << this->efficiency << endl;
  cout << "Alcohol by volume: " << this->abv << endl;
  cout << "Estimated alcohol by volume: " << this->estAbv << endl;
  cout << "##########################################" << endl;
}
