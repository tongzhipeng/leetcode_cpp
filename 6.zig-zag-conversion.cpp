/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (30.73%)
 * Likes:    1101
 * Dislikes: 3401
 * Total Accepted:    337.9K
 * Total Submissions: 1M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */
#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef vector<char> CharRows;
typedef vector<CharRows> CharColumns;
class Solution {
public:
    // string convert(string s, int numRows) {
    //     if (numRows == 1)
    //     {
    //         return s;
    //     }
        
    //     size_t size = s.length();
    //     int row = 0;
    //     int column = 0;
    //     CharColumns char_columns;
    //     char_columns.resize(numRows);
    //     size_t reset_column = numRows - 1;//重置循环周期的列数
    //     for (size_t i = 0; i < size; i++)
    //     {               
    //         row = i % (2 * numRows - 2);
    //         if (row >= numRows)
    //         {
    //             row = 2 * numRows - 2 - row; 
    //         }  
    //         char_columns[row].push_back(s[i]);
            
    //     }
    //     std::string ret;
    //     for (size_t i = 0; i < numRows; i++)
    //     {
    //         std::string temp(char_columns[i].begin(), char_columns[i].end());
    //         ret += temp;
    //     }
    //     return ret;       
    // }

    string convert(string s, int numRows) {
        if (numRows == 1)
        {
            return s;
        }
        
        size_t size = s.length();
        int row = 0;
        int column = 0;
        size_t reset_column = numRows - 1;//重置循环周期的列数
        std::string ret;
        ret.resize(size);
        size_t cycle = 2 * numRows - 2; 
        int cur_index = 0;
        for (size_t i = 0; i < numRows; i++)
        {           
            for (size_t j = i; j < size; j += cycle)
            {
                ret[cur_index++] = s[j];
                int secondJ = j - i + cycle - i;
                if (i != 0 && i != numRows -1 && secondJ < size)
                {                    
                    ret[cur_index++] = s[secondJ];
                }                
            }                   
        }

        return ret;       
    }
};


// int main()
// {
//     Solution s;
//     std::cout << s.convert("PAYPALISHIRING", 3);
//     // std::cout << s.convert(R"("A"\n1)", 3);
//     //std::cout << s.convert("A", 1);
//     system("pause");
//     return 0;
// }

