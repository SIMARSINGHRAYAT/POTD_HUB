#include <stdio.h>

unsigned long long int sum;


 

unsigned long long int getSum(unsigned long long int n)

{

    if(n/10<1){

        return n;

    }

    else{

        for (sum = 0; n > 0; sum += n % 10, n /= 10);

        return getSum(sum);

    }


 

    

}







 

void merge(unsigned long long int arr[], unsigned long long int l, unsigned long long int m, unsigned long long int r)

{

unsigned long long int i, j, k;

unsigned long long int n1 = m - l + 1;

unsigned long long int n2 = r - m;

 

 

unsigned long long int L[n1], R[n2];

 

 

for (i = 0; i < n1; i++)

L[i] = arr[l + i];

for (j = 0; j < n2; j++)

R[j] = arr[m + 1 + j];

 

 

i = 0;

j = 0;

k = l;

while (i < n1 && j < n2) {

if (L[i] <= R[j]) {

arr[k] = L[i];

i++;

}

else {

arr[k] = R[j];

j++;

}

k++;

}

 

 

while (i < n1) {

arr[k] = L[i];

i++;

k++;

}

 

while (j < n2) {

arr[k] = R[j];

j++;

k++;

}

}

 


 

void mergeSort(unsigned long long int arr[], unsigned long long int l, unsigned long long int r)

{

if (l < r) {

 

unsigned long long int m = l + (r - l) / 2;

 

 

mergeSort(arr, l, m);

mergeSort(arr, m + 1, r);

 

merge(arr, l, m, r);

}

}









 

unsigned long long int main(){

    unsigned long long int n,q,t,k;

    scanf("%llu %llu", &n, &q);

    unsigned long long int i;

    unsigned long long int *v;

    unsigned long long int *u;

    v = malloc(n * sizeof(unsigned long long int));

    u = malloc(n * sizeof(unsigned long long int));

    

    for(unsigned long long int i=0; i < n; i++)

    scanf("%llu", &v[i]);

    for(unsigned long long int i=0; i < n; i++){

        v[i]=getSum(v[i]);

    }

    mergeSort(v, 0, n-1);

    unsigned long long int d=n;

    for(unsigned long long int i=0;i<n;i++){

        u[i]=v[d-1];

        d=d-1;

 

    }

    unsigned long long int p=0;

    unsigned long long int f=0;

    for(unsigned long long int i=0;i<n;i++){

        v[i]=p+v[i];

        p=v[i];

            

        

    }



 

    for(unsigned long long int i=0;i<n;i++){

        u[i]=f+u[i];

        f=u[i];

        

    }



 

    for(unsigned long long int i=0; i < q; i++){

        scanf("%llu %llu", &t, &k);

        if(t==1){

            printf("%llu\n",u[k-1]);

        }

        else{

            printf("%llu\n",v[k-1]);

        }

        

    }

    

    return 0;

}
