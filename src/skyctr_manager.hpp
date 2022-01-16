#ifndef _SKYCTR_MANAGER_H_
#define _SKYCTR_MANAGER_H_
#include <iostream>

#include <skyctr_factory.hpp>

namespace sky{
    namespace core{
        class SkyctrManager{
            public:
                SkyctrManager();
                
                SkyStatus ParseMesonFile(std::string in);
                SkyStatus ParseVcxprojFile(std::string in);
                SkyStatus DumpCmakeFile(std::string in);
        };
    }
}


#endif //_SKYCTR_MANAGER_H_