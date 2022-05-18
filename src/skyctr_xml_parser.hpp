#ifndef _SKY_CTR_XML_PARSER_H_
#define _SKY_CTR_XML_PARSER_H_

#include <skyctr_parser.hpp>

namespace sky {
    namespace core {
        //template<typename T>
        class SkyctrXmlParser : public SkyctrParser<int> {
        public:
            virtual std::shared_ptr<Target> ParseFile(const std::string path);


        };
    }
}

#endif //_SKY_CTR_XML_PARSER_H_