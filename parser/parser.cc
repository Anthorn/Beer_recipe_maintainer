
#include <iostream>
#include <tinyxml.h>


using namespace std;


int main() {

  TiXmlDocument doc("example1.xml");
  bool loadOkay = doc.LoadFile();

  if(loadOkay)
  {
    TiXmlHandle hDoc(&doc);
    TiXmlElement* root = hDoc.FirstChildElement().Element();
    cout << "Printing: \n" << root->Value() << "\n, " << root->GetText() << endl;
  }
  return 0;
}
