#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

long long porownania = 0;
long long przypisania = 0;

int getDigit(int x, int pos, int d)
{
    for (int i = 0; i < pos; i++)
    {
        porownania++;
        x /= d;
        przypisania++;
    }
    porownania++;
    return x % d;             
}

void countingSortDigit(int A[], int B[], int n, int pos, int d)
{
    int *C = new int[d];
    przypisania++;

    for (int i = 0; i < d; i++) 
    {
        porownania++;
        C[i] = 0;
        przypisania++;
    }
    porownania++;

    for (int i = 0; i < n; i++) 
    {
        porownania++;
        int digit = getDigit(A[i], pos, d);
        przypisania++;
        C[digit]++;
        przypisania++;
    }
    porownania++;

    for (int i = 1; i < d; i++) 
    {
        porownania++;
        C[i] += C[i - 1];
        przypisania++;
    }
    porownania++;

    for (int i = n - 1; i >= 0; i--) 
    {
        porownania++;
        int digit = getDigit(A[i], pos, d);
        przypisania++;
        B[C[digit] - 1] = A[i];
        przypisania++;
        C[digit]--;
        przypisania++;
    }
    porownania++;

    for (int i = 0; i < n; i++) 
    {
        porownania++;
        A[i] = B[i];
        przypisania++;  
    }
    porownania++;

    delete[] C;
}

void radixSortNonNegative(int A[], int n, int d) 
{
    if (n == 0) return;

    int maxVal = A[0];
    przypisania++;

    for (int i = 1; i < n; i++) 
    {
        porownania++;
        if (A[i] > maxVal) 
        {
            porownania++;
            maxVal = A[i];
            przypisania++;
        } 
        else 
        {
            porownania++;
        }
    }
    porownania++;

    int k = 0;
    przypisania++;

    while (maxVal > 0) 
    {
        porownania++;
        maxVal /= d;
        przypisania++;
        k++;
        przypisania++;
    }
    porownania++;

    int *B = new int[n];
    przypisania++;

    for (int pos = 0; pos < k; pos++) 
    {
        porownania++;
        countingSortDigit(A, B, n, pos, d);
    }
    porownania++;

    delete[] B;
}

void radixSort(int A[], int n, int d) 
{
    int negCount = 0, posCount = 0;
    przypisania += 2;

    for (int i = 0; i < n; i++) 
    {
        porownania++;
        if (A[i] < 0) 
        {
            porownania++;
            negCount++;
            przypisania++;
        } 
        else 
        {
            porownania++;
            posCount++;
            przypisania++;
        }
    }
    porownania++;

    int *neg = new int[negCount];
    int *pos = new int[posCount];
    przypisania += 2;

    int ni = 0, pi = 0;
    przypisania += 2;

    for (int i = 0; i < n; i++) 
    {
        porownania++;
        if (A[i] < 0) 
        {
            porownania++;
            neg[ni] = -A[i];
            przypisania++;
            ni++;
            przypisania++;
        } 
        else 
        {
            porownania++;
            pos[pi] = A[i];
            przypisania++;
            pi++;
            przypisania++;
        }
    }
    porownania++;

    radixSortNonNegative(pos, posCount, d);
    radixSortNonNegative(neg, negCount, d);

    int idx = 0;
    przypisania++;

    for (int i = negCount - 1; i >= 0; i--) 
    {
        porownania++;
        A[idx] = -neg[i];
        przypisania++;
        idx++;
        przypisania++;
    }
    porownania++;

    for (int i = 0; i < posCount; i++) 
    {
        porownania++;
        A[idx] = pos[i];
        przypisania++;
        idx++;
        przypisania++;
    }
    porownania++;

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
    }

    radixSort(A, n, d);

    cout << "Porownania: " << porownania << endl;
    cout << "Przypisania: " << przypisania << endl;
    delete[] A;
    return 0;
}
