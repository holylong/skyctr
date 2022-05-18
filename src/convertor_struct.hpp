#ifndef _CONVERTOR_STRUCT_H_
#define _CONVERTOR_STRUCT_H_

/**
 * @file SkyConvertorStruct.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-13
 * 
 * @copyright Copyright (c) 2022
 * 
 * C++构建工具先关命令与定义
 */

#include <vector>
#include <iostream>

namespace sky{
  namespace core{

      enum SkyStatus {
          Status_UnKnow,
          Status_Ok,
          Status_Error,
          Status_ParseFileFailed
      };

      typedef enum {
        Type_Error = -1,
        Type_Shared_Library = 0,
        Type_Static_Library = 1,
        Type_Exec = 2
      }TargetType;

      typedef struct _TargetInfo{
        TargetType _target_type;
        std::string _target_name;
        /**cxxflag**/
        std::vector<std::string> m_cxxflag;
        /**cflag**/
        std::vector<std::string> m_cflag;
        /**编译器**/
        std::vector<std::string> m_compiler;
        /**源码文件**/
        std::vector<std::string> m_source;
        /**头文件目录**/
        std::vector<std::string> m_include;
        /**链接库目录**/
        std::vector<std::string> m_libpath;
        /**链接库**/
        std::vector<std::string> m_library;
        std::vector<std::string> m_header;
      }TargetInfo;

      class Target{
      public:
          Target();
        
        /**project name*/
        std::string              m_projectname;
      
        /**目标文件**/
        //std::vector<TargetInfo> m_targets;
        /**设置安装目录**/
        std::string              m_installpath;

        std::vector<TargetInfo>  m_targets;

        SkyStatus _status;

        Target operator+(Target target) const;
        Target& operator+=(Target& target);

        void PrintAll();
    };
  }
}

#endif //_CONVERTOR_STRUCT_H_