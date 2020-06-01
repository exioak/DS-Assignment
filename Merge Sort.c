#include<stdio.h>
#include<time.h>
#include<string.h>
void merge(char arr[],int lower,int mid,int upper){
    int n1= mid-lower+1;
    int n2=upper-mid,i,j,k;
    char left[n1],right[n2];
    for (i = 0; i < n1; i++)
    {
        left[i]=arr[lower+i];
    }
    for(j=0;j<n2;j++){
        right[j]=arr[mid+1+j];
    }
    i=0;
	j=0;
	k=lower;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++]=right[j++];
        }
    }
    for(;i<n1;i++){
        arr[k++]=left[i];
    }
    for(;j<n2;j++){
        arr[k++] = right[j];
    }
    
}
void MergeSort(char arr[],int lower,int upper){
    if(lower<upper){
        int mid =(upper+lower)/2;
        MergeSort(arr,lower,mid);
        MergeSort(arr,mid+1,upper);
        merge(arr,lower,mid,upper);
    }
}

int main(){
    char arr[]={"polynomial"};
    char arr2[]={"test case"};
    int n= strlen("polynomial"),i;
    int n1=strlen("test case");
    clock_t t = clock();
    MergeSort(arr,0,n);
    MergeSort(arr2,0,n);
    t=clock()-t;
    long double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Time Taken = %Lf\n",time_taken);
    for (i = 0; i < n; i++)
    {
        printf("%c\t",arr[i]);
    }
    printf("\n");
   for (i = 0; i < n1; i++)
    {
        printf("%c\t",arr2[i]);
    }
    printf("\n");
    return 0;
}
