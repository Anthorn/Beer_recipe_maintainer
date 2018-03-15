#ifndef DEF_BEERSMPARSER
#define DEF_BEERSMPARSER

#include <string>
#include <iostream>
#include <sstream>
#include <tinyxml.h>
#include <map>

using namespace std;

class BeersmithXMLParser {

  public:
    string recipe(TiXmlHandle* handleDoc);
    map<string, string> parseBeerData();

  private:
    string parseRecipeMetaData(TiXmlElement* data);
    string parserData(TiXmlElement* data);
    string parseHopVariety(TiXmlElement* hopVariety);
    string parseFermentable(TiXmlElement* fermentable);
    string parseYeast(TiXmlElement* yeast);
    string parseWaterProfile(TiXmlElement* waterProfile);
};

#endif

