#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;
using namespace std;

int main(int argc, char* argv[])
{
  json j;
  ifstream ifs("test.json");
  ifs >> j;
  cout << "json:" << j.dump() << endl;
  return 0;
}