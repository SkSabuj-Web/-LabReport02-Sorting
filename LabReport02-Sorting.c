
#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int array[],int size) {
    for (int index =0; index<size; ++index) {
        printf("%d",array[index]);
        if (index+1 == size) printf("\n");
        else printf(" ");
    }
}



int partition(int array[],int left,int right,int *comparisons){
    int pivot = array[right];
    int smallerIndex = left-1;

    for (int scanIndex = left; scanIndex<right; ++scanIndex) {
        ++(*comparisons);

        if (array[scanIndex]<pivot) {
            ++smallerIndex;
            swap(&array[smallerIndex],&array[scanIndex]);
        }
    }

    swap(&array[smallerIndex+1], &array[right]);
    return smallerIndex+1;
}

void QuickSort(int array[],int left,int right,int *comparisons) {
    if (left >= right) return;

    int pivotIndex = partition(array,left,right,comparisons);

    QuickSort(array,left, pivotIndex-1,comparisons);
    QuickSort(array,pivotIndex+1,right,comparisons);
}



void merge(int array[],int temp[],int left,int middle,int right,int *comparisons){
    int leftPartitionIndex = left;
    int rightPartitionIndex = middle+1;
    int tempIndex = left;

    while (leftPartitionIndex <= middle && rightPartitionIndex <= right){
        ++(*comparisons);

        if (array[leftPartitionIndex] <= array[rightPartitionIndex]){
            temp[tempIndex++] = array[leftPartitionIndex++];
        } else {
            temp[tempIndex++] = array[rightPartitionIndex++];
        }
    }

    while (leftPartitionIndex <= middle){
        temp[tempIndex++] = array[leftPartitionIndex++];
    }

    while (rightPartitionIndex <= right) {
        temp[tempIndex++] = array[rightPartitionIndex++];
    }

    for (int index = left; index <= right; ++index){
        array[index] = temp[index];
    }
}

void MergeSort(int array[],int temp[],int left,int right,int *comparisons) {
    if (left >= right) return;

    int middle = left+(right-left) / 2;

    MergeSort(array,temp,left,middle,comparisons);
    MergeSort(array,temp,middle+1,right,comparisons);

    merge(array,temp,left,middle,right,comparisons);
}


void mergeUpdatedArray(int array[],int newArray[],int updated[],int n,int m) {
    int i=0, j=0, k=0;

    while (i < n && j < m){
        if (array[i] <= newArray[j]){
            updated[k++] = array[i++];
        } else {
            updated[k++] = newArray[j++];
        }
    }

    while (i<n){
        updated[k++] = array[i++];
    }

    while (j < m){
        updated[k++] = newArray[j++];
    }
}

int main(void){
    FILE *file = fopen("input.txt","r");

    if (file == NULL) return 1;

    int n, m;
    fscanf(file, "%d %d",&n,&m);

    int *mergeArray = malloc((n + 1) * sizeof(int));
    int *quickArray = malloc((n + 1) * sizeof(int));
    int *newArray = malloc((m + 1) * sizeof(int));
    int *updated = malloc((n + m + 1) * sizeof(int));
    int *temp = malloc((n + 1) * sizeof(int));

    for (int index=0; index<n; ++index){
        fscanf(file, "%d", &mergeArray[index]);
        quickArray[index] = mergeArray[index];
    }

    for (int index=0; index<m; ++index){
        fscanf(file, "%d",&newArray[index]);
    }

    fclose(file);

    int mergeComparisons = 0;
    int quickComparisons = 0;

    MergeSort(mergeArray,temp,0,n-1,&mergeComparisons);

    QuickSort(quickArray,0,n-1,&quickComparisons);

    printf("Merge Sort: ");
    printArray(mergeArray, n);

    printf("Quick Sort: ");
    printArray(quickArray, n);

    printf("Merge Comparisons: %d\n", mergeComparisons);
    printf("Quick Comparisons: %d\n", quickComparisons);

    mergeUpdatedArray(mergeArray,newArray,updated,n,m);

    printf("Updated Array: ");
    printArray(updated,n+m);

    free(mergeArray);
    free(quickArray);
    free(newArray);
    free(updated);
    free(temp);

    return 0;
}
