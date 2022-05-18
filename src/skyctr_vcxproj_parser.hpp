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
#include <convertor_struct.hpp>
#include <tinyxml2.h>

//XMLDocument

namespace sky{
    namespace core{
        //template<typename T>
        class SkyctrVcxprojParser : public SkyctrParser<int>{
        public:

            //SkyctrVcxprojParser();

            std::shared_ptr<Target> ParseFile(const std::string path);
            
            std::shared_ptr<Target> QueryHeaders(tinyxml2::XMLDocument* doc);
            std::shared_ptr<Target> QuerySources(tinyxml2::XMLDocument* doc);
            std::shared_ptr<Target> QueryIncludes(tinyxml2::XMLDocument* doc);
            std::shared_ptr<Target> QueryLibraries(tinyxml2::XMLDocument* doc);
            std::shared_ptr<Target> QueryLibPaths(tinyxml2::XMLDocument* doc);
            std::shared_ptr<Target> QueryCFlags(tinyxml2::XMLDocument* doc);
            std::shared_ptr<Target> QueryCXXFlags(tinyxml2::XMLDocument* doc);

            void PrintSample(tinyxml2::XMLDocument* doc);
        };
    }
}

#endif //_SKY_CTR_MESON_PARSER_H_