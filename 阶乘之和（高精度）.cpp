#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
//加法可以把按位相加的结果覆盖其中一个操作数
//乘法不可以，需要把结果存到一个空数组里面，再进行操作
//进行乘法之前还要把存放结果的数组清零 
void add(int a[],int b[],int c[]){
	int bits=max(a[0],b[0]);
//	cout<<"bits="<<bits<<endl;
	for(int i=1;i<=bits;i++){
		c[i]=a[i]+b[i];
//		cout<<"c["<<i<<"]="<<c[i]<<endl;
	}
	for(int i=1;i<=bits+1;i++){
		if(c[i]>=10){
			c[i+1]+=(c[i]/10);
			c[i]%=10;
		}
	}
	if(c[bits+1]==0){
		c[0]=bits;
	}else{
		c[0]=bits+1;
	}
	for(int i=c[0]+1;i<1000;i++){
		c[i]=0;
	}
//	cout<<"c[0]="<<c[0]<<endl;
}

void multi(int a[],int b[],int c[]){
	c[0]=1;
	c[1]=0;
	for(int i=1;i<1000;i++){
		c[i]=0;
	}
	int bits=a[0]+b[0];
	for(int i=1;i<=a[0];i++){
		for(int j=1;j<=b[0];j++){
			c[i+j-1]+=a[i]*b[j];
		}
	}
	for(int i=1;i<=bits;i++){
		if(c[i]>=10){
			c[i+1]+=(c[i]/10);
			c[i]%=10;
		}
	}
	if(c[bits]!=0){
		c[0]=bits;
	}else{
		c[0]=bits-1;
	}
	for(int i=c[0]+1;i<1000;i++){
		c[i]=0;
	}
}
void print(int a[]){
	for(int i=a[0];i>=1;i--){
		cout<<a[i];
	}
}
void copy(int a[],int c[]){
	for(int i=0;i<1000;i++){
		a[i]=c[i];
	}
}
void reset_1(int a[]){
	a[0]=1;
	a[1]=1;
	for(int i=2;i<1000;i++){
		a[i]=0;
	}
} 
int main(){
	int a[1000];
	int b[1000];
	int c[1000];
	int d[1000];
	int sum[1000];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	memset(sum,0,sizeof(sum));
	a[0]=1;b[0]=1;d[0]=1;sum[0]=1;
	a[1]=1;b[1]=1;d[1]=1;sum[1]=0;
//	multi(a,b,c);
//	print(c);
	int n=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=i;j>0;j--){
			multi(a,b,c);
			copy(a,c);
			add(b,d,b);
		}
		add(sum,a,sum);
		//把abc重置 
		reset_1(a);
		reset_1(b);
		reset_1(c);
	}
	
	print(sum);
}


