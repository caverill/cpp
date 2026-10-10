#include <iostream>

using namespace std;

int main()
{
    int numbers[] = {2, 7, 11, 15};
    int target = 9;
    int size = 4;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (numbers[i] + numbers[j] == target)
            {
                cout << "Indices: " << i << ", " << j << endl;
                return 0;
            }
        }
    }

    cout << "No solution found" << endl;

    return 0;
}