class Solution {
public:
    int characterReplacement(string s, int k) {
    //     int n=s.size();
    //     int ans=0;
    //     for(int i=0;i<n;i++){
    //         vector<int> freq(26,0);
    //         int maxi=0;
    //         for(int j=i;j<n;j++){
    //             freq[s[j]-'A']++;
    //             maxi=max(maxi,freq[s[i]-'A']);
    //             int len=j-i+1;
    //             if(len-maxi<=k){
    //                 ans=max(ans,len);
    //             }
    //         }    
    //     }
    //     return ans;

    // //O(26*n^2)
    int n=s.size();
    vector<int> freq(26,0);
    int l=0;
    int ans=0;
    int maxi=0;
    for(int r=0;r<n;r++){
        freq[s[r]-'A']++;
        maxi=max(maxi,freq[s[r]-'A']);
        while((r-l+1)-maxi>k){
            freq[s[l]-'A']--;
            l++;
        }
        ans=max(ans,r-l+1);
    }
    return ans;
    //O(n)


    }

};
