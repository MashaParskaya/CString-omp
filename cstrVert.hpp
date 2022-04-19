#ifndef CSTR_VERT_HPP_INCLUDED
#define CSTR_VERT_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include "cstr.hpp"
#include "cstrHori.hpp"

using namespace std;

namespace cstr_hori_vert{

  class CStringV final : public CString {
  public:
    using CString::operator=;

    //CStringV operator+ (CString& a);

    virtual void output(const char *FILE_NAME=NULL) override final;

    CStringV(const char* tmp, int len, string filename="STDOUT");

    CStringV(const CString &tmp);

    CStringV();

    ~CStringV();
  };

}

#endif
