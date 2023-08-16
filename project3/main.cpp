#include <time.h>

#include <iostream>
#include <string>
#include <vector>

#include "expense.h"
#include "supplies.h"

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

void aged(vector<Expense> &list) {
  for (int i = 0; i < list.size(); i++) {
    list[i].assignAge(list[i].getAge() + 1);
  }
}

void unfilledOrders(vector<Expense> &orders) {
  cout << "Orders that currently need filling: " << endl << endl;
  int roundSize = orders.size();
  for (int i = roundSize - 1; i > -1; i--) {
    cout << "  " << i + 1 << ") " << orders[i].details() << endl;
  }
  cout << endl;
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
  while (true) {
    loadRoundOrders(expenseRecords);
    int roundSize = expenseRecords.size();
    unfilledOrders(expenseRecords);
    for (int i = 5; i > 0; i--) {
      cout << "you have " << i
           << " actions remaining. What would you like to do? Fill an order "
              "[1] "
              "or "
              "Buy more supplies [2]?"
           << endl;
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
            inventory.adjustBread(inventory.breadInv() -
                                  expenseRecords[index].breadS());
            inventory.printInv();
          }
        }
      } else if (choice == 2) {
      } else {
        cout << "please select an available option. " << endl;
        i++;
        continue;
      }
    }
    aged(expenseRecords);
  }
}
