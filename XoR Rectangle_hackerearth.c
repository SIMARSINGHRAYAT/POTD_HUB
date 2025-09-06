#include<stdio.h>

long a[1000001];

 long c[1000001][32];

int main()

{

 long n, i, q, c1, c2, j, x1, x2, y1, y2;

 scanf("%ld", &n);

 long sum;

 for(i=0; i<n; i++)

 {

 scanf("%ld", &a[i]);

 

if(i==0)

 {

 for(j=0; j<32; j++)

 {

 if((1<<j)&a[i])

 {

 c[i][j]=1;

 }

 else

 {

 c[i][j]=0;

 }

 }

 }

 else

 {

 for(j=0; j<32; j++)

 {

 if((1<<j)&a[i])

 {

 c[i][j]=c[i-1][j]+1;

 }

 else

 {

 c[i][j]=c[i-1][j];

 }

 }

 }

 

}

 

scanf("%ld", &q);

 

for(;q>0;q--)

 {

 sum=0;

 scanf("%ld %ld %ld %ld", &x1, &y1, &x2, &y2);

 x1--;x2--;y1--;y2--;

 for(j=0; j<32; j++)

 {

 c1=c[x2][j];

 if(x1>0)

 {

 c1=c1-c[x1-1][j];

 }

 c2=c[y2][j];

 if(y1>0)

 {

 c2=c2-c[y1-1][j];

 }

 

sum=sum+(1<<j)*(c1*(y2-y1+1-c2))+(1<<j)*(c2*(x2-x1+1-c1));

 }

 

printf("%ld\n", sum);

 }

}
