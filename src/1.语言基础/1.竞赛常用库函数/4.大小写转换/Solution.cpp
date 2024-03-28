#include <iostream>
#include <string>

char convertedCh(char ch)
{
    if(islower(ch)) ch = toupper(ch);
    else if(isupper(ch)) ch = tolower(ch);
    return ch;
}

int main()
{
    std::string s;
    std::getline(std::cin, s);
    for(auto& c : s)
    {
        c = convertedCh(c);
    }
    std::cout << s << std::endl;
    return 0;
}