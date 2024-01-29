/*约定数据格式，整形数组倒序存储数据，首元素表示位数，输入不超过99位*/
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

void init(int *a,int *b,string s1,string s2){	
	a[0]=s1.length();
	b[0]=s2.length();
	for(int i=1;i<=a[0];i++){
		a[i]=s1[a[0]-i]-'0';
	}
	for(int i=1;i<=b[0];i++){
		b[i]=s2[b[0]-i]-'0';
	}
}

void add(int a[],int b[],int c[]){
	int i=max(a[0],b[0]);
	int up=0;
	for(int j=1;j<=i+1;j++){
		c[j]=a[j]+b[j]+up;
		if(c[j]>=10){
			up=c[j]/10;
			c[j]%=10;
		}else{
			up=0;
		}
	}
	if(c[i+1]==0){
		c[0]=i;
	}else{
		c[0]=i+1;
	}
}

void print(int *c){
	for(int j=100;j>=1;j--){
		cout<<c[j];
	}
}

void multi(int a[],int b[],int c[]){
	//n位数乘m位数，结果的位数在n+m-1到n+m中 
	int up=0;
	for(int i=1;i<=a[0];i++){
		for(int j=1;j<=b[0];j++){
			c[i+j-1]=a[i]*b[j]+c[i+j-1];
		}
	}
	for(int i=1;i<=a[0]+b[0];i++){
		if(c[i]>=10){
			c[i+1]=c[i+1]+c[i]/10;
			c[i]%=10;
		}
	}
	if(c[a[0]+b[0]]==0){
		c[0]=a[0]+b[0]-1;
	}else{
		c[0]=a[0]+b[0];
	}
}
void step(int n){
	int sum=0;
	int ob=1;
	for(int i=0;i<n;i++){
		sum=sum*ob;
		ob++;
	}
}
void equal(int a[],int b[]){
	memset(a,0,sizeof(a));
	a[0]=b[0];
	for(int i=1;i<=a[0];i++){
		a[i]=b[i];
	}
} 
int main()
{
	//初始化 
	string s1;
	string s2;
	int a[100]={0};//ob1
	int b[100]={0};//ob2
	int c1[100]={0};//result
	int c2[100]={0};//result
	int d[100]={0};//递增算符 
//	cin>>s1;
//	cin>>s2;
//	init(a,b,s1,s2);
//	multi(a,b,c1);
//	print(c1);
	d[0]=1;d[1]=1;
	b[0]=1;b[1]=1;
	a[0]=1;a[1]=1;
	
	for(int i=0;i<3;i++){
		cout<<"相乘前："<<endl;; 
		cout<<"a=";
		print(a);
		cout<<endl;
		cout<<" b=";
		print(b);
		cout<<endl;
		cout<<" c1=";
		print(c1);
		cout<<endl;
		multi(a,b,c1);
		//c1按位复制给a 
		equal(a,c1);
		add(b,d,c2);
		//c2按位复制给b
		equal(b,c2);
		cout<<"相乘后："<<endl;; 
		cout<<"a=";
		print(a);
		cout<<endl;
		cout<<" b=";
		print(b);
		cout<<endl;
		cout<<" c1=";
		print(c1);
		cout<<endl;
	} 
	
}

