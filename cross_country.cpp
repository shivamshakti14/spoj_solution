#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define ll long long
using namespace std;
ll max(ll a,ll b){
	if(a>b){
		return a;
	}return b;
}
ll lcs(ll *arr,ll n1,ll *arr1,ll n2){
	ll a[n1+1][n2+1],i,j;
	for(i=0;i<n1+1;i++){
		for(j=0;j<n2+1;j++){
			if(i==0 || j==0){
				a[i][j]=0;
			}else if(arr[i-1]==arr1[j-1]){
				a[i][j] = a[i-1][j-1]+1;
			}else{
				a[i][j] = max(max(a[i-1][j-1],a[i-1][j]), a[i][j-1]);
			}
		}
	}
	//printf("%lld\n", a[n1][n2]);
	return a[n1][n2]-1;
}

int main(){
	ll t;
	scanf("%lld", &t);
	while(t--){
		ll arr[1000];
		ll n=0,p;
		while(1){
			scanf("%lld",&p);
			arr[n]=p;
			n+=1;
			if(p==0){
				break;
			}
		}
		ll mx=0;
		while(1){
			ll arr1[2000],n1=0;
			while(1){
				scanf("%lld",&p);
				arr1[n1]=p;
				n1+=1;
				if(p==0){
					break;
				}
			}
			if(n1==1){
				printf("%lld\n", mx);
				break;
			}else{
				mx = max(lcs(arr,n,arr1,n1),mx);
			}
		}
	}
	return 0;
}