#include <stdio.h>
#include <malloc.h>
#include "heap.c"

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

int main(int arcc, char **arcv) {
    FILE *fin;
    fin = fopen("C:/Users/valer/Desktop/data.txt", "r");
    int size = numberCount(fin);
    int *data = (int *) malloc(sizeof(int) * size);
    read(fin, size, data);
    fclose(fin);
    int *arr = build(data, size);
    for (int i = 0; i < size; ++i) {
        printf("%d\n", arr[i]);
    }
    FILE *fout;
    fout = fopen("C:/Users/valer/Desktop/data2.txt", "w");
    for (int i = 0; i < size; ++i) {
        fprintf(fout,"%d\n", arr[i]);
    }
    fclose(fout);
    deinit(arr);
    return 0;
}

