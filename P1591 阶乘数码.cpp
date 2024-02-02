#include <iostream>
#include <string.h>
using namespace std;

void add(int a[],int b[],int c[]){
	int bits=max(a[0],b[0])+1;
	for(int i=1;i<=bits;i++){
		c[i]=a[i]+b[i];
	}	
	for(int i=1;i<=bits;i++){
		if(c[i]>=10){
			c[i+1]+=(c[i]/10);
			c[i]%=10;
		}
	}
	if(c[bits]==0){
		c[0]=bits-1;
	}else{
		c[0]=bits;
	}
	for(int i=c[0]+1;i<10000;i++){
		c[i]=0;
	}
}

void multi(int a[],int b[],int c[]){
	for(int i=1;i<=a[0];i++){
		for(int j=1;j<=b[0];j++){
			c[i+j-1]+=a[i]*b[j];
		}
	}
	int bits=a[0]+b[0];
	for(int i=1;i<=bits;i++){
		if(c[i]>=10){
			c[i+1]+=(c[i]/10);
			c[i]%=10;
		}
	}
	if(c[bits]==0){
		c[0]=bits-1;
	}else{
		c[0]=bits;
	}
	for(int i=c[0]+1;i<10000;i++){
		c[i]=0;
	}
}
void print(int a[]){
	for(int i=a[0];i>=1;i--){
		cout<<a[i];
	}
}
void copy(int a[],int c[]){
	for(int i=0;i<10000;i++){
		a[i]=c[i];
	}
}
void setZero(int a[]){
	for(int i=0;i<10000;i++){
		a[i]=0;
	}
	a[0]=1;
}
void setOne(int a[]){
	for(int i=0;i<10000;i++){
		a[i]=0;
	}
	a[0]=1;a[1]=1;
}
int main(){
	int a[10000];
	int b[10000];
	int c[10000];
	int d[10000];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	a[0]=1;b[0]=1;a[1]=1;b[1]=1;c[0]=1;c[1]=0;d[0]=1;d[1]=1;
	int n;
	cin>>n;
	int order[n][2];
	for(int i=0;i<n;i++){
		cin>>order[i][0]>>order[i][1];
	}
	for(int i=0;i<n;i++){
//		cout<<"cic"<<endl;
		for(int j=0;j<order[i][0];j++){
			multi(a,b,c);
			copy(a,c);
			add(b,d,b);
			setZero(c);
		}
		int count=0;
		for(int j=1;j<=a[0];j++){
			if(a[j]==order[i][1]){
				count++;
			}
		}
		cout<<count<<endl;
//		print(a);
//		cout<<endl;
		setOne(a);
		setOne(b);
		setZero(c);
	}
}


