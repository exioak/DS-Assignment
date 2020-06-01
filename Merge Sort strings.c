#include<stdio.h>
#include<time.h>
#include<string.h>
void merge(char a[],int l,int m,int u)
    {
    int num1= m-l+1;
    int num2=u-m,i,j,k;
    char left[num1],right[num2];
    for (i = 0; i < num1; i++)
    {
        left[i]=a[l+i];
    }
    for(j=0;j<num2;j++){
        right[j]=a[m+1+j];
    }
    i=0;
	j=0;
	k=l;
    while(i<num1 && j<num2){
        if(left[i]<=right[j]){
            a[k++] = left[i++];
        }
        else{
            a[k++]=right[j++];
        }
    }
    for(;i<num1;i++){
        a[k++]=left[i];
    }
    for(;j<num2;j++){
        a[k++] = right[j];
    }
    
}
void ms(char a[],int l,int u){
    if(l<u){
        int m =(u+l)/2;
        ms(a,l,m);
        ms(a,m+1,u);
        merge(a,l,m,u);
    }
}

int main(){
    char a[]={"polynomial"};
    char a2[]={"test case"};
    int n= strlen("polynomial"),i;
    int num1=strlen("test case");
    clock_t s,e ;
    s= clock();
    ms(a,0,n);
    ms(a2,0,n);
    e=clock();
    long double time_taken = ((double)(e-s)/CLOCKS_PER_SEC);
    printf("Time Taken = %Lf\n",time_taken);
    for (i = 0; i < n; i++)
    {
        printf("%c\t",a[i]);
    }
    printf("\n");
   for (i = 0; i < num1; i++)
    {
        printf("%c\t",a2[i]);
    }
    printf("\n");
    return 0;
}
