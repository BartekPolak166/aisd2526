#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

long long porownania_2 = 0, przypisania_2 = 0;
long long porownania_3 = 0, przypisania_3 = 0;

void MERGE(int A[], int p, int s, int k)
{
    int n1 = s - p + 1;
    int n2 = k - s;
    int* L = new int[n1];
    int* R = new int[n2];
    for(int i = 0; i < n1; i++)
    {
        L[i] = A[p + i];
        przypisania_2++;
    }
    for(int j = 0; j < n2; j++) 
    {
        R[j] = A[s + 1 + j];
        przypisania_2++;
    }
    int i = 0, j = 0, r = p;
    while(i < n1 && j < n2)
    {
        porownania_2++;
        if(L[i] <= R[j]) 
        {
            A[r++] = L[i++];
            przypisania_2++;
        } 
        else 
        {
            A[r++] = R[j++];
            przypisania_2++;
        }
    }
    while(i < n1) 
    {
        A[r++] = L[i++];
        przypisania_2++;
    }
    while(j < n2) 
    {
        A[r++] = R[j++];
        przypisania_2++;
    }
    delete[] L;
    delete[] R;
}

void MERGE_SORT_2(int A[], int p, int k)
{
    porownania_2++;
    if(p < k)
    {
        int s = (p + k) / 2;
        MERGE_SORT_2(A, p, s);
        MERGE_SORT_2(A, s + 1, k);
        MERGE(A, p, s, k);
    }
}

void MERGE3(int A[], int p, int s1, int s2, int k)
{
    int n1 = s1 - p + 1;
    int n2 = s2 - s1;
    int n3 = k - s2;
    int* L1 = new int[n1];
    int* L2 = new int[n2];
    int* L3 = new int[n3];
    for(int i = 0; i < n1; i++) 
    {
        L1[i] = A[p + i];
        przypisania_3++;
    }
    for(int j = 0; j < n2; j++) 
    {
        L2[j] = A[s1 + 1 + j];
        przypisania_3++;
    }
    for(int m = 0; m < n3; m++) 
    {
        L3[m] = A[s2 + 1 + m];
        przypisania_3++;
    }
    int i = 0, j = 0, m = 0, r = p;
    while (i < n1 || j < n2 || m < n3)
    {
        int min_val = 1000000000;
        int min_index = 0;
        if(i < n1) 
        {
            porownania_3++;
            if (L1[i] < min_val) 
            {
                min_val = L1[i];
                min_index = 1;
                przypisania_3 += 2;
            }
        }
        if(j < n2) 
        {
            porownania_3++;
            if(L2[j] < min_val) 
            {
                min_val = L2[j];
                min_index = 2;
                przypisania_3 += 2;
            }
        }
        if (m < n3)
        {
            porownania_3++;
            if (L3[m] < min_val)
            {
                min_val = L3[m];
                min_index = 3;
                przypisania_3 += 2;
            }
        }

        if (min_index == 1)
        {
            A[r++] = L1[i++];
            przypisania_3++;
        } 
        else if (min_index == 2)
        {
            A[r++] = L2[j++];
            przypisania_3++;
        }
        else if (min_index == 3) 
        {
            A[r++] = L3[m++];
            przypisania_3++;
        }
    }
    delete[] L1;
    delete[] L2;
    delete[] L3;
}

void MERGE_SORT_3(int A[], int p, int k)
{
    porownania_3++;
    if (p < k)
    {
        int len = k - p + 1;
        if (len < 3)
        {
            MERGE_SORT_2(A, p, k);
            return;
        }
        int third = len / 3;
        int s1 = p + third - 1;
        int s2 = p + 2 * third - 1;
        if (s2 >= k) s2 = k - 1;
        MERGE_SORT_3(A, p, s1);
        MERGE_SORT_3(A, s1 + 1, s2);
        MERGE_SORT_3(A, s2 + 1, k);
        MERGE3(A, p, s1, s2, k);
    }
}

int main()
{
    srand(time(NULL));
    int n;
    cout << "Liczba elementow: ";
    cin >> n;
    int* A = new int[n];
    int* B = new int[n];
    for(int i = 0; i < n; i++)
    {
        A[i] = rand() % 1001;
        B[i] = A[i];
        cout << A[i] << " ";
    }

    MERGE_SORT_2(A, 0, n - 1);
    cout << endl << endl << "MERGE_SORT_2: " << "Porownania: " << porownania_2 << ", Przypisania: " << przypisania_2 << endl;
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    MERGE_SORT_3(B, 0, n - 1);
    cout << endl << endl << "MERGE_SORT_3: " << "Porownania: " << porownania_3 << ", Przypisania: " << przypisania_3 << endl;
    for (int i = 0; i < n; i++)
        cout << B[i] << " ";
    return 0;
}
