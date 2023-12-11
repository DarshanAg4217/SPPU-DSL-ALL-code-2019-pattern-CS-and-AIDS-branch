#include <iostream>
#include <string>
#include<stack>
using namespace std;

// Structure for Club Member
struct Member {
    string prn;
    string name;
    Member* next;
};

// Global pointers for President and Secretary
Member* president = nullptr;
Member* secretary = nullptr;

// Function to add a member at the end of the list
void addMember(Member*& head, Member*& tail, string prn, string name) {
    Member* newMember = new Member;
    newMember->prn = prn;
    newMember->name = name;
    newMember->next = nullptr;

    if (head == nullptr) {
        head = newMember;
        tail = newMember;
    } else {
        tail->next = newMember;
        tail = newMember;
    }
}

// Function to delete a member from the list
void deleteMember(Member*& head, Member*& tail, string prn) {
    if (head == nullptr) {
        cout << "There are no members in the club." << endl;
        return;
    }

    Member* curr = head;
    Member* prev = nullptr;

    // Handle case if the member to be deleted is the President
    if (curr != nullptr && curr->prn == prn) {
        if (curr == president) {
            president = curr->next;
        }
        head = curr->next;
        delete curr;
        cout << "Member with PRN " << prn << " deleted." << endl;
        return;
    }

    // Handle case if the member to be deleted is the Secretary
    if (curr != nullptr && curr->prn == prn && curr == secretary) {
        prev->next = curr->next;
        secretary = curr->next;
        delete curr;
        cout << "Member with PRN " << prn << " deleted." << endl;
        return;
    }

    while (curr != nullptr && curr->prn != prn) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Member with PRN " << prn << " not found." << endl;
    } else {
        prev->next = curr->next;
        delete curr;
        cout << "Member with PRN " << prn << " deleted." << endl;
    }
}

// Function to compute the total number of members
int getTotalMembers(Member* head) {
    int count = 0;
    Member* curr = head;
    while (curr != nullptr) {
        count++;
        curr = curr->next;
    }
    return count;
}

// Function to display all the club members
void displayMembers(Member* head) {
    if (head == nullptr) {
        cout << "There are no members in the club." << endl;
        return;
    }

    Member* curr = head;
    cout << "Club Members:" << endl;
    while (curr != nullptr) {
        cout << "PRN: " << curr->prn << ", Name: " << curr->name << endl;
        curr = curr->next;
    }
}

// Function to display the list in reverse order using recursion
void displayReverse(Member* head) {
    if (head == nullptr) {
        return;
    }
    displayReverse(head->next);
    cout << "PRN: " << head->prn << ", Name: " << head->name << endl;
}

// Function to concatenate two linked lists
Member* concatenateLists(Member* firstHead, Member* secondHead) {
    if (firstHead == nullptr) {
        return secondHead;
    }
    if (secondHead == nullptr) {
        return firstHead;
    }

    Member* curr = firstHead;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = secondHead;
    return firstHead;
}

int main() {
    Member* firstHead = nullptr;
    Member* firstTail = nullptr;
    Member* secondHead = nullptr;
    Member* secondTail = nullptr;

    // Add some sample members
    addMember(firstHead, firstTail, "1", "John");
    addMember(firstHead, firstTail, "3", "Alice");
    addMember(secondHead, secondTail, "2", "Bob");
    addMember(secondHead, secondTail, "4", "Eve");

    // Assign President and Secretary
    president = firstHead;
    secretary = firstTail;

    int choice;
    string prn, name;

    // Menu-driven program using a do-while loop
    do {
        cout << "Club Member Information System" << endl;
        cout << "1. Add Member" << endl;
        cout << "2. Delete Member" << endl;
        cout << "3. Total Members" << endl;
        cout << "4. Display Members" << endl;
        cout << "5. Display Members in Reverse Order" << endl;
        cout << "6. Concatenate Two Lists" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter PRN: ";
                cin >> prn;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                addMember(firstHead, firstTail, prn, name);
                cout << "Member added successfully." << endl;
                break;
            case 2:
                cout << "Enter PRN of the member to delete: ";
                cin >> prn;
                deleteMember(firstHead, firstTail, prn);
                break;
            case 3:
                cout << "Total Club Members: " << getTotalMembers(firstHead) << endl;
                break;
            case 4:
                displayMembers(firstHead);
                break;
            case 5:
                cout << "Club Members in Reverse Order:" << endl;
                displayReverse(firstHead);
                break;
            case 6:
                cout << "Concatenated Lists:" << endl;
                Member* combinedHead = concatenateLists(firstHead, secondHead);
                displayMembers(combinedHead);
                break;

            
        }
    } while(choice!=7);

    // Clean up memory
    Member* temp = nullptr;
    while (firstHead != nullptr) {
        temp = firstHead;
        firstHead = firstHead->next;
        delete temp;
    }
    while (secondHead != nullptr) {
        temp = secondHead;
        secondHead = secondHead->next;
        delete temp;
    }

    return 0;
}



