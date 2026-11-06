class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        int n = strs.size();
        for(int i=0;i<n;i++){
            res += to_string(strs[i].length())+"#"+strs[i];
        }
        return res;
    
    }

    vector<string> decode(string s) {
        vector<string>res;
        int i=0;
        int n = s.size();
        while(i<n){
            int j=i;
            while(j<n && s[j]!='#'){
                j++;
            }
            int len = stoi(s.substr(i,j-i));
            i = j+1;
            res.push_back(s.substr(i,len));
            i+=len;
        }
        return res;
    }
};
