#ifndef _SKY_CTR_VCXPROJ_PARSER_H_
#define _SKY_CTR_VCXPROJ_PARSER_H_

/**
 * @file skyctr_vcxproj_parser.hpp
 * @author your name (you@domain.com)
 * @brief 解析vcxproj
 * @version 0.1
 * @date 2022-05-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <skyctr_parser.hpp>
#include <skyctr_factory.hpp>

namespace sky{
    namespace core{
        //template<typename T>
        class SkyctrVcxprojParser : public SkyctrParser<int>{
        public:

            //SkyctrVcxprojParser();

            SkyStatus ParseFile(const std::string path);
            
        };
    }
}

#endif //_SKY_CTR_MESON_PARSER_H_