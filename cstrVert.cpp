#include "cstrVert.hpp"

namespace cstr_hori_vert{

  void CStringV::output(const char *FILE_NAME){
    if (FILE_NAME != "STDOUT" && FILE_NAME != NULL){
      ofstream fout;
      fout.open(FILE_NAME, ios::app);
      if (!fout.is_open()){
        cout << "Error! Cannot open file!\n";
      }
      else{
        for (int i = 0; i < this->get_length(); i++){
          fout << this->get_element(i) << endl;
        }
      }
      fout.close();
    }
    else{
      for (int i = 0; i < this->get_length(); i++){
        cout << this->get_element(i) << endl;
      }
    }
  }

  /*CStringV CStringV::operator+ (CString& a){
    CStringV ans;
    ans.set_str(a.get_length() + get_length());
    for(int i = 0; i < get_length(); i++){
      ans.set_element(i, get_element(i));
    }
    for(int i = 0; i < a.get_length(); i++){
      ans.set_element(get_length() + i, a.get_element(i));
    }
    return ans;
  }*/

  CStringV::CStringV(const char* tmp, int len, string filename) : CString(tmp, len, filename){}

  CStringV::CStringV(CString &tmp) : CString(tmp){}

  CStringV::CStringV() : CString(){}

  CStringV::~CStringV(){}
}
