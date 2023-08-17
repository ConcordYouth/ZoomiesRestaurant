#ifndef expense_h
#define expense_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Expense {
 private:
  int bread;
  int meat;
  int vegetables;
  double cost;
  int age;

 public:
  Expense(int b = 1, int m = 2, int v = 3, double c = 4, int a = 5);
  string details();
  int getAge();
  void assignAge(int incrementAge);
  int breadS();
  int meatS();
  int vegetablesS();
  double costS();
};

#endif
