#ifndef DEF_PARSABLE
#define DEF_PARSABLE

#include <string>
#include <iostream>
#include <parser.h>


using namespace std;


class Parsable {
  public:
     virtual void parse(BeersmithXMLParser* parser) = 0;
     virtual void populate(map<string, string> parsedMap) = 0;
     string toString();
     virtual void print() = 0;
     static bool convertStringToBool(string value)
     {
        if(value.compare("TRUE") == 0)
         {
          return true;
         } else {
          return false;
          }
      }
    static string printBool(bool value){
      if(value){
        return "true";
      } else {
        return "false";
        }
      }
  protected:

};

#endif
