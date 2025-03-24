class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> con;
        while (i < size1 && j < size2)
        {
            if (nums1[i] < nums2[j])
            {
                con.push_back(nums1[i]);
                i++;
            }
            else
            {
                con.push_back(nums2[j]);
                j++;
            }
        }
        while (i < size1)
        {
            con.push_back(nums1[i]);
            i++;
        }
        while (j < size2)
        {
            con.push_back(nums2[j]);
            j++;
        }
        if ((size1 + size2) % 2)
            return con[(size1 + size2) / 2];
        else
        {
            double x = 0.0;
            x += con[(size1 + size2) / 2];
            x += con[(size1 + size2) / 2 - 1];
            x /= 2;
            return x;
        }
    }
};