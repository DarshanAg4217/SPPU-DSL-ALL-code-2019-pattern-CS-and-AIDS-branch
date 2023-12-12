#include <iostream>
#define MAX_SIZE 5
using namespace std;

class CircularQueue {
private:
    int front, rear;
    int pizzaCount;
    int orderQueue[MAX_SIZE];
public:
    CircularQueue() {
        front = -1;
        rear = -1;
        pizzaCount = 0;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return ((rear + 1) % MAX_SIZE == front);
    }

    void enqueue(int order) {
        if (isFull()) {
            cout << "Queue is full. Cannot accept more orders." << endl;
        } else {
            if (isEmpty()) {
                front = 0;
            }
            rear = (rear + 1) % MAX_SIZE;
            orderQueue[rear] = order;
            pizzaCount++;
            cout << "Order placed successfully." << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No orders to serve." << endl;
        } else {
            int servedOrder = orderQueue[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % MAX_SIZE;
            }
            pizzaCount--;
            cout << "Order " << servedOrder << " served and removed from the queue." << endl;
        }
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Current order queue: ";
            int count = 0;
            int index = front;
            while (count < pizzaCount) {
                cout << orderQueue[index] << " ";
                index = (index + 1) % MAX_SIZE;
                count++;
            }
            cout << endl;
        }
    }
};

int main() {
    CircularQueue orderQueue;
    int choice, order;

    do {
        cout << "Pizza Parlor Management System" << endl;
        cout << "1. Place an order" << endl;
        cout << "2. Serve an order" << endl;
        cout << "3. Display current order queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the order number: ";
                cin >> order;
                orderQueue.enqueue(order);
                cout << endl;
                break;
            case 2:
                orderQueue.dequeue();
                cout << endl;
                break;
            case 3:
                orderQueue.displayQueue();
                cout << endl;
                break;
            case 4:
		cout<<"Thank You...!";
                break;
            default:
                cout << "Invalid choice. Please try again." << endl << endl;
                break;
        }
    } while (choice != 4);

return 0;
}


********************OUTPUT**********************


Pizza Parlor Management System
1. Place an order
2. Serve an order
3. Display current order queue
4. Exit
Enter your choice: 1
Enter the order number: 1
Order placed successfully.

Pizza Parlor Management System
1. Place an order
2. Serve an order
3. Display current order queue
4. Exit
Enter your choice: 1
Enter the order number: 2
Order placed successfully.

Pizza Parlor Management System
1. Place an order
2. Serve an order
3. Display current order queue
4. Exit
Enter your choice: 1
Enter the order number: 3
Order placed successfully.

Pizza Parlor Management System
1. Place an order
2. Serve an order
3. Display current order queue
4. Exit
Enter your choice: 1
Enter the order number: 4
Order placed successfully.

Pizza Parlor Management System
1. Place an order
2. Serve an order
3. Display current order queue
4. Exit
Enter your choice: 1
Enter the order number: 5
Order placed successfully.

Pizza Parlor Management System
1. Place an order
2. Serve an order
3. Display current order queue
4. Exit
Enter your choice: 2
Order 1 served and removed from the queue.

Pizza Parlor Management System
1. Place an order
2. Serve an order
3. Display current order queue
4. Exit
Enter your choice: 2
Order 2 served and removed from the queue.

Pizza Parlor Management System
1. Place an order
2. Serve an order
3. Display current order queue
4. Exit
Enter your choice: 3
Current order queue: 3 4 5 

Pizza Parlor Management System
1. Place an order
2. Serve an order
3. Display current order queue
4. Exit
Enter your choice: 2
Order 3 served and removed from the queue.

Pizza Parlor Management System
1. Place an order
2. Serve an order
3. Display current order queue
4. Exit
Enter your choice: 3
Current order queue: 4 5 

Pizza Parlor Management System
1. Place an order
2. Serve an order
3. Display current order queue
4. Exit
Enter your choice: 2
Order 4 served and removed from the queue.

Pizza Parlor Management System
1. Place an order
2. Serve an order
3. Display current order queue
4. Exit
Enter your choice: 3
Current order queue: 5 

Pizza Parlor Management System
1. Place an order
2. Serve an order
3. Display current order queue
4. Exit
Enter your choice: 2
Order 5 served and removed from the queue.

Pizza Parlor Management System
1. Place an order
2. Serve an order
3. Display current order queue
4. Exit
Enter your choice: 3
Queue is empty.

Pizza Parlor Management System
1. Place an order
2. Serve an order
3. Display current order queue
4. Exit
Enter your choice: 4
Thank You...!