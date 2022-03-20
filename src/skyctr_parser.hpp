#ifndef _SKY_CTR_PARSER_H_
#define _SKY_CTR_PARSER_H_

// #include <skyctr_core.hpp>

namespace sky{
    namespace core{

        template<typename T>
        class SkyctrParser{
            public:
                T getName(){return _name;}


            private:
                T _name;
        };
    }
}

#endif //_SKY_CTR_PARSER_H_