#include <stdio.h>
#include <iostream>
using namespace std;
void func(int n, char **str)
{
 int i;
 for(i = 0; i < n; i++)
  printf("/nstr[%d] = %s/n", i, str[i]);
}
int main()
{
// 	char* p[3];
 	char str[][5] = {"abc","def","ghi"};
//	 //str[1]是指向“def”所在空间的指针 
// 
// 	//下面两个是等效的 
// 	cout<<str[0];
 	cin>>*(*(str+1)+1);
 	cout<<(*(str+1));
// 	p[0] = &str[0][0];
// 	p[1] = str[1];
// 	p[2] = str[2];
//    func(3, p);
//	int *a;
//	int b;
//	a=&b;
//	cin>>*a;
//	cout<<a;
}

