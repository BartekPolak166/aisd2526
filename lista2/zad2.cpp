#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getDigit(int x, int pos, int d) 
{
    for (int i = 0; i < pos; i++) x /= d;
    return x % d;
}

void countingSortDigit(int A[], int B[], int n, int pos, int d) 
{
    int *C = new int[d];

    for (int i = 0; i < d; i++)     C[i] = 0;

    for (int i = 0; i < n; i++) 
    {
        int digit = getDigit(A[i], pos, d);
        C[digit]++;
    }

    for (int i = 1; i < d; i++)     C[i] += C[i - 1];

    for (int i = n - 1; i >= 0; i--) 
    {
        int digit = getDigit(A[i], pos, d);
        B[C[digit] - 1] = A[i];
        C[digit]--;
    }

    for (int i = 0; i < n; i++)     A[i] = B[i];

    delete[] C;
}

void radixSortNonNegative(int A[], int n, int d) 
{
    if (n == 0) return;

    int maxVal = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > maxVal)
            maxVal = A[i];

    int k = 0;
    while (maxVal > 0)
    {
        maxVal /= d;
        k++;
    }

    int *B = new int[n];

    for (int pos = 0; pos < k; pos++)
        countingSortDigit(A, B, n, pos, d);

    delete[] B;
}

void radixSort(int A[], int n, int d) 
{
    int negCount = 0, posCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] < 0) negCount++;
        else posCount++;
    }

    int *neg = new int[negCount];
    int *pos = new int[posCount];

    int ni = 0, pi = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] < 0) neg[ni++] = -A[i];
        else pos[pi++] = A[i];
    }

    radixSortNonNegative(pos, posCount, d);
    radixSortNonNegative(neg, negCount, d);

    int idx = 0;

    for (int i = negCount - 1; i >= 0; i--)
        A[idx++] = -neg[i];

    for (int i = 0; i < posCount; i++)
        A[idx++] = pos[i];

    delete[] neg;
    delete[] pos;
}

int main()
{
    srand(time(0));
    int n; cin>>n;
    int d = 10;
    int* A = new int[n];
    for (int i = 0; i < n; i++) 
    {
        int x = rand();
        A[i] = x;
        cout<<A[i]<<" ";
    }
    cout<<endl;

    radixSort(A, n, d);

    for (int i = 0; i < n; i++) 
    {
        cout<<A[i]<<" ";
    }

    delete[] A;
    return 0;
}
