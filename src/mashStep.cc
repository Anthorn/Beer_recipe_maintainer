#include <mashStep.h>

using namespace std;


void MashStep::print()
{
  cout << "     ########## Mash Step ##########" << endl;
  cout << "     Name       : " << this->name << endl;
  cout << "     Version    : " << this->version << endl;
  cout << "     Type       : " << this->type << endl;
  cout << "     Infuse amount  : " << this->infuseAmount << endl;
  cout << "     Step Time       : " << this->stepTime << endl;
  cout << "     Step Temp       : " << this->stepTemp << endl;
  cout << "     End Temp       : " << this->endTemp << endl;
  cout << "     Water/Grain       : " << this->waterGrainRatio << endl;
  cout << "     Infuse Temp       : " << this->infuseTemp << endl;
}

void MashStep::insertValue(string attribute, string value)
{
  if (mashStepAttr[0].compare(attribute) == 0 ){
    this->name = value;
  }
  else if (mashStepAttr[1].compare(attribute) == 0) {
    this->version = value;
  }
  else if (mashStepAttr[2].compare(attribute) == 0) {
    this->type = value;
  }
  else if (mashStepAttr[3].compare(attribute) == 0) {
    this->infuseAmount = stod(value);
  }
  else if (mashStepAttr[4].compare(attribute) == 0) {
    this->stepTime = stod(value);
  }
  else if (mashStepAttr[5].compare(attribute) == 0) {
    this->stepTemp = stod(value);
  }
  else if (mashStepAttr[6].compare(attribute) == 0) {
    this->endTemp = stod(value);
  }
  else if (mashStepAttr[7].compare(attribute) == 0) {
    this->waterGrainRatio = stod(value);
  }
  else if (mashStepAttr[8].compare(attribute) == 0) {
    this->infuseTemp = stod(value);
  }
}

void MashStep::populate(map<string, string> rawMashStep)
{
  for(const auto& attribute : mashStepAttr)
  {
    insertValue(attribute, rawMashStep[attribute]);
  }
}
