// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

	// Comparing each value to each value would take O(n^2) time complexity - which in this task is a lot.
	// We may sort the values O(nlog(n)) and then start comparing lowest value with biggest one. If the result is smaller then expected, we increase the lowest index, and if too large we decrease the highest one.
	// It takes in worst scenario O(n) operations. So The whole complexity is O(nlog(n))
	// Since we need to return index, I am storing data in pairs(value, index)


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index;
        vector<pair<int, int>> pairs;
        for(int i=0; i<nums.size(); i++)
            pairs.push_back({nums[i], i});
        sort(pairs.begin(), pairs.end());
        int i=0; int j = nums.size()-1;
        while(pairs[i].first+pairs[j].first!=target)
        {
            if(pairs[i].first+pairs[j].first<target) i++;
            else j--;
        }
        return {pairs[i].second, pairs[j].second};    
    }
};