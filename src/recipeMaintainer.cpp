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

    std::string cmd;

    std::cout << "Recipe successfully loaded! \n";
    while(1)
    {

        std::cout << "What would you like to do? [type h for help]\n";

        std::cin >> cmd;
        recipe->issueCommand(cmd);
    }


}
