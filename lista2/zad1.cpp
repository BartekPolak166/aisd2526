#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int PARTITION(int A[], int p, int k)
{
    int x = A[k];
    int i = p-1;

    for (int j = p; j <= k-1; j++)
    {
        if (A[j] <= x)
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[k]);
    return i+1;
}

void QUICK_SORT(int A[], int p, int k)
{
    if(p<k)
    {
        int s=PARTITION(A, p, k);
        QUICK_SORT(A, p, s-1);
        QUICK_SORT(A, s+1, k);
    }
}

void DUAL_PARTITION(int A[], int p, int k, int &s1, int &s2)
{

    if (A[p] > A[k])
        swap(A[p], A[k]);

    int pivot1 = A[p];
    int pivot2 = A[k];

    int lt = p + 1;
    int gt = k - 1;
    int i = p + 1;

    while (i <= gt)
    {
        if (A[i] < pivot1)
        {
            swap(A[i], A[lt]);
            lt++;
            i++;
        }
        else if (A[i] > pivot2)
        {
            swap(A[i], A[gt]);
            gt--;
        }
        else 
        {
            i++;
        }
    }

    lt--;
    gt++;

    swap(A[p], A[lt]);
    swap(A[k], A[gt]);

    s1=lt;
    s2=gt;
}

void QUICK_SORT_DUAL(int A[], int p, int k)
{
    if (p < k)
    {
        int s1,s2;
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
        cout<<A[i]<<" ";
    }
    cout<<endl;

    QUICK_SORT(A, 0, N - 1);
    QUICK_SORT_DUAL(B, 0, N - 1);

    for (int i = 0; i < N; i++) 
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < N; i++) 
    {
        cout<<B[i]<<" ";
    }

    delete[] A;
    delete[] B;
    return 0;
}
