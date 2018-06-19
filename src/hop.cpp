#include <hop.h>

using namespace std;


void Hop::print() const
{
    cout << "     ########## HOP ##########"<< endl;
    cout << "     Name     : " << name      << endl;
    cout << "     Version  : " << version   << endl;
    cout << "     Origin   : " << origin    << endl;
    cout << "     Usage    : " << use       << endl;
    cout << "     Notes    : " << notes     << endl;
    cout << "     Type     : " << type      << endl;
    cout << "     Form     : " << form      << endl;
    cout << "     AlphaAcid: " << alphaAcid << endl;
    cout << "     Amount   : " << amount    << endl;
    cout << "     Time     : " << time      << endl;
    cout << "     ########################" << endl;
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

