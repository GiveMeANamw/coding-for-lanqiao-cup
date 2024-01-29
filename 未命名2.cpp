#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin>>n;
	
	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=0;
		}
	}
	a[0][(n-1)/2]=1;
	//k-1的行和列 
	int i=0;
	int j=(n-1)/2;
	 
	for(int k=2;k<=n*n;k++){
		if(i==0&&j!=n-1){
//			cout<<"option1"<<endl; 
			a[n-1][j+1]=k;
			i=n-1;
			j=j+1;
//			cout<<"("<<i<<","<<j<<") "<<k<<endl;
		}
		else if(i!=0&&j==(n-1)){
//			cout<<"option2"<<endl; 
			a[i-1][0]=k;
			i=i-1;
			j=0;
//			cout<<"("<<i<<","<<j<<") "<<k<<endl;
		}
		else if(i==0&&j==(n-1)){
//			cout<<"option3"<<endl; 
			a[i+1][j]=k;
			i=i+1;
//			cout<<"("<<i<<","<<j<<") "<<k<<endl;
		}
		else if(i!=0&&j!=(n-1)){
//			cout<<"option4"<<endl; 
			if(a[i-1][j+1]==0){
				a[i-1][j+1]=k;
				i=i-1;
				j=j+1;
//				cout<<"("<<i<<","<<j<<") "<<k<<endl;
			}else{
				a[i+1][j]=k;
				i=i+1;
//				cout<<"("<<i<<","<<j<<") "<<k<<endl;
			}
		}
//		cout<<"circle end"<<endl;
	}
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cout<<a[x][y]<<" ";
		}
		cout<<endl;
	}
}
