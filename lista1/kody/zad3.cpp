#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void heapify_binary(int A[], int n, int i, long long &porownania, long long &przypisania) 
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n)
    {
        porownania++;
        if(A[left] > A[largest])
            largest = left;
    }

    if(right < n)
    {
        porownania++;
        if(A[right] > A[largest])
            largest = right;
    }

    if(largest != i) 
    {
        swap(A[i], A[largest]);
        przypisania += 3;
        heapify_binary(A, n, largest, porownania, przypisania);
    }
}

void heapSort_binary(int A[], int n, long long &porownania, long long &przypisania) 
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify_binary(A, n, i, porownania, przypisania);
    for (int i = n - 1; i > 0; i--) 
    {
        swap(A[0], A[i]);
        przypisania += 3;
        heapify_binary(A, i, 0, porownania, przypisania);
    }
}

void heapify_ternary(int A[], int n, int i, long long &porownania, long long &przypisania)
{
    int largest = i;
    int c1 = 3 * i + 1;
    int c2 = 3 * i + 2;
    int c3 = 3 * i + 3;

    if(c1 < n) 
    {
        porownania++;
        if(A[c1] > A[largest]) largest = c1;
    }
    if(c2 < n) 
    {
        porownania++;
        if(A[c2] > A[largest]) largest = c2;
    }
    if(c3 < n) 
    {
        porownania++;
        if(A[c3] > A[largest]) largest = c3;
    }

    if(largest != i)
    {
        swap(A[i], A[largest]);
        przypisania += 3;
        heapify_ternary(A, n, largest, porownania, przypisania);
    }
}

void heapSort_ternary(int A[], int n, long long &porownania, long long &przypisania) 
{
    for (int i = n / 3; i >= 0; i--)
        heapify_ternary(A, n, i, porownania, przypisania);
    for (int i = n - 1; i > 0; i--) 
    {
        swap(A[0], A[i]);
        przypisania += 3;
        heapify_ternary(A, i, 0, porownania, przypisania);
    }
}

int main() 
{
    srand(time(NULL));
    int n;
    cout << "Liczba elementow: ";
    cin >> n;

    int* tab = new int[n];
    int* B = new int[n];
    int* T = new int[n];

    cout << endl <<"Tablica przed: " << endl;
    for(int i = 0; i < n; i++) 
    {
        tab[i] = rand() % 1000; 
        cout << tab[i] << " ";
        B[i] = tab[i];
        T[i] = tab[i];
    }
    cout << endl;

    long long porownania_b = 0, przypisania_b = 0;
    heapSort_binary(B, n, porownania_b, przypisania_b);
    cout << endl << "heapSort_binary: " << "porownania: " << porownania_b << ", przypisania: " << przypisania_b << endl;
    for(int i = 0; i < n; i++)
        cout << B[i] << " ";

    long long porownania_t = 0, przypisania_t = 0;
    heapSort_ternary(T, n, porownania_t, przypisania_t);
    cout << endl << "heapSort_ternary: " << "porownania: " << porownania_t << ", przypisania: " << przypisania_t << endl;
    for(int i = 0; i < n; i++)
        cout << T[i] << " ";
    return 0;
}
