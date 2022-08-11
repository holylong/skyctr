#include <skyctr_vcxproj_parser.hpp>
#include <tinyxml2.h>
#include <spdlog/spdlog.h>

using namespace std;
using namespace tinyxml2;

namespace sky{
  namespace core{

    std::shared_ptr<Target> SkyctrVcxprojParser::QueryHeaders(tinyxml2::XMLDocument* doc)          
    {
        shared_ptr<Target> res = make_shared<Target>();
        XMLElement* root = doc->FirstChildElement("Project");
        TargetInfo info;
        XMLElement* item = root->FirstChildElement("PropertyGroup");
        while (item != NULL) {
            if (item->FirstChildElement("RootNamespace") != NULL) {
                XMLElement* namenode = item->FirstChildElement("RootNamespace");
                info._target_name = namenode->GetText();
                res.get()->m_projectname = namenode->GetText();
            }
            if (item->FirstChildElement("ProjectName") != NULL) {
                XMLElement* namenode = item->FirstChildElement("ProjectName");
                info._target_name = namenode->GetText();
                res.get()->m_projectname = namenode->GetText();
            }

            item = item->NextSiblingElement("PropertyGroup");
        }

        item = root->FirstChildElement("PropertyGroup");
        while (item != NULL) {
            if (item->FirstChildElement("ConfigurationType") != NULL) {
                XMLElement* namenode = item->FirstChildElement("ConfigurationType");
                spdlog::debug("==>> config type:{}", namenode->GetText());
                if (strcmp(namenode->GetText(), "Application") == 0) {
                    info._target_type = Type_Exec;
                }
                else if (strcmp(namenode->GetText(), "StaticLibrary")) {
                    info._target_type = Type_Static_Library;
                }
                else if (strcmp(namenode->GetText(), "DynamicLibrary") == 0) {
                    info._target_type = Type_Shared_Library;
                }
            }
            item = item->NextSiblingElement("PropertyGroup");
        }

        item = root->FirstChildElement("ItemGroup");
        while (item != NULL) {
            if (item->FirstChildElement("ClInclude") == NULL) {
                item = item->NextSiblingElement("ItemGroup");
            }
            else {
                XMLElement* srcnode = item->FirstChildElement("ClInclude");
                while (srcnode != NULL) {
                    string src = srcnode->Attribute("Include");
                    //spdlog::debug("==>>source:{}", src);
                    info.m_header.push_back(src);
                    srcnode = srcnode->NextSiblingElement("ClInclude");
                }
                item = item->NextSiblingElement("ItemGroup");
            }
        }
        res.get()->m_targets.push_back(info);
        return res;
    }

    std::shared_ptr<Target> SkyctrVcxprojParser::QueryProps(tinyxml2::XMLDocument* doc)
    {
        shared_ptr<Target> res = make_shared<Target>();
        //shared_ptr<Target> res = NULL;
        XMLElement* root = doc->FirstChildElement("Project");

        XMLElement* item = root->FirstChildElement("ImportGroup");
        while (item != NULL) {
            if (item->FirstChildElement("Import") != NULL) {
                XMLElement* propsnode = item->FirstChildElement("Import");
                while (propsnode != NULL) {
                    string src = propsnode->Attribute("Project");
                    spdlog::debug("==>> props:{}", src);
                    //info.m_header.push_back(src);
                    propsnode = propsnode->NextSiblingElement("Import");
                }
            }
            item = item->NextSiblingElement("Import");
        }

        return res;
    }

