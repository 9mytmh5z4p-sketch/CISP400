#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;

int countVowels(const char text[]);
void convertToUpper(char text[]);
void reverseText(char text[]);

int main() {
    const int CAPACITY = 80;
    char text[CAPACITY] = {};

    cout << "Enter text: ";
    cin.getline(text, CAPACITY);

    cout << "Vowels: " << countVowels(text) << "\n";

    convertToUpper(text);
    cout << "Uppercase: " << text << "\n";

    reverseText(text);
    cout << "Reversed: " << text << "\n";

    return 0;
}

int countVowels(const char text[]) {
    int count = 0;

    for (int index = 0; text[index] != '\0'; index++) {
        char letter = tolower(text[index]);

        if (letter == 'a' || letter == 'e' || letter == 'i' ||
            letter == 'o' || letter == 'u') {
            count++;
        }
    }

    return count;
}

void convertToUpper(char text[]) {
    for (int index = 0; text[index] != '\0'; index++) {
        text[index] = toupper(text[index]);
    }
}

void reverseText(char text[]) {
    int left = 0;
    int right = strlen(text) - 1;

    while (left < right) {
        char temp = text[left];
        text[left] = text[right];
        text[right] = temp;
        left++;
        right--;
    }
}
