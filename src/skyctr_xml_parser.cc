#include <skyctr_xml_parser.hpp>
#include <skyctr_factory.hpp>
#include <tinyxml2.h>

using namespace std;
using namespace tinyxml2;

namespace sky {
	namespace core {
		std::shared_ptr<Target> SkyctrXmlParser::ParseFile(const std::string path)
		{
			cout << "parse:" << path.c_str() << endl;
			XMLDocument doc;
			doc.LoadFile(path.c_str());

			doc.Print();

			cout << "errorid:" << doc.ErrorID() << endl;
			return NULL;
		}
	}
}