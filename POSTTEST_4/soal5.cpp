#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void exchangeHeadAndTail(Node *&head_ref) {
    if (head_ref == nullptr || head_ref->next == head_ref)
        return; // List kosong atau 1 node

    Node* head = head_ref;
    Node* tail = head_ref->prev;

    // Jika hanya dua node
    if (head->next == tail) {
        tail->next = head;
        tail->prev = head;
        head->next = tail;
        head->prev = tail;
        head_ref = tail;
        return;
    }

    // Simpan tetangga dari head dan tail
    Node* headNext = head->next;
    Node* tailPrev = tail->prev;

    // Sambungkan tetangga sekitar head dan tail ke posisi baru
    headNext->prev = tail;
    tailPrev->next = head;

    // Tukar posisi head dan tail
    tail->next = headNext;
    tail->prev = head->prev;  // prev tail sebelumnya adalah node terakhir sebelum head
    head->next = head_ref;    // sementara
    head->prev = tailPrev;

    // Hubungkan prev dan next tail-head baru agar circular tetap utuh
    tail->prev->next = tail;
    head->next = head_ref;
    head_ref->prev = head;

    // Update head baru
    head_ref = tail;
}

void printList(Node *head_ref)
{
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

void insertEnd(Node *&head_ref, int data)
{
    Node *newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main()
{
    Node *head = nullptr;

    // Buat list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    printList(head); 

    return 0;
}
