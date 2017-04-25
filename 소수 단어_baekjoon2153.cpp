#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
enum {a=1,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};

int main()
{
	char test[20];
	int sum = 0;
	int temp = 0;
	scanf("%s", test);
	int len = strlen(test);
	
	for (int i = 0; i < len; i++)	sum += test[i];
	for (int j = 2; j < sum; j++)
	{
		if (sum%j == 0) temp++; break;
	}
	if (temp == 0) puts("It is a prime word.");
	else puts("It is not a prime word.");
	return 0;
}