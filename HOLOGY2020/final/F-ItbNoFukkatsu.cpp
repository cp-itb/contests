/**
 * Contest : Hology 2020 - Final
 * Team    : ItbNoFukkatsu
 * Author  : Muhammad Hasan
 * Problem : F
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int K = 26;

char s[N];
int n;
string q[N];
int L[N], R[N];

struct Trie {
    struct Node {
        Node *child[K];
        int leaf;
        Node() {
            for (int i = 0; i < K; i++)
                child[i] = NULL;
            leaf = 0;
        }
    };

    Node *head;

    Trie() {
        head = new Node();
    }

    void insert(const string& str) {
        Node *cur = head;
        for (char cc : str) {
            int v = cc - 'a';
            if (cur->child[v] == NULL) {
                cur->child[v] = new Node();
            }
            cur = cur->child[v];
        }
        ++cur->leaf;
    }

    void addPos(int x, int y, bool forward) {
        Node *cur = head;
        if (forward) {
            for (int i = x; i <= y; i++) {
                int v = s[i] - 'a';
                if (cur->child[v] == NULL) break;
                cur = cur->child[v];
                R[x] += cur->leaf;
            }
        } else {
            for (int i = y - 1; i >= x; i--) {
                int v = s[i] - 'a';
                if (cur->child[v] == NULL) break;
                cur = cur->child[v];
                L[y] += cur->leaf;
            }
        }
    }
} myTrie, rvTrie;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> (s + 1);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string str; cin >> str;
        myTrie.insert(str);
        reverse(str.begin(), str.end());
        rvTrie.insert(str);
    }
    int len = strlen(s + 1);
    for (int i = 1; i <= len; i++) {
        myTrie.addPos(i, len, 1);
        rvTrie.addPos(1, i, 0);
    }
    long long ans = 0;
    for (int i = 1; i <= len; i++) {
        ans += (1LL) * L[i] * R[i];
    }
    cout << ans << '\n';

    return 0;
}