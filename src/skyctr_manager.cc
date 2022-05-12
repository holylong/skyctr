#include <skyctr_manager.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <streambuf>
#include <spdlog/spdlog.h>
#include <skyctr_vcxproj_parser.hpp>
#include <skyctr_meson_parser.hpp>

using namespace std;

namespace sky{
    namespace core{
       
        SkyctrManager::SkyctrManager()
        {

        }

        /**
         * @brief 解析meson.build
         * 
         * @param in 
         * @return SkyStatus 
         */
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

            _parser = std::make_shared<SkyctrMesonParser>();
            return Status_Ok;
        }

        
        /**
         * @brief 解析msvc sln
         * 
         * @param in 
         * @return SkyStatus 
         */
        SkyStatus SkyctrManager::ParseVcxprojFile(std::string in){
            _parser = std::make_shared<SkyctrVcxprojParser>();
            return Status_Ok;
        }

        /**
         * @brief 解析makefile
         * 
         * @param in 
         * @return SkyStatus 
         */
        SkyStatus SkyctrManager::ParseMakeFile(std::string in)
        {
            return Status_Ok;
        }

        /**
         * @brief parse ninja.build
         * 
         * @param in 
         * @return SkyStatus 
         */
        SkyStatus SkyctrManager::ParseNinjaFile(std::string in)
        {
            return Status_Ok;
        }

        /**
         * @brief 解析bazel
         * 
         * @param in 
         * @return SkyStatus 
         */
        SkyStatus SkyctrManager::ParseBazelFile(std::string in)
        {
            return Status_Ok;
        }

        /**
         * @brief 生成cmakelists.txt
         * 
         * @param in 
         * @return SkyStatus 
         */
        SkyStatus SkyctrManager::DumpCmakeFile(std::string in){
            return Status_Ok;
        }
    }
}

