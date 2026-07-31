class Solution {
public:
    int countSubsets(vector<int> &arr) {
        const int MOD = 1000000007;
        vector<int> prime = {2,3,5,7,11,13,17,19,23,29};

        vector<int> freq(31,0);
        for(int x: arr) freq[x]++;

        vector<int> mask(31,-1);

        for(int x=2;x<=30;x++){
            int t=x;
            int m=0;
            bool ok=true;
            for(int i=0;i<10;i++){
                int p=prime[i];
                if(t%(p*p)==0){
                    ok=false;
                    break;
                }
                if(t%p==0) m|=(1<<i);
            }
            if(ok) mask[x]=m;
        }

        vector<long long> dp(1<<10,0);
        dp[0]=1;

        for(int val=2;val<=30;val++){
            if(freq[val]==0 || mask[val]==-1) continue;

            vector<long long> ndp(dp);

            for(int s=0;s<(1<<10);s++){
                if((s & mask[val])==0){
                    ndp[s|mask[val]] =
                        (ndp[s|mask[val]] + dp[s]*freq[val])%MOD;
                }
            }
            dp.swap(ndp);
        }

        long long ans=0;
        for(int s=1;s<(1<<10);s++)
            ans=(ans+dp[s])%MOD;

        long long mul=1,base=2;
        int e=freq[1];
        while(e){
            if(e&1) mul=mul*base%MOD;
            base=base*base%MOD;
            e>>=1;
        }

        ans=ans*mul%MOD;
        return (int)ans;
    }
};