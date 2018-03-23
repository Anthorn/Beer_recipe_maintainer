#include <equipment.h>
#include <string>
#include <iostream>

void Equipment::print()
{
  cout << "##### EQUIPMENT #####" << endl;

  cout << "Name: " << this->name << endl;

  cout << "Version: " << this->version << endl;
  cout << "BoilSize: " << this->boilSize << endl;
  cout << "BatchSize: " << this->batchSize << endl;
  cout << "Tun Volume: " << this->tunVolume << endl;
  cout << "Trub loss to chill: " << this->trubChillerLoss << endl;
  cout << "Evaporation rate: " << this->evaporationRate << endl;
  cout << "Boil time: " << this->boilTime << endl;
  cout << "Lauter deadspace: " << this->lauterDeadspace << endl;
  cout << "Hop Util: " << this->hopUtil << endl;
  cout << "Notes: " << this->notes << endl;
  cout << "##########################################" << endl;
}

void Equipment::insertValue(string attribute, string value)
{
  cout << "inster attribute: " << attribute << endl;
   if (equipmentAttributes[0].compare(attribute) == 0) {
      this->name = value;
    }
    else  if (equipmentAttributes[1].compare(attribute) == 0) {
       this->version = value;
    }
    else  if (equipmentAttributes[2].compare(attribute) == 0) {
       this->boilSize = stod(value);
    }
    else  if (equipmentAttributes[3].compare(attribute) == 0) {
       this->batchSize = stod(value);
    }
    else  if (equipmentAttributes[4].compare(attribute) == 0) {
       this->tunVolume = stod(value);
    }
    else  if (equipmentAttributes[5].compare(attribute) == 0) {
       this->trubChillerLoss = stod(value);
    }
    else  if (equipmentAttributes[6].compare(attribute) == 0) {
       this->evaporationRate = stod(value);
    }
    else  if (equipmentAttributes[7].compare(attribute) == 0) {
       this->boilTime = stod(value);
    }
    else  if (equipmentAttributes[8].compare(attribute) == 0) {
       this->lauterDeadspace = stod(value);
    }
    else  if (equipmentAttributes[9].compare(attribute) == 0) {
       this->hopUtil = stod(value);
    }
    else  if (equipmentAttributes[10].compare(attribute) == 0) {
       this->notes = value;
    }

}

void Equipment::parse(BeersmithXMLParser* parser)
{
  map<string, string> current = parser->parseEquipment();
  this->populate(current);
}

void Equipment::populate(map<string, string> parsedMap)
{
  string currentValue;
  for(const auto& attribute : equipmentAttributes)
  {
    currentValue = parsedMap[attribute];
    insertValue(attribute, currentValue);
  }
}

void Equipment::setName(string name){
  name = name;
}

void Equipment::setVersion(string version){
  version = version;
}

void Equipment::setBatchSize(double batchSize){
  batchSize = batchSize;
}

void Equipment::setBoilSize(double boilSize){
  boilSize = boilSize;
}

void Equipment::setBoilTime(double boilTime){
  boilTime = boilTime;
}

void Equipment::setEfficency(double efficeny){
  efficency = efficency;
}

void Equipment::setTunVolume(double tunVolume){
  tunVolume = tunVolume;
}

void Equipment::setTrubChillerLoss(double trubLoss){
  trubChillerLoss = trubLoss;
}

void Equipment::setEvaporationRate(double evapRate){
  evaporationRate = evapRate;
}

void Equipment::setHopUtilization(double hopUtil){
  hopUtil = hopUtil;
}

void Equipment::setLauterDeadspace(double lauterDeadspace){
  lauterDeadspace = lauterDeadspace;
}
