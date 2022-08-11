#include <skyctr_cmake_generator.hpp>
#include <spdlog/spdlog.h>
#include <sstream>
#include <ostream>
#include <fstream>
#include <skyctr_core.hpp>

using namespace std;

namespace sky{
    namespace core{
        //template<typename T>
        SkyStatus SkyctrCmakeGenerator::DumpFile(string in, shared_ptr<Target> art, const string& license)
        {
            if (art == NULL) {
                spdlog::info("empty target");
                return Status_Error;
            }
            spdlog::debug("==> DumpFile:{} license{}", in, license);
            //ofstream ofs;

            ifstream ifs;
            vector<string> licenses;
            if(license != ""){
                ifs.open(license);
                if(ifs.is_open()){
                    
                //  string license_str((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
                //  stringstream buffer;
                //  buffer << ifs.rdbuf()
                //  license_str = buffer.str();
                string line = "";
                stringstream linewithhead;
                 while(!ifs.eof()){
                    getline(ifs, line);
                    linewithhead << "# ";
                    linewithhead << line;
                    spdlog::debug("==> license:{}", line);
                    licenses.push_back(linewithhead.str());
                    line = "";
                    // linewithhead.clear();//清空状态
                    linewithhead.str("");//清空内容
                }
                 ifs.close();
                }
            }

            stringstream ss;

            //license
            for(auto s:licenses){
                ss << s << endl;
            }
            

            //version
            ss << skyctr_cmake_minimum_required << skyctr_cmake_version << endl << endl;
            //project
            ss << skyctr_project << "(" << art.get()->m_projectname << ")" << endl << endl;
            //file source
            int beginidx = 0;
            int sumidx = 0;
            ss << skyctr_file << "(" << skyctr_GLOB << " " << art.get()->m_projectname << "_SRCS" << " ";
            for (auto targetinfo : art.get()->m_targets) {
                sumidx = targetinfo.m_source.size();
                for (auto src : targetinfo.m_source) {
                    //sumidx++;
                    if (beginidx++ == 0)ss << skyctr_CMAKE_CURRENT_SOURCE_DIR << "/" << src << endl;
                    else if (beginidx == sumidx)ss << skyctr_space << skyctr_CMAKE_CURRENT_SOURCE_DIR << "/" << src;
                    else ss << skyctr_space << skyctr_CMAKE_CURRENT_SOURCE_DIR << "/" << src << endl;
                }
            }
            ss << ")" << endl << endl;

            //file header
            beginidx = 0;
            sumidx = 0;
            ss << skyctr_file << "(" << skyctr_GLOB << " " << art.get()->m_projectname << "_INCS" << " ";
            for (auto targetinfo : art.get()->m_targets) {
                sumidx = targetinfo.m_header.size();
                for (auto src : targetinfo.m_header) {
                    //sumidx++;
                    if (beginidx++ == 0)ss << skyctr_CMAKE_CURRENT_SOURCE_DIR << "/" << src << endl;
                    else if (beginidx == sumidx)ss << skyctr_space << skyctr_CMAKE_CURRENT_SOURCE_DIR << "/" << src;
                    else ss << skyctr_space << skyctr_CMAKE_CURRENT_SOURCE_DIR << "/" << src << endl;
                }
            }
            ss << ")" << endl << endl;
            
            //add exec
            string targetname = "";
            for (auto targetinfo : art.get()->m_targets) {
                switch(targetinfo._target_type) {
                case Type_Shared_Library:
                    ss << skyctr_add_library << "(" << targetinfo._target_name << " " << skyctr_SHARED << " ${" << targetinfo._target_name << "_SRCS}" << " ${" <<
                        targetinfo._target_name << "_INCS}"; ss << ")" << endl << endl;
                    targetname = targetinfo._target_name;
                    break;
                case Type_Static_Library:
                    ss << skyctr_add_library << "(" << targetinfo._target_name  << " " << skyctr_STATIC << " ${" << targetinfo._target_name << "_SRCS}" << " ${" <<
                        targetinfo._target_name << "_INCS}"; ss << ")" << endl << endl;
                    targetname = targetinfo._target_name;
                    break;
                case Type_Exec:
                    ss << skyctr_add_executable << "(" << targetinfo._target_name << " ${" << targetinfo._target_name << "_SRCS}" << " ${" << 
                        targetinfo._target_name << "_INCS}"; ss << ")" << endl << endl;
                    targetname = targetinfo._target_name;
                    break;
                }
                
            }

            //add include
            for (auto targetinfo : art.get()->m_targets) {
                for (auto ti : targetinfo.m_include) {
                    ss << skyctr_target_include_directories << "(" << targetname.c_str() << " " << skyctr_PRIVATE
                        << " " << ti << ")"<< endl;;
                }
            }

            //add compile_options
            for (auto targetinfo : art.get()->m_targets) {
                for (auto ti : targetinfo.m_cxxflag) {
                    ss << skyctr_add_compile_definitions << "(" << ti << ")" << endl;;
                }
            }

            ss << endl;

            ofstream ofs;
            //ofs.open(in, ios::ate);
            ofs.open(in);
            ofs << ss.str();
            ofs.close();
            return Status_Ok;
        }
    }
}