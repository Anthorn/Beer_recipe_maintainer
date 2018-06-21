#include <yeast.h>


using namespace std;

void Yeast::print() const
{
    cout << "     ########## YEAST ##########"               << endl;
    cout << "     Name             : " << this->name         << endl;
    cout << "     Version          : " << this->version      << endl;
    cout << "     Type             : " << this->type         << endl;
    cout << "     Form             : " << this->form         << endl;
    cout << "     Amount           : " << this->amount       << endl;
    cout << "     IsAmountInWeight : " << Parsable::printBool(this->amountIsWeight) << endl;
    cout << "     Laboratory       : " << this->laboratory   << endl;
    cout << "     ProductID        : " << this->productID    << endl;
    cout << "     Minium Temp      : " << this->minTemp      << endl;
    cout << "     Maximum Temp     : " << this->maxTemp      << endl;
    cout << "     Flocculation     : " << this->flocculation << endl;
    cout << "     Attenuation      : " << this->attenuation  << endl;
    cout << "     Notes            : " << this->notes        << endl;
    cout << "     Culture date     : " << this->cultureDate  << endl;
    cout << "     #########################"                 << endl;
}

void Yeast::insertValue(string attribute, string value)
{
    if (yeastAttributes[0].compare(attribute) == 0)
    {
        name = value;
    }
    else if (yeastAttributes[1].compare(attribute) == 0)
    {
        version = value;
    }
    else if (yeastAttributes[2].compare(attribute) == 0)
    {
        type = value;
    }
    else if (yeastAttributes[3].compare(attribute) == 0)
    {
        form = value;
    }
    else if (yeastAttributes[4].compare(attribute) == 0)
    {
        amount = stod(value);
    }
    else if (yeastAttributes[5].compare(attribute) == 0)
    {
        amountIsWeight = Parsable::convertStringToBool(value);
    }
    else if (yeastAttributes[6].compare(attribute) == 0)
    {
        laboratory = value;
    }
    else if (yeastAttributes[7].compare(attribute) == 0)
    {
        productID = value;
    }
    else if (yeastAttributes[8].compare(attribute) == 0)
    {
        minTemp = stod(value);
    }
    else if (yeastAttributes[9].compare(attribute) == 0)
    {
        maxTemp = stod(value);
    }
    else if (yeastAttributes[10].compare(attribute) == 0)
    {
        flocculation = value;
    }
    else if (yeastAttributes[11].compare(attribute) == 0)
    {
        attenuation = stod(value);
    }
    else if (yeastAttributes[12].compare(attribute) == 0)
    {
        notes = value;
    }
    else if (yeastAttributes[13].compare(attribute) == 0)
    {
        cultureDate = value;
    }
}



void Yeast::populate(map<string, string> rawYeast)
{
    for (const auto& attribute : yeastAttributes)
    {
        insertValue(attribute, rawYeast[attribute]);
    }
}

std::ostream & operator<<(std::ostream & out, const Yeast yeast)
{
    out << "     ########## YEAST ##########"               << "\n";
    out << "     Name             : " << yeast.name         << "\n";
    out << "     Version          : " << yeast.version      << "\n";
    out << "     Type             : " << yeast.type         << "\n";
    out << "     Form             : " << yeast.form         << "\n";
    out << "     Amount           : " << yeast.amount       << "\n";
    out << "     IsAmountInWeight : " << Parsable::printBool(yeast.amountIsWeight) << "\n";
    out << "     Laboratory       : " << yeast.laboratory   << "\n";
    out << "     ProductID        : " << yeast.productID    << "\n";
    out << "     Minium Temp      : " << yeast.minTemp      << "\n";
    out << "     Maximum Temp     : " << yeast.maxTemp      << "\n";
    out << "     Flocculation     : " << yeast.flocculation << "\n";
    out << "     Attenuation      : " << yeast.attenuation  << "\n";
    out << "     Notes            : " << yeast.notes        << "\n";
    out << "     Culture date     : " << yeast.cultureDate  << "\n";
    out << "     #########################"                 << "\n";

    return out;
}
