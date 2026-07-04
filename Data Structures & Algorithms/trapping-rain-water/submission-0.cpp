class Solution {
public:

//  ans += min(leftMax[i], rightMax[i]) - height[i]; using this O(n^2) as for every i check boht left n rihgt by travesing O(1) SC
// if make preficmax, sufixmax O(n) but space O(n)
//below O(n) with space O(1)
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int lm=0;
        int rm=0;
        int ans=0;
        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]>=lm){
                    lm=height[l];
                }else{
                    ans+=lm-height[l];
                }
                l++;
            }else{
                if(height[r]>=rm){
                    rm=height[r];
                }else{
                    ans+=rm-height[r];
                }
                r--;
            }
        }
        return ans;
    }
};
