#include "cstrHori.hpp"
#include "omp.h"

namespace cstr_hori_vert{
  CStringH operator+ (CString& a, CString& b){
    CStringH ans;
    ans.set_str(a.get_length() + b.get_length());
    ans.set_filename(a.get_filename());
    omp_set_num_threads(4);
    #pragma omp parallel for
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

  CStringH simple_plus(CString& a, CString& b){
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

}
