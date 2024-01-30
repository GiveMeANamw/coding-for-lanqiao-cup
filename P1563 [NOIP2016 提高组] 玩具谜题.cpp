#include <iostream>
#include <cstring>
using namespace std;

class person{
	private :
		int f1;
		int f2;
		char job[100];
	public :
		int getf1(){
			return f1;
		}
		int getf2(){
			return f2;
		}
		void setf1(int p){
			f1=p; 
		}
		void setf2(int p){
			f2=p;
		}
		void setjob(const char a[]){
			strcpy(job,a);
		}
		void print(){
			cout<<job;
		}
};
int main(){
//对于朝内的人，从右手起是逆时针方向
//对于朝外的人，从左手起是逆时针方向 
//规定10是朝内，01是朝外 
	int n,m;
	int flag;
	cin>>n>>m;
	char job[100];
	person per[n];
	
	for(int i=0;i<n;i++){
		cin>>flag;
		cin>>job;
		per[i].setjob(job);
		if(flag==0){
			per[i].setf1(1);
			per[i].setf2(0);
		}else{
			per[i].setf1(0);
			per[i].setf2(1);
		}
	}
	int step;
	int pos=0;
	person *p=&per[pos];
	for(int i=0;i<m;i++){
		cin>>flag;
		cin>>step;
		if(flag==0){
			if(per[pos].getf1()==1&&per[pos].getf2()==0){

				pos=(pos-step+n)%n;
			}else if(per[pos].getf1()==0&&per[pos].getf2()==1){

				pos=(pos+step)%n;
			}
		}else{
			if(per[pos].getf1()==1&&per[pos].getf2()==0){

				 pos=(pos+step)%n;
			}else if(per[pos].getf1()==0&&per[pos].getf2()==1){
				pos=(pos-step+n)%n;
			}
		}
	}

	per[pos].print();
	return 0;
}


