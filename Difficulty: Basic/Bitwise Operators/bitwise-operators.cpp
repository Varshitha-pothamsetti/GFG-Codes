#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // perform bitwise operations here
    int d = a ^ a;
    int e = c ^ b;
    int f = a & b;
    int g = c | (a ^ a);
    e = ~e;
    cout << d << " " << e << " " << f << " " << g << endl;

    return 0;
}