#include<stdio.h>
#include<stdlib.h>

void create(int n, int arr[n]);
void display(int n, int arr[]);
void insert(int *n, int arr[], int elem, int pos);
void del(int *n, int arr[], int pos);


int main(){

    int n, arr[100], pos, elem;
    printf("enter n: ");
    scanf("%d",&n);

    create(n, arr);
    printf("the array is: ");
    display(n, arr);
    printf("\n");
    insert(&n, arr, elem, pos);
    del(&n, arr, pos);

    return EXIT_SUCCESS;
}


void create(int n, int arr[n]){

    printf("enter %d elements:\n",n);

    for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }

}

void display(int n, int arr[]){

    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}

void insert(int *n, int arr[], int elem, int pos){
    
    printf("enter position to insert an element:\n");
    scanf("%d", &pos);
    if(pos<0 || pos>*n){
        printf("invalid position");
        return;
    }
    printf("enter element to insert:\n");
    scanf("%d", &elem);
    arr[pos] = elem;
    printf("the new array is: ");
    for(int i = 0; i < *n; i++){
        printf("%d ", arr[i]);
    }

}

void del(int *n, int arr[], int pos){

    printf("\nenter position to delete the element:\n");
    scanf("%d", &pos);

    if(pos<0 || pos>*n){
        printf("invalid position");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;

    printf("new array is: ");
    for(int i=0; i < *n; i++){
        printf("%d ", arr[i]);
    }
}