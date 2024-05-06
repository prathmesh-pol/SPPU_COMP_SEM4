#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class node {
public:
    int key;
    node* left;
    node* right;

    node(int value) {
        key = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
public:
    node* root;
    BinaryTree() {
        root = NULL;
    }

    // Insertion of node:
    void Insert(int key) {
        root = _Insert(root, key);
    }

    node* _Insert(node* root, int key) {
        if (root == NULL)
            return new node(key);
        if (key < root->key)
            root->left = _Insert(root->left, key);
        else if (key > root->key)
            root->right = _Insert(root->right, key);
        return root;
    }

    // Recursive Traversals:

    // 1. Preorder:
    void recursivePreorder(node* root){
        if(root == NULL) return;
        cout << (root->key) << " ";
        recursivePreorder(root->left);
        recursivePreorder(root->right);
    }
    // 2. Inorder:
    void RecursiveInorder(node* root) {
        if(root == NULL) return;
        RecursiveInorder(root->left);
        cout << root->key << " ";
        RecursiveInorder(root->right);  
    }

    // 3. Postorder:
    void recursivePostorder(node* root){
        if(root == NULL) return;
        recursivePostorder(root->left);
        recursivePostorder(root->right);
        cout << (root->key) << " ";
    }


    // Iterative Traversals:

    // 1. Preorder:
    void iterativePreorder(node* root){
        if(root == NULL) return;

        stack<node*>st;
        st.push(root);

        while(!st.empty()){
            node* temp = st.top();
            st.pop();
            cout << temp->key << " ";

            if(temp->right != NULL){
                st.push(temp->right);
            }
            if(temp->left != NULL){
                st.push(temp->left);
            }
        }
    } 

    // 2. Inorder:
    void iterativeInorder(node* root){
        if(root == NULL) return;

        stack<node*> st;
        while(true){
            if(root != NULL){
                st.push(root);
                root = root->left;
            }
            else{
                if(st.empty()) break;
                root = st.top();
                st.pop();
                cout << root->key << " ";
                root = root->right;
            }
        }
    }

    // 3. Postorder:
    void iterativePostorder(node* root){
        if(root == NULL) return;

        stack<node*>st1, st2;
        st1.push(root);

        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);

            if(root->left != NULL){
                st1.push(root->left);
            }
            if(root->right != NULL){
                st1.push(root->right);
            }
        }

        while(!st2.empty()){
            cout << st2.top()->key << " ";
            st2.pop();
        }
    }


    // Height of tree
    int height(node* root) {
        if (root == NULL) return -1;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return max(leftHeight, rightHeight) + 1;
    }


    // Clone and erase
    node* clone(node* root) {
        if (root == NULL) return NULL;
            
        node* newRoot = new node(root->key);
        newRoot->left = clone(root->left);
        newRoot->right = clone(root->right);
        return newRoot;
    }

    void _erase(node* root) {
        if (root == NULL) return;
        _erase(root->left);
        _erase(root->right);
        delete root;
    }

    // Mirror image
    void mirror(node* root) {
        if (root == NULL) return;

        node* temp = root->left;
        root->left  = root->right;
        root->right = temp;

        mirror(root->left);
        mirror(root->right);
    }

    // Construct from inorder and preorder
    node* constructBinary(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd, int& preIndex) {
        if (inStart > inEnd) return NULL;

        node* root = new node(preorder[preIndex++]);
        int inIndex;
        for (int i = inStart; i <= inEnd; ++i) {
            if (inorder[i] == root->key) {
                inIndex = i;
                break;
            }
        }
        root->left = constructBinary(inorder, preorder, inStart, inIndex - 1, preIndex);
        root->right = constructBinary(inorder, preorder, inIndex + 1, inEnd, preIndex);
        return root;
    }

    // Deletion
    node* minValueNode(node* root) {
        node* current = root;
        while (current && current->left)
            current = current->left;
        return current;
    }
    node* deleteNode(node* root, int key) {
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == nullptr) {
                node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                node* temp = root->left;
                delete root;
                return temp;
            }
            node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }


    // Equality check
    bool areTreesEqual(node* root1, node* root2) {
        if (root1 == NULL && root2 == NULL)
            return true;

        if (root1 != NULL && root2 != NULL) {
            return (root1->key == root2->key && areTreesEqual(root1->left, root2->left) && areTreesEqual(root1->right, root2->right));
        }

        return false;
    }

};

int main() {
    BinaryTree bst;
    bst.Insert(50);
    bst.Insert(30);
    bst.Insert(70);
    bst.Insert(20);
    bst.Insert(40);
    bst.Insert(60);
    bst.Insert(80);

    node* root = bst.root;

    cout << "Preorder Traversal (Recursive): ";
    bst.recursivePreorder(root);
    cout << endl;

    cout << "Inorder Traversal (Recursive): ";
    bst.RecursiveInorder(root);
    cout << endl;

    cout << "Post Traversal (Recursive): ";
    bst.recursivePostorder(root);
    cout << endl;

    cout << "Preorder Traversal (Iterative): ";
    bst.iterativePreorder(root);
    cout << endl;

    cout << "Inorder Traversal (Iterative): ";
    bst.iterativeInorder(root);
    cout << endl;

    cout << "Postorder Traversal (Iterative): ";
    bst.iterativePostorder(root);
    cout << endl;

    cout << "Height of the tree: " << bst.height(root) << endl;

    node* temp = bst.clone(root);
    cout << "Inorder Traversal of Cloned Tree: ";
    bst.RecursiveInorder(temp);
    cout << endl;

    bst.mirror(root);
    cout << "Inorder Traversal of Mirror Image Tree: ";
    bst.RecursiveInorder(root);
    cout << endl;

    vector<int> inorder = {20, 30, 40, 50, 60, 70, 80};
    vector<int> preorder = {50, 30, 20, 40, 70, 60, 80};
    int preIndex = 0;
    
    node* newnode = bst.constructBinary(inorder, preorder, 0, inorder.size() - 1, preIndex);
    cout << "Inorder Traversal of Constructed Tree: ";
    bst.RecursiveInorder(newnode);
    cout << endl;

    node* del = bst.deleteNode(root, 30);
    cout << "Inorder Traversal after deleting node 30: ";
    bst.RecursiveInorder(del);
    cout << endl;

    BinaryTree bst2;
    node* root1 = NULL;
    node* root2 = NULL;

    bst2.Insert(50);
    bst2.Insert(30);
    bst2.Insert(20);
    bst2.Insert(40);
    bst2.Insert(70);
    bst2.Insert(60);
    bst2.Insert(80);

    root1 = bst2.root;
    root2 = bst.root;

    cout << "Are trees equal? " << (bst.areTreesEqual(root1, root2) ? "Yes" : "No") << endl;

    return 0;
}
