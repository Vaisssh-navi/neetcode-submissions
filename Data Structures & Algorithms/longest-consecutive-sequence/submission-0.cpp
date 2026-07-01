class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // int len=1;
        // int maxi=1;
        // for(int i=0;i<n-1;i++){
        //     if(nums[i]==nums[i+1]) continue;
        //     else if(nums[i]+1==nums[i+1]){
        //         len++;
        //         maxi=max(maxi,len);
        //     }
        //     else len=1;
        // }
        // return maxi;

        // // nlogn+n
        unordered_set<int> st(nums.begin(),nums.end());
        int maxi=0;
        for(int num:st){
            if(!st.count(num-1)){
                int curr=num;
                int len=1;
                while(st.count(curr+1)){
                    curr++;
                    len++;
                }
                maxi=max(len,maxi);
            }  
      }
      return maxi;

    }
};
