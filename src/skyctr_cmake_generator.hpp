#ifndef _SKYCTR_CMAKE_GENERATOR_H_
#define _SKYCTR_CMAKE_GENERATOR_H_

#include <skyctr_generator.hpp>

namespace sky{
    namespace core{
        //template<typename T>
        class SkyctrCmakeGenerator : public SkyctrGenerator<int>{
        public:
            SkyStatus DumpFile(std::string in, std::shared_ptr<Target> art);
        };
    }
}

#endif //_SKYCTR_CMAKE_GENERATOR_H_
