#include<stdio.h>
void main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a>b&&b>c){
		printf("a=%d,b=%d,c=%d",a,b,c);
	}
	if(a>c&&c>b){
		printf("a=%d,c=%d,b=%d",a,c,b);
	}
	if(a<b&&a>c){
		printf("b=%d,a=%d,c=%d",b,a,c);
	}
	if(c<b&&a<c){
		printf("b=%d,c=%d,a=%d",b,c,a);
	}
	if(a<b&&b<c){
		printf("c=%d,b=%d,a=%d",c,b,a);
	}
	if(a>b&&a<c){
		printf("c=%d,a=%d,b=%d",c,a,b);
	}
} 
