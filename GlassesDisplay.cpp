#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "GlassesDisplay.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int barcode) {
  return (barcode / 1000000) % 10;
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
Glasses::Glasses(string glassesColor, string glassesShape, string glassesBrand, unsigned int barcode): glassesColor_(glassesColor), glassesShape_(glassesShape), glassesBrand_(glassesBrand), barcode_(barcode)
{};

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
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

void GlassesDisplay::addGlasses(string glassesColor, string glassesShape, string glassesBrand, unsigned int barcode) {
    Glasses new_glasses(glassesColor, glassesShape, glassesBrand, barcode);
}


bool GlassesDisplay::removeGlasses(unsigned int barcode) {

}

unsigned int GlassesDisplay::bestHashing() {

}


// ALREADY COMPLETED
size_t GlassesDisplay::size() {
  if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size())|| (hT1.size() != hT6.size()) || (hT1.size() != hT7.size()))
    throw std::length_error("Hash table sizes are not the same");
	return hT1.size();
}