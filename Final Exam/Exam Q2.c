#include <stdio.h>
#include <stdlib.h>

int insertSorted(int arr[], int n,int key,int capacity)
{
    if (n >= capacity)
       return n;
    arr[n] = key;
    return (n + 1);
}
int findElement(int arr[], int n,int key);//Prototype

int deleteElement(int arr[], int n,int key)
{
    int pos = findElement(arr, n, key);
    if (pos == - 1)
    {
        printf("Element not found");
        return n;
    }

    // Deleting element
    int i;
    for (i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    return n - 1;
}

// Function to implement search operation
int findElement(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return - 1;
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


void main()
{
    int key;
    int arr[100],i,n,p,insert,k;
    int t;
    printf("Input the size of array : ");
    scanf("%d", &n);
    printf("Input %d elements in the array in ascending order:\n",n);

    for(i=0;i<n;i++){
        printf("element - %d : ",i);
        scanf("%d",&arr[i]);
        }
    printf("1-> Delete\n2-> Insert\n3-> Exit\n");
    scanf("%d",&t);
    k = sizeof(arr) / sizeof(arr[0]);
    int count=0;

    switch(t){
        case 1:
            printf("Number to be Deleted\n");
            scanf("%d",&key);
            printf("Array before deletion\n");
            for (i = 0; i < n; i++)
              printf("%d  ", arr[i]);
            n = deleteElement(arr, n, key);
            printf("\nArray after deletion\n");
            for (i = 0; i < n; i++)
              printf("%d  ", arr[i]);
            break;
        case 2:
            printf("Number to be Inserterted\n");
            scanf("%d",&key);
            printf("\n Before Insertion: ");
            for (i = 0; i < n; i++)
                printf("%d  ", arr[i]);
            n = insertSorted(arr, n, key, k);
            bubbleSort(arr, n);
            printf("\n After Insertion: ");
            printArray(arr, n);
        case 3:
            exit(0);



    }
}
