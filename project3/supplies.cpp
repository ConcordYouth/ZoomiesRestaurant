#include "supplies.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Supplies::Supplies(int b, int m, int v, double bal) {
  bread = b;
  meat = m;
  vegetables = v;
  balance = bal;
}
int Supplies::meatInv() { return meat; }
void Supplies::adjustMeat(int m) { meat = m; }
int Supplies::breadInv() { return bread; }
void Supplies::adjustBread(int b) { bread = b; }
int Supplies::vegetableInv() { return vegetables; }
void Supplies::adjustvegetables(int v) { vegetables = v; }
double Supplies::getBalance() { return balance; }
void Supplies::adjustBalance(double bal) { balance = bal; }
void Supplies::printInv() {
  cout << "bread: " << bread << endl;
  cout << "meat: " << meat << endl;
  cout << "vegetables " << vegetables << endl;
  cout << "Balance of $" << balance << endl;
}
