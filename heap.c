//
// Created by valer on 28.05.2021.
//
#include <malloc.h>
#include <string.h>
#include <limits.h>

void heapify(int *arr, int size, int i) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;
    if (left < size && arr[left] > arr[largest]) largest = left;
    if (right < size && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        int v = arr[i];
        arr[i] = arr[largest];
        arr[largest] = v;
        heapify(arr, size, largest);
    }
}

void increase(int *arr, int i, int key) {
    if (key < arr[i]) return;
    arr[i] = key;
    while (i > 1 && arr[i / 2] < arr[i]) {
        int v = arr[i / 2];
        arr[i / 2] = arr[i];
        arr[i] = v;
        i = i / 2;
    }
}

void insert(int *arr, int size, int element) {
    arr = (int *) realloc(arr, (size + 1) * sizeof(int));
    arr[size] = INT_MIN;
    increase(arr, size + 1, element);
}


int *build(int *data, int size) {
    int *arr = (int *) malloc(sizeof(int) * size);
    memcpy(&arr, &data, size);
    for (int i = size / 2; i >= 0; i--) {
        heapify(arr, size, i);
    }
    return arr;
}

void sort(int *arr, int size) {
    for (int i = size; i >= 0; i--) {
        int v = arr[i];
        arr[i] = arr[0];
        arr[0] = v;
        heapify(arr, size--, 0);
    }
}

int extract_max(int *arr, int size) {
    int max = arr[0];
    arr[0] = arr[size - 1];
    size--;
    heapify(arr, size, 0);
    return max;
}

void deinit(int *arr) {
    free(arr);
}
