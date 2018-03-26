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

list<map<string, string>> BeersmithXMLParser::parseHops()
{
  return parseAndBuildResult("HOPS", "HOP");
}

list<map<string, string>> BeersmithXMLParser::parseFermentables()
{
  return parseAndBuildResult("FERMENTABLES", "FERMENTABLE");
}

list<map<string, string>> BeersmithXMLParser::parseYeasts()
{
  return parseAndBuildResult("YEASTS", "YEAST");
}

list<map<string, string>> BeersmithXMLParser::parseWaterProfiles()
{
  return parseAndBuildResult("WATERS", "WATER");
}

list<map<string, string>> BeersmithXMLParser::parseMashSchedule()
{
  return parseAndBuildResult("MASH", "MASH_STEP");
}



list<map<string, string>> BeersmithXMLParser::parseAndBuildResult(string startKey, string elementKey)
{
  list<map<string, string>> current;

  TiXmlElement* start;
  if(elementKey == "MAST_STEP")
    start = fetchStartOfParse("MASH_STEPS");
  else
    start = fetchStartOfParse(startKey);
  TiXmlElement* currentElement;
  if(start == NULL) return current;

  if(elementKey.compare("MASH_STEP") == 0){

   currentElement = start->FirstChildElement("MASH_STEPS")->FirstChildElement(elementKey);
  } else {
   currentElement = start->FirstChildElement();
  }

  while(currentElement != NULL && currentElement->ValueStr().compare(elementKey) == 0)
  {
    current.push_back(parseIngredient(currentElement, elementKey));
    currentElement = currentElement->NextSiblingElement();
  }

  return current;
}

map<string, string> BeersmithXMLParser::parseIngredient(TiXmlElement* element, string type)
{
  if(type.compare("HOP") == 0){
    return parseHopVariety(element);
  }
  else if ( type.compare("FERMENTABLE") == 0) {
    return parseFermentable(element);
  }
  else if (type.compare("YEAST") == 0) {
    return parseYeast(element);
  }
  else if (type.compare("WATER") == 0) {
    return parseWater(element);
  }
  else if (type.compare("MASH_STEP") == 0) {
    return parseMashStep(element);
  }
  else {
    map<string, string> emptyMap; // Change this uggly fix;
    return emptyMap;
  }
}


map<string, string> BeersmithXMLParser::parseMashMetaData()
{
  TiXmlElement* start = fetchStartOfParse("MASH");

  return populateMapFromAttributes(start, mashMetaDataAttr, MASH_META_DATA_ATTR_SIZE);
}

map<string, string> BeersmithXMLParser::parseBeerData()
{
  TiXmlElement* start = fetchStartOfParse("RECIPE");

  return populateMapFromAttributes(start, beerDataAttributes, BEER_ATTRIBUTE_SIZE);
}

map<string, string> BeersmithXMLParser::parseStyle()
{
  TiXmlElement* start = fetchStartOfParse("STYLE");

  return populateMapFromAttributes(start, styleAttributes, STYLE_ATTRIBUTE_SIZE);
}

map<string, string> BeersmithXMLParser::parseEquipment()
{
  TiXmlElement* start = fetchStartOfParse("EQUIPMENT");

  return populateMapFromAttributes(start, equipmentAttributes, EQUIP_ATTRIBUTE_SIZE);

}

map<string, string> BeersmithXMLParser::parseHopVariety(TiXmlElement* hopElement)
{
  return populateMapFromAttributes(hopElement, hopAttributes, HOP_ATTRIBUTE_SIZE);
}

map<string, string> BeersmithXMLParser::parseFermentable(TiXmlElement* fermentableElement)
{
  return populateMapFromAttributes(fermentableElement, fermentableAttributes, FERMENTABLE_ATTRIBUTE_SIZE);
}

map<string, string> BeersmithXMLParser::parseYeast(TiXmlElement* yeastElement)
{
  return populateMapFromAttributes(yeastElement, yeastAttributes, YEAST_ATTRIBUTE_SIZE);
}

map<string, string> BeersmithXMLParser::parseWater(TiXmlElement* waterElement)
{
  return populateMapFromAttributes(waterElement, waterAttributes, WATER_ATTRIBUTE_SIZE);
}

map<string, string> BeersmithXMLParser::parseMashStep(TiXmlElement* mashStepElement)
{
  return populateMapFromAttributes(mashStepElement, mashStepAttr, MASH_STEP_ATTR_SIZE);

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

  return NULL;

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
    start = digForStart(root->FirstChildElement(), key);
  }

  return start;
}

map<string, string> BeersmithXMLParser::populateMapFromAttributes(TiXmlElement* element,
       string* attributes, size_t size)
{
  map<string, string> parsedAttributes;

  if(NULL == element) return parsedAttributes;

  //TODO: Fix potential null pointer when fetching FirstChildElement
  for(size_t i = 0; i < size; i++)
  {
    parsedAttributes[attributes[i]] = element->FirstChildElement(attributes[i])->GetText();
  }
  return parsedAttributes;
}

