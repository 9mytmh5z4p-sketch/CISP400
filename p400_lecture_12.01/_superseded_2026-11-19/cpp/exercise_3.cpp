#include <iostream>
#include <string>
using namespace std;

int main() {
    string products[3] = {"Apples", "Bananas", "Oranges"};
    int stock[3][3] = {
        {50, 30, 20},   // Apples
        {40, 25, 35},   // Bananas
        {60, 20, 15}    // Oranges
    };

    string searchItem;
    bool found = false;

    cout << "Enter a product name: ";
    cin >> searchItem;

    // Search for the product
    for (int i = 0; i < 3; i++) {
        if (products[i] == searchItem) {
            found = true;

            int total = 0;

            // Sum stock across all warehouses
            for (int j = 0; j < 3; j++) {
                total += stock[i][j];
            }

            cout << "Total stock for " << products[i] << ": " << total << endl;
        }
    }

    if (!found) {
        cout << "Product not found." << endl;
    }

    return 0;
}