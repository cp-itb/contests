/**
 * Contest : Ideafuse 2021 Qualification
 * Team    : OxD
 * Author  : Marcello Faria
 * Problem : A - Gunpla Collection
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T, N;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    cin >> N;
    int arr[N], sortedArr[N];
    for (int i = 0; i < N; i++)
    {
      cin >> arr[i];
      sortedArr[i] = arr[i];
    }
    sort(sortedArr, sortedArr + N);
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
      if (arr[i] != sortedArr[i])
        cnt++;
    }
    cout << "Case #" << t << ": " << cnt << endl;
  }
}