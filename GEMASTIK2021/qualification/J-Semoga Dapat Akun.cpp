 /**
  * Contest : Gemastik XIV (2021) Qualification
  * Team    : Semoga Dapat Akun
  * Author  : Marcello Faria
  * Problem : J - Maximum Sum of Array
  */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int arr[1000006];
int maxSubarraySum(int N, int M)
{
  int MS[N];
  MS[N - 1] = arr[N - 1];
  int mx = 0;
  for (int i = N - 2; i >= 0; i--)
  {
    if (i + M >= N)
    {
      MS[i] = max(arr[i], MS[i + 1]);
    }
    else
    {
      mx = max(mx, MS[i + M]);
      MS[i] = max(arr[i] + mx, MS[i + 1]);
    }
  }

  return MS[0];
}

int main()
{
  int N, M;
  cin >> N >> M;
  memset(arr, 0, sizeof(arr));
  for (int i = 0; i < N; i++)
  {
    cin >> arr[i];
  }
  cout << maxSubarraySum(N, M) << endl;

  return 0;
}