    std::shared_ptr<Target> SkyctrVcxprojParser::QuerySources(tinyxml2::XMLDocument* doc)          
    {
        shared_ptr<Target> res = make_shared<Target>();
        //shared_ptr<Target> res = NULL;
        XMLElement* root = doc->FirstChildElement("Project");
        TargetInfo info;
        //res.get()->m_targets.push_back();

        //project name
        XMLElement* item = root->FirstChildElement("PropertyGroup");
        while (item != NULL) {
            if (item->FirstChildElement("RootNamespace") != NULL) {
                XMLElement* namenode = item->FirstChildElement("RootNamespace");
                info._target_name = namenode->GetText();
                res.get()->m_projectname = namenode->GetText();
            }
            if (item->FirstChildElement("ProjectName") != NULL) {
                XMLElement* namenode = item->FirstChildElement("ProjectName");
                info._target_name = namenode->GetText();
                res.get()->m_projectname = namenode->GetText();
            }
            
            item = item->NextSiblingElement("PropertyGroup");
        }

        //project type
        item = root->FirstChildElement("PropertyGroup");
        while (item != NULL) {
            if (item->FirstChildElement("ConfigurationType") != NULL) {
                XMLElement* namenode = item->FirstChildElement("ConfigurationType");
                spdlog::debug("==>> config type:{}", namenode->GetText());
                if (strcmp(namenode->GetText(), "Application") == 0) {
                    info._target_type = Type_Exec;
                }
                else if (strcmp(namenode->GetText(), "StaticLibrary") == 0) {
                    info._target_type = Type_Static_Library;
                }
                else if (strcmp(namenode->GetText(), "DynamicLibrary") == 0) {
                    info._target_type = Type_Shared_Library;
                }
            }
            item = item->NextSiblingElement("PropertyGroup");
        }
        
        //project source
        item = root->FirstChildElement("ItemGroup");
        while(item != NULL){
            if (item->FirstChildElement("ClCompile") == NULL) {
                item = item->NextSiblingElement("ItemGroup");
            }
            else {
                XMLElement* srcnode = item->FirstChildElement("ClCompile");
                while(srcnode != NULL) {
                    string src = srcnode->Attribute("Include");
                    //spdlog::debug("==>>source:{}", src);
                    info.m_source.push_back(src);
                    srcnode = srcnode->NextSiblingElement("ClCompile");
                }
                item = item->NextSiblingElement("ItemGroup");
            }
        }

        //res.reset(&info);
        //res = make_shared<Target>(info);
        //res = move(make_shared<Target>(&info));
        //res = shared_ptr<Target>(&info);
        res.get()->m_targets.push_back(info);
        return res;
    }
    std::shared_ptr<Target> SkyctrVcxprojParser::QueryIncludes(tinyxml2::XMLDocument* doc)          
    {
        shared_ptr<Target> res = make_shared<Target>();
        //include dir
        XMLElement* root = doc->FirstChildElement("Project");
        TargetInfo info;
        //project name
        XMLElement* item = root->FirstChildElement("ItemDefinitionGroup");
        XMLElement* compileNode;
        while (item != NULL) {
            if ((compileNode = item->FirstChildElement("ClCompile")) != NULL) {
                XMLElement* namenode = compileNode->FirstChildElement("AdditionalIncludeDirectories");
                if(namenode != NULL){
                    spdlog::debug("==>> text:{}", namenode->GetText());
                    info.m_include.push_back(namenode->GetText());
                }
            }
            
            item = item->NextSiblingElement("ItemDefinitionGroup");
        }
        res.get()->m_targets.push_back(info);
        spdlog::debug("river ok");
        return res;
    }
    std::shared_ptr<Target> SkyctrVcxprojParser::QueryLibraries(tinyxml2::XMLDocument* doc)
    {
        shared_ptr<Target> res = make_shared<Target>();
        return res;
    }
    std::shared_ptr<Target> SkyctrVcxprojParser::QueryLibPaths(tinyxml2::XMLDocument* doc)          
    {
        shared_ptr<Target> res = make_shared<Target>();
        return res;
    }
    std::shared_ptr<Target> SkyctrVcxprojParser::QueryCFlags(tinyxml2::XMLDocument* doc)          
    {
        return NULL;
    }
    std::shared_ptr<Target> SkyctrVcxprojParser::QueryCXXFlags(tinyxml2::XMLDocument* doc)
    {
        shared_ptr<Target> res = make_shared<Target>();
        //include dir
        XMLElement* root = doc->FirstChildElement("Project");
        TargetInfo info;
        //project name
        XMLElement* item = root->FirstChildElement("ItemDefinitionGroup");
        XMLElement* compileNode;
        while (item != NULL) {
            if ((compileNode = item->FirstChildElement("ClCompile")) != NULL) {
                XMLElement* namenode = compileNode->FirstChildElement("PreprocessorDefinitions");
                if (namenode != NULL) {
                    spdlog::debug("==>> text:{}", namenode->GetText());
                    info.m_cxxflag.push_back(namenode->GetText());
                }
            }

            item = item->NextSiblingElement("ItemDefinitionGroup");
        }
        res.get()->m_targets.push_back(info);
        spdlog::debug("river ok");
        return res;
        return res;
    }

