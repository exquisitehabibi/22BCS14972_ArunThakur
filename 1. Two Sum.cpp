class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector <int> ind;
        int sum =0;
        for(int i =0; i< n; i++){
            for(int j =i+1; j<n;j++){
                if(nums[i]+nums[j]==target){
                return ind = {i,j};
            }         
            }
        }
        return ind;
        
    }
};
