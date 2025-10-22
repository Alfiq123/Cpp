//
// Created by algorithm on 10/21/25.
//

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* headCircular = nullptr;

void tambahData(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;

    if (headCircular == nullptr) {
        headCircular = baru;
        baru->next = headCircular;
    } else {
        Node* temp = headCircular;
        while (temp->next != headCircular) {
            temp = temp->next;
        }
        temp->next = baru;
        baru->next = headCircular;
    }
}

void tampilCircular() {
    if (headCircular == nullptr) {
        cout << "List kosong\n";
        return;
    }

    Node* temp = headCircular;
    cout << "Traversal Circular: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != headCircular);
    cout << endl;
}

int main() {
    tambahData(10);
    tambahData(20);
    tambahData(30);
    tambahData(40);

    tampilCircular();
}
