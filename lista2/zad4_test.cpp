#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

long long porownania = 0;
long long przypisania = 0;

struct Bucket 
{
    double* arr;
    int count;
};

void insert_sort(Bucket& bucket, double value) 
{
    int i = bucket.count - 1;
    porownania++;
    while (i >= 0 && (++porownania && bucket.arr[i] > value)) 
    { 
        bucket.arr[i + 1] = bucket.arr[i];
        przypisania++;
        i--;
    }
    bucket.arr[i + 1] = value;
    przypisania++;
    bucket.count++;
    przypisania++;
}

void bucketSort(double A[], int n) 
{
    if (n <= 1) return;

    double minVal = A[0], maxVal = A[0];
    przypisania += 2;
    for (int i = 1; i < n; i++) 
    {
        porownania++;
        if (A[i] < minVal) 
        {
            minVal = A[i];
            przypisania++;
        }
        porownania++;
        if (A[i] > maxVal) 
        {
            maxVal = A[i];
            przypisania++;
        }
    }

    double range = maxVal - minVal;
    przypisania++;
    porownania++;
    if (range == 0) return;

    Bucket* B = new Bucket[n];
    przypisania++;
    for (int i = 0; i < n; i++) 
    {
        B[i].arr = (double*)malloc(n * sizeof(double));
        B[i].count = 0;
        przypisania += 2;
    }

    for (int i = 0; i < n; i++) 
    {
        int index = (int)((A[i] - minVal) / range * (n - 1));
        przypisania++;
        insert_sort(B[index], A[i]);
    }

    int idx = 0;
    przypisania++;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < B[i].count; j++) 
        {
            A[idx++] = B[i].arr[j];
            przypisania++;
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
    }
    cout<<endl;

    bucketSort(A, n);

    cout << "porownania: " << porownania << endl;
    cout << "przypisania: " << przypisania << endl;

    delete[] A;
    return 0;
}
