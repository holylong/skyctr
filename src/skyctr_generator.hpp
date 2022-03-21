#ifndef _SKYCTR_GENERATOR_H_
#define _SKYCTR_GENERATOR_H_

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
        private:
            T _name;
        };
    }
}

#endif //_SKYCTR_GENERATOR_H_