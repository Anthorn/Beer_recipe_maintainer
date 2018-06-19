#include <mashStep.h>

using namespace std;


void MashStep::print() const
{
    cout << "     ########## Mash Step ##########"      << endl;
    cout << "     Name           : " << name            << endl;
    cout << "     Version        : " << version         << endl;
    cout << "     Type           : " << type            << endl;
    cout << "     Infuse amount  : " << infuseAmount    << endl;
    cout << "     Step Time      : " << stepTime        << endl;
    cout << "     Step Temp      : " << stepTemp        << endl;
    cout << "     End Temp       : " << endTemp         << endl;
    cout << "     Water/Grain    : " << waterGrainRatio << endl;
    cout << "     Infuse Temp    : " << infuseTemp      << endl;
}

void MashStep::insertValue(string attribute, string value)
{
    if (mashStepAttr[0].compare(attribute) == 0)
    {
        name = value;
    }
    else if (mashStepAttr[1].compare(attribute) == 0)
    {
        version = value;
    }
    else if (mashStepAttr[2].compare(attribute) == 0)
    {
        type = value;
    }
    else if (mashStepAttr[3].compare(attribute) == 0)
    {
        infuseAmount = stod(value);
    }
    else if (mashStepAttr[4].compare(attribute) == 0)
    {
        stepTime = stod(value);
    }
    else if (mashStepAttr[5].compare(attribute) == 0)
    {
        stepTemp = stod(value);
    }
    else if (mashStepAttr[6].compare(attribute) == 0)
    {
        endTemp = stod(value);
    }
    else if (mashStepAttr[7].compare(attribute) == 0)
    {
        waterGrainRatio = stod(value);
    }
    else if (mashStepAttr[8].compare(attribute) == 0)
    {
        infuseTemp = stod(value);
    }
}

void MashStep::populate(map<string, string> rawMashStep)
{
    for (const auto& attribute : mashStepAttr)
    {
        insertValue(attribute, rawMashStep[attribute]);
    }
}
