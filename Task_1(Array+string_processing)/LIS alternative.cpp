
#include <bits/stdc++.h>

using namespace std;


int longOddEvenIncSeq(int arr[], int n)
{

	int lioes[n];

	int maxLen = 0;

	for (int i = 0; i < n; i++)
		lioes[i] = 1;


	for (int i = 1; i < n; i++){
		for(int i=0;i<n;i++)
			cout<<lioes[i]<<" ";
		cout<<endl;
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j] && (arr[i] + arr[j]) % 2 != 0 && lioes[i] < lioes[j] + 1)
				lioes[i] = lioes[j] + 1;
	}


	for (int i = 0; i < n; i++)
		if (maxLen < lioes[i])
			maxLen = lioes[i];


	return maxLen;
}


int main()
{
	int arr[] = { 1, 2, 4, 4, 5, 5, 6, 8};
	int n = sizeof(arr) / sizeof(n);
	cout << "Longest Increasing Odd Even "
	     << "Subsequence: "
	     << longOddEvenIncSeq(arr, n);
	return 0;
}
