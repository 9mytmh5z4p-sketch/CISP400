#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int temps[4][7];

    srand(time(0));

    // Fill array with random temperatures (60–100)
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            temps[i][j] = rand() % 41 + 60; // 60–100
        }
    }

    // Find highest temperature
    int maxTemp = temps[0][0];
    int maxWeek = 0;
    int maxDay = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            if (temps[i][j] > maxTemp) {
                maxTemp = temps[i][j];
                maxWeek = i;
                maxDay = j;
            }
        }
    }

    cout << "Highest temperature: " << maxTemp << endl;
    cout << "Occurred on week " << maxWeek + 1 
         << ", day " << maxDay + 1 << endl;

    cout << "\n--- Weekly Averages ---\n";

    // Calculate average for each week
    for (int i = 0; i < 4; i++) {
        int sum = 0;

        for (int j = 0; j < 7; j++) {
            sum += temps[i][j];
        }

        double avg = sum / 7.0;
        cout << "Week " << i + 1 << " average: " << avg << endl;
    }

    return 0;
}