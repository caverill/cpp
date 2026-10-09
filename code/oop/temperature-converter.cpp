// Practice function abstraction by separating temperature conversion logic from main().
// Use individual functions for calculations and a conversion function to select the appropriate operation.

#include <iostream>
#include <cctype>

using namespace std;

double convertTemp(double tempInput, char unitInput);
double celsiusToFarenheit(double tempInput);
double farenheitToCelsius(double tempInput);

int main()
{

    double tempInput;
    char unitInput;

    cout << "Enter a temperature: ";
    cin >> tempInput;
    cout << "Do you want C or F? ";
    cin >> unitInput;

    unitInput = tolower(unitInput);

    double conversionResult = convertTemp(tempInput, unitInput);

    char labelInverse = unitInput == 'c' ? 'f' : 'c';

    cout << tempInput << unitInput << " is " << conversionResult << labelInverse << endl;
}

double convertTemp(double tempInput, char unitInput)
{

    switch (unitInput)
    {
    case 'c':
        return celsiusToFarenheit(tempInput);
    case 'f':
        return farenheitToCelsius(tempInput);
    default:
        cout << "Invalid unit. Enter C or F." << endl;
        return 0.0;
    }
}

double celsiusToFarenheit(double tempInput)
{
    return (tempInput * 9 / 5) + 32;
}

double farenheitToCelsius(double tempInput)
{
    return (tempInput - 32) * 5 / 9;
}