*********************OUTPUT**************************


Club Member Information System
1. Add Member
2. Delete Member
3. Total Members
4. Display Members
5. Display Members in Reverse Order
6. Concatenate Two Lists
7. Exit
Enter your choice: 1
Enter PRN: 123
Enter Name: A
Member added successfully.
Club Member Information System
1. Add Member
2. Delete Member
3. Total Members
4. Display Members
5. Display Members in Reverse Order
6. Concatenate Two Lists
7. Exit
Enter your choice: 1
Enter PRN: 456
Enter Name: B
Member added successfully.
Club Member Information System
1. Add Member
2. Delete Member
3. Total Members
4. Display Members
5. Display Members in Reverse Order
6. Concatenate Two Lists
7. Exit
Enter your choice: 1
Enter PRN: 789
Enter Name: C
Member added successfully.
Club Member Information System
1. Add Member
2. Delete Member
3. Total Members
4. Display Members
5. Display Members in Reverse Order
6. Concatenate Two Lists
7. Exit
Enter your choice: 1
Enter PRN: 234
Enter Name: D
Member added successfully.
Club Member Information System
1. Add Member
2. Delete Member
3. Total Members
4. Display Members
5. Display Members in Reverse Order
6. Concatenate Two Lists
7. Exit
Enter your choice: 1
Enter PRN: 345
Enter Name: E
Member added successfully.
Club Member Information System
1. Add Member
2. Delete Member
3. Total Members
4. Display Members
5. Display Members in Reverse Order
6. Concatenate Two Lists
7. Exit
Enter your choice: 1
Enter PRN: 654
Enter Name: F
Member added successfully.
Club Member Information System
1. Add Member
2. Delete Member
3. Total Members
4. Display Members
5. Display Members in Reverse Order
6. Concatenate Two Lists
7. Exit
Enter your choice: 1
Enter PRN: 765
Enter Name: G
Member added successfully.
Club Member Information System
1. Add Member
2. Delete Member
3. Total Members
4. Display Members
5. Display Members in Reverse Order
6. Concatenate Two Lists
7. Exit
Enter your choice: 2
Enter PRN of the member to delete: 123
Member with PRN 123 deleted.
Club Member Information System
1. Add Member
2. Delete Member
3. Total Members
4. Display Members
5. Display Members in Reverse Order
6. Concatenate Two Lists
7. Exit
Enter your choice: 4
Club Members:
PRN: 1, Name: John
PRN: 3, Name: Alice
PRN: 456, Name: B
PRN: 789, Name: C
PRN: 234, Name: D
PRN: 345, Name: E
PRN: 654, Name: F
PRN: 765, Name: G
Club Member Information System
1. Add Member
2. Delete Member
3. Total Members
4. Display Members
5. Display Members in Reverse Order
6. Concatenate Two Lists
7. Exit
Enter your choice: 3
Total Club Members: 8
Club Member Information System
1. Add Member
2. Delete Member
3. Total Members
4. Display Members
5. Display Members in Reverse Order
6. Concatenate Two Lists
7. Exit
Enter your choice: 2
Enter PRN of the member to delete: 456
Member with PRN 456 deleted.
Club Member Information System
1. Add Member
2. Delete Member
3. Total Members
4. Display Members
5. Display Members in Reverse Order
6. Concatenate Two Lists
7. Exit
Enter your choice: 3
Total Club Members: 7
Club Member Information System
1. Add Member
2. Delete Member
3. Total Members
4. Display Members
5. Display Members in Reverse Order
6. Concatenate Two Lists
7. Exit
Enter your choice: 5
Club Members in Reverse Order:
PRN: 765, Name: G
PRN: 654, Name: F
PRN: 345, Name: E
PRN: 234, Name: D
PRN: 789, Name: C
PRN: 3, Name: Alice
PRN: 1, Name: John
Club Member Information System
1. Add Member
2. Delete Member
3. Total Members
4. Display Members
5. Display Members in Reverse Order
6. Concatenate Two Lists
7. Exit
Enter your choice: 4
Club Members:
PRN: 1, Name: John
PRN: 3, Name: Alice
PRN: 789, Name: C
PRN: 234, Name: D
PRN: 345, Name: E
PRN: 654, Name: F
PRN: 765, Name: G
Club Member Information System
1. Add Member
2. Delete Member
3. Total Members
4. Display Members
5. Display Members in Reverse Order
6. Concatenate Two Lists
7. Exit
Enter your choice: 6
Concatenated Lists:
Club Members:
PRN: 1, Name: John
PRN: 3, Name: Alice
PRN: 789, Name: C
PRN: 234, Name: D
PRN: 345, Name: E
PRN: 654, Name: F
PRN: 765, Name: G
PRN: 2, Name: Bob
PRN: 4, Name: Eve
Club Member Information System
1. Add Member
2. Delete Member
3. Total Members
4. Display Members
5. Display Members in Reverse Order
6. Concatenate Two Lists
7. Exit

