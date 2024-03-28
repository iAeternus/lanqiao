/*
小蓝的括号串 1  
问题描述
小蓝有一个长度为n的括号串，括号串仅由字符（、）构成，请你帮他判断一下该括号串是否合法，合法请输出Yes，反之输出No。
合法括号序列：
1．空串是合法括号序列。
2．若8是合法括号序列，则（S）也是合法括号序列。3．若s,t都是合法括号序列，
   则st也是合法括号序列。例如（)(),(()),(())(）均为合法括号序列。

输入格式
第一行包含一个正整数n，表示括号串的长度。
第二行包含一个长度为n的括号串。

输出格式
输出共1行，若括号串合法请输出Yes，反之输出No。

样例输入1
10
(()(()))()
样例输出1
Yes

样例输入2
5
()()(
样例输出2
No
*/
#include <iostream>
#include <stack>

bool solve(const std::string& str)
{
    std::stack<char> st;

    for(char c : str)
    {
        if(c == '(')
        {
            st.push(c);
        }
        else // )
        {
            if(st.empty()) return false;
            
            st.pop();
        }
    }

    return st.empty();
}

int main()
{
    int n;
    std::cin >> n;
    std::string str;
    std::cin >> str;

    std::cout << (solve(str) ? "Yes" : "No") << std::endl;

    return 0;
}