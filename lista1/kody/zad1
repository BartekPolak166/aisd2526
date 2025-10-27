#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void INSERTION_SORT(int n, int* A)
{
    int x, j;
    long long porownania = 0;
    long long przypisania = 0;

    for (int i = 1; i < n; i++)
    {
        x = A[i];
        przypisania++;
        j = i - 1;
        przypisania++;
        while(true)
        {
            porownania++;
            if(j < 0) break;
            porownania++;
            if(A[j] > x)
            {
                A[j + 1] = A[j];
                przypisania++;
                j--;
                przypisania++;
            }
            else break;
        }
        A[j + 1] = x;
        przypisania++;
    }

    cout << "INSERTION_SORT: Porownania: " << porownania << ", Przypisania: " << przypisania << endl;
}

void INSERTION_SORT2(int n, int* A)
{
    int i = 0;
    long long porownania = 0;
    long long przypisania = 0;

    przypisania++;
    while(true)
    {
        porownania++;
        if(i >= n) break;
        porownania++;
        if(i + 1 < n)
        {
            int x1 = A[i];
            int x2 = A[i + 1];
            przypisania += 2;
            porownania++;
            if(x1 > x2)
            {
                swap(x1, x2);
                przypisania += 2;
            }
            int j = i - 1;
            przypisania++;
            while(true)
            {
                porownania++;
                if(j < 0) break;
                porownania++;
                if(A[j] > x1)
                {
                    A[j + 1] = A[j];
                    przypisania++;
                    j--;
                    przypisania++;
                }
                else break;
            }
            A[j + 1] = x1;
            przypisania++;
            j = i;
            przypisania++;
            while(true)
            {
                porownania++;
                if(j < 0) break;
                porownania++;
                if(A[j] > x2)
                {
                    A[j + 1] = A[j];
                    przypisania++;
                    j--;
                    przypisania++;
                }
                else break;
            }
            A[j + 1] = x2;
            przypisania++;
            i += 2;
            przypisania++;
        }
        else
        {
            int x = A[i];
            przypisania++;
            int j = i - 1;
            przypisania++;

            while(true)
            {
                porownania++;
                if(j < 0) break;
                porownania++;
                if(A[j] > x)
                {
                    A[j + 1] = A[j];
                    przypisania++;
                    j--;
                    przypisania++;
                }
                else break;
            }
            A[j + 1] = x;
            przypisania++;
            i++;
            przypisania++;
        }
    }

    cout << "INSERTION_SORT2: Porownania: " << porownania << ", Przypisania: " << przypisania << endl;
}

int main()
{
    srand(time(NULL));
    int n;
    cout << "Liczba elementow: ";
    cin >> n;

    int* A = new int[n];
    int* A2 = new int[n];

    cout << endl <<"Tablica przed: " << endl;
    for(int i = 0; i < n; i++)
    {
        A[i] = rand() % 1001;
        A2[i] = A[i];
        cout << A[i] << " ";
    }

    cout << endl << endl << "Po INSERTION_SORT: " << endl;
    INSERTION_SORT(n, A);
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";

    cout << endl << endl << "Po INSERTION_SORT2: " << endl;
    INSERTION_SORT2(n, A2);
    for(int i = 0; i < n; i++)
        cout << A2[i] << " ";
    cout << endl;
    return 0;
}

