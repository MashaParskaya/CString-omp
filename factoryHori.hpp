#ifndef FACTORY_HORI_HPP_INCLUDED
#define FACTORY_HORI_HPP_INCLUDED

#include "factory.hpp"
#include "cstr.hpp"
#include "cstrHori.hpp"

using namespace std;

namespace cstr_hori_vert{

  class FactoryHori : public Factory {
  public:
    virtual CString* Create(const char* tmp, const int len, const string filename) const override final {
      return new CStringH(tmp, len, filename);
    }

    FactoryHori() = default;
    ~FactoryHori() = default;
  };

}

#endif
