// User function Template for C++

int nextPrime(int n) {
    int number = n + (n % 2 == 0 ? 1 : 2);  
    if (n < 2) return 2;
    
    while(true) {
        bool is_prime = true;
        if (number <= 1) {
            is_prime = false;
        } else if (number == 2) {
            return 2;
        } else if (number % 2 == 0) {
            is_prime = false;
        } else {
            for (int i = 3; i * i <= number; i += 2) {
                if (number % i == 0) {
                    is_prime = false;
                    break;
                }
            }
        }
        if (is_prime) {
            return number;
        }
        number += 2;  
    }
}
