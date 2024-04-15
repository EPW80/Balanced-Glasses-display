#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "GlassesDisplay.hpp"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

unsigned int hashfct1(unsigned int barcode) {
  return (barcode / 1000000) % 10;
}

unsigned int hashfct2(unsigned int barcode) {
  return (barcode / 100000) % 10;
}

unsigned int hashfct3(unsigned int barcode) {
  return (barcode / 10000) % 10;
}

unsigned int hashfct4(unsigned int barcode) {
  return (barcode / 1000) % 10;
}

unsigned int hashfct5(unsigned int barcode) {
  return (barcode / 100) % 10;
}

unsigned int hashfct6(unsigned int barcode) {
  return (barcode / 10) % 10;
}

unsigned int hashfct7(unsigned int barcode) {
  return barcode % 10;
}
Glasses::Glasses(string glassesColor, string glassesShape, string glassesBrand, unsigned int barcode): glassesColor_(glassesColor), glassesShape_(glassesShape), glassesBrand_(glassesBrand), barcode_(barcode) {};
void GlassesDisplay::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string glassesColor;
    string glassesShape;
    string glassesBrand;
    unsigned int barcode;
    while (myfile >> glassesColor >> glassesShape >> glassesBrand >> barcode) {
      if (glassesColor.size() > 0)
        addGlasses(glassesColor, glassesShape, glassesBrand, barcode);
    }
    myfile.close();
  } else
    throw std::invalid_argument("Could not open file " + filename);
}

void GlassesDisplay::addGlasses(string glassesColor, string glassesShape, string glassesBrand, unsigned int barcode) {
  Glasses new_glasses(glassesColor, glassesShape, glassesBrand, barcode);

  if (hashfct1(barcode) < hT1.size()) {
    hT1[hashfct1(barcode)] = new_glasses;
  }
  if (hashfct2(barcode) < hT2.size()) {
    hT2[hashfct2(barcode)] = new_glasses;
  }
  if (hashfct3(barcode) < hT3.size()) {
    hT3[hashfct3(barcode)] = new_glasses;
  }
  if (hashfct4(barcode) < hT4.size()) {
    hT4[hashfct4(barcode)] = new_glasses;
  }
  if (hashfct5(barcode) < hT5.size()) {
    hT5[hashfct5(barcode)] = new_glasses;
  }
  if (hashfct6(barcode) < hT6.size()) {
    hT6[hashfct6(barcode)] = new_glasses;
  }
  if (hashfct7(barcode) < hT7.size()) {
    hT7[hashfct7(barcode)] = new_glasses;
  }
}

bool GlassesDisplay::removeGlasses(unsigned int barcode) {
  if (hashfct1(barcode) < hT1.size()) {
    hT1.erase(hashfct1(barcode));
  }
  if (hashfct2(barcode) < hT2.size()) {
    hT2.erase(hashfct2(barcode));
  }
  if (hashfct3(barcode) < hT3.size()) {
    hT3.erase(hashfct3(barcode));
  }
  if (hashfct4(barcode) < hT4.size()) {
    hT4.erase(hashfct4(barcode));
  }
  if (hashfct5(barcode) < hT5.size()) {
    hT5.erase(hashfct5(barcode));
  }
  if (hashfct6(barcode) < hT6.size()) {
    hT6.erase(hashfct6(barcode));
  }
  if (hashfct7(barcode) < hT7.size()) {
    hT7.erase(hashfct7(barcode));
  }
  return true;
}

unsigned int GlassesDisplay::bestHashing() {
  CustomHashTable* hash_tables[7] = {&hT1, &hT2, &hT3, &hT4, &hT5, &hT6, &hT7};

  unsigned int best_hash_table_index = 0;
  size_t min_balance = -1; 

  for (unsigned int i = 0; i < 7; ++i) {
    size_t max_bucket_size = 0;
    size_t min_bucket_size = -1; 
    unsigned int bucket_check = (hash_tables[i] -> bucket_count() < 10) ? hash_tables[i] -> bucket_count() : 10;

    for (unsigned int j = 0; j < bucket_check; ++j) {
      size_t bucket_size = hash_tables[i] -> bucket_size(j);
      max_bucket_size = (bucket_size > max_bucket_size) ? bucket_size : max_bucket_size;
      min_bucket_size = (bucket_size < min_bucket_size) ? bucket_size : min_bucket_size;
    }

    size_t balance = max_bucket_size - min_bucket_size;
    if (balance < min_balance) {
      min_balance = balance;
      best_hash_table_index = i;
    }
  }

  return best_hash_table_index + 1;
}

size_t GlassesDisplay::size() {
  // Check if the sizes of the hash tables are equal
  if (hT1.size() == hT2.size() && hT1.size() == hT3.size() && hT1.size() == hT4.size() && hT1.size() == hT5.size() && hT1.size() == hT6.size() && hT1.size() == hT7.size()) {
    return hT1.size();
  } else {
    throw std::length_error("Hash table sizes are not the same");
  }
}