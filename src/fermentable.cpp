#include <fermentable.h>
#include <utility>
#include <iostream>

using namespace std;

void Fermentable::insertValue(string attribute, string value)
{
    if (fermentableAttributes[0].compare(attribute) == 0)
    {
        name = value;
    }
    else if (fermentableAttributes[1].compare(attribute) == 0)
    {
        version = value;
    }
    else if (fermentableAttributes[2].compare(attribute) == 0)
    {
        type = value;
    }
    else if (fermentableAttributes[3].compare(attribute) == 0)
    {
        amount = stod(value);
    }
    else if (fermentableAttributes[4].compare(attribute) == 0)
    {
        yield = stod(value);
    }
    else if (fermentableAttributes[5].compare(attribute) == 0)
    {
        color = stod(value);
    }
    else if (fermentableAttributes[6].compare(attribute) == 0)
    {
        addAfterBoil = Parsable::convertStringToBool(value);
    }
    else if (fermentableAttributes[7].compare(attribute) == 0)
    {
        origin = value;
    }
    else if (fermentableAttributes[8].compare(attribute) == 0)
    {
        notes = value;
    }
    else if (fermentableAttributes[9].compare(attribute) == 0)
    {
        recommendedMash = Parsable::convertStringToBool(value);
    }
}


void Fermentable::populate(map<string, string> rawFermentable)
{
    for (const auto& attribute : fermentableAttributes)
    {
        insertValue(attribute, rawFermentable[attribute]);
    }
}

std::ostream & operator<<(std::ostream & out, const Fermentable fermentable)
{
    out << "     ########## FERMENTABLE ##########"                                         << "\n";
    out << "     Name                : " << fermentable.name                                << "\n";
    out << "     Version             : " << fermentable.version                             << "\n";
    out << "     Type                : " << fermentable.type                                << "\n";
    out << "     Origin              : " << fermentable.origin                              << "\n";
    out << "     Notes               : " << fermentable.notes                               << "\n";
    out << "     Amount              : " << fermentable.amount                              << "\n";
    out << "     Yield               : " << fermentable.yield                               << "\n";
    out << "     Color               : " << fermentable.color                               << "\n";
    out << "     After boil          : " << Parsable::printBool(fermentable.addAfterBoil)   << "\n";
    out << "     Reccomended in mash : " << Parsable::printBool(fermentable.recommendedMash)<< "\n";
    out << "     ######################"                                                    << "\n";

    return out;
}
