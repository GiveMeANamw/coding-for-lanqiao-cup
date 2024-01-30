#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
int nres[502];
void init(const char ob1[],const char ob2[],int nob1[],int nob2[]){
	nob1[0]=strlen(ob1);
	nob2[0]=strlen(ob2);
	for(int i=nob1[0];i>=1;i--){
		nob1[nob1[0]-i+1]=ob1[i-1]-'0';
	}
	for(int i=nob2[0];i>=1;i--){
		nob2[nob2[0]-i+1]=ob2[i-1]-'0';
	}
	int bits=max(nob1[0],nob2[0]);
	for(int i=1;i<=bits;i++){
		nres[i]=nob1[i]+nob2[i];
	}
//	for(int i=0;i<=nob1[0];i++){
//		cout<<nob1[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=0;i<=nob2[0];i++){
//		cout<<nob2[i]<<" ";
//	}
	for(int i=1;i<=bits;i++){
		if(nres[i]>=10){
			nres[i+1]+=(nres[i]/10);
			nres[i]%=10;
		}
	}
	if(nres[bits+1]==0){
		//表示最终没有进位
		nres[0]=bits; 
	}else{
		nres[0]=bits+1; 
	}
	for(int i=nres[0];i>=1;i--){
		cout<<nres[i];
	}
	
}
int main(){
	char ob1[501];
	char ob2[501];
	int nob1[501];
	int nob2[501];
	memset(nob1,0,sizeof(nob1));
	memset(nob2,0,sizeof(nob2));
	memset(nres,0,sizeof(nres));
	cin>>ob1>>ob2;
	init(ob1,ob2,nob1,nob2);
//	cout<<ob1<<endl;
//	cout<<ob2<<endl;
//	int bits=max(strlen(ob1),strlen(ob2));
//	cout<<bits<<endl;
	
	return 0;
}


