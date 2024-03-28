/*
https://www.lanqiao.cn/problems/3416/learning/?page=1&first_category_id=1&name=%E5%9B%9B%E5%85%83%E7%BB%84%E9%97%AE%E9%A2%98
大事化小：对于a<b<c<d.题目要求D<C<A<B 我们可考虑找到一个尽量大的数A， 
A怎么找？ 用一个栈存放第一个元素，后续数组元素a[i]依次进栈，如果a[i]大于栈顶元素，意味着找到了符合A<B的一种情况，
此时用k记录下来这个栈顶元素，k表示前 i 个数中所有满足条件A<B的最大的A。
显然 k 是需要不断更新的，我们不断判断 待进栈 元素是否大于栈顶元素，如果大于就出栈，并把出栈的元素和k比较。
因为出栈的元素就是符合A<B的A,出栈后继续比较栈顶元素和当前待进栈元素的大小。
直到栈空或者栈顶元素不小于这个进栈元素，最后让这个待进栈元素进栈。 
这样我们动态找到了最大的A,然后在后续元素j中判断，如果num[j]<A,那么num[j]就是我们要找的C，
接下来只需要判断j后面最小的数是否小于C, C后面最小的数怎么找？ 
用一个后缀和找： 
//min_r[i]表示i右边最小的数 vector min_r(n,INF); 
for(int i = n - 1;i >= 1;--i){ min_r[i] = min(min_r[i+1],a[i+1]); } 
如果小于，表示我们找到了D<C<A<B。输出 YES,否则继续让num[j]和栈顶元素判段。
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int N = 5e5 + 5;
int a[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    stack<int> st;
    int k = INT_MIN, INF = INT_MAX;
    // min_r[i]表示i右边最小的数
    vector<int> min_r(n, INF);
    for (int i = n - 1; i >= 1; --i)
    {
        min_r[i] = min(min_r[i + 1], a[i + 1]);
    }
    // d<c<a<b...k对应a,a[i]为b,min_r[i]为d
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] < k)
        {
            if (a[i] > min_r[i])
            {
                cout << "YES";
                return 0;
            }
        }

        while (!st.empty() && st.top() < a[i])
        {
            k = max(k, st.top());
            st.pop();
        }
        st.push(a[i]);
    }
    cout << "NO";

    return 0;
}