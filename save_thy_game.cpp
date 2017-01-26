#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
#define ll long long
typedef struct Node{
  ll aa[4];
}node;
node *b;

ll max(ll a,ll b){
  if(a>b){
    return a;
  }else{
    return b;
  }
}

ll f(ll *l,ll st, ll c, ll n){
  if(st<n){
    if(b[st].aa[c]==0){
    if(c==1){     
      if(st+1<n){
        b[st].aa[c] =  max(l[st]+f(l,st+1,2,n), max(f(l,st+1,0,n), l[st]+l[st+1]+f(l,st+2,3,n)));
      }
      else{
          b[st].aa[c] = max(l[st]+f(l,st+1,2,n), f(l,st+1,0,n));
      }
    }
    else if(c==2){
       b[st].aa[c] =  max(l[st]+f(l,st+1,3,n), f(l,st+2,0,n));
    }    
    else if(c==3){
      b[st].aa[c] = f(l,st+3,0,n);
    }
    else if(c==0){
       b[st].aa[c] = l[st] + f(l,st+1,1,n);
    }
    //cout<<st+1<<","<<c<<","<<b[st].aa[c]<<endl;
    return b[st].aa[c];
  }else
  return b[st].aa[c];}
  return 0;
}

int main(){
  ll t;
  cin>>t;
  while(t--){
    ll n;
    //cin>>n;
    scanf("%lld",&n);
    ll a[n],i;
    b = (node*)malloc(n*(sizeof(node)));
    for(i=0;i<n;i++){
      scanf("%lld",&a[i]);
      b[i].aa[0]=0;
      b[i].aa[1]=0;
      b[i].aa[2]=0;
      b[i].aa[3]=0;
    }
    //b[0].aa[0]=244;
    //cout<<b[0].aa[0]<<endl;
    b[0].aa[0]=max(a[0]+f(a,1,1,n),b[0].aa[0]);
    //cout<<b[0].aa[0]<<endl;
    //printf("%lld",a[0]+f(a,1,1,n));
    //for(i=0;i<n;i++){
     //printf("%lld ",b[i]);
    //}
    printf("%lld\n",b[0].aa[0]);
  }
  return 0;
}