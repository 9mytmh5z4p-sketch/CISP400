#include <iomanip>
#include <iostream>

using namespace std;

const int ROWS = 2;
const int COLS = 3;

void displayGrid(const int grid[][COLS], int rows);
void displayRowTotals(const int grid[][COLS], int rows);

int main() {
    int grid[ROWS][COLS] = {
        {8, 6, 7},
        {5, 3, 0}
    };

    displayGrid(grid, ROWS);
    displayRowTotals(grid, ROWS);

    return 0;
}

void displayGrid(const int grid[][COLS], int rows) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < COLS; col++) {
            cout << setw(4) << grid[row][col];
        }
        cout << "\n";
    }
}

void displayRowTotals(const int grid[][COLS], int rows) {
    for (int row = 0; row < rows; row++) {
        int total = 0;

        for (int col = 0; col < COLS; col++) {
            total += grid[row][col];
        }

        cout << "Row " << row << " total: " << total << "\n";
    }
}
