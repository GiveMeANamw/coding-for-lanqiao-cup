#include <iostream>

using namespace std;

int main(){
	int n;//幂
	cin>>n;
	int num[n+1];//系数
	
	for(int i=0;i<n+1;i++){
		cin>>num[i];
	}
	int temp=n;
	int pos=0;
	//find the first none-0
	while(num[pos]==0&&pos<=n){
//		cout<<"circle run"<<endl;
		pos++;
		temp--;
	}
//	cout<<"第一个非零项系数是"<<num[pos]<<"此时的幂指数为"<<temp<<endl;
	if(pos==n+1){
		cout<<0;
		return 0;
	}
	//num[pos]是第一个非零项 
	if(temp!=0){
		if(num[pos]>1){
			cout<<num[pos]<<"x^"<<temp;
		}else if(num[pos]==1){
			cout<<"x^"<<temp;
		}else if(num[pos]<-1){
			cout<<num[pos]<<"x^"<<temp;
		}else if(num[pos]==-1){
			cout<<"-x^"<<temp;
		}
	}else{
		cout<<num[pos];
	}
	temp--;

	for(int i=pos+1;i<n+1;i++){
		if(temp>1){
			if(num[i]>1){
			cout<<"+"<<num[i]<<"x^"<<temp;
			}else if(num[i]==1){
				cout<<"+x^"<<temp;
			}else if(num[i]==0){
				
			}else if(num[i]<-1){
				cout<<num[i]<<"x^"<<temp;
			}else if(num[i]==-1){
				cout<<"-x^"<<temp;
			}
		}else if(temp==0){
			if(num[i]>0){
				cout<<"+"<<num[i];
			}else if(num[i]==0){
				
			}else if(num[i]<0){
				cout<<num[i];
			}
		}else if(temp==1){
			if(num[i]>1){
			cout<<"+"<<num[i]<<"x";
			}else if(num[i]==1){
				cout<<"+x";
			}else if(num[i]==0){
				
			}else if(num[i]<-1){
				cout<<num[i]<<"x";
			}else if(num[i]==-1){
				cout<<"-x";
			}
		}
		temp--;
	}
}


