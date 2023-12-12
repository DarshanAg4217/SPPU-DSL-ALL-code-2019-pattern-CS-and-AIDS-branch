#include <iostream>

class Dequeue {
private:
    int* array;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Dequeue(int capacity) {
        this->capacity = capacity;
        front = -1;
        rear = 0;
        size = 0;
        array = new int[capacity];
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void insertFront(int element) {
        if (isFull()) {
            std::cout << "Dequeue is full. Unable to insert at the front.\n";
            return;
        }

        if (front == -1)
            front = 0;
        else if (front == 0)
            front = capacity - 1;
        else
            front--;

        array[front] = element;
        size++;

        std::cout << "Element " << element << " inserted at the front.\n";
    }

    void insertRear(int element) {
        if (isFull()) {
            std::cout << "Dequeue is full. Unable to insert at the rear.\n";
            return;
        }

        if (front == -1)
            front = 0;
        rear = (rear + 1) % capacity;

        array[rear] = element;
        size++;

        std::cout << "Element " << element << " inserted at the rear.\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            std::cout << "Dequeue is empty. Unable to delete from the front.\n";
            return;
        }

        int element = array[front];

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % capacity;

        size--;

        std::cout << "Element " << element << " deleted from the front.\n";
    }

    void deleteRear() {
        if (isEmpty()) {
            std::cout << "Dequeue is empty. Unable to delete from the rear.\n";
            return;
        }

        int element = array[rear];

        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = capacity - 1;
        else
            rear--;

        size--;

        std::cout << "Element " << element << " deleted from the rear.\n";
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Dequeue is empty. Nothing to display.\n";
            return;
        }

        std::cout << "Elements in the dequeue: ";
        int count = 0;
        int index = front;

        while (count < size) {
            std::cout << array[index] << " ";
            index = (index + 1) % capacity;
            count++;
        }

        std::cout << "\n";
    }
};

int main() {
    int capacity;
    std::cout << "Enter the capacity of the Dequeue: ";
    std::cin >> capacity;

    Dequeue dq(capacity);

    int choice, element;

    do {
        std::cout << "======= Dequeue Operations =======\n";
        std::cout << "1. Insert at the front\n";
        std::cout << "2. Insert at the rear\n";
        std::cout << "3. Delete from the front\n";
        std::cout << "4. Delete from the rear\n";
        std::cout << "5. Display the dequeue\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the element to insert at the front: ";
                std::cin >> element;
                dq.insertFront(element);
                break;
            case 2:
                std::cout << "Enter the element to insert at the rear: ";
                std::cin >> element;
                dq.insertRear(element);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                dq.display();
                break;
            case 6:
                std::cout << "Exiting the program...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

        std::cout << "\n";

    } while (choice != 6);

    return 0;
}


***********************OUTPUT******************************


Enter the capacity of the Dequeue: 5
======= Dequeue Operations =======
1. Insert at the front
2. Insert at the rear
3. Delete from the front
4. Delete from the rear
5. Display the dequeue
6. Exit
Enter your choice: 1
Enter the element to insert at the front: 1
Element 1 inserted at the front.

======= Dequeue Operations =======
1. Insert at the front
2. Insert at the rear
3. Delete from the front
4. Delete from the rear
5. Display the dequeue
6. Exit
Enter your choice: 1
Enter the element to insert at the front: 2
Element 2 inserted at the front.

======= Dequeue Operations =======
1. Insert at the front
2. Insert at the rear
3. Delete from the front
4. Delete from the rear
5. Display the dequeue
6. Exit
Enter your choice: 1
Enter the element to insert at the front: 3
Element 3 inserted at the front.

======= Dequeue Operations =======
1. Insert at the front
2. Insert at the rear
3. Delete from the front
4. Delete from the rear
5. Display the dequeue
6. Exit
Enter your choice: 2
Enter the element to insert at the rear: 4
Element 4 inserted at the rear.

======= Dequeue Operations =======
1. Insert at the front
2. Insert at the rear
3. Delete from the front
4. Delete from the rear
5. Display the dequeue
6. Exit
Enter your choice: 2
Enter the element to insert at the rear: 5
Element 5 inserted at the rear.

======= Dequeue Operations =======
1. Insert at the front
2. Insert at the rear
3. Delete from the front
4. Delete from the rear
5. Display the dequeue
6. Exit
Enter your choice: 2
Enter the element to insert at the rear: 6
Dequeue is full. Unable to insert at the rear.

======= Dequeue Operations =======
1. Insert at the front
2. Insert at the rear
3. Delete from the front
4. Delete from the rear
5. Display the dequeue
6. Exit
Enter your choice: 5
Elements in the dequeue: 3 2 1 4 5 

======= Dequeue Operations =======
1. Insert at the front
2. Insert at the rear
3. Delete from the front
4. Delete from the rear
5. Display the dequeue
6. Exit
Enter your choice: 3
Element 3 deleted from the front.

======= Dequeue Operations =======
1. Insert at the front
2. Insert at the rear
3. Delete from the front
4. Delete from the rear
5. Display the dequeue
6. Exit
Enter your choice: 5
Elements in the dequeue: 2 1 4 5 

======= Dequeue Operations =======
1. Insert at the front
2. Insert at the rear
3. Delete from the front
4. Delete from the rear
5. Display the dequeue
6. Exit
Enter your choice: 4
Element 5 deleted from the rear.

======= Dequeue Operations =======
1. Insert at the front
2. Insert at the rear
3. Delete from the front
4. Delete from the rear
5. Display the dequeue
6. Exit
Enter your choice: 5
Elements in the dequeue: 2 1 4 

======= Dequeue Operations =======
1. Insert at the front
2. Insert at the rear
3. Delete from the front
4. Delete from the rear
5. Display the dequeue
6. Exit
Enter your choice: 3
Element 2 deleted from the front.

======= Dequeue Operations =======
1. Insert at the front
2. Insert at the rear
3. Delete from the front
4. Delete from the rear
5. Display the dequeue
6. Exit
Enter your choice: 5
Elements in the dequeue: 1 4 

======= Dequeue Operations =======
1. Insert at the front
2. Insert at the rear
3. Delete from the front
4. Delete from the rear
5. Display the dequeue
6. Exit
Enter your choice: 4
Element 4 deleted from the rear.

======= Dequeue Operations =======
1. Insert at the front
2. Insert at the rear
3. Delete from the front
4. Delete from the rear
5. Display the dequeue
6. Exit
Enter your choice: 5
Elements in the dequeue: 1 

======= Dequeue Operations =======
1. Insert at the front
2. Insert at the rear
3. Delete from the front
4. Delete from the rear
5. Display the dequeue
6. Exit
Enter your choice: 6
Exiting the program...