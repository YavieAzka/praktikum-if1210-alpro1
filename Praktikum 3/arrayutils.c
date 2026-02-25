#include "arrayutils.h"


//tambahan aja kalau misal sort biasa terlalu lama

/**
 * @brief merge dua subarray dari indeks [a, b] dan [b+1, c] ke menjadi array berindeks [a, c].
 * @param arr pointer ke array yang diurutkan.
 * @param a indeks pertama subarray kiri
 * @param b indeks terakhir subarray kiri
 * @param c inteks terakhir subarray kanan
*/
void merge(int arr[], int a, int b, int c) {
    int n1 = b - a + 1;
    int n2 = c - b;
    int A[n1], B[n2];

    for (int i = 0; i < n1; i++) A[i] = arr[a + i];
    for (int i = 0; i < n2; i++) B[i] = arr[b + 1 + i];

    int i = 0, j = 0, k = a;
    while (i < n1 && j < n2) {
        if (A[i] < B[j]) arr[k++] = A[i++];
        else arr[k++] = B[j++];
    }
    
    while (i < n1) arr[k++] = A[i++];
    while (j < n2) arr[k++] = B[j++];
}

/**
 * @brief algoritma merge sort untuk array berindeks [a, c] secara rekursif.
 * @param arr array yang akan disort.
 * @param a indeks terkecil array.
 * @param c indeks terbesar array. 
 */
void mergesort(int arr[], int a, int c) {
    if (a < c) {
        int b = a + (c - a) / 2;
        mergesort(arr, a, b);
        mergesort(arr, b + 1, c);
        merge(arr, a, b, c);
    }
}

// Tambahan selesai
//---


void sort(int arr[], int n) {
    //Bubble sort
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int find(int arr[], int n, int target) {
    int found = 0, i = 0;
    while (!found && i < n) {
        if (arr[i] == target) {
            found = 1;
            break;
        }
        i++;
    }
    if (found) return i;
    else return -1;
}

double calculateAverage(int arr[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++) total += arr[i];
    return total/n;
}

int findMedian(int arr[], int n) {
    int temp[n];
    for (int i = 0; i < n; i++) temp[i] = arr[i];
    sort(temp, n);
    
    if (n % 2) return temp[n/2];
    else return (temp[n/2] + temp[n/2 - 1]) / 2;
}

int findMode(int arr[], int n) {
    int temp[n];
    for (int i = 0; i < n; i++) temp[i] = arr[i];
    sort(temp, n);

    int maxfreq = 1, freq = 1, mode = temp[0];
    for (int i = 1; i < n; i++) {
        if (temp[i] != temp[i - 1]) freq = 1;
        else freq++;

        if (freq > maxfreq) {
            mode = temp[i - 1];
            maxfreq = freq;
        }
    }
    return mode;
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

void reverseArray(int arr[], int n) {
    for (int i = 0; i < n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}