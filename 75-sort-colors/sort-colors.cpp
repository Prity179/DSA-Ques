class Solution{
    public:
    void sortColors(vector<int>& nums){
        int n = nums.size();
        int left = 0;
        int idx = 0;
        int right = n-1;
        while(idx<=right){
        if(nums[idx]==0){
            swap(nums[idx],nums[left]);
            left++;
            idx++;

        }
        else if(nums[idx]==2){
            swap(nums[idx],nums[right]);
            right--;
        }
        else 
        {
            idx++;
        }  
        }
    }
};