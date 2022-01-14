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
    public:
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
      /**设置安装目录**/
      std::string              m_installpath;
  };
}

#endif //_CONVERTOR_STRUCT_H_