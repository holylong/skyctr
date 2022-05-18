#ifndef _SKY_CTR_PARSER_H_
#define _SKY_CTR_PARSER_H_

// #include <skyctr_core.hpp>
#include <skyctr_factory.hpp>
#include <iostream>
#include <convertor_struct.hpp>

namespace sky{
    namespace core{

        template<typename T>
        class SkyctrParser{
            public:
                T getName(){return _name;}

                void PrintName() { std::cout << "type name:" << typeid(T).name() << std::endl; }

                virtual std::shared_ptr<Target> ParseFile(const std::string path) = 0;


            private:
                //ConvertorStruct
                T _name;
        };
    }
}

#endif //_SKY_CTR_PARSER_H_