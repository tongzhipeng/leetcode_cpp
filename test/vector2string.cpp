#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    std::string str = "hello";
    std::vector<char> ary(str.begin(), str.end());

    std::string str2(ary.begin(), ary.end());
    std::cout << ", str2=" << str2;
    return 0;    
}