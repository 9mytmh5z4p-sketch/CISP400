// Nested_switch.cpp
// File: static_cast_menu.cpp
#include <iostream>
using namespace std;

// Function prototypes
void showMainMenu();
void showToTypeMenu();
void showFromTypeMenu();
void collectData(int fromType, int& intValue, float& floatValue, short& shortValue);
void performCast(int fromType, int toType, int intValue, float floatValue, short shortValue);

int main() {
    int choice;
    int toType = 0;
    int fromType = 0;

    int intValue = 0;
    float floatValue = 0.0f;
    short shortValue = 0;

    bool dataCollected = false;

    do {
        showMainMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                showToTypeMenu();
                cin >> toType;

                if (toType < 1 || toType > 3) {
                    cout << "Invalid To type.\n";
                    toType = 0;
                }
                break;

            case 2:
                showFromTypeMenu();
                cin >> fromType;

                if (fromType < 1 || fromType > 3) {
                    cout << "Invalid From type.\n";
                    fromType = 0;
                    dataCollected = false;
                } else {
                    collectData(fromType, intValue, floatValue, shortValue);
                    dataCollected = true;
                }
                break;

            case 3:
                if (toType == 0 || fromType == 0 || !dataCollected) {
                    cout << "You must select both types and collect data before casting.\n";
                } else {
                    performCast(fromType, toType, intValue, floatValue, shortValue);
                }
                break;

            case 4:
                cout << "Goodbye.\n";
                break;

            default:
                cout << "Invalid menu option.\n";
        }

        cout << endl;

    } while (choice != 4);

    return 0;
}

void showMainMenu() {
    cout << "Main Menu\n";
    cout << "1. To type\n";
    cout << "2. From type\n";
    cout << "3. Cast!\n";
    cout << "4. Quit\n";
    cout << "Enter choice: ";
}

void showToTypeMenu() {
    cout << "\nTo Type Menu\n";
    cout << "1. Int\n";
    cout << "2. Float\n";
    cout << "3. Short\n";
    cout << "Enter target type: ";
}

void showFromTypeMenu() {
    cout << "\nFrom Type Menu\n";
    cout << "1. Int\n";
    cout << "2. Float\n";
    cout << "3. Short\n";
    cout << "Enter source type: ";
}

void collectData(int fromType, int& intValue, float& floatValue, short& shortValue) {
    switch (fromType) {
        case 1:
            cout << "Enter an int value: ";
            cin >> intValue;
            break;
        case 2:
            cout << "Enter a float value: ";
            cin >> floatValue;
            break;
        case 3:
            cout << "Enter a short value: ";
            cin >> shortValue;
            break;
    }
}

void performCast(int fromType, int toType, int intValue, float floatValue, short shortValue) {
    cout << "\nCast Result\n";

    switch (fromType) {
        case 1: // from int
            switch (toType) {
                case 1:
                    cout << "int to int: " << static_cast<int>(intValue) << endl;
                    break;
                case 2:
                    cout << "int to float: " << static_cast<float>(intValue) << endl;
                    break;
                case 3:
                    cout << "int to short: " << static_cast<short>(intValue) << endl;
                    break;
            }
            break;

        case 2: // from float
            switch (toType) {
                case 1:
                    cout << "float to int: " << static_cast<int>(floatValue) << endl;
                    break;
                case 2:
                    cout << "float to float: " << static_cast<float>(floatValue) << endl;
                    break;
                case 3:
                    cout << "float to short: " << static_cast<short>(floatValue) << endl;
                    break;
            }
            break;

        case 3: // from short
            switch (toType) {
                case 1:
                    cout << "short to int: " << static_cast<int>(shortValue) << endl;
                    break;
                case 2:
                    cout << "short to float: " << static_cast<float>(shortValue) << endl;
                    break;
                case 3:
                    cout << "short to short: " << static_cast<short>(shortValue) << endl;
                    break;
            }
            break;
    }
}