#ifndef _SKY_CTR_FACTORY_H_
#define _SKY_CTR_FACTORY_H_

enum SkyStatus{
    Status_UnKnow,
    Status_Ok,
    Status_Error,
    Status_ParseFileFailed
};

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