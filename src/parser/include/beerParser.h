#pragma once
#include <string>
#include <list>
#include <iostream>
#include <sstream>
#include <tinyxml.h>
#include <map>
#include "attributes.h"


class BeersmithXMLParser {

  public:
    BeersmithXMLParser(const char* fileName);

    std::map<std::string, std::string> parseBeerData();
    std::map<std::string, std::string> parseStyle();
    std::map<std::string, std::string> parseEquipment();
    std::map<std::string, std::string> parseMashMetaData();

    std::list<std::map<std::string, std::string>> parseHops();
    std::list<std::map<std::string, std::string>> parseFermentables();
    std::list<std::map<std::string, std::string>> parseYeasts();
    std::list<std::map<std::string, std::string>> parseWaterProfiles();
    std::list<std::map<std::string, std::string>> parseMashSchedule();

    std::map<std::string, std::string> parseHopVariety(TiXmlElement* hopVariety);
    std::map<std::string, std::string> parseFermentable(TiXmlElement* fermentable);
    std::map<std::string, std::string> parseYeast(TiXmlElement* yeast);
    std::map<std::string, std::string> parseWater(TiXmlElement* water);
    std::map<std::string, std::string> parseMashStep(TiXmlElement* mashStep);

  private:
    TiXmlDocument*                                  doc;
    TiXmlHandle*                                    handle;
    TiXmlElement*                                   fetchStartOfParse(std::string key);
    std::map<std::string, std::string>              populateMapFromAttributes(TiXmlElement* element, std::string* attributes, size_t size);
    std::list<std::map<std::string, std::string>>   parseAndBuildResult(std::string startKey, std::string elementKey);
    std::map<std::string, std::string>              parseIngredient(TiXmlElement* element, std::string type);

};


