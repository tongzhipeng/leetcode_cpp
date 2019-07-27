/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (40.92%)
 * Likes:    1209
 * Dislikes: 87
 * Total Accepted:    364.5K
 * Total Submissions: 795.9K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        size_t length = nums.size();
        int closest_target = nums[0] + nums[1] + nums[2];
        size_t min_delta = abs(target - closest_target);
        for (int i = 0; i < nums.size(); i++)
        {
            int a1 = nums[i];//a1 + a2 + a3 ?= 0
            int left_two_sum = target - a1;
            int front = i + 1;
            int back = length - 1;
            while (front < back)
            {        
                int font_back_sum = nums[front] + nums[back];
                size_t abs_delta = abs(font_back_sum - left_two_sum);
                if (abs_delta < min_delta)
                {
                    closest_target = a1 + font_back_sum;
                    min_delta = abs_delta;
                }                
                if (min_delta == 0)
                {
                    return target;
                }
                if (font_back_sum > left_two_sum)
                {
                    back--;
                }
                else
                {
                    front++;
                }              
            }          
        }
        return closest_target;
    }
};



