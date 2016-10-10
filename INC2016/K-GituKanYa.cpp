/**
 * Contest : INC 2016
 * Team    : GituKanYa
 * Author  : Turfa Auliarachman
 * Problem : K - Operations on Matrix
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > rotateCCW(vector<vector<int> > mat){
    vector<vector<int> > ret;
    ret = mat;

    for(int i=0;i<ret.size();i++){
      for(int j=0;j<ret.size();j++){
        ret[i][j] = mat[j][ret.size()-i-1];
      }
    }

    return ret;
}

vector<vector<int> > rotateCW(vector<vector<int> > mat){
    vector<vector<int> > ret;
    ret = mat;

    for(int i=0;i<ret.size();i++){
      for(int j=0;j<ret.size();j++){
        ret[j][ret.size()-i-1] = mat[i][j];
      }
    }

    return ret;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  for(int tc=1;tc<=t;tc++){
      int n,m,q;
      vector<vector<int> > mat;
      cout << "Case #" << tc << ":\n";


      cin >> n >>m>>q;
      vector<int> kosong(m,0);

      for(int i=0;i<n;i++){
        mat.push_back(kosong);
        for(int j=0;j<m;j++){
          cin >> mat[i][j];
        }
      }

      while(q--){
        string op1, op2;
        cin >> op1 >> op2;

        if (op1=="rotate"){
          int r,c,s;
          vector<vector<int> > keluar;
          cin >> r >> c >>s;
          r--;c--;

          for(int i=r;i<=r+s;i++){
            keluar.push_back(kosong);
            for(int j=c;j<=c+s;j++){
              keluar[i-r][j-c] = mat[i][j];
            }
          }

          if (op2=="cw") keluar = rotateCW(keluar);
          else keluar = rotateCCW(keluar);

          for(int i=r;i<=r+s;i++){
            for(int j=c;j<=c+s;j++){
              mat[i][j] = keluar[i-r][j-c];
            }
          }
        }
        else{
          int r1,c1,r2,c2;
          cin >> r1 >> c1 >> r2 >> c2;

          r1--;c1--;r2--; c2--;

          if(op2=="x"){
            for(int i=r1;i<=(r1+r2)/2;i++){
              for(int j=c1;j<=c2;j++){
                swap(mat[i][j],mat[r1+r2-i][j]);
              }
            }
          }
          else{
            for(int i=r1;i<=r2;i++){
              for(int j=c1;j<=(c1+c2)/2;j++){
                swap(mat[i][j],mat[i][c1+c2-j]);
              }
            }
          }
        }
      }

      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          cout << mat[i][j] << (j==m-1?"\n":" ");
        }
      }

  }

}
