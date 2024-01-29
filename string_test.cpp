#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char a[40];
	scanf("%s",a);//scanf只接受空格之前的内容，而且a前面没有前缀，因为单拿出来一个a，表示数组首元素的地址，*a就表示数组的首元素 
	printf("%s\n",a);
	cout<<strlen(a); 
}
