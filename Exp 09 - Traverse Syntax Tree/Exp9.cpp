#include <iostream>

// Define structure
struct Node
{
    char data;
    Node* left;
    Node* right;
};

// Create new node
Node* createNode(char data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to traverse the syntax tree and perform arithmetic operations
int evaluate(Node* root)
{
    if (root == nullptr)
        return 0;

    // If the node is a number, return its value
    if (root->data >= '0' && root->data <= '9')
    {
        return root->data - '0';
    }

    int leftValue = evaluate(root->left);
    int rightValue = evaluate(root->right);

    // Perform arithmetic operations based on the operator
    switch (root->data)
    {
    case '+':
        return leftValue + rightValue;
    case '-':
        return leftValue - rightValue;
    case '*':
        return leftValue * rightValue;
    case '/':
        if (rightValue != 0)
        {
            return leftValue / rightValue;
        }
        else
        {
            std::cerr << "Error: Division by zero\n";
            exit(EXIT_FAILURE);
        }
    default:
        std::cerr << "Error: Invalid operator\n";
        exit(EXIT_FAILURE);
    }
}

int main()
{
    // Construct the syntax tree for the expression "((3+2)*5)"
    Node* root = createNode('*');
    root->left = createNode('+');
    root->right = createNode('5');
    root->left->left = createNode('3');
    root->left->right = createNode('2');

    int result = evaluate(root);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
