class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        std::sort(nums.begin(), nums.end()); 
        
        for (int i = 0; i < n - 2; ++i) {

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;

                    while (left < right && nums[left] == nums[left - 1]) ++left;
                    while (left < right && nums[right] == nums[right + 1]) --right;
                } else if (sum < 0) {
                    ++left;
                } else {
                    --right; 
                }
            }
        }
        
        return result;
    //     int n = nums.size();
    //     map <int,int,int> mp;
    //     sort(nums.begin(),nums.end());
    //     for(int i =0; i<n;i++){
    //         if(mp[])
    //         for(int j =i+1;j<n;j++){
    //             for(int k =j+1; k<n;k++){
    //                 if((nums[i]+nums[j]+nums[k]==0))
    //                 arr.insert({nums[i], nums[j], nums[k]});
    //         }
    //     }
    // }
        
    //     int n = nums.size();
    //     sort(nums.begin(),nums.end());
    //     set<vector<int>> arr;
    //     for(int i =0; i<n;i++){
    //         for(int j =i+1;j<n;j++){
    //             for(int k =j+1; k<n;k++){
    //                 if((nums[i]+nums[j]+nums[k]==0))
    //                 arr.insert({nums[i], nums[j], nums[k]});
    //         }
    //     }
    // }
    // return std::vector<std::vector<int>>(arr.begin(), arr.end());

    }
};
