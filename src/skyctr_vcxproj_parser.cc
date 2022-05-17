#include <skyctr_vcxproj_parser.hpp>
#include <tinyxml2.h>

using namespace std;
using namespace tinyxml2;

namespace sky{
  namespace core{

    //template<typename T>
    SkyStatus SkyctrVcxprojParser::ParseFile(const std::string path)
    {
        //cout << "type:" << typeid(T).name() << endl;
        cout << "parse:" << path.c_str() << endl;
        XMLDocument doc;
        doc.LoadFile(path.c_str());

        //doc.Print();

        cout << "errorid:" << doc.ErrorID() << endl;
        cout << "parse:" << path.c_str() << endl;

        cout << "first child:" << doc.FirstChild()->ToDeclaration()->Value() << endl;
        cout << "first child ele:" << doc.FirstChildElement()->Value() << endl;
        cout << "first child ele:" << doc.FirstChildElement()->FirstChildElement()->Value() << endl;
        cout << "first child ele:" << doc.FirstChildElement()->FirstChildElement()->FirstChildElement()->Attribute("Include") << " " <<
            doc.FirstChildElement()->FirstChildElement()->FirstChildElement()->Value() << endl;

        XMLElement* root = doc.FirstChildElement("Project");
        cout << "next ele 1:" << root->FirstChildElement("PropertyGroup")->Value() << endl;
        cout << "next ele 2:" << root->FirstChildElement("PropertyGroup")->Attribute("Label")<< endl;

        cout << "next ele 3:" << root->FirstChildElement("PropertyGroup")->NextSiblingElement("PropertyGroup")->Attribute("Condition") << endl;
        cout << "next ele 4:" << root->FirstChildElement("PropertyGroup")->NextSiblingElement("PropertyGroup")->NextSiblingElement("PropertyGroup")->Attribute("Condition") << endl;
        cout << "next ele 5:" << root->FirstChildElement("PropertyGroup")->NextSiblingElement("ImportGroup")->Attribute("Label") << endl;
        cout << "item group:" << root->FirstChildElement("ItemGroup")->NextSiblingElement("ItemGroup")->FirstChildElement()->Attribute("Include")<< endl;
        cout << "item group:" << root->FirstChildElement("ItemGroup")->NextSiblingElement("ItemGroup")->FirstChildElement()->NextSiblingElement()->Attribute("Include") << endl;
        cout << "item group:" << root->FirstChildElement("ItemGroup")->NextSiblingElement("ItemGroup")->NextSiblingElement("ItemGroup")->FirstChildElement()->Attribute("Include") << endl;

        if (root->FirstChildElement("ItemGroup")->NextSiblingElement("ItemGroup")->NextSiblingElement("ItemGroup")->FirstChildElement()->NextSiblingElement() == NULL) {
            cout << "cannot find next cpp" << endl;
        }
        else {
            cout << "find next cpp ok" << endl;
        }
        cout << "last ele:" << doc.LastChildElement()->Value() << endl;

        //½âÎöÎÄ¼þ
        return Status_Ok;
    }

    //template<typename T>
    //SkyctrVcxprojParser<T>::SkyctrVcxprojParser()
    //{
    //    cout << "type:" << typeid(T).name() << endl;
    //}
  }
}


