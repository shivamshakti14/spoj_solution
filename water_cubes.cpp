#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <queue>
#include <limits.h>
using namespace std;
std::vector<vector < int > > v;
std::vector<vector < int > > arr;
std::vector<vector < int > > visited;
int row,col;
int change_x[]= {0,0,1,-1};
int change_y[]= {-1,1,0,0};
priority_queue < pair <int,pair< int , int > > >  d;
long long solution;
bool check_cord(int x,int y){
	if((x>=0 && x<row) && (y>=0 && y<col)){
		return true;
	}return false;
}

void calc(){
	while(!d.empty()){
		pair < int, pair < int ,int > > p = d.top();
		d.pop();
		int val = p.first;
		int x = p.second.first;
		int y = p.second.second;
		int i;
		for(i=0;i<4;i++){
			int x1=x+change_x[i];
			int y1=y+change_y[i];
			if(check_cord(x1,y1) && visited[x1][y1]==0){
				visited[x1][y1]=1;
				if(v[x1][y1]<arr[x][y]){
					arr[x1][y1]=arr[x][y];
				}else{
					arr[x1][y1]=v[x1][y1];
				}
				d.push(make_pair(-arr[x1][y1],make_pair(x1,y1)));
			}
		}
	}
}

int main(){
	int t,tt;
	cin>>t;
	for(tt=0; tt<t; tt++){
		solution=0;
		int r,c;
		cin>>r>>c;
		row=r;
		col=c;
		v.resize(r);
		visited.resize(r);
		arr.resize(r);
		int i,j;
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				int a;
				cin>>a;
				v[i].push_back(a);
				if(i==0 || i==r-1 || j==0 || j==c-1){
					arr[i].push_back(a);
					visited[i].push_back(1);
					d.push(make_pair(-a,make_pair(i,j)));
				}else{
					arr[i].push_back(0);
					visited[i].push_back(0);
				}
			}
		}
		calc();
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				solution+= (arr[i][j]-v[i][j]);
			}
		}
		cout<<solution<<endl;
		solution=0;
		v.clear();
		visited.clear();
		arr.clear();
	}return 0;
}