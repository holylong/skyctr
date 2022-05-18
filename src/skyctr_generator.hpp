#ifndef _SKYCTR_GENERATOR_H_
#define _SKYCTR_GENERATOR_H_

#include <iostream>
#include <convertor_struct.hpp>

/**
 * @brief 解决方案生成器
 * 
 */

namespace sky{
    namespace core{
        template<typename T>
        class SkyctrGenerator{
        public:
            T getName(){return _name;}

            virtual SkyStatus DumpFile(std::string in, std::shared_ptr<Target> art) = 0;
        private:
            T _name;
        };
    }
}

#endif //_SKYCTR_GENERATOR_H_