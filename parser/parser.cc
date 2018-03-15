#include <parser.h>

using namespace std;




string BeersmithXMLParser::parseRecipeMetaData(TiXmlElement* data)
{
  ostringstream oss;


  TiXmlElement* current;
  current = data->FirstChildElement("NAME");
  if(current != NULL){
    oss << "Name: " << current->GetText() << endl;
  }

  current = data->FirstChildElement("VERSION");
  if(current != NULL){
    oss << "Version: " << current->GetText() << endl;
  }

  cout << oss.str();

  return "";

}


string BeersmithXMLParser::recipe(TiXmlHandle* handleDoc){
  ostringstream oss;
  TiXmlElement* rootOfRecipe = handleDoc->FirstChildElement().Element();

  for(TiXmlElement* current = rootOfRecipe->FirstChildElement();
      current != NULL; current = current->NextSiblingElement()){

    cout << "Current key: " <<  current->Value() << endl;

    string currentValue = current->Value();

    if(currentValue == "RECIPE")
    {
      oss << parseRecipeMetaData(current);
    }
  }

  return "";
  }

int main() {

  TiXmlDocument doc("recipes.xml");
  bool loadOkay = doc.LoadFile();


  BeersmithXMLParser parser;

  if(loadOkay)
  {
    TiXmlHandle hDoc(&doc);
    parser.recipe(&hDoc);
  }
  return 0;
}
