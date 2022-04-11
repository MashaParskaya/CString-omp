#ifndef FACTORY_VERT_HPP_INCLUDED
#define FACTORY_VERT_HPP_INCLUDED

#include "factory.hpp"
#include "cstr.hpp"
#include "cstrVert.hpp"

using namespace std;

namespace cstr_hori_vert{

  class FactoryVert : public Factory {
  public:
    virtual CString* Create(const char* tmp, const int len, const string filename) const override final {
      return new CStringV(tmp, len, filename);
    }

    FactoryVert() = default;
    ~FactoryVert() = default;
  };

}

#endif
