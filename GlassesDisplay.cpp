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


}

unsigned int GlassesDisplay::bestHashing() {
}


// ALREADY COMPLETED
size_t GlassesDisplay::size() {
  if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size())|| (hT1.size() != hT6.size()) || (hT1.size() != hT7.size()))
    throw std::length_error("Hash table sizes are not the same");
	return hT1.size();
}