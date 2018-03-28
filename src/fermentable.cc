#include <fermentable.h>
#include <utility>
#include <iostream>
using namespace std;

/*
 *
 *
 */

void Fermentable::print()
{
  cout << "     ########## FERMENTABLE ##########" << endl;
  cout << "     Name       : " << this->name << endl;
  cout << "     Version    : " << this->version << endl;
  cout << "     Type       : " << this->type << endl;
  cout << "     Origin     : " << this->origin << endl;
  cout << "     Notes      : " << this->notes << endl;
  cout << "     Amount     : " << this->amount << endl;
  cout << "     Yield      : " << this->yield << endl;
  cout << "     Color      : " << this->color << endl;
  cout << "     After boil : " << Parsable::printBool(this->addAfterBoil) << endl;
  cout << "     Reccomended in mash : " << Parsable::printBool(this->recommendedMash) << endl;
  cout << "     #########################" << endl;
}


void Fermentable::insertValue(string attribute, string value)
{
  if (fermentableAttributes[0].compare(attribute) == 0 ){
    this->name = value;
  }
  else if (fermentableAttributes[1].compare(attribute) == 0) {
    this->version = value;
  }
  else if (fermentableAttributes[2].compare(attribute) == 0) {
    this->type = value;
  }
  else if (fermentableAttributes[3].compare(attribute) == 0) {
    this->amount = stod(value);
  }
  else if (fermentableAttributes[4].compare(attribute) == 0) {
    this->yield = stod(value);
  }
  else if (fermentableAttributes[5].compare(attribute) == 0) {
    this->color = stod(value);
  }
  else if (fermentableAttributes[6].compare(attribute) == 0) {
    this->addAfterBoil = Parsable::convertStringToBool(value);
  }
  else if (fermentableAttributes[7].compare(attribute) == 0) {
    this->origin = value;
  }
  else if (fermentableAttributes[8].compare(attribute) == 0) {
    this->notes = value;
  }
  else if (fermentableAttributes[9].compare(attribute) == 0) {
    this->recommendedMash = Parsable::convertStringToBool(value);
  }
}


void Fermentable::populate(map<string, string> rawFermentable)
{
  for(const auto& attribute : fermentableAttributes)
  {
    insertValue(attribute, rawFermentable[attribute]);
  }
}

