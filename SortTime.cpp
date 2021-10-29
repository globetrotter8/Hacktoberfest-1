#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
//BubbleSort
void bubbleSort(int array[], int size)
{
for (int step = 0; step < (size-1); ++step)
{
for (int i = 0; i < size - (step-1); ++i)
{
if (array[i] > array[i + 1])
{
swap(array[i],array[i+1]);
}
}
}
}
//InsertionSort
void insertionSort(int arr[], int n)
{
int i, key, j;
for (i = 1; i < n; i++)
{
key = arr[i];
j = i - 1;
while (j >= 0 && arr[j] > key)
{
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}
}
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}//SelectionSort
void selectionSort(int array[], int size)
{
for (int step = 0; step < size - 1; step++)
{
int min_idx = step;
for (int i = step + 1; i < size; i++)
{
if (array[i] < array[min_idx])
min_idx = i;
}
swap(&array[min_idx], &array[step]);
}
}//MergeSort
void merge(int arr[], int p, int q, int r)
{
int n1 = q - p + 1;
int n2 = r - q;
int L[n1], M[n2];
for (int i = 0; i < n1; i++)
L[i] = arr[p + i];
for (int j = 0; j < n2; j++)
M[j] = arr[q + 1 + j];
int i, j, k;
i = 0;
j = 0;
k = p;
while (i < n1 && j < n2) {
if (L[i] <= M[j]) {
arr[k] = L[i];
i++;
} else {
arr[k] = M[j];
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
arr[k] = M[j];
j++;
k++;
}
}
void mergeSort(int arr[], int l, int r)
{
if (l < r) {
int m = l + (r - l) / 2;
mergeSort(arr, l, m);
mergeSort(arr, m + 1, r);
merge(arr, l, m, r);
}
}
//QuickSort
int partition(int array[], int low, int high)
{
int pivot = array[high];
int i = (low - 1);
for (int j = low; j < high; j++) {
if (array[j] <= pivot) {
i++;
swap(&array[i], &array[j]);
}
}
swap(&array[i + 1], &array[high]);
return (i + 1);
}
void quickSort(int array[], int low, int high)
{
if (low < high) {
int pi = partition(array, low, high);
quickSort(array, low, pi - 1);
quickSort(array, pi + 1, high);
}
}
void printArray(int arr[],int size)
{
int i;
for(i=0;i<size;i++)
{
cout<<arr[i]<<" ";
}
}
int main()
{
 int size=100000;
int arr[size];
int i;
for(i=0;i<size;i++)
arr[i]=rand();
auto start = std::chrono::high_resolution_clock::now();
quickSort(arr,0,size);
auto finish = std::chrono::high_resolution_clock::now();
auto elapsed = duration_cast<microseconds>(finish - start);
std::cout << "\nElapsed time: " << elapsed.count() << " microseconds\n";
/*
bubbleSort(arr,size);
printArray(arr,size);

insertionSort(arr,size);
printArray(arr,size);

mergeSort(arr,0,size);
printArray(arr,size);

quickSort(arr,0,size);
printArray(arr,size);

*/

}
