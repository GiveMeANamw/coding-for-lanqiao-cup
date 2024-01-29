#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;
int main(){
	int n;
	int op;
	char a[100];
	char b[100];
	cin>>n;
	cin>>a;
	for(int i=0;i<n;i++){
		cin>>op;
		if(op==1){
			cin>>b;
			strcat(a,b);
			cout<<a<<endl;
		}else if(op==2){
			//keep word from x to y
			int x=0;
			int y=0;
			cin>>x>>y;
			a[x+y]='\0';//avoid memory overlap
			strcpy(b,&a[x]);
			strcpy(a,b);
			cout<<a<<endl;
		}else if(op==3){
			char c[100];
			int pos=0;
			cin>>pos;
			cin>>c;
			for(int i=0;i+pos+1<100;i++){
				b[i]=a[i+pos];
				a[i+pos]='\0';
			}
			strcat(a,c);
			strcat(a,b);
			cout<<a<<endl;
		}else if(op==4){
			cin>>b;
			char*p=strstr(a,b);
			if(p!=NULL){
				char *q=&a[0];
				int count=0;
				while(q!=p){
					count++;
					q++;
				}
				cout<<count<<endl;
			}else{
				cout<<-1<<endl;
			}
		}
	}
}
