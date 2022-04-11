#ifndef FACTORY_HPP_INCLUDED
#define FACTORY_HPP_INCLUDED

#include <memory>
#include "cstr.hpp"
using namespace std;

namespace cstr_hori_vert {

  class Factory {
  public:
    virtual CString* Create(const char* tmp, const int len, const string filename) const = 0;

    Factory() = default;
    virtual ~Factory() = default;
  };

}

#endif
