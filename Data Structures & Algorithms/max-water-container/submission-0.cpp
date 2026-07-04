class Solution {
public:
    int maxArea(vector<int>& heights) {
        // int n=heights.size();
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         ans=max(ans,min(heights[i],heights[j])*(j-i));
        //     }
        // }
        // return ans;

        // n^2 

        int n=heights.size();
        int l=0;
        int r=n-1;
        int ans=0;
        while(l<r){
            int w=r-l;
            int minh=min(heights[l],heights[r]);
            ans=max(ans,minh*w);
            if(heights[l]<heights[r]){
                l++;
            }else{
                r--;
            }
        }
        return ans;
        //O(n)
    }

};
