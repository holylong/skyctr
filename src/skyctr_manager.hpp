#ifndef _SKYCTR_MANAGER_H_
#define _SKYCTR_MANAGER_H_
#include <iostream>

#include <skyctr_factory.hpp>
#include <skyctr_parser.hpp>
#include <skyctr_generator.hpp>

namespace sky{
    namespace core{
        class SkyctrManager{
            public:
                SkyctrManager();
                
                SkyStatus ParseMesonFile(std::string in);
                SkyStatus ParseVcxprojFile(std::string in);
                SkyStatus DumpCmakeFile(std::string in);

            private:
                //源解决方案解析器
                SkyctrParser<int> _parser;
                //目标解决方案生成器
                SkyctrGenerator<int> _generator;
                
        };
    }
}


#endif //_SKYCTR_MANAGER_H_