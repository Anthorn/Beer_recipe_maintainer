#include <mashSchedule.h>


void MashSchedule::insertValue(string attribute, string value)
{
    if (mashMetaDataAttr[0].compare(attribute) == 0)
    {
        name = value;
    }
    else if (mashMetaDataAttr[1].compare(attribute) == 0)
    {
        version = value;
    }
    else if (mashMetaDataAttr[2].compare(attribute) == 0)
    {
        spargeTemp = stod(value);
    }
    else if (mashMetaDataAttr[3].compare(attribute) == 0)
    {
        ph = stod(value);
    }
}

void MashSchedule::print()
{
    cout << "###### MASH SCHEDULE ######"    << endl;
    cout << "  Name         : "  << name       << endl;
    cout << "  Version      : "  << version    << endl;
    cout << "  Sparge temp  : "  << spargeTemp << endl;
    cout << "  PH           : "  << ph         << endl;
    for (const auto& mashStep : mashSteps)
    {
        mashStep->print();
    }
}

list<std::shared_ptr<MashStep>> MashSchedule::getMashSteps()
{
    return list<std::shared_ptr<MashStep>>();
}

void MashSchedule::parse(shared_ptr<BeersmithXMLParser> parser)
{
    map<string, string> rawMashMetaData = parser->parseMashMetaData();
    populateMetaData(rawMashMetaData);

    list<map<string, string>> rawMashSchedule = parser->parseMashSchedule();
    populate(rawMashSchedule);

}

void MashSchedule::populate(list<map<string, string>> rawMashSchedule)
{
    std::shared_ptr<MashStep> mashStep;
    for (const auto& rawMashStep : rawMashSchedule)
    {
        mashStep.reset(new MashStep());
        mashStep->populate(rawMashStep);
        mashSteps.push_back(mashStep);
    }
}

void MashSchedule::populateMetaData(map<string, string> rawMashMetaData)
{
    for (int i = 0; i < MASH_META_DATA_ATTR_SIZE; i++)
    {
        insertValue(mashMetaDataAttr[i], rawMashMetaData[mashMetaDataAttr[i]]);
    }

}
