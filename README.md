[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/6eDWscw1)

# Project 3 - Balanced Glasses Display

This project focuses on the implementation of an algorithm related to hash tables. There are different hash functions that will produce hash chains of various length when the same dataset is given.

Group members:

Erik Williams

epwilliams@csu.fullerton.edu

## Implementation

-main.cpp contains tests to check on the correctness of the function members. This is provided for you to use to test your software as you are writing it. You may change this file to add helpful functions for your own testing. I will test your project with a different but similar file.
-GlassesDisplay.cpp and GlassesDisplay.hpp contain the skeleton of the classes and function member
-in1.txt contains 18 types of glasses
-in2.txt contains 36 types of glasses

-The code to decide which digit leads to the most balanced hashtable is to be implemented in class . Since you will be comparing seven hashtables (which differ only in their hash function), class GlassesDisplay only has seven hash tables as its member variables. The other member functions are:
-addGlasses(): Given information about one pair of glasses, create a Glasses object and insert into each of the seven hashtables. Note that each hash table has the product number as the key and a Glasses object as the value. To be completed.
-removeGlasses(): Given product number, remove the corresponding pair of glasses from each of the seven hashtables. To be completed.
-bestHashing(): The logic to calculate the balance for each of the seven hashtables, and then identifying the hashtable with the best balance should go into this method. Here, balance is defined as the difference between the sizes of the largest bucket and smallest bucket. Only check the first 10 buckets! (If the lowest balance factor is shared by more than one hash table, then return the first hash table with that lowest balance factor. For example, if both hT3 and hT7 have the lowest balance factor, then return the number 3. If hT2, hT4, and ht6 all share the lowest balance factor, then return the number 2.) Some hints on how to get the number of items in each bucket are included. To be completed.
-readTextfile(): The list of pairs of glasses are in a text file. This method calls addGlasses() for each line. The code to read from the text file is already given.

The seven hash tables will differ in only the hash function that they will use. You are to provide code for these hash functions. Each hash function will take a 7-digit number and return either the first, second, etc. , seventh (last) digit.
-hashfct1(number): return the first digit of number. To be completed.
-hashfct2(number): return the second digit of number. To be completed.
-hashfct3(number): return the third digit of number. To be completed.
-hashfct4(number): return the fourth digit of number. To be completed.
-hashfct5(number): return the fifth digit of number. To be completed.
-hashfct6(number): return the fourth digit of number. To be completed.
-hashfct7(number): return the fifth digit of number. To be completed.
