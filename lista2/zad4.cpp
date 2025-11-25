#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Bucket
{
    double* arr;
    int count;
};

void insert_sort(Bucket& bucket, double value)
{
    int i = bucket.count - 1;
    while (i >= 0 && bucket.arr[i] > value)
    {
        bucket.arr[i + 1] = bucket.arr[i];
        i--;
    }
    bucket.arr[i + 1] = value;
    bucket.count++;
}

void bucketSort(double A[], int n)
{
    if (n <= 1) return;

    double minVal = A[0], maxVal = A[0];
    for (int i = 1; i < n; i++) 
    {
        if (A[i] < minVal) minVal = A[i];
        if (A[i] > maxVal) maxVal = A[i];
    }

    double range = maxVal - minVal;
    if (range == 0) return;

    Bucket* B = new Bucket[n];
    for (int i = 0; i < n; i++)
    {
        B[i].arr = (double*)malloc(n * sizeof(double));
        B[i].count = 0;
    }

    for (int i = 0; i < n; i++) 
    {
        int index = (int)((A[i] - minVal) / range * (n - 1));
        insert_sort(B[index], A[i]);
    }

    int idx = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < B[i].count; j++) 
        {
            A[idx++] = B[i].arr[j];
        }
    }

    delete[] B;
}

int main() 
{
    srand(time(0));
    int n; cin>>n;
    double* A = new double[n];
    for (int i = 0; i < n; i++) 
    {
        int x = rand();
        A[i] = x;
        cout<<A[i]<<" ";
    }
    cout<<endl;

    bucketSort(A, n);

    for (int i = 0; i < n; i++) 
    {
        cout<<A[i]<<" ";
    }

    delete[] A;
    return 0;
}
