/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (42.72%)
 * Likes:    3550
 * Dislikes: 455
 * Total Accepted:    405.6K
 * Total Submissions: 889.5K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * 
 * 
 * 
 * 
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49. 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * 
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // int maxArea(vector<int>& height) {
    //     size_t max_volume = 0;
    //     for (size_t step = 1; step < height.size(); step++)
    //     {
    //         size_t max_height = 0;
    //         for (size_t i = 0; i < height.size() - step; i++)
    //         {
    //             size_t container_height = min((size_t)height[i], (size_t)height[i + step]);
    //             max_height = max(container_height, max_height);
    //         }
    //         max_volume = max(step * max_height, max_volume);
    //     }
    //     return max_volume;
    // }
    int maxArea(vector<int>& height) {
        size_t max_volume = 0;
        int i = 0, j = height.size() - 1;
        while (i < j)
        {
            size_t h = min(height[i], height[j]);
            max_volume = max(max_volume, (j - i) * h);
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;            
        }
        
        return max_volume;
    }
};
