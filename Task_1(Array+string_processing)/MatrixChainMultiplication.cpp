#include<bits/stdc++.h>
using namespace std;
int M[5][5], S[5][5];
void hehe(int i, int j)
{
    
    if (i==j) {
        cout << i;
        return;
    }
    cout << "(";
    hehe(i, S[i][j]);
    hehe(S[i][j] + 1, j);
    cout << ")";

}
int main() {
    int n = 5;
    int p[5] = {5, 4, 6, 2, 7};
    int j, min, q;

    memset(M, 0, sizeof(M));
    memset(S, 0, sizeof(S));
    for (int d = 1; d < n - 1; ++d) {
        for (int i = 1; i < n - d; ++i) {
            j = i + d;
            min = 32767;
            for (int k = i; k <= j - 1; ++k) {
                q = M[i][k] + M[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                if (q < min) {
                    min = q;
                    S[i][j] = k;
                }
            }
            M[i][j] = min;
        }
    }

    printf("%d\n", M[1][n - 1]);
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
            cout << S[i][j] << " ";
        cout << endl;
    }
    hehe(1, 4);
}
