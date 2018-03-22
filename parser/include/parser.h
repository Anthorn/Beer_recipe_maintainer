#ifndef DEF_BEERSMPARSER
#define DEF_BEERSMPARSER

#include <string>
#include <list>
#include <iostream>
#include <sstream>
#include <tinyxml.h>
#include <map>
#include <attributes.h>



using namespace std;



class BeersmithXMLParser {

  public:
    BeersmithXMLParser(const char* fileName);
    string recipe(TiXmlHandle* handleDoc);
    map<string, string> parseBeerData();
    list<map<string, string>> parseHops();
    list<map<string, string>> parseFermentables();
    list<map<string, string>> parseYeasts();
    map<string, string> parseHopVariety(TiXmlElement* hopVariety);
    map<string, string> parseFermentable(TiXmlElement* fermentable);
    map<string, string> parseYeast(TiXmlElement* yeast);
    map<string, string> parseWaterProfile(TiXmlElement* waterProfile);

  private:
    TiXmlDocument* doc;
    TiXmlHandle* handle;
    string parseRecipeMetaData(TiXmlElement* data);
    string parserData(TiXmlElement* data);
    TiXmlElement* fetchStartOfParse(string key);
    map<string, string> populateMapFromAttributes(TiXmlElement* element, string* attributes, size_t size);
    list<map<string, string>> populateAttributeLists();
    list<map<string, string>> parseAndBuildResult(string startKey, string elementKey);
    map<string, string> parseIngredient(TiXmlElement* element, string type);

};

#endif

