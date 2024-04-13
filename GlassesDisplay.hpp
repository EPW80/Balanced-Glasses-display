#pragma once
#include <string>
#include <unordered_map>
using std::string;
struct Glasses {
  string glassesColor_;
  string glassesShape_;
  string glassesBrand_;
  unsigned int barcode_;
  Glasses(string glassesColor = "", string glassesShape = "", string glassesBrand = "", unsigned int barcode = 1000000);
};

unsigned int hashfct1(unsigned int);
unsigned int hashfct2(unsigned int);
unsigned int hashfct3(unsigned int);
unsigned int hashfct4(unsigned int);
unsigned int hashfct5(unsigned int);
unsigned int hashfct6(unsigned int);
unsigned int hashfct7(unsigned int);

typedef std::unordered_map<unsigned int, Glasses, decltype(&hashfct1)> CustomHashTable;
class GlassesDisplay {
public:
  void addGlasses(string glassesColor, string glassesShape, string glassesBrand, unsigned int barcode);

  // removes a specified pair of glasses from the main display; if successful,
  // then it returns true; TO BE COMPLETED
  bool removeGlasses(unsigned int barcode);

  // identifies which hash function (among the seven provided, fct1 - fct7)
  // computes the most balanced hash table; TO BE COMPLETED
  unsigned int bestHashing();

  size_t size();

  // Load information from a text file
  // with the given filename; THIS FUNCTION IS COMPLETE
  void readTextfile(string filename);

private:
  CustomHashTable hT1, hT2, hT3, hT4, hT5, hT6, hT7;
  // add other private member variables as needed
};