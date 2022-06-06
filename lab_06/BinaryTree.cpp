#include "BinaryTree.hpp"
#include <cstdio>


void print_spaces(int n)
{
    for (int i = 0; i < n; i++)
        putchar(' ');
}


void BinaryTree::ClearTree(Node *current_root)
{
    if (!current_root)
        return;

    ClearTree(current_root->LeftSubTree());
    ClearTree(current_root->RightSubTree());
    delete current_root;
    current_root = 0;
}


BinaryTree::~BinaryTree()
{
    ClearTree(root);
}


void BinaryTree::AddNewNode(char new_letter)
{
    Node *new_node = new Node;

    new_node->Letter(new_letter);
    new_node->RightSubTree(0);
    new_node->LeftSubTree(0);

    if (!root){
        root = new_node;
        return;
    }
    
    Node *current_node = root;
    while (current_node->RightSubTree()){
        current_node = current_node->RightSubTree();
    }

    current_node->RightSubTree(new_node);
}

void BinaryTree::ShowTree(Node *current_root, int depth) const
{
    if (!current_root)
        return;

    print_spaces(depth * 4);
    printf("%c\n", current_root->Letter() == '\0'? '*' : current_root->Letter());
    ShowTree(current_root->RightSubTree(), depth + 1);
    ShowTree(current_root->LeftSubTree(), depth + 1);
}


