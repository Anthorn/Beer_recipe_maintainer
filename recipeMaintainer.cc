#include <recipe.h>


using namespace std;



int main() {

  const char* filename = "recipes.xml";
  Recipe* recipe = new Recipe(filename);

  BeerData* data;
  Hops* hops;

  data = recipe->getBeerData();
  data->print();

  hops = recipe->getHops();
  hops->print();

}
