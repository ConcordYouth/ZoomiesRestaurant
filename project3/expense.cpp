#include "expense.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Expense::Expense(int b, int m, int v, double c, int a) {
  bread = b;
  meat = m;
  vegetables = v;
  cost = c;
  age = a;
}
string Expense::details() {
  string num_text = to_string(cost);
  string rounded = num_text.substr(0, num_text.find(".") + 3);
  string order = to_string(bread) + " slices of bread, " + to_string(meat) +
                 " ounces of meat, " + to_string(vegetables) +
                 " ounces of vegetables, costing $" + rounded + " placed";
  if (age == 0) {
    order += " now";
  } else if (age == 1) {
    order += " 1 turn ago";
  } else {
    order += " " + to_string(age) + " turns ago.";
  }
  return order;
}
int Expense::getAge() { return age; }
void Expense::assignAge(int incrementedAge) { age = incrementedAge; }
int Expense::breadS() { return bread; }
int Expense::meatS() { return meat; }
int Expense::vegetablesS() { return vegetables; }
double Expense::costS() { return cost; }
