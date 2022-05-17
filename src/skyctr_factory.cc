#include <skyctr_factory.hpp>
#include <skyctr_manager.hpp>

namespace sky{
namespace core{
        SkyctrManager* SkyctrFactory::makeSkyctrManager(){
            return new SkyctrManager();
        }
    }
}