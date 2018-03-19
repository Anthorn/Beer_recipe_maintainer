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
  protected:

};

#endif
