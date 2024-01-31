#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int s[n][n];
	int order[m][4];
	for(int i=0;i<m;i++){
		for(int j=0;j<4;j++){
			cin>>order[i][j];
		}
	}
	int t=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			s[i][j]=t;
			t++;
		}
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			cout<<s[i][j]<<" ";
//		}
//		cout<<endl;
//	}

	
	for(int k=0;k<m;k++){
		//read orders
		int start_col=order[k][0]-1-order[k][2];
		int x0=order[k][0]-1;
		int y0=order[k][1]-1;
		int start_line=order[k][1]-1-order[k][2];
		int lenth=order[k][2]*2+1;
		int temp[lenth][lenth]={0};
		int sub[lenth][lenth]={0};
//		cout<<"start_col="<<start_col<<" start_line="<<start_line<<" lenth="<<lenth<<endl;
		//把子矩阵抠出来 
		for(int i=start_col;i<start_col+lenth;i++){
			for(int j=start_line;j<start_line+lenth;j++){
				sub[i-start_col][j-start_line]=s[i][j];
			}
		}
		//旋转子矩阵 
		for(int i=0;i<lenth;i++){
			for(int j=0;j<lenth;j++){
				if(order[k][3]==0){
					temp[j][lenth-1-i]=sub[i][j];
				}else{
					temp[lenth-1-j][i]=sub[i][j];
				}	
			}
		}
		for(int i=start_col;i<start_col+lenth;i++){
			for(int j=start_line;j<start_line+lenth;j++){
				s[i][j]=temp[i-start_col][j-start_line];
			}
		}
		
		
	}
	for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<s[i][j]<<" ";
			}
			cout<<endl;
		}
}


