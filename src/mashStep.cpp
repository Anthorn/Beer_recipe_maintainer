#include <mashStep.h>

using namespace std;


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

std::ostream & operator<<(std::ostream & out, const MashStep step)
{
    out << "     ########## Mash Step ##########"           << "\n";
    out << "     Name           : " << step.name            << "\n";
    out << "     Version        : " << step.version         << "\n";
    out << "     Type           : " << step.type            << "\n";
    out << "     Infuse amount  : " << step.infuseAmount    << "\n";
    out << "     Step Time      : " << step.stepTime        << "\n";
    out << "     Step Temp      : " << step.stepTemp        << "\n";
    out << "     End Temp       : " << step.endTemp         << "\n";
    out << "     Water/Grain    : " << step.waterGrainRatio << "\n";
    out << "     Infuse Temp    : " << step.infuseTemp      << "\n";

    return out;
}
