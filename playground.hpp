#ifndef PLAYGROUND_HPP_INCLUDED
#define PLAYGROUND_HPP_INCLUDED

#include <iostream>
#include <string>
#include <chrono>
#include "cstr.hpp"
#include "cstrVert.hpp"
#include "operator_plus.hpp"

using namespace std;
using namespace cstr_hori_vert;

bool if_to_enable(){
  string line;
  int attempts_left = 3;
  bool result = false;
  while (attempts_left != 0){
    cout << "Do you want to enable sandbox?(y/n):";
    getline(cin, line);
    if (line == "y"){
      result = true;
      break;
    }
    else if (line == "n"){
      break;
    }
    else{
      attempts_left--;
      if (attempts_left != 0){
        cout << "bad attempt, try again\n" << attempts_left << " attempts left\n";
      }
      else{
        cout << "sorry, no attempts left\ngoodbye!\n";
      }
    }
  }
  return result;
}

string parse_string(string& tmp){
  string answer = "";
  int number = 0;
  bool seen_mul = false;
  for (int i = 0; i < tmp.size(); i++){
    if (int(tmp[i]) == 42){
      seen_mul = true;
    }
    else{
      if (seen_mul){
        number *= 10;
        if (int(tmp[i]) <= int('9') || int(tmp[i]) >= int('0'))
          number += int(tmp[i]) - int('0');
        else
          return "*mul went wrong*";
      }
      else{
        answer += tmp[i];
      }
    }
  }
  if (seen_mul){
    if (number == 0){
      return "";
    }
    else{
      string result = "";
      while (number != 0){
        result += answer;
        number--;
      }
      return result;
    }
  }
  else{
    return answer;
  }
}

void playgroud_enable(){
  for (int i = 0; i < 50; i++){
    cout << endl;
  }
  cout << "Wellcome to the sandbox!\nEnter \"help\" for help\n";
  int mode = 0;
  CStringH result;
  while (true){
    cout << "host@sandbox>";
    string line;
    getline(cin, line);
    if (line == "help"){
      cout << "List of commands\n";
      cout << "    help         - for help\n";
      cout << "    chmod plus 0 - to change plus mode to consistent (default consistent)\n";
      cout << "    chmod plus 1 - to change plus mode to parallel (default consistent)\n";\
      cout << "    mode         - to see the set mode\n";
      cout << "    compute      - to compute the sum of two strings (multiplying string by an int is enabled, space is enterprited as a symbol, * as a math operator)\n";
      cout << "    print        - to print the last computed string (CAUTION it can be very long)\n";
      cout << "    quit         - to quit sandbox\n";
    }
    else if (line == "chmod plus 0"){
      mode = 0;
    }
    else if (line == "chmod plus 1"){
      mode = 1;
    }
    else if (line == "mode") {
      if (mode == 1){
        cout << "parallel\n";
      }
      else{
        cout << "consistent\n";
      }
    }
    else if (line == "compute"){
      string first, second;
      cin >> first;
      cin >> second;
      first = parse_string(first);
      if (first == "*mul went wrong*" || first == ""){
        cout << "ERROR: cannot convert string to int\n";
        cout << first;
        continue;
      }
      second = parse_string(second);
      if (second == "*mul went wrong*" || second == ""){
        cout << "ERROR: cannot convert string to int\n";
        cout << first;
        continue;
      }
      CStringH s1;
      s1 = first;
      CStringH s2;
      s2 = second;
      auto start_time = chrono::high_resolution_clock::now();
      auto elapsed_time = chrono::high_resolution_clock::now() - start_time;
      long long ms = chrono::duration_cast<chrono::microseconds>(elapsed_time).count();
      start_time = chrono::high_resolution_clock::now();
      if (mode == 1){
        start_time = chrono::high_resolution_clock::now();
        result = s1 + s2;
        elapsed_time = chrono::high_resolution_clock::now() - start_time;
        ms = chrono::duration_cast<chrono::microseconds>(elapsed_time).count();
        cout << "Time consumed: " << ms << "mks" << endl;
      }
      else{
        start_time = chrono::high_resolution_clock::now();
        result = simple_plus(s1, s2);
        elapsed_time = chrono::high_resolution_clock::now() - start_time;
        ms = chrono::duration_cast<chrono::microseconds>(elapsed_time).count();
        cout << "Time consumed: " << ms << "mks" << endl;
      }
    }
    else if (line == "print"){
      result.output();
    }
    else if (line == "quit"){
      cout << "goodbye!";
      break;
    }
    else if (line != ""){
      cout << "Wromg command, try again\n";
    }
  }
}

#endif
