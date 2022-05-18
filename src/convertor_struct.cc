#include <convertor_struct.hpp>
#include <spdlog/spdlog.h>
/**
 * @brief 结局方案变量
 * 
 */

using namespace std;
using namespace spdlog;

namespace sky{
    namespace core{ 
        Target::Target(){
            m_projectname = "";
            m_installpath = "";
            m_targets.clear();
            _status = Status_Ok;
        }

        Target& Target::operator+=(Target& target)
        {
            if (target.m_projectname != "") {
                m_projectname = target.m_projectname;
            }

            if (target.m_installpath != "") {
                m_installpath = target.m_installpath;
            }

            if (!target.m_targets.empty() && !m_targets.empty()) {
                bool isfound = false;
                vector<TargetInfo> arrRes;
                for (auto srcinfo : target.m_targets) {
                    for (int i = 0; i < m_targets.size(); i++) {
                        if (m_targets[i]._target_name == srcinfo._target_name) {
                            isfound = true;
                            m_targets[i].m_cflag.insert(m_targets[i].m_cflag.end(), srcinfo.m_cflag.begin(), srcinfo.m_cflag.end());
                            m_targets[i].m_compiler.insert(m_targets[i].m_compiler.end(), srcinfo.m_compiler.begin(), srcinfo.m_compiler.end());
                            m_targets[i].m_cxxflag.insert(m_targets[i].m_cxxflag.end(), srcinfo.m_cxxflag.begin(), srcinfo.m_cxxflag.end());
                            m_targets[i].m_include.insert(m_targets[i].m_include.end(), srcinfo.m_include.begin(), srcinfo.m_include.end());
                            m_targets[i].m_libpath.insert(m_targets[i].m_libpath.end(), srcinfo.m_libpath.begin(), srcinfo.m_libpath.end());
                            m_targets[i].m_library.insert(m_targets[i].m_library.end(), srcinfo.m_library.begin(), srcinfo.m_library.end());
                            m_targets[i].m_source.insert(m_targets[i].m_source.end(), srcinfo.m_source.begin(), srcinfo.m_source.end());
                            m_targets[i].m_header.insert(m_targets[i].m_header.end(), srcinfo.m_header.begin(), srcinfo.m_header.end());
                            break;
                        }
                    }

                    if (isfound == false) {
                        arrRes.push_back(srcinfo);
                    }

                    isfound = false;
                }

                m_targets.insert(m_targets.end(), arrRes.begin(), arrRes.end());
            }
            else if (m_targets.empty() && !target.m_targets.empty()) {
                //dst.m_targets.emplace_back(target.m_targets);
                m_targets.insert(m_targets.end(), target.m_targets.begin(), target.m_targets.end());
            }

            if (target._status != Status_Ok) {
                _status = target._status;
            }

            return *this;
        }

        Target Target::operator+(Target target) const{
            Target dst;
            dst.m_projectname = m_projectname;
            dst.m_installpath = m_installpath;
            //dst.m_targets.emplace_back(m_targets);
            dst.m_targets.insert(dst.m_targets.end(), m_targets.begin(), m_targets.end());
            dst._status = _status;
            if(target.m_projectname != ""){
                dst.m_projectname = target.m_projectname;
            }

            if(target.m_installpath != ""){
                dst.m_installpath = target.m_installpath;
            }

            if(!target.m_targets.empty() && !dst.m_targets.empty()){
                bool isfound = false;
                vector<TargetInfo> arrRes;
                for(auto srcinfo : target.m_targets){
                    //for(auto dstinfo : dst.m_targets){//cannot modify element content
                    for(int i = 0; i < dst.m_targets.size(); i++){
                        if(dst.m_targets[i]._target_name == srcinfo._target_name){
                            isfound = true;
                            dst.m_targets[i].m_cflag.insert(m_targets[i].m_cflag.end(), srcinfo.m_cflag.begin(), srcinfo.m_cflag.end());
                            dst.m_targets[i].m_compiler.insert(m_targets[i].m_compiler.end(), srcinfo.m_compiler.begin(), srcinfo.m_compiler.end());
                            dst.m_targets[i].m_cxxflag.insert(m_targets[i].m_cxxflag.end(), srcinfo.m_cxxflag.begin(), srcinfo.m_cxxflag.end());
                            dst.m_targets[i].m_include.insert(m_targets[i].m_include.end(), srcinfo.m_include.begin(), srcinfo.m_include.end());
                            dst.m_targets[i].m_libpath.insert(m_targets[i].m_libpath.end(), srcinfo.m_libpath.begin(), srcinfo.m_libpath.end());
                            dst.m_targets[i].m_library.insert(m_targets[i].m_library.end(), srcinfo.m_library.begin(), srcinfo.m_library.end());
                            dst.m_targets[i].m_source.insert(m_targets[i].m_source.end(), srcinfo.m_source.begin(), srcinfo.m_source.end());
                            dst.m_targets[i].m_header.insert(m_targets[i].m_header.end(), srcinfo.m_header.begin(), srcinfo.m_header.end());
                            break;
                        }
                    }

                    if(isfound == false){
                        arrRes.push_back(srcinfo);
                    }
                }

                dst.m_targets.insert(dst.m_targets.end(), arrRes.begin(), arrRes.end());
            }else if(dst.m_targets.empty() && !target.m_targets.empty()){
                //dst.m_targets.emplace_back(target.m_targets);
                dst.m_targets.insert(dst.m_targets.end(), target.m_targets.begin(), target.m_targets.end());
            }

            if(target._status != Status_Ok){
                dst._status = target._status;
            }

            return dst;
        }


        void Target::PrintAll()
        {
            debug("project name:{}", m_projectname);
            debug("installer path:{}", m_installpath);
            debug("status:{}", _status);

            for (auto target : m_targets) {
                debug("target name:{}", target._target_name);
                debug("target type:{}", target._target_type);
                for(auto cflag:target.m_cflag)
                    debug("cflag:{}", cflag);
                for (auto source : target.m_source)
                    debug("source:{}", source);
                for (auto header : target.m_header)
                    debug("header:{}", header);
                for (auto inc : target.m_include)
                    debug("inc:{}", inc);
            }
        }
    }
}