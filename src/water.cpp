#include <water.h>

using namespace std;


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

std::ostream & operator<<(std::ostream & out, const Water water)
{
    out << "     ########## WATER ##########"           <<"\n";
    out << "     Name         : " << water.name         <<"\n";
    out << "     Version      : " << water.version      << "\n";
    out << "     Amount       : " << water.amount       << "\n";
    out << "     Calcium      : " << water.calcium      << "\n";
    out << "     Bicarbonate  : " << water.bicarbonate  << "\n";
    out << "     Sulfate      : " << water.sulfate      << "\n";
    out << "     Chloride     : " << water.chloride     << "\n";
    out << "     Sodium       : " << water.sodium       << "\n";
    out << "     Magnesium    : " << water.magnesium    << "\n";
    out << "     PH           : " << water.ph           << "\n";
    out << "     Notes        : " << water.notes        << "\n";

    return out;
}
