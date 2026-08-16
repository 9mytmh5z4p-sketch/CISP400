// loggertime.cpp
// Basic logger implementation with timestamps
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void Logger(string);
void Foo();

int main()
{
    auto start = chrono::high_resolution_clock::now();

    Logger("Calling Foo()");
    auto startFoo = chrono::high_resolution_clock::now();
    Foo();
    auto elapsedFoo = chrono::high_resolution_clock::now() - start;
    long long microsec =
        chrono::duration_cast<chrono::microseconds>(elapsedFoo).count();
    Logger("Done with Foo()");
    string s = "Elapsed time: " + to_string(microsec) + " ms\n";
    Logger(s);

    auto elapsed = chrono::high_resolution_clock::now() - start;
    // Convert measured time into a chrono object
    long long microseconds =
        chrono::duration_cast<chrono::microseconds>(elapsed).count();

    cout << "Elapsed time: " << microseconds << " ms\n";
    return 0;
}

void Logger(string str)
{
    ofstream logFile;
    logFile.open("log.txt", ios_base::app);
    logFile << str << endl;
    logFile.close();
}

void Foo()
{
    cout << "Testing Foo\n";
}
