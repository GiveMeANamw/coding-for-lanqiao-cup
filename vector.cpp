#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

#define int long long

const int maxn=100010;
int a[maxn];
int cnt;
int ans;

int quick_pow(int a,int b){
	int num=1;
	while(b){
		if(b&1) num=num*a;
		a=a*a;
		b>>=1;
	}
	return num;
}

signed main(){
	while(cin>>a[++cnt]);
	for(int i=1;i<cnt;i++){
		ans+=(quick_pow(2,cnt-2)*a[i]);
	}
	cout<<ans<<'\n';
	return 0;
}
