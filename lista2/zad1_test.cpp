#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

long long porownania1 = 0, przypisania1 = 0;
long long porownania2 = 0, przypisania2 = 0;

void swap1(int &a, int &b)
{
    int temp = a; przypisania1++;
    a = b;        przypisania1++;
    b = temp;     przypisania1++;
}

int PARTITION(int A[], int p, int k) 
{
    int x = A[k]; przypisania1++;
    int i = p - 1; przypisania1++;

    for (int j = p; j <= k - 1; j++) 
    {
        porownania1++; 

        porownania1++;
        if (A[j] <= x)
        {
            i++; przypisania1++;
            swap1(A[i], A[j]);
        }
    }
    swap1(A[i + 1], A[k]);
    return i + 1;
}

void QUICK_SORT(int A[], int p, int k) 
{
    porownania1++;
    if (p < k) 
    {
        int s = PARTITION(A, p, k);
        QUICK_SORT(A, p, s - 1);
        QUICK_SORT(A, s + 1, k);
    }
}

void swap2(int &a, int &b) 
{
    int temp = a; przypisania2++;
    a = b;        przypisania2++;
    b = temp;     przypisania2++;
}

void DUAL_PARTITION(int A[], int p, int k, int &s1, int &s2) {

    porownania2++;
    if (A[p] > A[k]) 
    {
        swap2(A[p], A[k]);
    }

    int pivot1 = A[p]; przypisania2++;
    int pivot2 = A[k]; przypisania2++;

    int lt = p + 1; przypisania2++;
    int gt = k - 1; przypisania2++;
    int i  = p + 1; przypisania2++;

    while (true) 
    {
        porownania2++;
        if (!(i <= gt)) break;

        porownania2++;
        if (A[i] < pivot1) 
        {
            swap2(A[i], A[lt]);
            lt++; przypisania2++;
            i++; przypisania2++;
        }
        else 
        {
            porownania2++;
            if (A[i] > pivot2) 
            {
                swap2(A[i], A[gt]);
                gt--; przypisania2++;
            }
            else 
            {
                i++; przypisania2++;
            }
        }
    }

    lt--; przypisania2++;
    gt++; przypisania2++;

    swap2(A[p], A[lt]);
    swap2(A[k], A[gt]);

    s1 = lt; przypisania2++;
    s2 = gt; przypisania2++;
}

void QUICK_SORT_DUAL(int A[], int p, int k) 
{
    porownania2++;
    if (p<k) 
    {
        int s1, s2;
        DUAL_PARTITION(A, p, k, s1, s2);
        QUICK_SORT_DUAL(A, p, s1 - 1);
        QUICK_SORT_DUAL(A, s1 + 1, s2 - 1);
        QUICK_SORT_DUAL(A, s2 + 1, k);
    }
}

int main() 
{
    srand(time(0));
    int n; cin>>n;
    const int N = n;
    int* A = new int[N];
    int* B = new int[N];
    for (int i = 0; i < N; i++) 
    {
        int x = rand();
        A[i] = x;
        B[i] = x;
    }

    QUICK_SORT(A, 0, N - 1);
    QUICK_SORT_DUAL(B, 0, N - 1);

    cout << "KLASYCZNY QUICKSORT:\n";
    cout << "  porownania:   " << porownania1 << "\n";
    cout << "  przypisania:  " << przypisania1 << "\n\n";

    cout << "DUAL-PIVOT QUICKSORT:\n";
    cout << "  porownania:   " << porownania2 << "\n";
    cout << "  przypisania:  " << przypisania2 << "\n\n";

    delete[] A;
    delete[] B;
    return 0;
}
