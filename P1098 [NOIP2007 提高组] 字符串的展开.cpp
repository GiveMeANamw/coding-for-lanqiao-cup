#include <iostream>
#include <string.h>
using namespace std;

int main(){
	int order[3]={0,0,0};
	for(int i=0;i<3;i++){
		cin>>order[i];
	}
	char str[100];
	cin>>str;
	for(int i=0;i<strlen(str);i++){
		//ֻ�е�-���߶�Ϊ�ַ��������ֵ�ʱ����ܽ���չ������
		if(str[i]!='-')
			cout<<str[i]; 
		if(str[i]=='-'&&
		   ((str[i+1]>='a'&&str[i+1]<='z'&&str[i-1]>='a'&&str[i-1]<='z')||
		   (str[i+1]>='0'&&str[i+1]<='9'&&str[i-1]>='0'&&str[i-1]<='9'))&&(str[i+1]>str[i-1])
		  ){
		  	if(order[0]==1){
//		  		cout<<"��չСд��ĸ������"<<endl;
				if(order[2]==1){
					for(char j=str[i-1]+1;j<str[i+1];j++){
						for(int k=0;k<order[1];k++){
							cout<<j;
						}						
					} 
				}else if(order[2]==2){
				//��չСд��ĸ���� 
					for(char j=str[i+1]-1;j>str[i-1];j--){
						for(int k=0;k<order[1];k++){
							cout<<j;
						}
					}
				}
			}else if(order[0]==2){
				//��չΪ��д��ĸ ,���� 
				if(order[2]==1){
					for(char j=str[i-1]+1;j<str[i+1];j++){
						for(int k=0;k<order[1];k++){
							if(j>='a'&&j<='z'){
								char t=j-'a'+'A';
								cout<<t;
							}else{
								cout<<j;
							} 
						}
					} 
				}else if(order[2]==2){
				//��չ��д��ĸ���� 
					for(char j=str[i+1]-1;j>str[i-1];j--){
						for(int k=0;k<order[1];k++){
							if(j>='a'&&j<='z'){
								char t=j-'a'+'A';
								cout<<t;
							}else{
								cout<<j;
							}
						} 
					}
				}
			}else if(order[0]==3){
				for(char j=str[i-1]+1;j<str[i+1];j++){
					for(int k=0;k<order[1];k++)
						cout<<'*';
				}
			}
			
		}else{
			if(str[i]=='-')
				cout<<'-';
		}
		
	}
}


