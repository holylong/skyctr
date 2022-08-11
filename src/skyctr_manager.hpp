#ifndef _SKYCTR_MANAGER_H_
#define _SKYCTR_MANAGER_H_
#include <iostream>

#include <skyctr_factory.hpp>
#include <skyctr_parser.hpp>
#include <skyctr_vcxproj_parser.hpp>
#include <skyctr_generator.hpp>
#include <memory>
#include <convertor_struct.hpp>

namespace sky{
    namespace core{
        class SkyctrManager{
            public:
                SkyctrManager(std::unique_ptr<SkyctrParser<int>> parser);
                SkyctrManager();
                
                SkyStatus ParseMesonFile(std::string in);
                SkyStatus ParseVcxprojFile(std::string in, std::unique_ptr<SkyctrParser<int>> parser);
                SkyStatus ParseVcxprojFile(std::string in);
                SkyStatus ParseMakeFile(std::string in);
                SkyStatus ParseNinjaFile(std::string in);
                SkyStatus ParseBazelFile(std::string in);

                SkyStatus ParseXmlFile(std::string in);
                
                SkyStatus DumpCmakeFile(const std::string& in, const std::string& license);
                

            private:
                //源解决方案解析器
                std::unique_ptr<SkyctrParser<int>> _parser;
                //目标解决方案生成器
                std::unique_ptr<SkyctrGenerator<int>> _generator;

                std::shared_ptr<Target> _target;
                
        };
    }
}


#endif //_SKYCTR_MANAGER_H_