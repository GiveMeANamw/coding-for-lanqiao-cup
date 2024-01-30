#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
int nres[4001];
void init(const char ob1[],const char ob2[],int nob1[],int nob2[]){
	int l_ob1=strlen(ob1);
	int l_ob2=strlen(ob2);
	nob1[0]=l_ob1;
	nob2[0]=l_ob2;
	for(int i=l_ob1;i>=1;i--){
		nob1[nob1[0]-i+1]=ob1[i-1]-'0';
	} 
	for(int i=l_ob2;i>=1;i--){
		nob2[nob2[0]-i+1]=ob2[i-1]-'0';
	}
//	for(int i=1;i<=nob1[0];i++){
//		cout<<nob1[i];
//	}
//	cout<<endl;
//	for(int i=1;i<=nob2[0];i++){
//		cout<<nob2[i];
//	}
}
void multi(const int nob1[],const int nob2[]){
	for(int i=1;i<=nob1[0];i++){
		for(int j=1;j<=nob2[0];j++){
			nres[i+j-1]+=nob1[i]*nob2[j];
		}
	}
	for(int i=1;i<=nob1[0]+nob2[0];i++){
		if(nres[i]>=10){
			nres[i+1]+=nres[i]/10;
			nres[i]%=10;
		}
	}
	if(nres[nob1[0]+nob2[0]]==0){
		nres[0]=nob1[0]+nob2[0]-1;
	}else{
		nres[0]=nob1[0]+nob2[0];
	}
	int flag=0;
	for(int i=nres[0];i>=1;i--){
		if(nres[i]!=0){
			flag=1;
		}
	}
	if(flag==1){
//		cout<<"not 0"<<endl;
		for(int i=nres[0];i>=1;i--){
			cout<<nres[i];
		}
	}else{
		cout<<0;
	}
	
}
int main(){
	char ob1[2001];
	char ob2[2001];
	int nob1[2001];
	int nob2[2001];
	memset(nob1,0,sizeof(nob1));
	memset(nob2,0,sizeof(nob2));
	memset(nres,0,sizeof(nres));
	cin>>ob1>>ob2;
	init(ob1,ob2,nob1,nob2);
	multi(nob1,nob2);
//	cout<<ob1<<endl;
//	cout<<ob2<<endl;
//	int bits=max(strlen(ob1),strlen(ob2));
//	cout<<bits<<endl;
	
	return 0;
}


