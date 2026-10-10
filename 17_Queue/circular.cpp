#include <iostream>
using namespace std;

#define MAX 3
int queue[MAX];

int currsize = 0;
int front = 0;
int rear = -1;

void enqueue(int val) {
    if (currsize == MAX) {
        cout << "Queue is full\n";
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = val;
    currsize++;
    cout << "Inserted: " << val << endl;
}

void dequeue() {
    if (currsize == 0) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Removed: " << queue[front] << endl;
    front = (front + 1) % MAX;
    currsize--;
}

int myfront() {
    if (currsize == 0) {
        cout << "Queue is empty\n";
        return -1;
    }
    return queue[front];
}

void printqueue() {
    if (currsize == 0) {
        cout << "Queue is empty\n";
        return;
    }

    int idx = front;
    for (int i = 0; i < currsize; i++) {
        cout << queue[idx] << " ";
        idx = (idx + 1) % MAX;
    }
    cout << endl;
}

int main() {
    enqueue(78);
    enqueue(23);
    enqueue(98);

    printqueue();

    dequeue();
    dequeue();

    cout << "Front element: " << myfront() << endl;
    enqueue(11);
    printqueue();
    return 0;
}
