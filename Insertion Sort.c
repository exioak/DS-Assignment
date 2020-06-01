//C program by Aman Kant, IT, 11912054
#include<stdio.h>
#include<time.h>
void Insert(int a[],int n){
    int i,j,k;
    for(i=0;i<n;i++){
        j=a[i];
        k=i-1;
        while(a[k]>j && k>=0){           
            a[k+1] = a[k];
            k=k-1;
        }
        a[k+1]=j;
    }
}
int main(){
    int a[100], i ;
    for ( i = 100; i > 0; i--)
    {
        a[i]=i;
    }
    clock_t s,e; 
	s = clock();
    Insert(a,100);
    e=clock();
    long double time_taken = ((double)(e-s))/CLOCKS_PER_SEC;
    printf("Time Taken = %Lf\n",time_taken);
    for (i = 0; i < 6; i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
