#ifndef _SKY_CTR_FACTORY_H_
#define _SKY_CTR_FACTORY_H_


namespace sky{
    namespace core{
        class SkyctrManager;
        class SkyctrFactory{
            public:
                SkyctrManager* makeSkyctrManager();
        };
    }
}

#endif //_SKY_CTR_FACTORY_H_