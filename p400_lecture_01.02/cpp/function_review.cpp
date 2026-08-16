// Fixed Debug 6-2
// User enters price
// Program computes tax rate
// 5% at prices $10 and under, otherwise 7%
#include <iostream>
using namespace std;

double askPrice();
double calcTax(double);

int main()
{
    double price;
    double taxRate;

    price = askPrice();
    taxRate = calcTax(price);

    cout << "On $" << price << ", the taxRate is " << taxRate << endl;

    return 0;
}

double askPrice()
{
    double price;

    cout << "Enter price $";
    cin >> price;

    return price;
}

double calcTax(double price)
{
    double rate;
    const double CUTOFF = 10.00;
    const double LOWRATE = 0.05;
    const double HIGHRATE = 0.07;

    if (price <= CUTOFF)
        rate = LOWRATE;
    else
        rate = HIGHRATE;

    return rate;
}
