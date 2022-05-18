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
        SkyStatus SkyctrCmakeGenerator::DumpFile(std::string in, std::shared_ptr<Target> art)
        {
            if (art == NULL) {
                spdlog::info("empty target");
                return Status_Error;
            }
            spdlog::debug("==> DumpFile:{}", in);
            //ofstream ofs;

            stringstream ss;
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
                    if (beginidx++ == 0)ss << src << endl;
                    else if (beginidx == sumidx)ss << skyctr_space << src;
                    else ss << skyctr_space << src << endl;
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
                    if (beginidx++ == 0)ss << src << endl;
                    else if (beginidx == sumidx)ss << skyctr_space << src;
                    else ss << skyctr_space << src << endl;
                }
            }
            ss << ")" << endl << endl;
            
            //add exec
            for (auto targetinfo : art.get()->m_targets) {
                switch(targetinfo._target_type) {
                case Type_Shared_Library:
                    ss << skyctr_add_library << "(" << targetinfo._target_name << " " << skyctr_SHARED << " " << targetinfo._target_name << "_SRCS" << " " <<
                        targetinfo._target_name << "_INCS";
                    break;
                case Type_Static_Library:
                    ss << skyctr_add_library << "(" << targetinfo._target_name  << " " << skyctr_STATIC << " " << targetinfo._target_name << "_SRCS" << " " <<
                        targetinfo._target_name << "_INCS";
                    break;
                case Type_Exec:
                    ss << skyctr_add_executable << "(" << targetinfo._target_name << " " << targetinfo._target_name << "_SRCS" << " " << 
                        targetinfo._target_name << "_INCS";
                    break;
                }
                ss << ")" << endl << endl;
            }
            ofstream ofs;
            //ofs.open(in, ios::ate);
            ofs.open(in);
            ofs << ss.str();
            ofs.close();
            return Status_Ok;
        }
    }
}