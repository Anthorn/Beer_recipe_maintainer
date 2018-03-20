#include <hop.h>

using namespace std;

/*
 *
 * This class represent a hop variety
 *
 */


void Hop::print()
{
  cout << "     ########## HOP ##########" << endl;
  cout << "     Name     : " << this->name << endl;
  cout << "     Version  : " << this->version << endl;
  cout << "     Origin   : " << this->origin << endl;
  cout << "     Usage    : " << this->use << endl;
  cout << "     Notes    : " << this->notes << endl;
  cout << "     Type     : " << this->type << endl;
  cout << "     Form     : " << this->form << endl;
  cout << "     AlphaAcid: " << this->alphaAcid << endl;
  cout << "     Amount   : " << this->amount << endl;
  cout << "     Time     : " << this->time << endl;
  cout << "     #########################" << endl;
}


void Hop::insertValue(string attribute, string value)
{
  if (hopAttributes[0].compare(attribute) == 0 ){
    this->name = value;
  }
  else if (hopAttributes[1].compare(attribute) == 0) {
    this->version = value;
  }
  else if (hopAttributes[2].compare(attribute) == 0) {
    this->origin = value;
  }
  else if (hopAttributes[3].compare(attribute) == 0) {
    this->alphaAcid = stod(value);
  }
  else if (hopAttributes[4].compare(attribute) == 0) {
    this->use = value;
  }
  else if (hopAttributes[5].compare(attribute) == 0) {
    this->time = stod(value);
  }
  else if (hopAttributes[6].compare(attribute) == 0) {
    this->notes = value;
  }
  else if (hopAttributes[7].compare(attribute) == 0) {
    this->type = value;
  }
  else if (hopAttributes[8].compare(attribute) == 0) {
    this->form = value;
  }
  else if (hopAttributes[9].compare(attribute) == 0) {
    this->amount = stod(value);
  }
}


void Hop::populate(map<string, string> rawHop)
{
  for(const auto& attribute : hopAttributes)
  {
    insertValue(attribute, rawHop[attribute]);
  }
}

