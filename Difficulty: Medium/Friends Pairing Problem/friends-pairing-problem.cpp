class Solution {
public:
    int countFriendsPairings(int n) {

        if (n == 1)
            return 1;

        if (n == 2)
            return 2;

        long long a = 1;
        long long b = 2;
        long long c;

        for (int i = 3; i <= n; i++) {
            c = b + (i - 1) * a;
            a = b;
            b = c;
        }

        return b;
    }
};