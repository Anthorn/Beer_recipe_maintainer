#include <parser.h>

using namespace std;




BeersmithXMLParser::BeersmithXMLParser(const char* fileName)
{
  TiXmlDocument* doc = new TiXmlDocument(fileName);
  bool loadOk = doc->LoadFile();
  if(loadOk){
    this->doc = doc;

  } else {
    cout << "Could not read file, exiting..." << endl;
    exit(0);
  }

}


map<string, string> BeersmithXMLParser::parseBeerData()
{
  map<string, string> current;
  TiXmlElement* start = fetchStartOfParse("RECIPE");
  if(start == NULL){
    return current;
  }

  for(int i = 0; i < BEER_ATTRIBUTE_SIZE; i++) {
    current[beerData[i]] = start->FirstChildElement(beerData[i])->GetText();
  }
  return current;
}

TiXmlElement* BeersmithXMLParser::fetchStartOfParse(string key)
{

  TiXmlHandle handle(this->doc);

  TiXmlElement* root = handle.FirstChildElement().Element();
  for(TiXmlElement* current = root->FirstChildElement();
      current != NULL; current = current->NextSiblingElement()){
    if(key == current->ValueStr()){
      return current;
    }
  }

  return NULL;
}

string BeersmithXMLParser::parseRecipeMetaData(TiXmlElement* data)
{
  ostringstream oss;


  TiXmlElement* current;
  current = data->FirstChildElement("NAME");
  if(current != NULL){
    oss << "Name: " << current->GetText() << endl;
  }

  current = data->FirstChildElement("VERSION");
  if(current != NULL){
    oss << "Version: " << current->GetText() << endl;
  }

  cout << oss.str();

  return "";

}


string BeersmithXMLParser::recipe(TiXmlHandle* handleDoc){
  ostringstream oss;
  TiXmlElement* rootOfRecipe = handleDoc->FirstChildElement().Element();

  cout << "inside ParseBeerData" << endl;
  for(TiXmlElement* current = rootOfRecipe->FirstChildElement();
      current != NULL; current = current->NextSiblingElement()){

    cout << "Current key: " <<  current->Value() << endl;

    string currentValue = current->Value();

    if(currentValue == "RECIPE")
    {
      oss << parseRecipeMetaData(current);
    }
  }

  return "";
  }
