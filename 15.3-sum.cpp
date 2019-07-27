/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.45%)
 * Likes:    4137
 * Dislikes: 476
 * Total Accepted:    596K
 * Total Submissions: 2.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());
        size_t length = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            int a1 = nums[i];//a1 + a2 + a3 ?= 0
            int left_two_sum = 0 - a1;
            int front = i + 1;
            int first_back = 0;
            int back = length - 1;
            while (front < back)
            {        
                int font_back_sum = nums[front] + nums[back];
                if (font_back_sum > left_two_sum)
                {
                    back--;
                }
                else if (font_back_sum < left_two_sum)
                {
                    front++;
                }
                else
                {
                    ret.emplace_back(std::vector<int>({a1, nums[front], nums[back]}));
                    while (front + 1 < back && nums[front + 1] == nums[front]) front++;
                    while (back - 1 > front && nums[back - 1] == nums[back]) back--; 
                    front++;
                    back--;
                }               
            }          
            while (i + 1 < length && nums[i+1] == nums[i]) i++;
        }
        return ret;
    }
};


