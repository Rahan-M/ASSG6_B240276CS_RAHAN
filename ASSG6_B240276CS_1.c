#include<stdio.h>

void insertIntoHT(int key, int arr[], int n){
    int i=key%n;
    while(arr[i]!=-1){
        i=(i+1)%n;
        if(i==key%n) return; // No empty slots
    } 
    arr[i]=key;
}

int search(int key, int arr[], int n){
    int i=key%n;
    while(arr[i]!=key){
        i=(i+1)%n;
        if(i==key%n) return -1;
    }
    return i;
}

int main(){
    int n, k, key;
    scanf("%d%d", &n, &k);
    int arr[n];
    for(int i=0;i<n;i++) arr[i]=-1;

    for(int i=0;i<k;i++){
        scanf("%d",&key);
        insertIntoHT(key, arr, n);
    }

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&key);
        printf("%d\n",search(key, arr, n));
    }
    return 0;
}
