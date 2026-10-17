class Solution {
public:
    bool isItPossible(string &s1, string &s2) {
        int n = s1.size();

        if (s1.size() != s2.size())
            return false;

        int i = 0, j = 0;

        while (i < n && j < n) {
            while (i < n && s1[i] == '#')
                i++;

            while (j < n && s2[j] == '#')
                j++;

            if (i == n || j == n)
                break;

            if (s1[i] != s2[j])
                return false;

            if (s1[i] == 'A' && i < j)
                return false;

            if (s1[i] == 'B' && i > j)
                return false;

            i++;
            j++;
        }

        while (i < n && s1[i] == '#')
            i++;

        while (j < n && s2[j] == '#')
            j++;

        return i == n && j == n;
    }
};