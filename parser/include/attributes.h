#ifndef DEF_ATTRIBUTES_H
#define DEF_ATTRIBUTES_H

#include <string>

#define BEER_ATTRIBUTE_SIZE 10

using namespace std;

static string beerData[BEER_ATTRIBUTE_SIZE] =  {
  "NAME",
  "VERSION",
  "TYPE",
  "BREWER",
  "BATCH_SIZE",
  "BOIL_SIZE",
  "BOIL_TIME",
  "EFFICIENCY",
  "ABV",
  "EST_ABV"};

#endif
