#include<iostream>
#include<string.h>
#include<algorithm>
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
    char a[6100],b[6100];
    cin>>a;
    strcpy(b,a);
    int n=strlen(a),i,j;
    reverse(b, b+n);
    //cout<<b;
    int arr[n+1][n+1];
    for(i=0;i<=n;i++){
      for(j=0;j<=n;j++){
        if(i==0 or j==0){
          arr[i][j]=0;
        }else if(a[i-1]==b[j-1]){
          arr[i][j] = arr[i-1][j-1]+1;
        }else{
          arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
        }
      }
    }
    cout<<n-arr[n][n]<<endl;
  }
  return 0;
}