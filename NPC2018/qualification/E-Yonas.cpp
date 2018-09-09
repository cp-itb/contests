#include <bits/stdc++.h>
#define ll long long
#define maks first
#define mini second
#define MAX_SIZE 400005
#define POSINF 10000000000000
#define NEGINF -10000000000000
using namespace std;

// template segment tree from https://www.geeksforgeeks.org/lazy-propagation-in-segment-tree/
ll lazy[MAX_SIZE] = {0};
pair<ll, ll> tree[MAX_SIZE];

void updateRangeUtil(int si, int ss, int se, int us,
                     int ue, ll diff) {
    if (lazy[si] != 0) {
        tree[si].maks += lazy[si];
        tree[si].mini += lazy[si];

        if (ss != se) {
            lazy[si*2 + 1]   += lazy[si];
            lazy[si*2 + 2]   += lazy[si];
        }
        lazy[si] = 0;
    }

    if (ss>se || ss>ue || se<us)
        return ;

    if (ss>=us && se<=ue) {
        tree[si].maks += diff;
        tree[si].mini += diff;

        if (ss != se) {
            lazy[si*2 + 1]   += diff;
            lazy[si*2 + 2]   += diff;
        }
        return;
    }

    int mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);

    tree[si].maks = max(tree[si*2+1].maks, tree[si*2+2].maks);
    tree[si].mini = min(tree[si*2+1].mini, tree[si*2+2].mini);
}

void updateRange(int n, int us, int ue, ll diff)
{
   updateRangeUtil(0, 0, n-1, us, ue, diff);
}

pair<ll, ll> getSumUtil(int ss, int se, int qs, int qe, int si) {
    if (lazy[si] != 0) {
        tree[si].maks += lazy[si];
        tree[si].mini += lazy[si];
        if (ss != se) {
            lazy[si*2+1] += lazy[si];
            lazy[si*2+2] += lazy[si];
        }

        lazy[si] = 0;
    }

    if (ss>se || ss>qe || se<qs)
        return make_pair(NEGINF, POSINF);

    // If this segment lies in range
    if (ss>=qs && se<=qe)
        return tree[si];

    // If a part of this segment overlaps with the given
    // range
    int mid = (ss + se)/2;
    pair<ll, ll> le = getSumUtil(ss, mid, qs, qe, 2*si+1);
    pair<ll, ll> ri = getSumUtil(mid+1, se, qs, qe, 2*si+2);
    return make_pair(max(le.maks, ri.maks), min(le.mini, ri.mini));
}

pair<ll, ll> getSum(int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return make_pair(-1, -1);
    }

    return getSumUtil(0, n-1, qs, qe, 0);
}

void constructSTUtil(int arr[], int ss, int se, int si) {
    if (ss > se)
        return ;

    if (ss == se)
    {
        tree[si].maks = arr[ss];
        tree[si].mini = arr[ss];
        return;
    }

    int mid = (ss + se)/2;
    constructSTUtil(arr, ss, mid, si*2+1);
    constructSTUtil(arr, mid+1, se, si*2+2);

    tree[si].maks = max(tree[si*2+1].maks, tree[si*2+2].maks);
    tree[si].mini = min(tree[si*2+1].mini, tree[si*2+2].mini);
}

void constructST(int arr[], int n) {
    constructSTUtil(arr, 0, n-1, 0);
}


int arr[100005];

int main()
{
    int n, q;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    constructST(arr, n);

    scanf("%d", &q);
    for (int i=0; i<q; i++) {
        int x, l, r, v;
        scanf("%d%d%d", &x, &l, &r);
        l--;
        r--;
        if (x == 1) {
            scanf("%d", &v);
            updateRange(n, l, r, v);
        } else {
            pair<ll, ll> ans = getSum(n, l, r);
            printf("%lld\n", ans.first - ans.second);
        }
    }
    return 0;
}
