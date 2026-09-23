#include <iostream>
using namespace std;
struct Node {   //node structure
    int data;
    Node* next;
};

//inserting a node at the beginning
void insertAtHead(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Node inserted at head successfully.\n";}

// Inserting a node at the 3rd position
void insertAtThird(Node*& head, int value) {
    // Checking if node<2
    if (head == nullptr || head->next == nullptr) {
        cout << "List has fewer than 2 nodes.\n";
        cout << "Cannot insert at the 3rd position.\n";
        return;}

    Node* newNode = new Node;
    newNode->data = value;
    
    Node* temp = head;   // Moving it to the second node
    temp = temp->next;

    //inserting a  new node 
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Node inserted at the 3rd position successfully.\n";}

// DISPLAY 
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return; }

    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next; }

    cout << "NULL\n";
}

// DELETING THE LAST NODE
void deleteLast(Node*& head) {
    //*Empty list
    if (head == nullptr) {
        cout << "The list is empty. Nothing to delete.\n";
        return;}

    //*Only one node
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Last node deleted successfully.\n";
        return;}

    //*More than one node
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;}

    delete temp->next;
    temp->next = nullptr;
    cout << "Last node deleted successfully.\n";
}

//counting the total nodes
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

//reversing the linked list iteratively
void reverseList(Node*& head) {

    Node* previous = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) {

        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    head = previous;
    cout << "Linked list reversed successfully.\n";
}

//searching for a value
void searchValue(Node* head, int value) {

    Node* temp = head;
    int position = 1;
    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Value " << value
                 << " found at position "
                 << position << ".\n";
            return;
        }
        temp = temp->next;
        position++;
    }

    cout << "Value " << value << " was not found in the list.\n";
}

//destroying the complete linked list
void destroyList(Node*& head) {

    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;}
    cout << "Linked list destroyed successfully.\n";
}


int main() {
    Node* head = nullptr;
    int choice;
    int value;

    do {

        cout << "=============== Singly Linked List Menu==============\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at 3rd Position\n";
        cout << "3. Display List\n";
        cout << "4. Delete Last Node\n";
        cout << "5. Count Nodes\n";
        cout << "6. Reverse List\n";
        cout << "7. Search Value\n";
        cout << "8. Destroy List\n";
        cout << "9. Exit\n";
        cout << "====================================\n";

        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> value;

                insertAtHead(head, value);
                displayList(head);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;

                insertAtThird(head, value);
                displayList(head);
                break;

            case 3:
                displayList(head);
                break;

            case 4:
                deleteLast(head);
                displayList(head);
                break;

            case 5:
                cout << "Number of nodes: "
                     << countNodes(head) << endl;
                break;

            case 6:
                reverseList(head);
                displayList(head);
                break;

            case 7:
                cout << "Enter value to search: ";
                cin >> value;

                searchValue(head, value);
                break;

            case 8:
                destroyList(head);
                break;

            case 9:
                //Before exiting free the memory 
                destroyList(head);
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";}

    } while (choice != 9);
    return 0;
}
