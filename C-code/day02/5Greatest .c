#include<stdio.h>
void main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int temp,i;
	if(a<b){
	      temp=a;
	      a=b;
	      b=temp;
	 }
//    for(i=b; i>0; i--)
//        if(a%i==0 && b%i==0)
//        {
//            printf("The ���Լ�� of %d and %d is: %d\n", a, b, i);
//            break;
//        }
	while(i!=0){
		i=a%b;
		a=b;
		b=i;
	}
	printf("The ���Լ�� is: %d\n",a);
}
