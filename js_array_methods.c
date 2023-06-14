#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
void printArr(int arr[], int s){
   for (int i = 0; i < s; ++i) {
      printf("%d ", arr[i]);
   }
   printf("\n");
}
void swap (int*, int*);
int* concat (int[], int, int[], int, int*);
bool every (int[], int, bool (*callback) (int));
bool some (int[], int, bool (*callback) (int));
int* filter(int [], int*, int, bool (*callback) (int));
void forEach(int[], int, void (*callback) (int));
int indexOf (int[], int, int);
int lastIndexOf (int[], int, int);
int* map (int[], int, int*, int (*callback) (int));
int* reverse (int[], int);
int reduce (int[], int, int (*callback) (int, int), int);
int* slice (int[], int, int*, int, int);
int* sort (int[], int, int (*callback) (int, int));
int partition(int[], int, int, int (*callback)(int ,int));
void sort_quick (int[], int, int, int (*callback) (int, int));
int* splice (int[], int, int, int, int*, int, int*);
int find (int[], int, bool (*callback) (int));
int findIndex (int[], int, bool (*callback) (int));
bool includes(int[], int, int, int);
char* join (int[], int, char*, int*);
struct Next{
   int value[2];
   bool done;
};
struct Entires{
   struct Next next;
};
struct Entries* entries(int[], int);
struct Next* next(int[], int, struct Next*);
int* fill (int[], int, int, int, int);
int* with (int[], int, int, int);
int* flat (int**, int, int);
bool c (int a){return a == 25;}


