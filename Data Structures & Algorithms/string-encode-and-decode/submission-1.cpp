class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string res = "";
        for(int i=0;i<n;i++){
            res += to_string(strs[i].length())+"#"+strs[i];
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int n = s.length();
        int i=0;
        while(i<n){
            int j = i;
            while(j<n && s[j]!='#'){
                j++;
            }
            int len = stoi(s.substr(i,j-i));
            i = j+1;
            string res = s.substr(i,len);
            i+=len;
            ans.push_back(res);
        }
        return ans;
    }
};
