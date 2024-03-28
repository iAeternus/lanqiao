#include <iostream>
#include <stack>

int main()
{
    std::stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    std::cout << "top = " << st.top() << std::endl;
    st.pop();

    std::cout << (st.empty() ? "empty" : "not empty") << std::endl;
    std::cout << "size = " << st.size() << std::endl;

    return 0;
}