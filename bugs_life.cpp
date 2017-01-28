#include<iostream>
#include<stdlib.h>
#include<queue>
#include<stdio.h>
#define ll long long
using namespace std;
typedef struct Node{
	ll key;
	struct Node *next;
}node;

node *create(ll key){
	node *t=(node*)malloc(sizeof(node));
	t->key = key;
	t->next = NULL;
	return t;
}
void insert(node **root,ll a,ll key){
	if(root[a]==NULL){
		root[a] = create(key);
	}else{
		node *t=create(key);
		t->next=root[a];
		root[a] = t;
	}
}
/*
void print(node **root,ll n){
	ll i;
	for(i=1;i<=n;i++){
		cout<<i<<"->";
		while(root[i]!=NULL){
			cout<<root[i]->key<<"  ";//<<root[i]->weight<<" "
			root[i]=root[i]->next;
		}//cout<<"\n";
	}
}*/
void bfs(node **root,ll n,ll cc){
	ll visited[n],i;
	for(i=0;i<n;i++){
		visited[i]=0;
	}
	queue <ll> q;
	ll flag=1;
	ll col=0;
	for(i=0;i<n;i++){
		if(visited[i]==0){
			q.push(i+1);
			while(!q.empty()){
				ll u = q.front();
				if(visited[u-1]==0){
					col = 1;
				}else{
					col=visited[u-1];
				}
				//cout<<u<<" ";
				q.pop();
				while(root[u]!=NULL){
					//cout<<visited[root[u]->key - 1]<<" "<<col<<" "<<u<<endl;
					if(visited[root[u]->key - 1]==0){
						if(col==1){
							visited[root[u]->key - 1] = 2;
						}else{
							visited[root[u]->key - 1] = 1;
						}
						q.push(root[u]->key);
					}else if(visited[root[u]->key - 1]==col){
						flag=0;
						break;
					}
					root[u]=root[u]->next;
				}
				if(flag==0){
					break;
				}
			}
		}
		if(flag==0){
			break;
		}
	}
	printf("Scenario #%lld:\n",cc);
	if(flag==0){
		printf("Suspicious bugs found!\n");
	}else{
		printf("No suspicious bugs found!\n");
	}
	return;
}
int main(){
	ll t;
	scanf("%lld",&t);
	ll cc=1;
	while(t--){
		ll n,e,i;
		scanf("%lld %lld",&n,&e);
		node **root = (node**)calloc(n+1,sizeof(node*));
		for(i=0;i<e;i++){
			ll a,b,weight;
			scanf("%lld %lld",&a,&b);
			insert(root,a,b);
			insert(root,b,a);
		}
		//print(root,n);
		bfs(root,n,cc);
		cc+=1;
	}
	return 0;
}