#include <yeasts.h>

using namespace std;

void Yeasts::print()
{

    cout << "###### YEASTS ######" << endl;
    for (const auto& yeast : this->yeastList)
    {
        yeast->print();
    }
}

void Yeasts::populate(list<map<string, string>> rawYeastList)
{
    std::shared_ptr<Yeast> yeast;

    for (const auto& rawYeast : rawYeastList)
    {
        yeast.reset(new Yeast);
        yeast->populate(rawYeast);
        yeastList.push_back(yeast);
    }
}

list<std::shared_ptr<Yeast>> Yeasts::getYeastList()
{
    return list<std::shared_ptr<Yeast>>();
}

void Yeasts::parse(std::shared_ptr<BeersmithXMLParser> parser)
{
    list<map<string, string>> rawYeastList = parser->parseYeasts();
    populate(rawYeastList);
}
