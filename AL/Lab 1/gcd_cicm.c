#include <stdio.h>
#include <stdlib.h>

int gcd_cicm(int a, int b, int *opc)
{
	int t;
	if(a>b){
		t=b;
	}
	else{
		t=a;
	}

for (int i=t; i > 0; i--)
{
(*opc)++;
if (a % i == 0 && b % i == 0)
{
return i;
}
}
}

int main()
{
int m, n;
printf("Enter the two numbers: ");
scanf("%d %d", &m, &n);
int opc = 0;

int result = gcd_cicm(m, n, &opc);
if(m==0 || n==0){
	printf("0 is invalid input");
}
else{
printf("GCD of %d and %d is %d,\n m+n is %d and \n the  no. of operation count  is %d\n",m,n, result,m+n, opc);
	
}
}
