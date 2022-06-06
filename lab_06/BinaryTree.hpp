#ifndef BINARY_TREE_H
#define BINARY_TREE_H

struct Node {
private:
    char letter;
    Node *right;
    Node *left;
public:
    Node() { letter = 0; right = 0; left = 0; }

    void Letter(char i_letter) { letter = i_letter; }
    void RightSubTree(Node *i_right) { right = i_right; }
    void LeftSubTree(Node *i_left) { left = i_left; }

    char Letter() const { return letter; }
    Node *RightSubTree() const { return right; }
    Node *LeftSubTree() const { return left; }
};





class BinaryTree {
    Node *root;
public:
    BinaryTree() { root = 0; }
    ~BinaryTree();

    Node *GetRoot() const { return root; };


    void AddNewNode(char new_letter);
    void ShowTree(Node *current_root, int depth = 0) const;

private:
    BinaryTree(const BinaryTree &ref);
    BinaryTree operator=(const BinaryTree &ref);
    void ClearTree(Node *current_root);
};



#endif