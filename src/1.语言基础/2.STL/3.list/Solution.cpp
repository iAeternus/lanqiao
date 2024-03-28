#include <iostream>
#include <list>
#include <algorithm>

int main()
{
    std::list<int> myList;
    for (int i = 0; i < 10; ++i)
    {
        myList.push_back(i);
    }

    for (const auto& it : myList)
    {
        std::cout << it << std::endl;
    }

    std::cout << "=========================================\n";

    std::reverse(myList.begin(), myList.end());

    for (const auto& it : myList)
    {
        std::cout << it << std::endl;
    }

    return 0;
}