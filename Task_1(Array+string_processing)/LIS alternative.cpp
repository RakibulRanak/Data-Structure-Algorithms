
#include <bits/stdc++.h>

using namespace std;


int main()
{
	int ara[] = { 1, 2, 3, 4, 5, 5, 8, 9};
	int n = sizeof(ara) / sizeof(n);
	int lioes[n];

	int max= 0;
	int lastindex;
	bool odd = false, even = false;

	for (int i = 0; i < n; i++)
		lioes[i] = 1;


	for (int i = 1; i < n; i++) {
		for (int i = 0; i < n; i++)
			cout << lioes[i] << " ";

		cout << endl;

		for (int j = 0; j < i; j++) {
			if (ara[i] > ara[j] && (ara[i] + ara[j]) % 2 != 0 && lioes[i] < lioes[j] + 1) {
				lioes[i] = lioes[j] + 1;
				if (lioes[i] > max) {
					max= lioes[i];
					lastindex = i;
					if (lioes[i] % 2 == 1) {
						odd = true;
						even = false;

					}
					else
					{
						odd = false;
						even = true;
					}

				}
			}
		}
	}
	for(int i=0;i<n;i++)
		cout<<lioes[i]<<" ";
	cout<<endl;

	cout << max << endl;
	vector<int>vec;

	int value = ara[lastindex];
	int i = lastindex;
	while (max > 0)
	{
		if ((i == lastindex &&even &&ara[i]%2==0) || (value > ara[i] && even &&ara[i]%2==0))
		{
			max--;
			vec.push_back(ara[i]);
			value = ara[i];
			even = false;
			odd = true;


		}
		else if ((i == lastindex && odd && ara[i]%2==1) || (value > ara[i] && odd &&ara[i]%2==1))
		{
			max--;
			vec.push_back(ara[i]);
			value = ara[i];
			even = true;
			odd = false;

		}
		i--;
	}
	for (int i = vec.size() - 1; i >= 0; i--)
		cout << vec[i] << " ";
	cout << endl;

	return 0;
}
