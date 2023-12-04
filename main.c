#include <stdio.h>
#include <stdlib.h>

int* create(int);
void PushBack(int*, int*, int);
void PopBack(int*, int*);
void Top(int*, int*);
void operation(int*, int*);
void Delete(int*);

int main() {
    int size = 1;
    int* arr = create(size);
    operation(arr, &size);
    return 0;
}

int* create(int len) {
    int* arr = (int*)calloc(len, sizeof(int));

    return arr;
}

void operation(int* arr, int* len) {
    printf("Choose an option.\n");
    printf("1. PushBack.\n2. PopBack.\n3. Top\n4. Exit.\n");

    int option = 0;
    do {
        scanf("%d", &option);
    } while (option < 1 || option > 4);

    if (option == 1) {
        int num = 0;
        printf("Enter a number: ");
        scanf("%d", &num);
        PushBack(arr, len, num);
    } else if (option == 2) {
        PopBack(arr, len);
    } else if (option == 3) {
        printf("The last element is: ");
        Top(arr, len);
        printf("\n");
    } else {
        Delete(arr);
        return;
    }

    operation(arr, len);
}

void PushBack(int* arr, int* len, int num) {
    int* arr1 = realloc(arr, *len + 1);
    arr = arr1;
    *(arr + *len) = num;
    ++*(len);
}

void PopBack(int* arr, int* len) {
    if (*len == 1) {
        printf("There's no element to pop.\n");
        return;
    }
    printf("The last element will be deleted.\n");
    int* arr1 = realloc(arr, *len - 1);
    arr = arr1;
    --*(len);
}

void Top(int* arr, int* len) {
    printf("%d\n", *(arr + *(len) - 1));
}

void Delete (int* arr) {
    free(arr);
    arr = NULL;
}