    void SkyctrVcxprojParser::PrintSample(tinyxml2::XMLDocument* doc)
    {
        doc->Print();

        spdlog::debug("errorid:{}",doc->ErrorID());

        spdlog::debug("first child:{}",doc->FirstChild()->ToDeclaration()->Value());
        spdlog::debug("first child ele:{}",doc->FirstChildElement()->Value());
        spdlog::debug("first child ele:{}",doc->FirstChildElement()->FirstChildElement()->Value());
        spdlog::debug("first child ele 2:{1} _ {0}",doc->FirstChildElement()->FirstChildElement()->FirstChildElement()->Attribute("Include"),
            doc->FirstChildElement()->FirstChildElement()->FirstChildElement()->Value());

        XMLElement* root = doc->FirstChildElement("Project");
        spdlog::debug("next ele 1:{}",root->FirstChildElement("PropertyGroup")->Value());
        spdlog::debug("next ele 2:{}",root->FirstChildElement("PropertyGroup")->Attribute("Label"));

        spdlog::debug("next ele 3:{}",root->FirstChildElement("PropertyGroup")->NextSiblingElement("PropertyGroup")->Attribute("Condition"));
        spdlog::debug("next ele 4:{}",root->FirstChildElement("PropertyGroup")->NextSiblingElement("PropertyGroup")->NextSiblingElement("PropertyGroup")->Attribute("Condition"));
        spdlog::debug("next ele 5:{}",root->FirstChildElement("PropertyGroup")->NextSiblingElement("ImportGroup")->Attribute("Label"));
        spdlog::debug("item group:{}",root->FirstChildElement("ItemGroup")->NextSiblingElement("ItemGroup")->FirstChildElement()->Attribute("Include"));
        spdlog::debug("item group:{}",root->FirstChildElement("ItemGroup")->NextSiblingElement("ItemGroup")->FirstChildElement()->NextSiblingElement()->Attribute("Include"));
        spdlog::debug("item group:{}",root->FirstChildElement("ItemGroup")->NextSiblingElement("ItemGroup")->NextSiblingElement("ItemGroup")->FirstChildElement()->Attribute("Include"));

        if (root->FirstChildElement("ItemGroup")->NextSiblingElement("ItemGroup")->NextSiblingElement("ItemGroup")->FirstChildElement()->NextSiblingElement() == NULL) {
            spdlog::debug("cannot find next cpp");
        }
        else {
            spdlog::debug("find next cpp ok");
        }
        spdlog::debug("last ele:{}",doc->LastChildElement()->Value());
    }

    //template<typename T>
    std::shared_ptr<Target> SkyctrVcxprojParser::ParseFile(const std::string path)
    {
        //cout << "type:" << typeid(T).name() << endl;
        spdlog::debug("parse:{}", path.c_str());
        XMLDocument doc;
        doc.LoadFile(path.c_str());

        //PrintSample(&doc);

        //shared_ptr<Target> art;

        auto art = QuerySources(&doc);
        spdlog::debug("parse source ok");
        auto target = QueryHeaders(&doc);
        if (target == NULL && art == NULL)
            return NULL;

        if(art != NULL && target != NULL){
            Target* artp = art.get();
            *artp += *(target.get());
        }
        spdlog::debug("parse header ok");

        target.reset();
        target = QueryProps(&doc);
        if (art != NULL && target != NULL) {
            Target* artp = art.get();
            *artp += *(target.get());
        }
        spdlog::debug("parse props ok");
        target.reset();
        target = QueryIncludes(&doc);
        target->MergeIncludes();
        if (art != NULL && target != NULL) {
            Target* artp = art.get();
            *artp += *(target.get());
        }
        spdlog::debug("parse include ok");

        target.reset();
        target = QueryCXXFlags(&doc);
        target->MergeCxxFlags();
        if (art != NULL && target != NULL) {
            Target* artp = art.get();
            *artp += *(target.get());
        }

        spdlog::debug("parse props ok");
        art->PrintAll();
        
        return art;
    }

    //template<typename T>
    //SkyctrVcxprojParser<T>::SkyctrVcxprojParser()
    //{
    //    cout << "type:{}",typeid(T).name() << endl;
    //}
  }
}


