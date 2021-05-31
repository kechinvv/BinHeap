#include "heap.h"
#include <stdio.h>
#include <malloc.h>


int main(int argc, char **argv) {
    if (argc != 3) return -1;
    FILE *fin = fopen(argv[1], "r");
    int cur = 20;
    int *data = (int *) malloc(sizeof(int) * cur);
    int count = 0;
    while (1) {
        if (count == cur) {
            cur += 20;
            int *ndata = (int *) realloc(data, (cur) * sizeof(int));
            if (ndata != 0) {
                data = ndata;
                fclose(fin);
                free(ndata);
                return -1;
            };
        }
        if (fscanf(fin, "%d", &data[count]) == 1) count++;
        if (feof(fin))
            break;
    }
    int size = count;
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
    return 0;
}

