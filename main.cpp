/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <gflags/gflags.h>
#include <skyctr_factory.hpp>
#include <skyctr_manager.hpp>
#include <skyctr_logger.hpp>
// #include <easylogging++.h>
//read build tool file to memory and save to cmake file

using namespace std;
using namespace gflags;
using namespace sky::core;

// INITIALIZE_EASYLOGGINGPP



DEFINE_string(origin, "make", "origin build file type");
DEFINE_string(path, "makefile", "origin file path");
DEFINE_string(out, "./", "output dir");
DEFINE_string(gen, "cmake", "to build file");

static std::string g_version;
static std::string g_help;

std::string& getVersion() {
  g_version = "0.0.1";
  return g_version;
}
std::string& getHelp() {
  g_help = "help message \r\r\r\r\n\nskyctr meson.build -g cmake -o CMakeList.txt\n"
           "skyctr -origin make -path Makefile -gen cmake -out CMakeList.txt";
  return g_help;
}

int main(int argc, char* argv[])
{
  cout << "skyctr convertor enter" << endl;
  sky::InitLogger();
  sky::LoggerTest();
  SetVersionString(getVersion());
  SetUsageMessage(getHelp());
  ParseCommandLineFlags(&argc, &argv, true);
  cout << "origin = " << FLAGS_origin << endl;
  cout << "path = " << FLAGS_path << endl;
  cout << "out = " << FLAGS_out << endl;
  cout << "gen = " << FLAGS_gen << endl;

  SkyctrFactory skyctrFactory;

  SkyctrManager *manager = skyctrFactory.makeSkyctrManager();
  
  //parse origin file
  if(FLAGS_origin == "make"){
    
  }else if(FLAGS_origin == "meson"){
    manager->ParseMesonFile(FLAGS_path);
  }else if(FLAGS_origin == "vcxproj"){
    manager->ParseVcxprojFile(FLAGS_path);
  }

  if(FLAGS_gen == "cmake"){
    manager->DumpCmakeFile(FLAGS_out);
  }

  //dump to dest file

  ShutDownCommandLineFlags();
  cout << "skyctr convertor exit" << endl;
  return 0;
}
