#include <iostream>
#include <cstring>
using namespace std;

class person{
	private :
		person *left;
		person *right;
		char job[100];
	public :
		person *getleft(){
			return this->left;
		}
		person *getright(){
			return this->right;
		}
		void setleft(person &p){
			left=&p; 
		}
		void setright(person &p){
			right=&p;
		}
		void setjob(const char a[]){
			strcpy(job,a);
		}
		void print(){
			cout<<job<<endl;
		}
};
int main(){
//	person p1,p2;
//	p1.setjob("worker");
//	p2.setjob("officer");
//	p1.setleft(p2);
//	p2.setright(p1);
//	p1.getleft()->print();
//对于朝内的人，从右手起是逆时针方向
//对于朝外的人，从左手起是逆时针方向 
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
			per[i].setright(per[(i+1)%n]);
			per[i].setleft(per[(i-1+n)%n]);
		}else if(flag==1){
			per[i].setleft(per[(i+1)%n]);
			per[i].setright(per[(i-1+n)%n]);
		}
	}
	int step;
	person *p=&per[0];
	for(int i=0;i<m;i++){
		cin>>flag;
		cin>>step;
		if(flag==0){
			for(int j=0;j<step;j++){
				p=p->getleft();
			}
		}else{
			for(int j=0;j<step;j++){
				p=p->getright();
			}
		}
	}
	p->print();
	for(int i=0;i<n;i++){
		per[i].print();
		per[i].getleft()->print();
		per[i].getright()->print();
	}
	return 0;
}


