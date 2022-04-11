#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include "omp.h"

#include "cstrHori.hpp"
#include "cstrVert.hpp"
#include "cstr.hpp"
#include "operator_plus.hpp"
#include "autotest.hpp"
#include "factory.hpp"
#include "FactoryHori.hpp"
#include "FactoryVert.hpp"

using namespace std;
using namespace cstr_hori_vert;

int main(){
  Autotest();

  map< string, Factory* > factoryMap;
  factoryMap["Hori"] = new FactoryHori();
  factoryMap["Vert"] = new FactoryVert();
  vector<CString*> strVector;

  string datafile;
  cin >> datafile;
  ifstream fin;
  fin.open(datafile.c_str(), ios::in);
  if (!fin.is_open()){
    cout << "Error! Cannot open file!\n";
    return 0;
  }
  string tmp;
  while (getline(fin, tmp)){
    //parse start
    /*
    input data format:

    Hori outputfile1 text_without_spaces_1
    Vert outputfile2 text_without_spaces_2
    ...
    */
    tmp += " ";
    vector<string> parsed = {};
    string tmp_parse = "";
    for (int i = 0; i < tmp.length(); i++){
      if (tmp.at(i) == ' '){
        parsed.push_back(tmp_parse);
        tmp_parse = "";
      }
      else{
        tmp_parse += tmp[i];
      }
    }
    //parse end

    if (parsed.size() != 3) {
      throw invalid_argument("Parsing Error! Wrong amount of arguments!\n");
    }

    auto curFactory = factoryMap.find(parsed[0]);
    if (curFactory == factoryMap.end()) {
      throw invalid_argument("Error! Wrong type of vector in file input.txt!\n");
    }

    auto curStr = curFactory->second->Create(parsed[2].c_str(), parsed[2].length(), parsed[1]);
    strVector.push_back(curStr);
  }
  fin.close();

  #
  for (int i = 0; i < strVector.size(); i++){
        strVector[i]->output(strVector[i]->get_filename().c_str());
  }

  return 1;
}
