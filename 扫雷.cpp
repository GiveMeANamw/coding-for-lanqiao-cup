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
//				cout<<"("<<i<<","<<j<<")"<<endl;
				if(j+1<m){
					if(map[i][j+1]=='*'){
//						cout<<"find it from right"<<endl;
						num[i][j]++;
					}
				}
				if(j-1>=0){
					if(map[i][j-1]=='*'){
//						cout<<"find it from left"<<endl;
						num[i][j]++;
					}
				}
				if(i+1<n){
					if(map[i+1][j]=='*'){
//						cout<<"find it from beneath"<<endl;
						num[i][j]++;
					}
				}
				if(i-1>=0){
					if(map[i-1][j]=='*'){
//						cout<<"find it from above"<<endl;
						num[i][j]++;
					}
				}
				if(i+1<n&&j-1>=0){
					if(map[i+1][j-1]=='*'){
//						cout<<"find it from above"<<endl;
						num[i][j]++;
					}
				}
				if(i-1>=0&&j-1>=0){
					if(map[i-1][j-1]=='*'){
//						cout<<"find it from above"<<endl;
						num[i][j]++;
					}
				}
				if(i+1<n&&j+1<m){
					if(map[i+1][j+1]=='*'){
//						cout<<"find it from above"<<endl;
						num[i][j]++;
					}
				}
				if(i-1>=0&&j+1<m){
					if(map[i-1][j+1]=='*'){
//						cout<<"find it from above"<<endl;
						num[i][j]++;
					}
				}
				map[i][j]=num[i][j]+'0';
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<map[i][j];
		}
		cout<<endl;
	}
	return 0;
}


