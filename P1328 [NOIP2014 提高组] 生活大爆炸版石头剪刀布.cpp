#include <iostream>

using namespace std;

int main(){
	int n;
	int na;
	int nb;
	cin>>n>>na>>nb;
	int regu_a[na];
	int regu_b[nb];
	for(int i=0;i<na;i++){
		cin>>regu_a[i];
	}
	for(int i=0;i<nb;i++){
		cin>>regu_b[i];
	}
	int order[5][5]={
		{0,-1,1,1,-1},
		{1,0,-1,1,-1},
		{-1,1,0,-1,1},
		{-1,-1,1,0,1},
		{1,1,-1,-1,0}
	};
	int score_a=0;int score_b=0;
	for(int i=0;i<n;i++){
		int op1=regu_a[i%na];
		int op2=regu_b[i%nb];
		if(order[op1][op2]==1){
			score_a++;
		}else if(order[op1][op2]==-1){
			score_b++;
		}
	}
	cout<<score_a<<" "<<score_b;
}


