#include <time.h>

#include <iostream>
#include <string>
#include <vector>

#include "expense.hpp"
#include "supplies.hpp"

using namespace std;

void loadRoundOrders(vector<Expense> &list) {
  for (int i = 0; i < 3; i++) {
    int b = rand() % 3;
    int m = 6 + rand() % 10;
    int v = 6 + rand() % 10;
    int c = b * 3 + m * 1.75 + v * 1;
    int a = 0;
    list.push_back(Expense(b, m, v, c, a));
  }
}

bool aged(vector<Expense> &list) {
  for (int i = 0; i < list.size(); i++) {
    list[i].assignAge(list[i].getAge() + 1);
    if (list[i].getAge() == 6) {
      return true;
    }
  }
  return false;
}

void unfilledOrders(vector<Expense> orders) {
  cout << "Orders that currently need filling: " << endl << endl;
  int roundSize = orders.size();
  for (int i = roundSize - 1; i > -1; i--) {
    cout << "  " << i + 1 << ") " << orders[i].details() << endl;
  }
  cout << endl;
}

bool adequateSupplies(Expense Order, Supplies inventory) {
  bool adequate;
  if ((inventory.breadInv() >= Order.breadS()) &&
      (inventory.meatInv() >= Order.meatS()) &&
      (inventory.vegetableInv() >= Order.vegetablesS())) {
    adequate = true;
  } else {
    adequate = false;
  }
  return adequate;
}

Supplies fillOrder(int index, Expense order, Supplies &inventory) {
  inventory.adjustBread(inventory.breadInv() - order.breadS());
  inventory.adjustMeat(inventory.meatInv() - order.meatS());
  inventory.adjustvegetables(inventory.vegetableInv() - order.vegetablesS());
  inventory.adjustBalance(inventory.getBalance() + order.costS());
  inventory.printInv();
  return inventory;
}

int main() {
  srand(time(0));
  vector<Expense> expenseRecords;
  Supplies inventory = Supplies(20, 20, 20);
  cout << "Welcome to Zoomies Restaurant. Type play to begin. ";
  string start;
  while (true) {
    cin >> start;
    if (start == "play") {
      break;
    }
  }
  cout << endl
       << endl
       << "fulfill orders as quickly as possible. If any order does not get "
          "fulfilled within 5 turns, you lose."
       << endl;
  while (true) {
    loadRoundOrders(expenseRecords);
    for (int i = 5; i > 0; i--) {
      cout << endl << endl;
      unfilledOrders(expenseRecords);
      cout << "Your inventory: " << endl;
      inventory.printInv();
      if (i != 1) {
        cout << endl
             << "you have " << i
             << " actions remaining. What would you like to do? Fill an order "
                "[1] "
                "or "
                "Buy more supplies [2]?"
             << endl;
      } else {
        cout << endl
             << "you have 1 action remaining. What would you like to do? Fill "
                "an order "
                "[1] "
                "or "
                "Buy more supplies [2]?"
             << endl;
      }
      int choice;
      cin >> choice;
      if (choice == 1) {
        while (true) {
          cout << "which order would you like to fill?" << endl;
          int index;
          cin >> index;
          index--;
          if (index < 0 || index >= expenseRecords.size()) {
            continue;
          } else {
            // fill out the order, subtract supplies, and add to the balance.
            if (adequateSupplies(expenseRecords[index], inventory)) {
              fillOrder(index, expenseRecords[index], inventory);
              expenseRecords.erase(expenseRecords.begin() + index);
            } else {
              cout << "not filling out an order because the order cannot be "
                      "fulfilled"
                   << endl;
              cout << "would you like to fill out a different order? y/n"
                   << endl;
              string ans;
              cin >> ans;
              if (ans == "n") {
                break;
              }
              continue;
            }
            break;
          }
        }
      } else if (choice == 2) {
      } else {
        cout << "please select an available option. " << endl;
        i++;
        continue;
      }
    }
    bool gameOver = aged(expenseRecords);
    if (gameOver) {
      break;
    }
  }
  cout << endl << endl << "Game Over" << endl << endl;
  cout << endl
       << "make sure you fulfill orders within 5 turns of them being placed"
       << endl;
}
