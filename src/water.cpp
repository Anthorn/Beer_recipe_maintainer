#include <water.h>

using namespace std;

void Water::print()
{
    cout << "     ########## WATER ##########"          << endl;
    cout << "     Name         : " << this->name        << endl;
    cout << "     Version      : " << this->version     << endl;
    cout << "     Amount       : " << this->amount      << endl;
    cout << "     Calcium      : " << this->calcium     << endl;
    cout << "     Bicarbonate  : " << this->bicarbonate << endl;
    cout << "     Sulfate      : " << this->sulfate     << endl;
    cout << "     Chloride     : " << this->chloride    << endl;
    cout << "     Sodium       : " << this->sodium      << endl;
    cout << "     Magnesium    : " << this->magnesium   << endl;
    cout << "     PH           : " << this->ph          << endl;
    cout << "     Notes        : " << this->notes       << endl;

}

void Water::insertValue(string attribute, string value)
{
    if (waterAttributes[0].compare(attribute) == 0)
    {
        this->name = value;
    }
    else if (waterAttributes[1].compare(attribute) == 0)
    {
        this->version = value;
    }
    else if (waterAttributes[2].compare(attribute) == 0)
    {
        this->amount = stod(value);
    }
    else if (waterAttributes[3].compare(attribute) == 0)
    {
        this->calcium = stod(value);
    }
    else if (waterAttributes[4].compare(attribute) == 0)
    {
        this->bicarbonate = stod(value);
    }
    else if (waterAttributes[5].compare(attribute) == 0)
    {
        this->sulfate = stod(value);
    }
    else if (waterAttributes[6].compare(attribute) == 0)
    {
        this->chloride = stod(value);
    }
    else if (waterAttributes[7].compare(attribute) == 0)
    {
        this->sodium = stod(value);
    }
    else if (waterAttributes[8].compare(attribute) == 0)
    {
        this->magnesium = stod(value);
    }
    else if (waterAttributes[9].compare(attribute) == 0)
    {
        this->ph = stod(value);
    }
    else if (waterAttributes[10].compare(attribute) == 0)
    {
        this->notes = value;
    }
}

void Water::populate(map<string, string> rawWater)
{

    for (const auto& attribute : waterAttributes)
    {
        insertValue(attribute, rawWater[attribute]);
    }
}

