#include <hop.h>

using namespace std;


void Hop::print() const
{
}


void Hop::insertValue(string attribute, string value)
{
    if (hopAttributes[0].compare(attribute) == 0)
    {
        name = value;
    }
    else if (hopAttributes[1].compare(attribute) == 0)
    {
        version = value;
    }
    else if (hopAttributes[2].compare(attribute) == 0)
    {
        origin = value;
    }
    else if (hopAttributes[3].compare(attribute) == 0)
    {
        alphaAcid = stod(value);
    }
    else if (hopAttributes[4].compare(attribute) == 0)
    {
        use = value;
    }
    else if (hopAttributes[5].compare(attribute) == 0)
    {
        time = stod(value);
    }
    else if (hopAttributes[6].compare(attribute) == 0)
    {
        notes = value;
    }
    else if (hopAttributes[7].compare(attribute) == 0)
    {
        type = value;
    }
    else if (hopAttributes[8].compare(attribute) == 0)
    {
        form = value;
    }
    else if (hopAttributes[9].compare(attribute) == 0)
    {
        this->amount = stod(value);
    }
}


void Hop::populate(map<string, string> rawHop)
{
    for (const auto& attribute : hopAttributes)
    {
        insertValue(attribute, rawHop[attribute]);
    }
}

std::ostream & operator<<(std::ostream & out, const Hop hop)
{
    out << "     ########## HOP ##########"    << "\n";
    out << "     Name     : " << hop.name      << "\n";
    out << "     Version  : " << hop.version   << "\n";
    out << "     Origin   : " << hop.origin    << "\n";
    out << "     Usage    : " << hop.use       << "\n";
    out << "     Notes    : " << hop.notes     << "\n";
    out << "     Type     : " << hop.type      << "\n";
    out << "     Form     : " << hop.form      << "\n";
    out << "     AlphaAcid: " << hop.alphaAcid << "\n";
    out << "     Amount   : " << hop.amount    << "\n";
    out << "     Time     : " << hop.time      << "\n";
    out << "     ########################"     << "\n";

    return out;
}
