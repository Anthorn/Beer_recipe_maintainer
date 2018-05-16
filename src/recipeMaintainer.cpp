#include "recipe.h"


int main()
{

    const char* filename = "recipes.xml";
    Recipe* recipe = new Recipe(filename);

    recipe->loadBeerData();
    recipe->loadHops();
    recipe->loadFermentables();
    recipe->loadYeasts();
    recipe->loadWaterProfiles();
    recipe->loadStyle();
    recipe->loadEquipment();
    recipe->loadMashSchedule();

    recipe->printRecipe();

    while(1)
    { }

}
