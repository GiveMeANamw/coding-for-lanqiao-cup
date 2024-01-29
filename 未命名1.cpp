#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
//ctrl+z should be placed at the begining 
int main(){
	int n,m;
	cin>>n>>m;
	char map[n][m];
	int num[n][m]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			num[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]=='?'){
				if(j+1<m){
					if(map[i][j+1]='*'){
						num[i][j]++;
					}
				}
				if(j-1>=0){
					if(map[i][j-1]='*'){
						num[i][j]++;
					}
				}
				if(i+1<n){
					if(map[i+1][j]='*'){
						num[i][j]++;
					}
				}
				if(i-1>=0){
					if(map[i-1][j]='*'){
						num[i][j]++;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<num[i][j];
		}
		cout<<endl;
	}
}


