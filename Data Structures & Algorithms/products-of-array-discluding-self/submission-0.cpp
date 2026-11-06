class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        vector<int>pre(n+1,1);
        vector<int>suff(n+1,1);
        vector<int>res(n,0);
        for(int i=1;i<=n;i++){
            pre[i]  = pre[i-1]*a[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suff[i] = suff[i+1]*a[i+1];
        }
        for(int i=0;i<n;i++){
            int pro = pre[i]*suff[i];
            res[i] = pro;
        }
        return res;
    }
};
