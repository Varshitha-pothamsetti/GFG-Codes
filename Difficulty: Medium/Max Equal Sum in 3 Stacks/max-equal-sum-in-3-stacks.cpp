class Solution {
public:
    int maxEqualSum(vector<int> &s1, vector<int> &s2, vector<int> &s3) {
        int sum1 = 0, sum2 = 0, sum3 = 0;

        for(int i = 0; i < s1.size(); i++)
            sum1 += s1[i];

        for(int i = 0; i < s2.size(); i++)
            sum2 += s2[i];

        for(int i = 0; i < s3.size(); i++)
            sum3 += s3[i];

        int i = 0, j = 0, k = 0;

        while(i < s1.size() && j < s2.size() && k < s3.size()) {

            if(sum1 == sum2 && sum2 == sum3)
                return sum1;

            if(sum1 >= sum2 && sum1 >= sum3) {
                sum1 -= s1[i];
                i++;
            }
            else if(sum2 >= sum1 && sum2 >= sum3) {
                sum2 -= s2[j];
                j++;
            }
            else {
                sum3 -= s3[k];
                k++;
            }
        }

        return 0;
    }
};