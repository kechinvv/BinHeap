//
// Created by valer on 29.05.2021.
//
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "heap.h"

int *createArr(int size) {
    int *arr = (int *) malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 20;
    }
    return arr;
}

void test_build() {
    int flag = 0;
    int size = 10;
    int *data = createArr(size);
    int *arr = build(data, size);
    for (int i = 0; i < size; ++i) {
        if (2 * i + 2 < size) if (arr[i] < arr[2 * i + 2]) flag = -1;
        if (2 * i + 1 < size) if (arr[i] < arr[2 * i + 1]) flag = -1;
    }
    assert(flag == 0);
    free(arr);
    free(data);
}

void test_sort() {
    int flag = 0;
    int size = 10;
    int *data = createArr(size);
    int *arr = build(data, size);
    sort(arr, size);
    for (int i = 1; i < size; ++i) {
        if (arr[i - 1] > arr[i]) flag = -1;
    }

    assert(flag == 0);
    free(arr);
    free(data);
}

void test_add() {
    int flag = -1;
    int size = 10;
    int *data = createArr(size);
    int *arr = build(data, size);

    arr = insert(arr, size, 10101);
    size++;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == 10101) {
            flag = 0;
            break;
        }
    }
    assert(flag == 0);

    for (int i = 0; i < size; ++i) {
        if (2 * i + 2 < size) if (arr[i] < arr[2 * i + 2]) flag = -1;
        if (2 * i + 1 < size) if (arr[i] < arr[2 * i + 1]) flag = -1;
    }
    assert(flag == 0);

    free(arr);
    free(data);
}

void test_max() {
    int flag = 0;
    int size = 10;
    int *data = createArr(size);
    int *arr = build(data, size);
    int orig_max = INT_MIN;
    for (int i = 0; i < size; ++i) {
        if (data[i] > orig_max) orig_max = data[i];
    }
    int new_max = extract_max(arr, size);
    assert(new_max == orig_max);
    size--;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == new_max) {
            flag = -1;
            break;
        }
    }
    assert(flag == 0);
    free(arr);
    free(data);
}

int main() {
    test_build();
    test_add();
    test_max();
    test_sort();
}