#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

#include "GlassesDisplay.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

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
Glasses::Glasses(string glassesColor, string glassesShape, string glassesBrand, unsigned int barcode): glassesColor_(glassesColor), glassesShape_(glassesShape), glassesBrand_(glassesBrand), barcode_(barcode)
{};
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
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

void GlassesDisplay::addGlasses(string glassesColor, string glassesShape, string glassesBrand, unsigned int barcode) {
  Glasses new_glasses(glassesColor, glassesShape, glassesBrand, barcode);
  
  hT1[hashfct1(barcode)] = new_glasses;
  hT2[hashfct2(barcode)] = new_glasses;
  hT3[hashfct3(barcode)] = new_glasses;
  hT4[hashfct4(barcode)] = new_glasses;
  hT5[hashfct5(barcode)] = new_glasses;
  hT6[hashfct6(barcode)] = new_glasses;
  hT7[hashfct7(barcode)] = new_glasses;
}

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
    }
    return false;
}

unsigned int GlassesDisplay::bestHashing() {
    // Array of pointers to each of the hash tables
    CustomHashTable* hashTables[7] = {&hT1, &hT2, &hT3, &hT4, &hT5, &hT6, &hT7};
    unsigned int bestHashTableIndex = 0;
    size_t minBalance = static_cast<size_t>(-1);  // Initialize to the maximum possible value

    // Iterate through each hash table
    for (unsigned int i = 0; i < 7; i++) {
        size_t maxBucketSize = 0;
        size_t minBucketSize = static_cast<size_t>(-1);  // Initialize to the maximum possible value

        // Check only the first 10 buckets, or fewer if the hash table is smaller
        unsigned int numBucketsToCheck = static_cast<unsigned int>(std::min(static_cast<size_t>(10), hashTables[i]->bucket_count()));
        for (unsigned int j = 0; j < numBucketsToCheck; j++) {
            size_t bucketSize = hashTables[i]->bucket_size(j);
            if (bucketSize > maxBucketSize) {
                maxBucketSize = bucketSize;  // Update max bucket size found
            }
            if (bucketSize < minBucketSize) {
                minBucketSize = bucketSize;  // Update min bucket size found
            }
        }

        size_t currentBalance = maxBucketSize - minBucketSize;  // Current balance of the hash table
        if (currentBalance < minBalance) {
            minBalance = currentBalance;
            bestHashTableIndex = i + 1;  // Update the index of the best hash table
        }
    }

    return bestHashTableIndex;
}

size_t GlassesDisplay::size() {
  if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size())|| (hT1.size() != hT6.size()) || (hT1.size() != hT7.size()))
    throw std::length_error("Hash table sizes are not the same");
	return hT1.size();
}



