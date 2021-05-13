#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool is_valid(string& str)
{
    stack<char> s;
    int tmp = 0;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] == '(' || str[i] == ')')
            s.push(str[i]);
    }
    if (s.top() != ')')
        return false;
    while (!s.empty())
    {
        if (s.top() == ')')
            ++tmp;
        else
            --tmp;
        s.pop();
    }
    if (tmp == 0)
        return true;
    return false;
}

bool is_balanced_brackets(string& str)
{
    stack<char> s;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            s.push(str[i]);
        if (str[i] == ')' && s.top()=='(')
            s.pop();
        if (str[i] == ']' && s.top() == '[')
            s.pop(); 
        if (str[i] == '}' && s.top() == '{')
            s.pop();
    }    
    if (s.empty())
        return true;
    return false;
}

int main()
{
    string str = ")(";
    if (is_valid(str))
        cout << "valid string" << '\n';
    else
        cout << "invalid string" << '\n';

    string str1 = "([)]";
    if (is_balanced_brackets(str1))
        cout << "valid string" << '\n';
    else
        cout << "invalid string" << '\n';

    system("pause");
    return 1;
}