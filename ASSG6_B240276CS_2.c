#include<stdio.h>
#include<string.h>
int h(int key, int i, int n){
    return ((key%n) + i*i)%n;
}

void insertIntoHT(int key, int arr[], int n){
    int i=0;
    while(arr[h(key,i,n)]!=-1){
        i++;
        if(h(key, i, n)==key%n) return;
    } 
    arr[h(key, i, n)]=key;
}

int search(int key, int arr[], int n){
    int i=0;
    while(arr[h(key,i,n)]!=key){
        i++;
        if(h(key, i, n)==key%n) return -1;
    } 
    return h(key, i, n);
}

int delete(int key, int arr[], int n){
    int idx=search(key, arr, n);
    if(idx==-1) return -1;
    arr[idx]=-1;
}

int main(){
    int n, key;
    scanf("%d", &n);
    char str[10];
    int arr[n];
        for(int i=0;i<n;i++) arr[i]=-1;
    for(int i=0;i<n;i++){
        scanf(" %s", str);
        if(strcmp(str, "INSERT")==0){
            scanf(" %d", &key);
            insertIntoHT(key, arr, n);
        }
        else if(strcmp(str, "SEARCH")==0){
            scanf(" %d", &key);
            if(search(key, arr, n)==-1)printf("-1\n");
            else printf("1\n");
        }
        else if(strcmp(str, "DELETE")==0){
            scanf(" %d", &key);
            delete(key, arr, n);
        }
    }
    return 0;
}