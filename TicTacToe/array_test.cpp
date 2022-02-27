#include <iostream>
using namespace std;

int main()
{
    char One = '1';
    char newArray[5] = {'1','2','3','4','5'};
    newArray[int (One)] = 'a';
    for (int i = 0; i < 5; i++)
    {
            cout << newArray[i]  << " ";
    }
    return 0;
}