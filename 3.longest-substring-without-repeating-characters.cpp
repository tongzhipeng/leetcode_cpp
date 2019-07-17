/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (27.97%)
 * Likes:    5835
 * Dislikes: 335
 * Total Accepted:    996.2K
 * Total Submissions: 3.5M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */
#include <iostream>
#include <map>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

void reset_previous_chars(map<char, int>& c, int target_index)
{
    for (auto i = c.begin(), last = c.end(); i != last; i++) {
        if (i->second < target_index) {
            i->second = -1;
        }
    }
}

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         map<char, int> unique_set;
//         size_t lastLongLen = 0;
//         int index = 0;
//         for (auto& c : s)
//         {
//             auto r = unique_set.insert(make_pair(c, index++));
//             if (!r.second)
//             {          
//                 int curLen =  unique_set.size(); 
//                 if (curLen > lastLongLen)
//                 {
//                     lastLongLen = curLen;
//                 }
//                 auto same_exist_iter = r.first;
//                 int same_exist_index = same_exist_iter->second;
//                 same_exist_iter->second = index - 1;               
//                 erase_previous_chars(unique_set, same_exist_index);               
//             }         
//         }
//         return max(unique_set.size(), lastLongLen);
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> unique_set;
        size_t max_len = 0;
        int index = 0;
        int unique_begin_index = 0;
        for (auto& c : s)
        {
            int cur_index = index++;        
            auto iter = unique_set.find(c);
            if (iter != unique_set.end() && iter->second != -1)
            {
                int same_exist_index = iter->second;
                int curLen = cur_index - unique_begin_index;
                if (curLen > max_len)
                {
                    max_len = curLen;
                }
                reset_previous_chars(unique_set, same_exist_index);
                iter->second = cur_index;
                unique_begin_index = same_exist_index + 1;
            }
            else if (iter->second == -1)
            {
                iter->second = cur_index;
            }            
            else
            {
                unique_set.insert(make_pair(c, cur_index));
            }
                      
        }
        return max(s.length() - unique_begin_index, max_len);
    }
};

// int main()
// {
//     Solution s;
//     std::cout << s.lengthOfLongestSubstring("aabaab!bb") << std::endl;
//     system("pause");
//     return 0;
// }

