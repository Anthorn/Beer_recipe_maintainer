#include <yeast.h>


using namespace std;

void Yeast::print()
{
    cout << "     ########## YEAST ##########" << endl;
    cout << "     Name       : " << this->name << endl;
    cout << "     Version    : " << this->version << endl;
    cout << "     Type       : " << this->type << endl;
    cout << "     Form       : " << this->form << endl;
    cout << "     Amount     : " << this->amount << endl;
    cout << "     IsAmountInWeight : " << Parsable::printBool(this->amountIsWeight) << endl;
    cout << "     Laboratory     : " << this->laboratory << endl;
    cout << "     ProductID     : " << this->productID << endl;
    cout << "     Minium Temp   : " << this->minTemp << endl;
    cout << "     Maximum Temp   : " << this->maxTemp << endl;
    cout << "     Flocculation   : " << this->flocculation << endl;
    cout << "     Attenuation      : " << this->attenuation << endl;
    cout << "     Notes      : " << this->notes << endl;
    cout << "     Culture date : " << this->cultureDate << endl;
    cout << "     #########################" << endl;
}



void Yeast::insertValue(string attribute, string value)
{
    if (yeastAttributes[0].compare(attribute) == 0)
    {
        this->name = value;
    }
    else if (yeastAttributes[1].compare(attribute) == 0)
    {
        this->version = value;
    }
    else if (yeastAttributes[2].compare(attribute) == 0)
    {
        this->type = value;
    }
    else if (yeastAttributes[3].compare(attribute) == 0)
    {
        this->form = value;
    }
    else if (yeastAttributes[4].compare(attribute) == 0)
    {
        this->amount = stod(value);
    }
    else if (yeastAttributes[5].compare(attribute) == 0)
    {
        this->amountIsWeight = Parsable::convertStringToBool(value);
    }
    else if (yeastAttributes[6].compare(attribute) == 0)
    {
        this->laboratory = value;
    }
    else if (yeastAttributes[7].compare(attribute) == 0)
    {
        this->productID = value;
    }
    else if (yeastAttributes[8].compare(attribute) == 0)
    {
        this->minTemp = stod(value);
    }
    else if (yeastAttributes[9].compare(attribute) == 0)
    {
        this->maxTemp = stod(value);
    }
    else if (yeastAttributes[10].compare(attribute) == 0)
    {
        this->flocculation = value;
    }
    else if (yeastAttributes[11].compare(attribute) == 0)
    {
        this->attenuation = stod(value);
    }
    else if (yeastAttributes[12].compare(attribute) == 0)
    {
        this->notes = value;
    }
    else if (yeastAttributes[13].compare(attribute) == 0)
    {
        this->cultureDate = value;
    }
}



void Yeast::populate(map<string, string> rawYeast)
{
    for (const auto& attribute : yeastAttributes)
    {
        insertValue(attribute, rawYeast[attribute]);
    }
}
