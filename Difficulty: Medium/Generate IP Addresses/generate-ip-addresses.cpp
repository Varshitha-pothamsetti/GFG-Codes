class Solution {
  public:
  
    bool valid(string s){
        if(s.size() > 3) return false;
        if(s.size() > 1 && s[0] == '0') return false;
        
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }
  
    vector<string> generateIp(string &s) {
        
        vector<string> ans;
        int n = s.size();
        
        if(n < 4 || n > 12) return ans;
        
        for(int i = 1; i <= 3 && i < n; i++){
            for(int j = i+1; j <= i+3 && j < n; j++){
                for(int k = j+1; k <= j+3 && k < n; k++){
                    
                    string A = s.substr(0,i);
                    string B = s.substr(i,j-i);
                    string C = s.substr(j,k-j);
                    string D = s.substr(k);
                    
                    if(valid(A) && valid(B) && valid(C) && valid(D)){
                        ans.push_back(A+"."+B+"."+C+"."+D);
                    }
                }
            }
        }
        
        return ans;
    }
};