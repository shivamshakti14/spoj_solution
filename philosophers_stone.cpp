#include<iostream>
using namespace std;
#define ll long long

int max(int a,int b){
  if(a>b){
    return a;
  }else{
    return b;
  }
}
int main(){
  ll t;
  cin>>t;
  while(t--){
    ll r,c;
    cin>>r>>c;
    ll i,j,a[r][c];
    for(i=0;i<r;i++){
      for(j=0;j<c;j++){
        cin>>a[i][j];
      }
    }
    for(i=1;i<r;i++){
      for(j=0;j<c;j++){
        int p=a[i][j];
        if(j==0){
          a[i][j] += max(a[i-1][j], a[i-1][j+1]);
        }else if(j==c-1){
          a[i][j] += max(a[i-1][j], a[i-1][j-1]);
        }else{
          a[i][j] += max(max(a[i-1][j], a[i-1][j-1]), a[i-1][j+1]);
        }
        //cout<<a[i][j]<<" ";
      }//cout<<endl;
    }
    int m=0;
    for(i=0;i<c;i++){
      m=max(m,a[r-1][i]);
    }
    cout<<m<<endl;
  }
  return 0;
}