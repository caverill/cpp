#include <iostream>

using namespace std;

int largest(int numbers[])
{

    int largest{0};

    for (int i = 0; i < 15; i++)
    {
        if (numbers[i] > largest)
        {
            largest = numbers[i];
        }
    }

    return largest;
}

int main()
{
    int numbers[15] = {11, 23, 573, 823, 58, 266, 1100, 262, 567, 891, 426, 63, 8, 998, 458};

    cout << "Largest number found: " << largest(numbers) << endl;
}