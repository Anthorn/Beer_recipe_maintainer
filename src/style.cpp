#include <style.h>


using namespace std;

void Style::print()
{
    cout << "     ########## STYLE ##########"      << endl;
    cout << "     Name     : " << this->name        << endl;
    cout << "     Version  : " << this->version     << endl;
    cout << "     Type     : " << this->type        << endl;
    cout << "     Category : " << this->category    << endl;
    cout << "     Notes    : " << this->notes       << endl;
    cout << "     MinAbv   : " << this->minAbv      << endl;
    cout << "     MaxAbv   : " << this->maxAbv      << endl;
    cout << "     MaxColor : " << this->colorMax    << endl;
    cout << "     MinColor : " << this->colorMin    << endl;
    cout << "     IBUMin   : " << this->IBUMin      << endl;
    cout << "     IBUMax   : " << this->IBUMax      << endl;
    cout << "     #########################"        << endl;
}

void Style::insertValue(string attribute, string value)
{
    if (styleAttributes[0].compare(attribute) == 0)
    {
        this->name = value;
    }
    else  if (styleAttributes[1].compare(attribute) == 0)
    {
        this->version = value;
    }
    else  if (styleAttributes[2].compare(attribute) == 0)
    {
        this->type = value;
    }
    else  if (styleAttributes[3].compare(attribute) == 0)
    {
        this->category = value;
    }
    else  if (styleAttributes[4].compare(attribute) == 0)
    {
        this->notes = value;
    }
    else  if (styleAttributes[5].compare(attribute) == 0)
    {
        this->minAbv = stod(value);
    }
    else  if (styleAttributes[6].compare(attribute) == 0)
    {
        this->maxAbv = stod(value);
    }
    else  if (styleAttributes[7].compare(attribute) == 0)
    {
        this->colorMax = stod(value);
    }
    else  if (styleAttributes[8].compare(attribute) == 0)
    {
        this->colorMin = stod(value);
    }
    else  if (styleAttributes[9].compare(attribute) == 0)
    {
        this->IBUMin = stod(value);
    }
    else  if (styleAttributes[10].compare(attribute) == 0)
    {
        this->IBUMax = stod(value);
    }
}
void Style::parse(std::shared_ptr<BeersmithXMLParser> parser)
{
    map<string, string> current = parser->parseStyle();
    this->populate(current);
}


void Style::populate(map<string, string> parsedMap)
{
    string currentValue;
    for (const auto& attribute : styleAttributes)
    {
        currentValue = parsedMap[attribute];
        insertValue(attribute, currentValue);
    }
}
