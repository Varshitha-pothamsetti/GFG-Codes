#include <iostream>
#include <string>
using namespace std;

int main() {
    string num;
    cin >> num;

    // Convert string to integer
    int value = stoi(num);

    // Double the value
    cout << value * 2;

    return 0;
}
