

class Solution {
public:
    //[Performance]
    //Cost 71 ms for 2080 testcases, beats 66.45%.
    //[Algorithm]
    //Streamly put two arrays into single empty array from min to max,
    //then get the median num in the single array.
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> rstVec;
        rstVec.empty();
        while (!nums1.empty() || !nums2.empty()){
            if (nums1.empty()){
                rstVec.push_back(nums2.front());
                nums2.erase(nums2.begin());
            }
            else if (nums2.empty()){
                rstVec.push_back(nums1.front());
                nums1.erase(nums1.begin());
            }
            else if (nums2.front()<=nums1.front()){
                rstVec.push_back(nums2.front());
                nums2.erase(nums2.begin());
            }
            else if (nums1.front()<=nums2.front()){
                rstVec.push_back(nums1.front());
                nums1.erase(nums1.begin());
            }
        }
        if (0 != rstVec.size()){
            if(0 == rstVec.size()%2)
                return ((double)(rstVec[rstVec.size()/2-1] + rstVec[rstVec.size()/2]))/2;
            return rstVec[rstVec.size()/2];
        }
        return 0;
    }
};