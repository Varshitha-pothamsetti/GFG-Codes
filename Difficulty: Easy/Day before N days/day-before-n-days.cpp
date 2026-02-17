// User function Template for C++

int nthDay(int d, int n) {

    // write your code here
    int stepBack = n % 7;
    return (d - stepBack + 7) % 7;
}