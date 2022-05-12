#ifndef _SKY_CTR_MESON_PARSER_H_
#define _SKY_CTR_MESON_PARSER_H_

#include <skyctr_parser.hpp>

namespace sky{
    namespace core{
        //template<typename T>
        class SkyctrMesonParser : public SkyctrParser<int>{
        public:
            virtual SkyStatus ParseFile(const std::string path);
        };
    }
}

#endif //_SKY_CTR_MESON_PARSER_H_