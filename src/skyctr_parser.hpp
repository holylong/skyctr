#ifndef _SKY_CTR_PARSER_H_
#define _SKY_CTR_PARSER_H_

// #include <skyctr_core.hpp>
#include <skyctr_factory.hpp>
#include <iostream>

namespace sky{
    namespace core{

        template<typename T>
        class SkyctrParser{
            public:
                T getName(){return _name;}

                void PrintName() { std::cout << "type name:" << typeid(T).name() << std::endl; }

                virtual SkyStatus ParseFile(const std::string path) = 0;


            private:
                T _name;
        };
    }
}

#endif //_SKY_CTR_PARSER_H_