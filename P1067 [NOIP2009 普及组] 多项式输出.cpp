#include <iostream>

using namespace std;

int main(){
	int n;//��
	cin>>n;
	int num[n+1];//ϵ��
	
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
//	cout<<"��һ��������ϵ����"<<num[pos]<<"��ʱ����ָ��Ϊ"<<temp<<endl;
	if(pos==n+1){
		cout<<0;
		return 0;
	}
	//num[pos]�ǵ�һ�������� 
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


