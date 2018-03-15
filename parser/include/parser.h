#include <string>
#include <iostream>
#include <sstream>
#include <tinyxml.h>

using namespace std;

class BeersmithXMLParser {

  public:
    string recipe(TiXmlHandle* handleDoc);
  private:
    string parserData(TiXmlElement* data);
    string parseRecipeMetaData(TiXmlElement* metaData);
    string parseHopVariety(TiXmlElement* hopVariety);
    string parseFermentable(TiXmlElement* fermentable);
    string parseYeast(TiXmlElement* yeast);
    string parseWaterProfile(TiXmlElement* waterProfile);
};
