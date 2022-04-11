#include "autotest.hpp"
#include "omp.h"
#include <chrono>

int test1(){
  constexpr int n = 10;
  char b[n];
  for (int i = 0; i < n; i++){
    b[i] = 'a';
  }
  CStringH s(b, n);
  if (s.get_length() != n){
    cout << "TEST 1 ERROR\n";
    return 0;
  }
  for (int i = 0; i < n; i++){
    if (s.get_element(i) != b[i]){
      cout << "TEST 1 ERROR\n";
      return 0;
    }
  }
  cout << "TEST 1 CORRECT\n";
  return 0;
}

int test2(){
  constexpr int n = 10;
  char b[n];
  for (int i = 0; i < n; i++){
    b[i] = 'a';
  }
  CStringH s(b, n);
  if (s.get_length() != n){
    cout << "TEST 2 ERROR\n";
    return 0;
  }
  CStringH s1(s);
  if (s1.get_length() != n){
    cout << "TEST 2 ERROR\n";
    return 0;
  }
  for (int i = 0; i < n; i++){
    if (s1.get_element(i) != b[i]){
      cout << "TEST 2 ERROR\n";
      return 0;
    }
  }
  cout << "TEST 2 CORRECT\n";
  return 0;
}

int test3(){
  constexpr int n = 10;
  char b[n];
  for (int i = 0; i < n; i++){
    b[i] = 'a';
  }
  CStringV s(b, n);
  if (s.get_length() != n){
    cout << "TEST 3 ERROR\n";
    return 0;
  }
  CStringV s1 = s;
  if (s1.get_length() != n){
    cout << "TEST 3 ERROR\n";
    return 0;
  }
  for (int i = 0; i < n; i++){
    if (s1.get_element(i) != b[i]){
      cout << "TEST 3 ERROR\n";
      return 0;
    }
  }
  cout << "TEST 3 CORRECT\n";
  return 0;
}

int test4(){
  constexpr int n = 10;
  constexpr int m = 5;
  char b[n];
  char c[m];
  for (int i = 0; i < n; i++){
    b[i] = 'a';
  }
  for (int i = 0; i < m; i++){
    c[i] = '1';
  }
  CStringV s(b, n);
  CStringV s1(c, m);
  if (s.get_length() != n){
    cout << "TEST 4 ERROR\n";
    return 0;
  }
  if (s1.get_length() != m){
    cout << "TEST 4 ERROR\n";
    return 0;
  }
  CStringV s2(s);
  s2 = s + s1;
  if (s2.get_length() != n + m){
    cout << "TEST 4 ERROR\n";
    return 0;
  }
  for (int i = 0; i < n; i++){
    if (s2.get_element(i) != b[i]){
      cout << "TEST 4 ERROR\n";
      return 0;
    }
  }
  for (int i = 0; i < m; i++){
    if (s2.get_element(n + i) != c[i]){
      cout << "TEST 4 ERROR\n";
      return 0;
    }
  }
  cout << "TEST 4 CORRECT\n";
  return 0;
}

int test5(){
  string b = "aaaaaaaaaa";
  CStringH s;
  s = b;
  if (s.get_length() != b.size()){
    cout << "TEST 5 ERROR\n";
    return 0;
  }
  for (int i = 0; i < s.get_length(); i++){
    if (s.get_element(i) != b[i]){
      cout << "TEST 5 ERROR\n";
      return 0;
    }
  }
  cout << "TEST 5 CORRECT\n";
  return 0;
}

int test6(){
  string b = "aaaaaaaaaa";
  CStringV s;
  s = b;
  CStringH sH(s);
  sH.output("CString_test6.test");
  ifstream fin;
  fin.open("CString_test6.test", ios::in);
  string tmp;
  getline(fin, tmp);
  fin.close();
  remove("CString_test6.test");
  if (tmp == b){
    cout << "TEST 6 CORRECT\n";
  }
  else{
    cout << "TEST 6 ERROR\n";
  }
  return 0;
}

int test7(){
  string b = "aaaaaaaaaa";
  CStringH s;
  s = b;
  CStringV sV(s);
  sV.output("CString_test7.test");
  ifstream fin;
  fin.open("CString_test7.test", ios::in);
  string tmp;
  string it;
  while (getline(fin, it)){
    tmp += it;
  }
  fin.close();
  remove("CString_test7.test");
  if (tmp == b){
    cout << "TEST 7 CORRECT\n";
  }
  else{
    cout << "TEST 7 ERROR\n";
  }
  return 0;
}

CStringH test_plus(CString& a, CString& b){
  CStringH ans;
  ans.set_str(a.get_length() + b.get_length());
  ans.set_filename(a.get_filename());
  for(int i = 0; i < a.get_length() + b.get_length(); i++){
    if (i < a.get_length())
    {
      ans.set_element(i, a.get_element(i));
    }
    else
    {
      ans.set_element(i, b.get_element(i - a.get_length()));
    }
  }
  return ans;
}

int parallel_test(long long len){
  cout << "Please, wait" << endl;
  char* a = new char[len];
  char* b = new char[len];
  for (int i = 0; i < len; i++){
    a[i] = 'a';
    b[i] = 'b';
  }
  CStringH s1(a, len);
  CStringH s2(b, len);
  CStringH s_res_1;
  CStringH s_res_2;
  auto start_time = chrono::high_resolution_clock::now();
  auto elapsed_time = chrono::high_resolution_clock::now() - start_time;
  long long ns = chrono::duration_cast<chrono::microseconds>(elapsed_time).count();
  start_time = chrono::high_resolution_clock::now();
  s_res_1 = test_plus(s1, s2);
  elapsed_time = chrono::high_resolution_clock::now() - start_time;
  ns = chrono::duration_cast<chrono::microseconds>(elapsed_time).count();
  cout << "Time consumed without omp to concenate 2 strings of length " << len << ": " << ns << "ms" << endl;

  start_time = chrono::high_resolution_clock::now();
  s_res_2 = s1 + s2;
  elapsed_time = chrono::high_resolution_clock::now() - start_time;
  ns = chrono::duration_cast<chrono::microseconds>(elapsed_time).count();
  cout << "Time consumed with omp to concenate 2 strings of length " << len << ":    " << ns << "ms" << endl;

  delete []a;
  delete []b;
  return 1;
}

void Autotest(){
  cout << "Testing...\n";
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  parallel_test(100000000);
  cout << "Testing completed\n";
}
