#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
using namespace std;

int f(char *s,int n,int i,int s1){
	if(i==n){
		return 1;
	}
	if(i==n-1){
		if((int(s[i])-48)>=s1){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(i==n-2){
		if((int(s[i])-48)>=s1){
			if(int(s[i+1])>=int(s[i])){
				return 2;
			}
			else{
				return 1;
			}
		}
		else{
			if((int(s[i+1])+int(s[i]) -48-48)>=s1){
				return 1;
			}
			else{
				return 0;
			}
		}
	}
	int s2=0;
	int count=0;
	int j;
	for(j=i;j<n;j++){
		s2+=(int(s[j])-48);
		if(s2>=s1){
			count += f(s,n,j+1,s2);
		}
		else{
			count += 0;
		}
	}
	return count;
}

int main(){
	int t=1;
	while(1){
		char s[100];
		//s=(char*)malloc(35*sizeof(char));
		scanf("%s",s);
		//cin>>s;
		//printf("%s\n",s[0] );
		char *ss = s;
		char sss[] ="b";
		if(ss[0]==sss[0]){
			break;
		}else{
			//printf("%s\n",s);
			int count=0;
			int i, n=strlen(s),s1=0;
			for(i=0;i<n;i++){
				s1+=(int(s[i])-48);
				count+=f(s,n,i+1,s1);
			}
			printf("%d. ",t);
			printf("%d\n",count);
			t++;
		}
	}
	return 0;
}