//@author Kristen Lee
//@date 01/30/2019

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* makeRandomArray(int size);
int* makeSpareArray(int size);
void printArray(int* array, int size);
void copyArray(int* fromArray, int start, int end, int* toArray);
void subMerge(int* top, int start, int middle, int end, int* down);
void merge(int* down, int start, int end, int* top);
void mergeSort(int* start, int* spare, int size);

//Make array of random ints 1-100 inclusive, mostly used for testing
//@param int size of array
int* makeRandomArray(int size){
  int* array_builder = (int*)malloc(sizeof(int) * size);
  for(int i = 0; i < size; i++){
    array_builder[i] = (int)(rand() % 100);
  }
  return array_builder;
}
//Make the spare array of given size and all index assigned 0
//@param int size of array
int* makeSpareArray(int size){
  int* array_builder = (int*)malloc(sizeof(int) * size);
  for(int i = 0; i < size; i++){
    array_builder[i] = (int)0;
  }
  return array_builder;
}
//Print array function
//@param array to print and size of array to print
void printArray(int* array, int size){
  printf("[%d", array[0]);
  for(int i = 1; i < size; i++){
    printf(", %d", array[i]);
  }
  printf("]\n");
}
//Copy a given array with specified start and end to a spare array
//@param array to copy, start, end, spare array
void copyArray(int* fromArray, int start, int end, int* toArray){
  for(int i = start; i < end; i++){
    toArray[i] = fromArray[i];
  }
}
//subfunction to merge two int arrays via rank
//@param array , start, end, array
void subMerge(int* top, int start, int middle, int end, int* down){
  int i = start, j = middle;
  for(int k = start; k < end; k++){
    if(i < middle && (j >= end || top[i] <= top[j])){
      down[k] = top [i];
      i++;
    }
    else{
      down[k] = top[j];
      j++;
    }
  }
}
//Continually splits array down until it reaches units of one, then recursively merge
//@param spare array, starting index, ending index, starting array
void merge(int* down, int start, int end, int* top){
  if(end - start < 2) return;//if units are down to one, ie no more possible splitting, stop
  int middle = (end + start)/2;//else split in halves again
  merge(top, start, middle, down);
  merge(top, middle, end, down);
  subMerge(down, start, middle, end, top);//merge left and right
}
//Takes start array and uses spare array to sort
//@param starting array, spare array, size of array to sort
void mergeSort(int* start, int* spare, int size){
  copyArray(start, 0, size, spare);
  merge(spare, 0, size, start);
}

//Main method
int main(int argc, char* argv[]){
  if(argv[1] == NULL) printf("Execute the binary file again with a command line argument.\n");
  else{
    int array_size = atoi(argv[1]);//converts string to int
    printf("Sorting array size of %d.\n", array_size);
    srand(time(NULL));//seed srand once in main
    time_t begin, end;
    long i;
    int* random_array = makeRandomArray(array_size);
    int* spare_array = makeSpareArray(array_size/2);
    printf("Before: ");
    printArray(random_array, array_size);
    begin = time(NULL);
    mergeSort(random_array, spare_array, array_size);//actual merge sort process
    end = time(NULL);
    printf("After: ");
    printArray(random_array, array_size);
    free(random_array);
    free(spare_array);
    int difference = end - begin;
    printf("Sorting took %ld to complete.\n", end - begin);
  }
  return 0;
}
