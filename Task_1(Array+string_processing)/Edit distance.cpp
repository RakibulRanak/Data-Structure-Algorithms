#include<bits/stdc++.h>
using namespace std;

int min(int x, int y, int z)
{
	return min(min(x, y), z);
}


int editDistDP(string str1, string str2, int m, int n)
{

	int dp[m + 1][n + 1];


	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{

			if (i == 0)
				dp[i][j] = j;


			else if (j == 0)
				dp[i][j] = i;


			else if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];


			else
				dp[i][j] = 1 + min(dp[i][j - 1], // Insert
				                   dp[i - 1][j], // Remove
				                   dp[i - 1][j - 1]); // Replace
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	int i = m, j = n;
	//vector<string>vec;
	//cout<<"hi"<<endl;
	while (i > 0 && j > 0)
	{
		//cout<<"hi2"<<endl;

		if (str1[i - 1] == str2[j - 1])
		{
			cout << "No operations : " << i << endl;
			j--;
			i--;
		}
		else if(dp[i][j] == dp[i - 1][j - 1] + 1)
		{
			cout << "Replaced : " << i << endl;
			i--;
			j--;
		}

		else if (dp[i][j] == dp[i - 1][j] + 1)
		{
			cout << "Deleted : " << i << endl;
			i--;
		}
		else
		{
			cout << "Inserted : " << i << endl;
			j--;
		}

	}

	return dp[m][n];
}


int main()
{

	string str1;
	string str2;
	cin >> str1 >> str2;

	cout << editDistDP(str1, str2, str1.length(), str2.length());

	return 0;
}
