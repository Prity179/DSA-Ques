class Solution {
public:
    void merge(vector<int>& nums, int start, int mid, int end) {
        int left = start;
        int right = mid + 1;
        int index = 0;
        vector<int> temp(end - start + 1);

        while (left <= mid && right <= end) {
            if (nums[left] < nums[right]) {
                temp[index++] = nums[left++];
            } else {
                temp[index++] = nums[right++];
            }
        }

        while (left <= mid) {
            temp[index++] = nums[left++];
        }

        while (right <= end) {
            temp[index++] = nums[right++];
        }

        index = 0;
        while (start <= end) {
            nums[start++] = temp[index++];
        }
    }

    void mergeSort(vector<int>& nums, int start, int end) {
        if (start >= end) return;
        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};