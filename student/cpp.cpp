#include<iostream>

using namespace std;

int main() {
    int input, count = 0, sum = 0, n = 1;
    cout << "A program to find the average of numbers:\n";

    while (true) {
        cout << "Enter number " << n << " (-1 to exit): ";
        cin >> input;

        if (input == -1)
            break;

        sum += input;
        count++;
        n++;
    }

    if (sum != 0)
        cout << "The average of " << count << " numbers is " << static_cast<float>(sum) / count << endl;
    else
        cout << "No data entered..." << endl;

    return 0;
}
