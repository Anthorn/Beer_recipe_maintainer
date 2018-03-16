#include <beerData.h>
#include <map>
#include <array>


using namespace std;


void BeerData::insertValue(string attribute, string value)
{
   if (attributes[0].compare(attribute) == 0) {
      this->name = value;
    }
    else  if (attributes[1].compare(attribute) == 0) {
       this->version = value;
    }
    else if ( attributes[2].compare(attribute) == 0) {
      this->type = value;
    }
    else if ( attributes[3].compare(attribute) == 0) {
      this->brewer = value;
    }
    else if ( attributes[4].compare(attribute) == 0) {
      this->batchSize = stoi(value);
    }
    else if ( attributes[5].compare(attribute) == 0) {
      this->boilSize = stoi(value);
    }
    else if ( attributes[6].compare(attribute) == 0) {
      this->boilTime = stoi(value);
    }
    else if ( attributes[7].compare(attribute) == 0) {
      this->efficency = stoi(value);
    }
    else if ( attributes[8].compare(attribute) == 0) {
      this->abv = stod(value);
    }
    else if ( attributes[9].compare(attribute) == 0) {
      this->estAbv = stod(value);
    }
}


void BeerData::parse(BeersmithXMLParser parser)
{
  map<string, string> current = parser.parseBeerData();
  this->populate(current);
}


 void BeerData::populate(map<string, string> parsedMap)
{
  string currentValue;
  for(const auto& attribute : attributes)
  {
    currentValue = parsedMap[attribute];
    insertValue(attribute, currentValue);
  }
}

void BeerData::toString()
{
  cout << "##### Parsed BeerData #####" << endl;

  cout << "Name: " << this->name << endl;

  cout << "Version: " << this->version << endl;
  cout << "Type: " << this->type << endl;
  cout << "brewer: " << this->brewer << endl;
  cout << "BatchSize: " << this->batchSize << endl;
  cout << "BoilSize: " << this->boilSize << endl;
  cout << "BoilTime: " << this->boilTime << endl;
  cout << "Efficency: " << this->efficency << endl;
  cout << "Alcohol by volume: " << this->abv << endl;
  cout << "Estimated alcohol by volume: " << this->estAbv << endl;
  cout << "##########################################" << endl;
}
