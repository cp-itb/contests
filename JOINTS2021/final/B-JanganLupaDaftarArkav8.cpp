#include <bits/stdc++.h>
using namespace std;

struct {
    bool operator()(string a, string b) const
    {
        string value1 = a + b;
        string value2 = b + a;
 
        return value1 < value2;
    }
} customCompare;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin>>n;
    vector <int> v1;
    vector <string> v;
    for(int i =0 ; i<n;i++)
    {
        int x;
        cin>>x;
        v1.push_back(x);
    }
    
    for(int a : v1) {
        v.push_back(to_string(a));
        // cout<<to_string(a)<<endl;
    }
    sort(begin(v), end(v), customCompare);
    bool lead = false;
    for (size_t i = 0; i < v.size(); ++i) 
    {
        if(v[i].compare("0") == 0 && !lead)
        {
            continue;
        }
        lead = true;
        cout<<v[i];
    }
    if(!lead) {
        cout<<"0";
    }
    cout<<endl;
    return 0;
}