/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-14
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 * 
 * 
 */
#include <iostream>
#include <gflags/gflags.h>
#include <skyctr_factory.hpp>
#include <skyctr_manager.hpp>
#include <skyctr_logger.hpp>
#include <skyctr_vcxproj_parser.hpp>
// #include <easylogging++.h>
//read build tool file to memory and save to cmake file

using namespace std;
using namespace gflags;
using namespace sky::core;

// INITIALIZE_EASYLOGGINGPP



DEFINE_string(origin, "vcxproj", "origin build file type");
DEFINE_string(path, "All.vcxproj", "origin file");
DEFINE_string(out, "CMakeLists.txt", "output file");
DEFINE_string(gen, "cmake", "to build file type");
DEFINE_string(license, "license", "license file");

static std::string g_version;
static std::string g_help;

std::string& getVersion() {
  g_version = "0.0.1";
  return g_version;
}
//-origin xml -path ..\examples\data\xml\styles.xml -gen cmake -out CMakeList.txt
//-origin vcxproj -path ..\examples\data\vcxproj\tinyxml2.vcxproj -gen cmake -out CMakeList.txt
//-origin vcxproj -path ..\examples\data\vcxproj\2015Remote.vcxproj -gen cmake -out CMakeList.txt
std::string& getHelp(char* argv[]) {
  g_help = "help message \r\r\r\r\n\nskyctr meson.build -g cmake -o CMakeList.txt\n";
  g_help += std::string(argv[0]);
  g_help += " -origin make -path Makefile -gen cmake -out CMakeLists.txt --license license.md\n";
  g_help += " -origin xml -path ..\\examples\\data\\xml\\styles.xml -gen cmake -out CMakeLists.txt --license license.md";
  return g_help;
}

int main(int argc, char* argv[])
{
  cout << "skyctr convertor enter" << endl;
  sky::InitLogger();
  sky::LoggerTest();
  SetVersionString(getVersion());
  SetUsageMessage(getHelp(argv));

  ParseCommandLineFlags(&argc, &argv, true);
  cout << "origin = " << FLAGS_origin << endl;
  cout << "path = " << FLAGS_path << endl;
  cout << "out = " << FLAGS_out << endl;
  cout << "gen = " << FLAGS_gen << endl;

  SkyctrFactory skyctrFactory;

  SkyctrManager *manager = skyctrFactory.makeSkyctrManager();
  
  //parse origin file
  if(FLAGS_origin == "make"){
    manager->ParseMakeFile(FLAGS_path);
  }else if(FLAGS_origin == "meson"){
    manager->ParseMesonFile(FLAGS_path);
  }else if(FLAGS_origin == "vcxproj"){
      //std::unique_ptr<SkyctrVcxprojParser> parser(new SkyctrVcxprojParser());
    //manager->ParseVcxprojFile(FLAGS_path, std::move(std::make_unique<SkyctrVcxprojParser>()));
      //manager->ParseVcxprojFile(FLAGS_path, std::move(parser));
      manager->ParseVcxprojFile(FLAGS_path);
  }else if(FLAGS_origin == "ninja"){
    manager->ParseNinjaFile(FLAGS_path);
  }else if (FLAGS_origin == "xml") {
      manager->ParseXmlFile(FLAGS_path);
  }

  if(FLAGS_gen == "cmake"){
    manager->DumpCmakeFile(FLAGS_out, FLAGS_license);
  }

  //dump to dest file

  ShutDownCommandLineFlags();
  cout << "skyctr convertor exit" << endl;
  return 0;
}