int main(){

        return 0;
}
void swap (int* a, int* b){
   int tmp = *a;
   *a = *b;
   *b = tmp;
}
int* concat(int arr1[], int size1, int arr2[], int size2, int* resSize) {
   *resSize = size1 + size2;
   int* dest = (int*)malloc(*resSize * sizeof(int));
   for (int i = 0; i < size1; ++i) {
      dest[i] = arr1[i];
   }
   for (int i = 0; i < size2; ++i) {
      dest[i + size1] = arr2[i];
   }
   return dest;

}
bool every(int arr[], int size, bool (*callback)(int)) {
   for (int i = 0; i < size; ++i) {
      if(!callback(arr[i])){
         return false;
      }
   }
   return true;
} 
bool some (int arr[], int size, bool (*callback)(int)) {
   for (int i = 0; i < size; ++i) {
      if(callback(arr[i])){
         return true;
      }
   }
   return false;
} 
int* filter(int arr[],  int* resSize, int size, bool (*callback) (int)) {
   int* dest = (int*)malloc(size * sizeof(int));
   *resSize = 0;
   for (int i = 0; i < size; ++i) {
      if (callback(arr[i])) {
         dest[*resSize] = arr[i]; 
         *resSize += 1;
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
int* map (int arr[], int size, int* resSize, int (*callback) (int)) {
   *resSize = size;
   int* dest = (int*)malloc(*resSize * sizeof(int));
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
int reduce (int arr[], int size, int (*callback) (int, int), int init){
   int res = 0;
   for (int i = 0; i < size; ++i) {
       res = callback(init, arr[i]);
       init = res;
   }
   return res;
};
int* slice(int arr[], int size, int* resultSize, int start, int end){
   if (start < 0){
      start += size;
   }
   if(end < 0){
      end += size;
   }
   if(start > end){
     *resultSize = 0;
      return NULL;
   }
   *resultSize = end - start;
   int* dest = (int*)malloc(*resultSize * sizeof(int));
   for (int i = 0; i < *resultSize; ++i){
      dest[i] = arr[start++];
   } 
   return dest;
}
int partition(int arr[], int low, int high, int (*callback)(int ,int)){
	int pivot = arr[high];
	for (int i = low; i < high; ++i) {
		if (callback(arr[i], pivot) != 1) {
		 swap(&arr[low],&arr[i]);
		 ++low;
    	}	
	}
	swap(&arr[high],&arr[low]);
	return low;
}
void sort_quick (int arr[], int low , int high, int (*callback) (int, int) ){
					
    if (low < high){
	    int pivot = partition(arr, low, high, callback);
		 sort_quick(arr, low, pivot - 1, callback);
		 sort_quick(arr, pivot + 1,  high, callback);
	}

 }
int* sort (int arr[], int size, int (*callback)(int, int)){
     sort_quick(arr, 0, size - 1, callback);
     return arr;
};
int* splice (int arr[], int size, int start, int deleteCount, int* insert, int insertCount, int* newSize){
   if (deleteCount == 0 && insertCount != 0) {
      *newSize = size + insertCount;
      arr = (int*)realloc(arr, *newSize * sizeof(int));
      for (int i = 0; i < insertCount; ++i){
         int tmp = arr[start + i];
         arr[start + i] = insert[i];
         arr[size + i] = tmp;   
      }
      return NULL;
   }
   if(deleteCount != 0 && insertCount == 0){
      int* res = (int*) malloc(deleteCount * sizeof(int));
      for (int i = 0; i < deleteCount && i + start < size; ++i){
         res[i] = arr[start + i];
      }
      if(deleteCount + start >= size){
         arr = (int*) realloc(arr, start * sizeof(int));
         *newSize = start;
         return res;
      }
      for(int i = 0; i < deleteCount; ++i){
         arr[start + i] = arr[start + deleteCount + i];
      }
      *newSize = size - deleteCount;
      arr = (int*) realloc(arr, *newSize * sizeof(int));
       return res;

   }
   int* res = (int*) malloc(deleteCount * sizeof(int));
   for (int i = 0; i < deleteCount && i + start < size; ++i){
        res[i] = arr[start + i];
    }
    *newSize = deleteCount >= size ? start + insertCount : size - deleteCount + insertCount; 
    arr = (int*) realloc(arr, *newSize * sizeof(int));
    for (int i = 0; i < insertCount; ++i){
       arr[start + i] = insert[i];  
    }
    return res;
};

struct Entries* entries(int arr[] , int size){
    struct Entires* obj = (struct Entires*)malloc(sizeof(struct Entires));     
    obj -> next.value[0] = 0;
    obj -> next.value[1] = arr[0];
    obj -> next.done = false;
    return obj;
};
struct Next* next(int arr[], int size, struct Next* next){
   if (next -> value[0] == size - 1){
      next -> done = true;
      return next;
   }
   next -> value[0] += 1;
   next -> value[1] = arr[next -> value[0]];
   return next;
};
int* fill (int arr[], int size, int value, int start, int end){
   for (int i = start; i < size && i < end; ++i){
      arr[i] = value;
   }
   return arr;
};

int find (int arr[], int size, bool (*callback) (int)){
   for(int i = 0; i < size; ++i){
      if(callback(arr[i])){
         return arr[i];
      }
   }
   return EOF;
};
int findIndex (int arr[], int size, bool (*callback) (int)){
   for(int i = 0; i < size; ++i){
      if(callback(arr[i])){
         return i;
      }
   }
   return -1;
};
bool includes (int arr[], int size,int start, int value){
   for (int i = start; i < size; ++i){
      if (arr[i] == value){
         return true;
      }
   }
   return false;
}
char* join (int arr[], int size, char* sep, int* resSize){
   *resSize = (size * sizeof(int)) + (strlen(sep) * (size - 1));
   char* res = (char*)malloc(*resSize * sizeof(char));
   int resIndex = 0;
   int arrIndex = 0;
   for(;arrIndex < size; ++arrIndex){     
      char buffer[15];
      sprintf(buffer,"%d",arr[arrIndex]);
      if(strlen(buffer) + resIndex + strlen(sep) >= *resSize){
         *resSize += (size - arrIndex) * (strlen(sep) + sizeof(int));
         res = (char*) realloc(res, *resSize);
      }
      strcpy(&res[resIndex], buffer);
      resIndex += strlen(buffer);
      if(arrIndex >= size - 1){
         break;
      }
      strcpy(&res[resIndex], sep);
      resIndex += strlen(sep);
   }
   return res;

   }

int* with (int arr[], int size, int index, int value){
   if(index < 0 || index >= size){
      return NULL;
   }
   int* res = slice(arr, size, &size, 0, size);
   res[index] = value;
   return res;
};
int* flat (int** arr, int rows, int columns){
   int* res = calloc(sizeof(int), columns * rows);
   int resIndex = 0;
   for (int i = 0; i < rows; ++i){
      for(int j = 0; j < columns; ++j){
         res[resIndex++] = arr[i][j];
      }
   }
   return res;
};
