#include<bits/stdc++.h>
using namespace std;

string lcs( string X, string Y, int m, int n )
{
	
	int L[m + 1][n + 1];
	int i, j;

	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;

			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	//find the lcs string
	string s = "";
	i = m, j = n;
	while (L[i][j]!=0)
	{

		if (X[i-1]==Y[j-1])
		{
			s = X[i - 1] + s;
			j--;
			i--;
		}
		else if (L[i - 1][j] == L[i][j - 1])
		{
			if(i>=j)
				j--;
			else
				i--;
		}
		else if (L[i - 1][j] > L[i][j - 1])
			i--;
		else
			j--;
	}

	return s;
}


int main()
{
	string X, Y;
	cin >> X >> Y;


	int m = X.size();
	int n = Y.size();
	string ans = lcs( X, Y, m, n ) ;
	cout << ans.size() << endl;
	cout << ans << endl;

	return 0;
}
