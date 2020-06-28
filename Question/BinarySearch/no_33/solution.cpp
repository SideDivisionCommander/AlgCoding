class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        res = -1;
        if (nums.size() == 0) {
            return -1;
        }
        int index = GetIndex(nums);
        if (index == 0) { // no ratate
            res = BinaryFind(nums, target);
            if (res != -1) {
                return res;
            }
        } else { // ratated
            vector<int> nums1;
            vector<int> nums2;
            nums1.assign(nums.begin(), nums.begin() + index);
            nums2.assign(nums.begin() + index, nums.end());
            res = BinaryFind(nums1, target);
            if (res != -1) {
                return res;
            } else {
                res = BinaryFind(nums2, target);
                if (res != -1) {
                    return res + index;
                }
            }
        }
        return -1;
    }
private:
    int res;
    
    int GetIndex(vector<int>& nums)
    {
        if (nums.size() == 1) {
            return 0;
        }
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                return i;
            }
        }
        return 0;
    }
    
    int BinaryFind(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target) {
                right = middle - 1;
                continue;
            }
            if (nums[middle] < target) {
                left = middle + 1;
                continue;
            }
            return middle;
        }
        return -1;
    }
};