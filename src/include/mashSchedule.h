#pragma once

#include "mashStep.h"

class MashSchedule : public Parsable {
  public:
    void                                    parse(std::shared_ptr<BeersmithXMLParser> parser);
    void                                    print() const override;
    void                                    populate(std::list<std::map<std::string, std::string>> rawMashSteps);

    void                                    populateMetaData(std::map<std::string, std::string> rawMashMetaData);
    void                                    insertValue(std::string attribute, std::string value);
    std::list<std::shared_ptr<MashStep>>    getMashSteps();

  private:
    std::string                          name, version;
    double                               spargeTemp, ph;
    std::list<std::shared_ptr<MashStep>> mashSteps;
};
