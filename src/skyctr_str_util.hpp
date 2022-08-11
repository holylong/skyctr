#ifndef _SKYCTR_STR_UTIL_HPP_
#define _SKYCTR_STR_UTIL_HPP_

#include <iostream>

namespace sky{
  namespace core{
  class SkyctrStrUtil{
    public:
      // static std::string replace(const std::string& str, const std::string& ch = "\\", const std::string& pl = "/")
      // {
      //   std::string result = str;
      //   size_t pos = result.find(ch);
      //   while(pos != std::string::npos){
      //     result.replace(pos, 1, pl);
      //     pos = result.find(ch);
      //   }

      //   return result;
      // }

      static void replace(std::string& str, const std::string& ch = "\\", const std::string& pl = "/")
      {
        size_t pos = str.find(ch);
        while(pos != std::string::npos){
          str.replace(pos, 1, pl);
          pos = str.find(ch);
        }
      }

      static void strsplit(std::vector<std::string>& res, const std::string& str, const std::string& ch = " ")
      {
          //res.clear();
          std::string orgstr = str;
          size_t bginx = 0;
          while (bginx != std::string::npos) {
              bginx = orgstr.find_first_of(ch);
              res.push_back(orgstr.substr(0, bginx));
              orgstr = orgstr.substr(bginx + 1, orgstr.size() - bginx);
          }
      }
  };
}

}






#endif //_SKYCTR_STR_UTIL_HPP_