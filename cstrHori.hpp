#ifndef CSTR_HORI_HPP_INCLUDED
#define CSTR_HORI_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include "cstr.hpp"

using namespace std;

namespace cstr_hori_vert{

  class CStringH final : public CString {
  public:
    using CString::operator=;

    //CStringH operator+ (CString& a);

    virtual void output(const char *FILE_NAME=NULL) override final;

    CStringH();

    CStringH(const char* tmp, int len, string filename="STDOUT");

    CStringH(CString &tmp);

    ~CStringH();
  };

}

#endif
