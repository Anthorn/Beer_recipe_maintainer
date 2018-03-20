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

map<string, string> BeersmithXMLParser::parseHopVariety(TiXmlElement* currentHop)
{
  map<string, string> current;

  for(int i = 0; i < HOP_ATTRIBUTE_SIZE; i++)
  {
    current[hopAttributes[i]] = currentHop->FirstChildElement(hopAttributes[i])->GetText();
  }

  return current;
}


list<map<string, string>> BeersmithXMLParser::parseHops()
{
  list<map<string, string>> current;
  TiXmlElement* start = fetchStartOfParse("HOPS");

  if(start == NULL) return current;

  TiXmlElement* currentElement = start->FirstChildElement();

  while(currentElement != NULL &&currentElement->ValueStr().compare("HOP") == 0)
  {
    current.push_back(parseHopVariety(currentElement));
    currentElement = currentElement->NextSiblingElement();
  }

  return current;
}

map<string, string> BeersmithXMLParser::parseFermentable(TiXmlElement* currentFermentable)
{
  map<string, string> current;

  //TODO: Fix potential null pointer in every parse-method
  for(int i = 0; i < FERMENTABLE_ATTRIBUTE_SIZE; i++)
  {
    current[fermentableAttributes[i]] = currentFermentable->FirstChildElement(fermentableAttributes[i])->GetText();
  }

  return current;
}

list<map<string, string>> BeersmithXMLParser::parseFermentables()
{
  list<map<string, string>> current;
  TiXmlElement* start = fetchStartOfParse("FERMENTABLES");

  if(start == NULL) return current;

  TiXmlElement* currentElement = start->FirstChildElement();

  while(currentElement != NULL &&currentElement->ValueStr().compare("FERMENTABLE") == 0)
  {
    current.push_back(parseFermentable(currentElement));
    currentElement = currentElement->NextSiblingElement();
  }

  return current;

}

/*
 Private method to be used only inside fetchStartOfParse
 It iterates through one level of xml and returns the first element
 that has the key key.
 */

TiXmlElement* digForStart(TiXmlElement* currentRoot, string key)
{
  for(TiXmlElement* current = currentRoot->FirstChildElement();
      current != NULL; current = current->NextSiblingElement()){

    if(key == current->ValueStr()){

      return current;
    }
  }

  return 0;
}

TiXmlElement* BeersmithXMLParser::fetchStartOfParse(string key)
{

  TiXmlHandle handle(this->doc);

  TiXmlElement* root = handle.FirstChildElement().Element();
  TiXmlElement* start = digForStart(root, key);

  if(start == NULL){
    //If we cant find our start key at the first level, we go one level
    //deeper to look for it. Kind of ugly, but works for now since we will
    //only have two levels containing start keys.
    start = root->FirstChildElement();
    start = digForStart(start, key);
  }

  return start;
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

