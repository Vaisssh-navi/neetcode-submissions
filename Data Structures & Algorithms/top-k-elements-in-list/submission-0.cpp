class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i:nums){
            freq[i]++;
        }
    //     vector<int> ans;
    //     while(k--){
    //         int mx=-1;
    //         int num=0;
    //         for(auto &it:freq){
    //             if(it.second>mx){
    //                 mx=it.second;
    //                 num=it.first;
    //             }
    //         }
    //         ans.push_back(num);
    //         freq.erase(num);
    //     }
    //     return ans;
    // 
    // //O(nk)

    // vector<pair<int,int>> arr;
    // for(auto &it:freq){
    //     arr.push_back({it.second,it.first});
    // }
    // sort(arr.begin(),arr.end(),greater<pair<int,int>>());
    // vector<int> ans;
    // for(int i=0;i<k;i++){
    //     ans.push_back(arr[i].second);
    // }
    // return ans;
    // //nlog n

//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>  pq;
//     for(auto &it:freq){
//         pq.push({it.second,it.first});
//         if(pq.size()>k) pq.pop();
//     }
//     vector<int> ans;
//    while(!pq.empty()){
//         ans.push_back(pq.top().second);
//         pq.pop();
//     }
//     return ans;
//     //n+mlogk

vector<vector<int>> bucket(nums.size()+1);
for(auto &it:freq){
    bucket[it.second].push_back(it.first);
}
vector<int> ans;
for(int i=nums.size();i>=1&&ans.size()<k;i--){
    for(int x:bucket[i]){
        ans.push_back(x);
        if(ans.size()==k) return ans;
    }
}
return ans;
//n
    }

};
