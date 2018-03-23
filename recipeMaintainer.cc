#include <recipe.h>


using namespace std;



int main() {

  const char* filename = "recipes.xml";
  Recipe* recipe = new Recipe(filename);

  BeerData* data;
  Hops* hops;
  Fermentables* fermentables;
  Yeasts* yeasts;
  WaterProfiles* waterProfiles;

  data = recipe->getBeerData();
  data->print();

  hops = recipe->getHops();
  hops->print();

  fermentables = recipe->getFermentables();
  fermentables->print();

  yeasts = recipe->getYeasts();
  yeasts->print();

  waterProfiles = recipe->getWaterProfiles();
  waterProfiles->print();

}
