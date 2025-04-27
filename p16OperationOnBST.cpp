/*
15) Design, Develop and Implement a menu driven Program for the following operations on Binary Search Tree (BST) of Integers.
a. Insertion in a BST.
b. Traverse the BST in Inorder, Preorder and Post Order.
c. Search an element in BST
d. Deletion in BST
e. Exit
*/
#include <iostream>
using namespace std;

// Define the structure for a node in the Binary Search Tree
struct Node
{
    int data;
    Node *left;
    Node *right;

    // Constructor to create a new node
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert a node into the BST
Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value); // Create a new node if the tree is empty or find the correct position
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value); // Insert in the left subtree if value is smaller
    }
    else
    {
        root->right = insert(root->right, value); // Insert in the right subtree if value is larger
    }

    return root;
}

// Function to perform inorder traversal (left-root-right)
void inorder(Node *root)
{
    if (root != nullptr)
    {
        inorder(root->left);       // Traverse left subtree
        cout << root->data << " "; // Visit node
        inorder(root->right);      // Traverse right subtree
    }
}

// Function to perform preorder traversal (root-left-right)
void preorder(Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " "; // Visit node
        preorder(root->left);      // Traverse left subtree
        preorder(root->right);     // Traverse right subtree
    }
}

// Function to perform postorder traversal (left-right-root)
void postorder(Node *root)
{
    if (root != nullptr)
    {
        postorder(root->left);     // Traverse left subtree
        postorder(root->right);    // Traverse right subtree
        cout << root->data << " "; // Visit node
    }
}

// Function to search for an element in the BST
Node *search(Node *root, int value)
{
    if (root == nullptr || root->data == value)
    {
        return root; // Return the node if value is found or tree is empty
    }

    if (value < root->data)
    {
        return search(root->left, value); // Search in the left subtree
    }

    return search(root->right, value); // Search in the right subtree
}

// Function to delete a node in the BST
Node *deleteNode(Node *root, int value)
{
    if (root == nullptr)
    {
        return root; // Return null if the node is not found
    }

    // Find the node to be deleted
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value); // Delete in the left subtree
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value); // Delete in the right subtree
    }
    else
    {
        // Node with only one child or no child
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp; // Return the right child
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp; // Return the left child
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node *temp = root->right;
        while (temp && temp->left != nullptr)
        {
            temp = temp->left;
        }

        root->data = temp->data;                           // Copy the inorder successor's content to this node
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }

    return root;
}

// Function to display the menu
void displayMenu()
{
    cout << "\n--- Binary Search Tree Operations ---\n";
    cout << "1. Insert in BST\n";
    cout << "2. Inorder Traversal\n";
    cout << "3. Preorder Traversal\n";
    cout << "4. Postorder Traversal\n";
    cout << "5. Search Element\n";
    cout << "6. Delete Node\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    cout<<"ABHISHEK SINGH 2315272/2435222";

    Node *root = nullptr; // Start with an empty tree
    int choice, value;

    while (true)
    {
        displayMenu(); // Display menu
        cin >> choice;

        switch (choice)
        {
        case 1: // Insert
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;

        case 2: // Inorder Traversal
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;

        case 3: // Preorder Traversal
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
            break;

        case 4: // Postorder Traversal
            cout << "Postorder Traversal: ";
            postorder(root);
            cout << endl;
            break;

        case 5: // Search Element
            cout << "Enter value to search: ";
            cin >> value;
            Node *result = search(root, value);
            if (result != nullptr)
            {
                cout << "Element " << value << " found in the BST.\n";
            }
            else
            {
                cout << "Element " << value << " not found in the BST.\n";
            }
            break;

        case 6: // Delete Node
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            cout << "Node " << value << " deleted.\n";
            break;

        case 7: // Exit
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
