#include <stdio.h>
#include <stdbool.h>


void printArr(int arr[], int s){
   for (int i = 0; i < s; ++i) {
      printf("%d ", arr[i]);
   }
   printf("\n");
}
void swap(int*, int*);
int* concat(int[], int, int[], int, int[]);
bool evry(int[], int, bool (*callback) (int));
int* filter(int [], int [], int, bool (*callback) (int));
void forEach(int[], int, void (*callback) (int));
int indexOf (int[], int, int);
int lastIndexOf (int[], int, int);
int* map (int[], int, int[], int (*callback) (int));
int* reverse (int[], int);
int c (int i){return i * 2;}


int main(){
   int arr1[] = {1, 2, 3, 3};
   int arr2[] = {4, 5, 6 };
   //printf("%d", lastIndexOf(arr1, 4, 3));
   reverse(arr1, 4);
   printArr(arr1, 4);
   

   return 0;
}
void swap (int* a, int* b){
   int tmp = *a;
   *a = *b;
   *b = tmp;
}
int* concat(int arr1[], int size1, int arr2[], int size2, int dest[]) {
   for (int i = 0; i < size1; ++i) {
      dest[i] = arr1[i];
   }
   for (int i = 0; i < size2; ++i) {
      dest[i + size1] = arr2[i];
   }
   return dest;

}
bool evry(int arr[], int size, bool (*callback)(int)) {
   for (int i = 0; i < size; ++i) {
      if(!callback(arr[i])){
         return false;
      }
   }
   return true;
} 
int* filter(int arr[],  int dest[], int size, bool (*callback) (int)) {
   int j = 0;
   for (int i = 0; i < size; ++i) {
      if (callback(arr[i])) {
         dest[j++] = arr[i]; 
      }
   }
   return dest;
}
void forEach(int arr[], int size, void (*callback)(int)) {
  for (int i = 0; i < size; ++i) {
    callback(arr[i]);
  }
}
int indexOf (int arr[], int size, int elem) {
   for (int i = 0; i < size; ++i) {
      if (arr[i] == elem){
         return i;
      }
   }
   return -1;
}
int lastIndexOf (int arr[], int size, int elem) {
   for (int i = size - 1; i >= 0; --i) {
      if (arr[i] == elem){
         return i;
      }
   }
   return -1;
}
int* map (int arr[], int size, int dest[], int (*callback) (int)) {
   for (int i = 0; i < size; ++i){
      dest[i] = callback(arr[i]);
   }
   return dest;
}
int* reverse (int arr[], int size) {
   for (int i = 0; i < size; ++i){
      swap(&arr[i], &arr[(size--) - 1]);
   }
   return arr;
};
