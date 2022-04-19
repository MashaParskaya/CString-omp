#ifndef CSTR_HPP_INCLUDED
#define CSTR_HPP_INCLUDED

#include <iostream>
#include <string>
#include "omp.h"

using namespace std;

namespace cstr_hori_vert{

  class CString {
  private:
    int length;
    char* stroka;
    string fileout;
  public:
    void set_str(int len);

    void set_element(int pos, char el);

    void set_filename(string filename);

    char get_element(int pos);

    int get_length();

    string get_filename();

    virtual void output(const char *FILE_NAME=NULL) = 0;

    CString();

    CString(const char* tmp, int len, string filename="STDOUT");

    CString(const CString &tmp);

    CString& operator= (const CString& a);

    CString& operator= (const string& a);

    virtual ~CString();
  };
}

#endif
