#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node
{
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

class Lista
{
private:
    Node* head;

public:
    Lista() : head(nullptr) {}

    void push_back(int v)
    {
        Node* newNode = new Node(v);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void print()
    {
        Node* temp = head;
        while (temp)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertion_sort()
    {
        if (!head || !head->next)
            return;

        Node* sorted = nullptr;

        Node* current = head;
        while (current)
        {
            Node* next = current->next;

            if (!sorted || sorted->value >= current->value)
            {
                current->next = sorted;
                sorted = current;
            } 
            else 
            {
                Node* temp = sorted;
                while (temp->next && temp->next->value < current->value)
                    temp = temp->next;

                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
        head = sorted;
    }
};

int main()
{
    srand(time(0));
    Lista list;
    int n; cin>>n;
    for (int i = 0; i < n; i++) 
    {
        int x = rand();
        list.push_back(x);
    }
    cout<<endl;

    list.print();
    list.insertion_sort();
    list.print();

    return 0;
}
