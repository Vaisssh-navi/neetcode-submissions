class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        // vector<int> pm(n);
        // pm[0]=1;
        // vector<int> sm(n);
        // sm[n-1]=1;
        // for(int i=1;i<n;i++){
        //     pm[i]=pm[i-1]*nums[i-1];
        // } 
        // for(int i=n-2;i>=0;i--){
        //     sm[i]=sm[i+1]*nums[i+1];
        // }  
        // vector<int> ans(n);
        // for(int i=0;i<n;i++){
        //     ans[i]=pm[i]*sm[i];
        // }
        // return ans;
        // // time O(n) space O(2n) extra apart from ans 
        vector<int> ans(n);
        ans[0]=1;
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        int suff=1;
        for(int i=n-1;i>=0;i--){
            ans[i]*=suff;
            suff*=nums[i];
        }
    return ans;
    // O(1) no extra space
    }
};
