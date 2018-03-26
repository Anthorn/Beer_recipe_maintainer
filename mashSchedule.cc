#include <mashSchedule.h>

using namespace std;


void MashSchedule::insertValue(string attribute, string value)
{
  if(mashMetaDataAttr[0].compare(attribute) == 0)
  {
    this->name = value;
  }
  else if (mashMetaDataAttr[1].compare(attribute) == 0) {
    this->version = value;
  }
  else if (mashMetaDataAttr[2].compare(attribute) == 0) {
    this->spargeTemp = stod(value);
  }
  else if (mashMetaDataAttr[3].compare(attribute) == 0) {
    this->ph = stod(value);
  }
}

void MashSchedule::print()
{
  cout << "###### MASH SCHEDULE ######" << endl;
  cout << "  Name: " << this->name << endl;
  cout << "  Version: " << this->version << endl;
  cout << "  Sparge temp: " << this->spargeTemp << endl;
  cout << "  PH: " << this->ph << endl;
  for(const auto& mashStep : this->mashSteps)
  {
    mashStep->print();
  }
}

void MashSchedule::populate(list<map<string, string>> rawMashSchedule)
{
  MashStep* mashStep;
  for(const auto& rawMashStep : rawMashSchedule)
  {
    mashStep = new MashStep();
    mashStep->populate(rawMashStep);
    this->mashSteps.push_back(mashStep);
  }
}

void MashSchedule::populateMetaData(map<string, string> rawMashMetaData)
{
  for(int i = 0; i < MASH_META_DATA_ATTR_SIZE; i++)
  {
    insertValue(mashMetaDataAttr[i], rawMashMetaData[mashMetaDataAttr[i]]);
  }

}

void MashSchedule::parse(BeersmithXMLParser* parser)
{
  map<string, string> rawMashMetaData = parser->parseMashMetaData();
  populateMetaData(rawMashMetaData);

  list<map<string, string>> rawMashSchedule = parser->parseMashSchedule();
  populate(rawMashSchedule);

}
