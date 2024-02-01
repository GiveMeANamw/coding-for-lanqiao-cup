#include <iostream>

using namespace std;

int main(){
	char map[10][10];
	//0 north
	//1 east
	//2 south
	//3 west
	int dir_h=0;int dir_c=0;
	int x_h=0;int y_h=0;int x_c=0;int y_c=0;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cin>>map[i][j];
			if(map[i][j]=='F'){
				x_h=i;y_h=j;
			}
			if(map[i][j]=='C'){
				x_c=i;y_c=j;
			}				
		}
	}	
//	for(int i=0;i<10;i++){
//		for(int j=0;j<10;j++){
//			cout<<map[i][j];
//		}
//		cout<<endl;
//	}
//	for(int i=0;i<10;i++){
//		for(int j=0;j<10;j++){
//			//human move
//			
//		}
//		cout<<endl;
//	}
	int minute=0;
	while(1){
			if(dir_h==0){
				if(x_h-1>=0&&map[x_h-1][y_h]!='*'){
					//如果北方不是边界，也不是阻碍物，向上移动一格
					map[x_h-1][y_h]='F';
					map[x_h][y_h]='.';
					x_h-=1;
				}else{
					dir_h=1;
				}
			}else if(dir_h==1){
				if(y_h+1<10&&map[x_h][y_h+1]!='*'){
					//如果east不是边界，也不是阻碍物，向上移动一格
					map[x_h][y_h+1]='F';
					map[x_h][y_h]='.';
					y_h+=1;
				}else{
					dir_h=2;
				}
			}else if(dir_h==2){
				if(x_h+1<10&&map[x_h+1][y_h]!='*'){
					//如果south不是边界，也不是阻碍物，向上移动一格
					map[x_h+1][y_h]='F';
					map[x_h][y_h]='.';
					x_h+=1;
				}else{
					dir_h=3;
				}
			}else if(dir_h==3){
				if(y_h-1>=0&&map[x_h][y_h-1]!='*'){
					//如果west不是边界，也不是阻碍物，向上移动一格
					map[x_h][y_h-1]='F';
					map[x_h][y_h]='.';
					y_h-=1;
				}else{
					dir_h=0;
				}
			}
			
			//cow move
			if(dir_c==0){
				if(x_c-1>=0&&map[x_c-1][y_c]!='*'){
					//如果北方不是边界，也不是阻碍物，向上移动一格
					map[x_c-1][y_c]='C';
					map[x_c][y_c]='.';
					x_c-=1;
				}else{
					dir_c=1;
				}
			}else if(dir_c==1){
				if(y_c+1<10&&map[x_c][y_c+1]!='*'){
					//如果east不是边界，也不是阻碍物，向上移动一格
					map[x_c][y_c+1]='F';
					map[x_c][y_c]='.';
					y_c+=1;
				}else{
					dir_c=2;
				}
			}else if(dir_c==2){
				if(x_c+1<10&&map[x_c+1][y_c]!='*'){
					//如果soutc不是边界，也不是阻碍物，向上移动一格
					map[x_c+1][y_c]='F';
					map[x_c][y_c]='.';
					x_c+=1;
				}else{
					dir_c=3;
				}
			}else if(dir_c==3){
				if(y_c-1>=0&&map[x_c][y_c-1]!='*'){
					//如果west不是边界，也不是阻碍物，向上移动一格
					map[x_c][y_c-1]='F';
					map[x_c][y_c]='.';
					y_c-=1;
				}else{
					dir_c=0;
				}
			}
			minute++;
			if(x_c==x_h&&y_c==y_h){
				break;
			}
			if(minute>=99999){
				minute=0;
				break;
			}
	}
	
	cout<<minute<<endl;
}


