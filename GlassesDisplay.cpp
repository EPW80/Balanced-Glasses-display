#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <limits.h>

#include "GlassesDisplay.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::max;
using std::min;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int barcode) {
  return barcode / 1000000;
}

// function to return the hash value based on the second digit
unsigned int hashfct2(unsigned int barcode) {
  return (barcode / 100000) % 10;
}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int barcode) {
  return (barcode / 10000) % 10;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int barcode) {
  return (barcode / 1000) % 10;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int barcode) {
  return (barcode / 100) % 10;
}

// function to return the hash value based on the sixth digit
unsigned int hashfct6(unsigned int barcode) {
  return (barcode / 10) % 10;
}

// function to return the hash value based on the seventh digit
unsigned int hashfct7(unsigned int barcode) {
  return barcode % 10;
}

// Constructor for struct Item
Glasses::Glasses(string glassesColor, string glassesShape, string glassesBrand, unsigned int barcode): glassesColor_(glassesColor), glassesShape_(glassesShape), glassesBrand_(glassesBrand), barcode_(barcode) {};

// Constructor for GlassesDisplay initializes hash tables with predefined hash functions
GlassesDisplay::GlassesDisplay(): hT1(1, hashfct1), hT2(1, hashfct2), hT3(1, hashfct3), hT4(1, hashfct4),
  hT5(1, hashfct5), hT6(1, hashfct6), hT7(1, hashfct7) {}

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
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

// adding the specified pair of glasses to main display
void GlassesDisplay::addGlasses(string glassesColor, string glassesShape, string glassesBrand, unsigned int barcode) {
  Glasses new_glasses = Glasses(glassesColor, glassesShape, glassesBrand, barcode);
  hT1[new_glasses.barcode_] = new_glasses;
  hT2[new_glasses.barcode_] = new_glasses;
  hT3[new_glasses.barcode_] = new_glasses;
  hT4[new_glasses.barcode_] = new_glasses;
  hT5[new_glasses.barcode_] = new_glasses;
  hT6[new_glasses.barcode_] = new_glasses;
  hT7[new_glasses.barcode_] = new_glasses;
}

// remove the specified pair of glasses from main display
bool GlassesDisplay::removeGlasses(unsigned int barcode) {
  if (hT1.find(barcode) != hT1.end()) {
    hT1.erase(barcode);
    hT2.erase(barcode);
    hT3.erase(barcode);
    hT4.erase(barcode);
    hT5.erase(barcode);
    hT6.erase(barcode);
    hT7.erase(barcode);
    return true;
  } else {
    return false;
  }
}

// Helper function to return the hash value based on the first digit
int GlassesDisplay::bucket_count(const CustomHashTable & table) {
  int max_count = 0;   // Tracks the maximum size of the observed buckets.
  int min_count = INT_MAX;  // Tracks the minimum size of the observed buckets.

  // Determine the number of buckets to iterate over. Assumes the hash table can provide this info.
  size_t num_buckets = std::min(table.bucket_count(), size_t(10));

  for (size_t i = 0; i < num_buckets; ++i) {
    auto first = table.begin(i);
    auto last = table.end(i);
    int count = std::distance(first, last);

    // Update the maximum and minimum with the current bucket size.
    max_count = std::max(max_count, count);
    min_count = std::min(min_count, count);
  }

  // Return the difference between the largest and smallest bucket sizes.
  return max_count - min_count;
}

unsigned int GlassesDisplay::bestHashing() {
  unsigned int best_table = 1;
  int best_distance = bucket_count(hT1); // Initializes the best distance to the size of the first table

  int distances[6] = {
    bucket_count(hT2),
    bucket_count(hT3),
    bucket_count(hT4),
    bucket_count(hT5),
    bucket_count(hT6),
    bucket_count(hT7)
  };

  for (unsigned int i = 0; i < 6; ++i) {
    if (distances[i] < best_distance) {
      best_distance = distances[i];
      best_table = i + 2; // +2 because index starts from 0 and table counting starts from 2 here...dp
    }
  }

  std::cout << "Best hash table: " << best_table << std::endl;
  return best_table;
}

// ALREADY COMPLETED
size_t GlassesDisplay::size() {
  if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size()) || (hT1.size() != hT6.size()) || (hT1.size() != hT7.size()))
    throw std::length_error("Hash table sizes are not the same");
  return hT1.size();
}