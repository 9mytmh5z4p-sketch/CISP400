// 0808Out.cpp -- What's the output?
#include <iostream>
using namespace std;

int main()
{
    int alpha[8];

    for (int i = 0; i < 4; i++)
    {
        alpha[i] = i * (i + 1);
        if (i % 2 == 0)
            alpha[4 + i] = alpha[i] + 1;
        else if (i % 3 == 0)
            alpha[4 + i] = alpha[i] - 1;
        else if (i > 0)
            alpha[4 + i] = alpha[i] - alpha[i - 1];
    }

    for (int i = 0; i < 8; i++)
        cout << alpha[i] << " ";
    cout << endl;

    return 0;
}
