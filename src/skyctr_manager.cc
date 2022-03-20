#include <skyctr_manager.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <streambuf>
#include <spdlog/spdlog.h>

using namespace std;

namespace sky{
    namespace core{
       
        SkyctrManager::SkyctrManager()
        {

        }

        
        SkyStatus SkyctrManager::ParseMesonFile(std::string in){
            ifstream ifs(in);
            if(ifs.is_open()){
            #if 0
                //文本二进制都可以
                ifs.seekg(0, ios::end);
                streampos len = ifs.tellg();
                ifs.seekg(0, ios::beg);
                char* res = new char[len];
                ifs.read(res, len);
            #endif
            #if 0
                //文本文件可以、二进制不可以
                stringstream buffer;
                buffer << ifs.rdbuf();
                string res = buffer.str();
            #endif  
                //文本文件可以、二进制不可以
                string str((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
                spdlog::info("origin content{}", str);
                ifs.close();
            }
            return Status_Ok;
        }

        
        SkyStatus SkyctrManager::ParseVcxprojFile(std::string in){
            return Status_Ok;
        }

        
        SkyStatus SkyctrManager::DumpCmakeFile(std::string in){
            return Status_Ok;
        }
    }
}

