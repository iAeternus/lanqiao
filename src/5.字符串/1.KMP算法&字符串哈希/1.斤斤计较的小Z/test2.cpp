/*
sample input1
LQYK
LQYK
sample output1
1

sample input2
LQYK
LQYKLQYKLQYKLQYK
sample output
4

sample input3
AADSDFGADSWADADADD
WSAD
sample output
0
*/
#include <iostream>
#include <string>

int main() {
    std::string str1;
    std::string str2;
    std::getline(std::cin, str1);
    std::getline(std::cin, str2);
    int count = 0;
    size_t pos = 0;
    while ((pos = str2.find(str1, pos)) != std::string::npos) {
        ++count;             // 计数器自增
        pos += str1.size();  // 更新检索点
    }
    std::cout << count;

    return 0;
}