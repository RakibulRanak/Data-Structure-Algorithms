
#include<bits/stdc++.h>
using namespace std;


int minCoins(int coins[], int m, int V)
{
 
    int table[V + 1];
    table[0] = 0;

    for (int i = 1; i <= V; i++)
        table[i] = 100;


    for (int i = 0; i < m; i++)
    {
       
        for (int j = coins[i]; j <= V; j++)
            table[j]=min(table[j-coins[i]]+1 ,table[j]);
        for (int x = 0; x <= V; x++)
            cout<<table[x]<<" ";
        cout<<endl;
    }
    return table[V];
}


int main()
{
    int coins[] = {1, 5, 6,8};
    int m = sizeof(coins) / sizeof(coins[0]);
    int V = 11;
    cout << "Minimum coins required is "
         << minCoins(coins, m, V);
    return 0;
}
