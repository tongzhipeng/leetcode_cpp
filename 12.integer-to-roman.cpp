/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 *
 * https://leetcode.com/problems/integer-to-roman/description/
 *
 * algorithms
 * Medium (49.82%)
 * Likes:    631
 * Dislikes: 1978
 * Total Accepted:    246.9K
 * Total Submissions: 478.7K
 * Testcase Example:  '3'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 

 * 
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * 
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given an integer, convert it to a roman numeral. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: 3
 * Output: "III"
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "IV"
 * 
 * Example 3:
 * 
 * 
 * Input: 9
 * Output: "IX"
 * 
 * Example 4:
 * 
 * 
 * Input: 58
 * Output: "LVIII"
 * Explanation: L = 50, V = 5, III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: 1994
 * Output: "MCMXCIV"
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 */
 #include <string>
 #include <iostream>
 #include <cstring>
 using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        char main[] = {'I', 'X', 'C', 'M'};
        char mid[] = {'V', 'L', 'D'};
        std::string strRet;
        int index = 0;
        while (num > 0)
        {      
            int cur_pos_num = num % 10;     
            char buf[5] = { 0 };
            if (cur_pos_num < 4)
            {
                memset(buf, main[index], cur_pos_num);
            }
            else if (cur_pos_num == 4)
            {
                buf[0] = main[index];
                buf[1] = mid[index];
            }
            else if (cur_pos_num < 9)
            {
                buf[0] = mid[index];
                memset(buf + 1, main[index], cur_pos_num - 5);
            }
            else
            {
                buf[0] = main[index];
                buf[1] = main[index + 1];
            }
            strRet = std::string(buf) + strRet;
            num /= 10;
            index++;
        }
        return strRet;
    }

    // string intToRoman(int num) {
    //     string table[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
    //                         {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
    //                         {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
    //                         {"", "M", "MM", "MMM"}
    //                         };
    //     string result;
    //     int count = 0;
    //     while(num > 0){
    //         int temp = num % 10;
    //         result = table[count][temp] + result;
    //         num /= 10;
    //         count++;
    //     }
    //     return result;
    // }
};

// int main()
// {
//     Solution s;

//     cout << s.intToRoman(1994) << endl;
//     return 0;
// }

