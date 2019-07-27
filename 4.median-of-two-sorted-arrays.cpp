/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (25.58%)
 * Likes:    4668
 * Dislikes: 656
 * Total Accepted:    470.2K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> numsMerge(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), numsMerge.begin());
        size_t length = numsMerge.size();
        if (length % 2 == 0)
        {
            return ((double)(numsMerge[length/2] + numsMerge[length/2 - 1]))/2;
        }
        else
        {
            return numsMerge[length/2];
        }
           
    }
};

