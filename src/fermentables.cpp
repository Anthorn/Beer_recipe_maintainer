#include <fermentables.h>

using namespace std;

void Fermentables::print()
{
    cout << "###### FERMENTABLES ######" << endl;
    for (const auto& fermentable : fermentables)
    {
        fermentable->print();
    }
}

void Fermentables::populate(list<map<string, string>> rawFermentables)
{
    std::shared_ptr<Fermentable> fermentable;
    for (const auto& rawFermentable : rawFermentables)
    {
        fermentable.reset(new Fermentable());
        fermentable->populate(rawFermentable);
        fermentables.push_back(fermentable);
    }
}

list<std::shared_ptr<Fermentable>> Fermentables::getFermentables()
{
    return list<std::shared_ptr<Fermentable>>();
}

void Fermentables::parse(std::shared_ptr<BeersmithXMLParser> parser)
{
    list<map<string, string>> rawFermentables = parser->parseFermentables();
    populate(rawFermentables);
}
