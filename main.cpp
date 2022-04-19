#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <chrono>
#include "omp.h"

#include "cstrHori.hpp"
#include "cstrVert.hpp"
#include "cstr.hpp"
#include "operator_plus.hpp"
#include "autotest.hpp"
#include "factory.hpp"
#include "FactoryHori.hpp"
#include "FactoryVert.hpp"
#include "playground.hpp"

using namespace std;
using namespace cstr_hori_vert;

int main(){
  Autotest();

  string datafile;
  getline(cin, datafile);
  ifstream fin;
  fin.open(datafile.c_str(), ios::in);
  if (!fin.is_open()){
    cout << "Error! Cannot open file!\n";
    return 1;
  }
  string first, second;

  getline(fin, first);
  getline(fin, second);

  CStringH s1(first.c_str(), first.length());
  CStringH s2(second.c_str(), second.length());
  CStringH s_res_1, s_res_2;

  // for init not to waste time
  auto start_time = chrono::high_resolution_clock::now();
  auto elapsed_time = chrono::high_resolution_clock::now() - start_time;
  long long mks = chrono::duration_cast<chrono::microseconds>(elapsed_time).count();

  start_time = chrono::high_resolution_clock::now();
  s_res_1 = simple_plus(s1, s2);
  elapsed_time = chrono::high_resolution_clock::now() - start_time;
  mks = chrono::duration_cast<chrono::microseconds>(elapsed_time).count();
  cout << "Time consumed without omp: " << mks << "mks" << endl;

  start_time = chrono::high_resolution_clock::now();
  s_res_2 = s1 + s2;
  elapsed_time = chrono::high_resolution_clock::now() - start_time;
  mks = chrono::duration_cast<chrono::microseconds>(elapsed_time).count();
  cout << "Time consumed with omp:    " << mks << "mks" << endl;

  if (if_to_enable()){
    playgroud_enable();
  }

  return 0;
}
