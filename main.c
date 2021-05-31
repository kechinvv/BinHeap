#include "heap.h"
#include <stdio.h>
#include <malloc.h>
#include "tests.c"


int numberCount(FILE *file) {
    fseek(file, 0, SEEK_SET);
    int count = 0;
    while (1) {
        int value;
        if (fscanf(file, "%d", &value) == 1)
            count++;
        if (feof(file))
            return count;
    }
}

void read(FILE *file, int size, int *data) {
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < size; ++i) {
        fscanf(file, "%d", &data[i]);
    }
}

void tests(){
    test_sort();
    test_max();
    test_add();
    test_build();
}

int main(int argc, char **argv) {
    if (argc != 3) return -1;
    FILE *fin = fopen(argv[1], "r");
    int size = numberCount(fin);
    int *data = (int *) malloc(sizeof(int) * size);
    read(fin, size, data);
    fclose(fin);
    int *arr = build(data, size);
    for (int i = 0; i < size; ++i) {
        printf("%d\n", arr[i]);
    }
    FILE *fout = fopen(argv[2], "w");
    for (int i = 0; i < size; ++i) {
        fprintf(fout, "%d\n", arr[i]);
    }
    fclose(fout);
    free(arr);
    free(data);
    tests();
    return 0;
}

