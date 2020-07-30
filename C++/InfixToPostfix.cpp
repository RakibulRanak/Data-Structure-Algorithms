#include <bits/stdc++.h>
using namespace std;

bool isOperand(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/')
		return false;
	else
		return true;
}

int Precedence(char x)
{
	if (x == '+' || x == '-')
		return 1;
	else
		return 2;

}

string InfixToPostfix(string infix)
{
	int len = infix.size();
	string postfix = "";
	stack<char>s;
	int i = 0, j = 0;
	while (i < len)
	{
		if (isOperand(infix[i]))
		{
			postfix += infix[i++];
		}
		else
		{
			if (s.size() == 0 || Precedence(infix[i]) > Precedence(s.top()))
				s.push(infix[i++]);
			else
			{
				while (s.size() != 0 && Precedence(infix[i]) <= Precedence(s.top()))
				{
					char x = s.top();
					s.pop();
					postfix += x;
				}
				s.push(infix[i++]);
			}
		}
	}
	while (!s.empty()) {
		postfix += s.top();
		s.pop();
	}

	return postfix;
}


int main()
{
	string infix;
	cin >> infix;
	string postfix = "";
	postfix = InfixToPostfix(infix);
	cout << postfix << endl;
}