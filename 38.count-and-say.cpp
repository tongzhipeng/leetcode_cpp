/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (39.57%)
 * Likes:    807
 * Dislikes: 6235
 * Total Accepted:    292.4K
 * Total Submissions: 714.7K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string Say(string seq)
    {
        int len = seq.length();       
        const char* pseq = seq.c_str();
        char curChar = pseq[0];
        int curCharSum = 1;
        string result;
        for (size_t i = 1; i <= len; i++)
        {
            if (i != len && curChar == pseq[i])
            {
                curCharSum++;
            }
            else
            {  
                char buf[3] = {0};
                buf[0] = '0' + curCharSum;
                buf[1] = curChar;
                result.append(buf);
                if (i != len)
                {
                    curChar = pseq[i];
                    curCharSum = 1;
                }
            }
        }
        return result;        
    }
    // string countAndSay(int n) {
    //     if (n == 1)
    //     {
    //         return "1";
    //     }        
    //     return Say(countAndSay(n-1));
    // }

    string countAndSay(int n) {
        string buf = "1";
        for (size_t i = 0; i < n - 1; i++)
        {
            buf = Say(buf);
        }
        return buf;
    }
    
};

// int main()
// {
//     Solution s;
//     cout << s.countAndSay(6) << std::endl;
//     system("pause");
//     return 0;
// }

