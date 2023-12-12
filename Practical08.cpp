#include <iostream>
#include <string>
using namespace std;

// Node structure for linked list
struct Node {
    string studentName;
    bool likesVanilla;
    bool likesButterscotch;
    Node* next;
};

// Function to add a student to the linked list
void addStudent(Node*& head, string name, bool likesVanilla, bool likesButterscotch) {
    Node* newNode = new Node;
    newNode->studentName = name;
    newNode->likesVanilla = likesVanilla;
    newNode->likesButterscotch = likesButterscotch;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to compute and display students who like either vanilla or butterscotch or both
void displayLikeEither(Node* head) {
    if (head == nullptr) {
        cout << "No students in the list." << endl;
        return;
    }

    cout << "Students who like either vanilla or butterscotch or both:" << endl;

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->likesVanilla || temp->likesButterscotch) {
            cout << temp->studentName << endl;
        }
        temp = temp->next;
    }
}

// Function to compute and display students who like both vanilla and butterscotch
void displayLikeBoth(Node* head) {
    if (head == nullptr) {
        cout << "No students in the list." << endl;
        return;
    }

    cout << "Students who like both vanilla and butterscotch:" << endl;

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->likesVanilla && temp->likesButterscotch) {
            cout << temp->studentName << endl;
        }
        temp = temp->next;
    }
}

// Function to compute and display students who like only vanilla not butterscotch
void displayLikeOnlyVanilla(Node* head) {
    if (head == nullptr) {
        cout << "No students in the list." << endl;
        return;
    }

    cout << "Students who like only vanilla not butterscotch:" << endl;

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->likesVanilla && !temp->likesButterscotch) {
            cout << temp->studentName << endl;
        }
        temp = temp->next;
    }
}

// Function to compute and display students who like only butterscotch not vanilla
void displayLikeOnlyButterscotch(Node* head) {
    if (head == nullptr) {
        cout << "No students in the list." << endl;
        return;
    }

    cout << "Students who like only butterscotch not vanilla:" << endl;

    Node* temp = head;
    while (temp != nullptr) {
        if (!temp->likesVanilla && temp->likesButterscotch) {
            cout << temp->studentName << endl;
        }
        temp = temp->next;
    }
}

// Function to compute and display students who like neither vanilla nor butterscotch
void displayLikeNeither(Node* head) {
    if (head == nullptr) {
        cout << "No students in the list." << endl;
        return;
    }

    cout << "Number of students who like neither vanilla nor butterscotch:" << endl;

    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (!temp->likesVanilla && !temp->likesButterscotch) {
            count++;
        }
        temp = temp->next;
    }

    cout << count << endl;
}

// Function to display the menu options
void displayMenuOptions() {
    cout << endl;
    cout << "Menu Options:" << endl;
    cout << "1. Set of students who like either vanilla or butterscotch or both." << endl;
    cout << "2. Set of students who like both vanilla and butterscotch." << endl;
    cout << "3. Set of students who like only vanilla not butterscotch." << endl;
    cout << "4. Set of students who like only butterscotch not vanilla." << endl;
    cout << "5. Number of students who like neither vanilla nor butterscotch." << endl;
    cout << "6. Exit." << endl;
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Getting user input for students and their ice cream preferences
    cout << "Enter the number of students: ";
    int numStudents;
    cin >> numStudents;

    for (int i = 1; i <= numStudents; i++) {
        string name;
        bool likesVanilla, likesButterscotch;

        cout << "Enter name of student " << i << ": ";
        cin.ignore();
        getline(cin, name);
        cout << "Does " << name << " like vanilla? (1 for yes, 0 for no): ";
        cin >> likesVanilla;
        cout << "Does " << name << " like butterscotch? (1 for yes, 0 for no): ";
        cin >> likesButterscotch;

        addStudent(head, name, likesVanilla, likesButterscotch);
    }

    int choice;

    do {
        displayMenuOptions();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayLikeEither(head);
                break;

            case 2:
                displayLikeBoth(head);
                break;

            case 3:
                displayLikeOnlyVanilla(head);
                break;

            case 4:
                displayLikeOnlyButterscotch(head);
                break;

            case 5:
                displayLikeNeither(head);
                break;

            case 6:
                cout << "Exiting the program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    } while (choice != 6);

    // Freeing the memory allocated for the linked list
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}



********************OUTPUT********************


Enter the number of students: 4
Enter name of student 1: A
Does A like vanilla? (1 for yes, 0 for no): 1
Does A like butterscotch? (1 for yes, 0 for no): 1
Enter name of student 2: B
Does B like vanilla? (1 for yes, 0 for no): 1
Does B like butterscotch? (1 for yes, 0 for no): 0
Enter name of student 3: C
Does C like vanilla? (1 for yes, 0 for no): 0
Does C like butterscotch? (1 for yes, 0 for no): 1
Enter name of student 4: D
Does D like vanilla? (1 for yes, 0 for no): 0
Does D like butterscotch? (1 for yes, 0 for no): 0
Menu Options:
1. Set of students who like either vanilla or butterscotch or both.
2. Set of students who like both vanilla and butterscotch.
3. Set of students who like only vanilla not butterscotch.
4. Set of students who like only butterscotch not vanilla.
5. Number of students who like neither vanilla nor butterscotch.
6. Exit.

Enter your choice: 1
Students who like either vanilla or butterscotch or both:
A
B
C

Menu Options:
1. Set of students who like either vanilla or butterscotch or both.
2. Set of students who like both vanilla and butterscotch.
3. Set of students who like only vanilla not butterscotch.
4. Set of students who like only butterscotch not vanilla.
5. Number of students who like neither vanilla nor butterscotch.
6. Exit.

Enter your choice: 2
Students who like both vanilla and butterscotch:
A

Menu Options:
1. Set of students who like either vanilla or butterscotch or both.
2. Set of students who like both vanilla and butterscotch.
3. Set of students who like only vanilla not butterscotch.
4. Set of students who like only butterscotch not vanilla.
5. Number of students who like neither vanilla nor butterscotch.
6. Exit.

Enter your choice: 3
Students who like only vanilla not butterscotch:
B

Menu Options:
1. Set of students who like either vanilla or butterscotch or both.
2. Set of students who like both vanilla and butterscotch.
3. Set of students who like only vanilla not butterscotch.
4. Set of students who like only butterscotch not vanilla.
5. Number of students who like neither vanilla nor butterscotch.
6. Exit.

Enter your choice: 4
Students who like only butterscotch not vanilla:
C

Menu Options:
1. Set of students who like either vanilla or butterscotch or both.
2. Set of students who like both vanilla and butterscotch.
3. Set of students who like only vanilla not butterscotch.
4. Set of students who like only butterscotch not vanilla.
5. Number of students who like neither vanilla nor butterscotch.
6. Exit.

Enter your choice: 5
Number of students who like neither vanilla nor butterscotch:
1

Menu Options:
1. Set of students who like either vanilla or butterscotch or both.
2. Set of students who like both vanilla and butterscotch.
3. Set of students who like only vanilla not butterscotch.
4. Set of students who like only butterscotch not vanilla.
5. Number of students who like neither vanilla nor butterscotch.
6. Exit.

Enter your choice: 6
Exiting the program...
