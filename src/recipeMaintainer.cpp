#include "recipe.h"



void loadRecipe(Recipe& recipe)
{

    recipe.loadBeerData();
    recipe.loadHops();
    recipe.loadFermentables();
    recipe.loadYeasts();
    recipe.loadWaterProfiles();
    recipe.loadStyle();
    recipe.loadEquipment();
    recipe.loadMashSchedule();
}

void toUpper(std::string& str)
{
    for (char& c : str)
    {
        c = toupper(c);
    }
}

int main()
{

    const char* filename = "recipes.xml";
    Recipe* recipe = new Recipe(filename);


    loadRecipe(*recipe);
    std::string cmd;

    std::cout << "Recipe successfully loaded! \n";
    while(1)
    {

        std::cout << "What would you like to do? [type 'help' for instructions]\n";

        std::cin >> cmd;
        toUpper(cmd);

        recipe->issueCommand(cmd);
    }
}
