#include <recipe.h>


using namespace std;



int main() {

  const char* filename = "recipes.xml";
  Recipe* recipe = new Recipe(filename);

  BeerData* data;

  data = recipe->getBeerData();
  data->toString();

}
