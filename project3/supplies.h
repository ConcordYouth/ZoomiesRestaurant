#ifndef supplies_h
#define supplies_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Supplies {
 private:
  double balance;
  int bread;
  int meat;
  int vegetables;

 public:
  Supplies(int b, int m, int v, double bal = 10);
  int breadInv();
  void adjustBread(int b);
  int meatInv();
  void adjustMeat(int m);
  int vegetableInv();
  void adjustvegetables(int v);
  double getBalance();
  void adjustBalance(double bal);
  void printInv();
};

#endif
