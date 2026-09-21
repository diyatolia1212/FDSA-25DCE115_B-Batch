#include <iostream>
#include <stack>
#include <cctype>
using namespace std;
int priority(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;

    if (ch == '*' || ch == '/')
        return 2;

    return 0;
}
int main()
{
    string infix, postfix = "";
    stack<char> s;
    cout << "Enter infix expression: ";
    cin >> infix;
    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];
        if (isdigit(ch))
        {
            postfix = postfix + ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (s.top() != '(')
            {
                postfix = postfix + s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && priority(s.top()) >= priority(ch))
            {
                postfix = postfix + s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty())
    {
        postfix = postfix + s.top();
        s.pop();
    }
    cout << "Postfix expression: " << postfix << endl;
    stack<int> values;
    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];
        if (isdigit(ch))
        {
            values.push(ch - '0');
        }
        else
        {
            int b = values.top();
            values.pop();
            int a = values.top();
            values.pop();
            if (ch == '+')
                values.push(a + b);
            else if (ch == '-')
                values.push(a - b);
            else if (ch == '*')
                values.push(a * b);
            else if (ch == '/')
                values.push(a / b);
        }
    }
    cout << "Result: " << values.top() << endl;
    return 0;
}
