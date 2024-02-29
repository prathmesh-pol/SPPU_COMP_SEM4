#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node() {
        data = 0;
        left = NULL;
        right = NULL;
    }
};

class Tree : public Node{
    Node *root;

public:
    Tree(){
        root = NULL;
    }

    Node *return_root() {
        return root;
    }

    int return_root_data() {
        return root->data;
    }

    void insert_iterative(int key) {
        if (root == NULL) {
            root = new Node;
            root->data = key;
            root->left = NULL;
            root->right = NULL;
            cout << "\t Element Inserted!! \n";
            return;
        }
        Node *temp = root;
        while (true) {
            if (temp->data == key) {
                cout << "\n\t Error: No duplicate values can be inserted!! \n";
                return;
            } else if (temp->data > key) {
                if (temp->left == NULL) {
                    temp->left = new Node;
                    temp->left->data = key;
                    break;
                } else
                    temp = temp->left;
            } else {
                if (temp->right == NULL) {
                    temp->right = new Node;
                    temp->right->data = key;
                    break;
                } else
                    temp = temp->right;
            }
        }
        cout << "\t Element Inserted!! \n";
    }

    void insert_binary_tree(int value) {
        if (root == NULL) {
            root = new Node;
            root->data = value;
            root->left = NULL;
            root->right = NULL;
            cout << "\t Element Inserted!! \n";
            return;
        }
        Node *temp = root;
        while (true) {
            if (temp->data == value) {
                cout << "\n\t Error: No duplicate values can be inserted!! \n";
                return;
            }
            int choice;
            cout << "\t Where do you want to Insert?\n\t 1. Left of " << temp->data << "\t 2. Right of " << temp->data;
            cout << "\n\t Enter Your Choice :: ";
            cin >> choice;
            if (choice == 1) {
                if (temp->left == NULL) {
                    temp->left = new Node;
                    temp->left->data = value;
                    break;
                } else
                    temp = temp->left;
            } else if (choice == 2) {
                if (temp->right == NULL) {
                    temp->right = new Node;
                    temp->right->data = value;
                    break;
                } else
                    temp = temp->right;
            }
        }
        cout << "\t Element Inserted!! \n";
    }

    Node *search_node(Node *root, int value) {
        if (root == NULL || root->data == value)
            return root;

        Node *leftResult = search_node(root->left, value);
        if (leftResult != NULL)
            return leftResult;

        return search_node(root->right, value);
    }



    void delete_node(int value) {
        Node *searched_parent = search_node(root, value);
        Node *to_delete = NULL;
        if (searched_parent == NULL) {
            cout << "\n The Node is not Present in the Tree!!\n";
            return;
        } else {
            int flag = 1;
            if (searched_parent->left->data == value) {
                flag = 0;
                to_delete = searched_parent->left;
            } else
                to_delete = searched_parent->right;
            if (flag == 0) {
                // The Node does not have any children
                if (to_delete->left == NULL && to_delete->right == NULL) {
                    searched_parent->left = NULL;
                    delete (to_delete);
                }
                // The Node has only one Child
                if (to_delete->left != NULL && to_delete->right == NULL) {
                    searched_parent->left = to_delete->left;
                    delete (to_delete);
                }
                if (to_delete->left == NULL && to_delete->right != NULL) {
                    searched_parent->left = to_delete->right;
                    delete (to_delete);
                }
            }
            if (flag == 1) {
                // The Node does not have any children
                if (to_delete->left == NULL && to_delete->right == NULL) {
                    searched_parent->right = NULL;
                    delete (to_delete);
                }
                // The Node has only one Child
                if (to_delete->left != NULL && to_delete->right == NULL) {
                    searched_parent->right = to_delete->left;
                    to_delete->left = NULL;
                    delete (to_delete);
                }
                if (to_delete->left == NULL && to_delete->right != NULL) {
                    searched_parent->right = to_delete->right;
                    to_delete->right = NULL;
                    delete (to_delete);
                }
            }
        }
        cout << "\n\t Element Deleted!!";
    }

    void build_tree_from_inorder_preorder(vector<int>& inorder, vector<int>& preorder) {
        root = build_tree_helper(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
        cout << "\t Tree Built from Inorder and Preorder!!\n";
    }

    void preorder_recursive(Node *root) {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preorder_recursive(root->left);
        preorder_recursive(root->right);
    }

    void inorder_recursive(Node *root) {
        if (root == NULL)
            return;
        inorder_recursive(root->left);
        cout << root->data << " ";
        inorder_recursive(root->right);
    }

    void postorder_recursive(Node *root) {
        if (root == NULL)
            return;
        postorder_recursive(root->left);
        postorder_recursive(root->right);
        cout << root->data << " ";
    }

    void preorder_iterative(Node *r) {
        stack<Node *> s;
        Node *temp = r;
        while (temp != NULL || s.size() != 0) {
            while (temp != NULL) {
                cout << temp->data << " ";
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            temp = temp->right;
        }
    }

    void inorder_iterative(Node *r) {
        stack<Node *> s;
        Node *temp = r;
        while (temp != NULL || s.size() != 0) {
            while (temp != NULL) {
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }

    void postorder_iterative(Node *r) {
        stack<Node *> s1, s2;
        Node *t = NULL;
        s1.push(r);
        while (s1.size() != 0) {
            t = s1.top();
            s1.pop();
            s2.push(t);
            if (t->left != NULL)
                s1.push(t->left);
            if (t->right != NULL)
                s1.push(t->right);
        }
        while (s2.size() != 0) {
            t = s2.top();
            s2.pop();
            cout << t->data << " ";
        }
    }

    void level_order() {
        queue<Node *> q;
        q.push(root);
        while (q.size() != 0) {
            Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }

    int height(Node *r) {
        if (r == NULL)
            return 0;
        return 1 + max(height(r->left), height(r->right));
    }

    int number_of_nodes(Node *r) {
        if (r == NULL)
            return 0;
        return 1 + number_of_nodes(r->left) + number_of_nodes(r->right);
    }

    Node *copy_tree(Node *r) {
        if (r == NULL)
            return NULL;
        Node *t = new Node;
        t->data = r->data;
        t->left = copy_tree(r->left);
        t->right = copy_tree(r->right);
        return t;
    }

    Node *mirror_image(Node *r) {
        if (r == NULL)
            return NULL;
        Node *t = new Node;
        t->data = r->data;
        t->right = copy_tree(r->left);
        t->left = copy_tree(r->right);
        return t;
    }

    bool check_for_equal(Node *tree1, Node *tree2) {
        if (tree1 == NULL && tree2 == NULL)
            return true;
        if (tree1 == NULL || tree2 == NULL)
            return false;

        return (
            (tree1->data == tree2->data) &&
            check_for_equal(tree1->left, tree2->left) &&
            check_for_equal(tree1->right, tree2->right)
        );
    }

    void insert_bst(int key) {
        insert_iterative(key);
    }

    void delete_bst(int value) {
        delete_node(value);
    }

    void search_bst(int value) {
        if (return_root_data() == value) {
            cout << "\t Value is Present in the BST!! \n";
            return;
        }
        if (search_node(return_root(), value) != NULL) {
            cout << "\t Value is Present in the BST!! \n";
        } else {
            cout << "\t Value is !Present in the BST!! \n";
        }
    }

private:
    Node *build_tree_helper(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd, int preStart, int preEnd) {
        if (inStart > inEnd || preStart > preEnd)
            return NULL;

        int rootValue = preorder[preStart];
        Node *root = new Node;
        root->data = rootValue;

        int rootIndex;
        for (rootIndex = inStart; rootIndex <= inEnd; ++rootIndex) {
            if (inorder[rootIndex] == rootValue)
                break;
        }

        int leftSubtreeSize = rootIndex - inStart;

        root->left = build_tree_helper(inorder, preorder, inStart, rootIndex - 1, preStart + 1, preStart + leftSubtreeSize);
        root->right = build_tree_helper(inorder, preorder, rootIndex + 1, inEnd, preStart + leftSubtreeSize + 1, preEnd);

        return root;
    }
};

int main() {
    Tree bst, bt;
    int op_choice = 0;

    while (op_choice != 14) {
        cout << "\n Choose from the following ::";
        cout << "\n 1. Insert into BST \n 2. Display BST \n 3. Search in BST \n 4. Delete from BST";
        cout << "\n 5. Number of Nodes in BST \n 6. Height of BST \n 7. Copy BST \n 8. Mirror Image BST \n 9. Check if Equal (BST)";
        cout << "\n 10. Insert in Binary Tree \n 11. Display Binary Tree \n 12. Build Tree from Inorder and Preorder";
        cout << "\n 13. Delete from Binary Tree \n 14. Search in Tree \n 15. Exit";

        cout << "\n Your Choice --> ";
        cin >> op_choice;

        if (op_choice == 1) {
            int key;
            cout << "\t Enter the value to Insert into BST :: ";
            cin >> key;
            bst.insert_bst(key);
        }else if (op_choice == 2) {
            int traversal_choice = 0;
            cout << "\n\t 1. PreOrder \t 2. InOrder \t 3. PostOrder \t 4. LevelOrder";
            cout << "\n\t Enter Your Choice :: ";
            cin >> traversal_choice;

            if (traversal_choice == 1) {
                cout << " -------------- PRE-ORDER TRAVERSAL ---------------- \n\t";
                cout << " ITERATIVE :: ";
                bst.preorder_iterative(bst.return_root());
                cout << endl;
            } else if (traversal_choice == 2) {
                cout << " -------------- IN-ORDER TRAVERSAL ---------------- \n\t";
                cout << " ITERATIVE :: ";
                bst.inorder_iterative(bst.return_root());
                cout << endl;
            } else if (traversal_choice == 3) {
                cout << " -------------- POST-ORDER TRAVERSAL ---------------- \n\t";
                cout << " ITERATIVE :: ";
                bst.postorder_iterative(bst.return_root());
                cout << endl;
            } else if (traversal_choice == 4) {
                cout << " -------------- LEVEL-ORDER TRAVERSAL ---------------- \n\t";
                bst.level_order();
                cout << endl;
            } else
                cout << "\n No Such Choice!!";
        }else if (op_choice == 3) {
            int v;
            cout << "\t Enter the Value to Search in BST :: ";
            cin >> v;
            bst.search_bst(v);
        }else if (op_choice == 4) {
            int v;
            cout << "\t Enter the Node to Delete in BST :: ";
            cin >> v;
            bst.delete_bst(v);
        } else if (op_choice == 5) {
            cout << "\t Number of Nodes in BST :: " << bst.number_of_nodes(bst.return_root()) << endl;
        }else if (op_choice == 6) {
            cout << "\t Height of BST :: " << bst.height(bst.return_root()) << endl;
        }else if (op_choice == 7) {
            Node *copy = bst.copy_tree(bst.return_root());
            cout << "\t BST Copied!!\n";
        }else if (op_choice == 8) {
            Node *mirror = bst.mirror_image(bst.return_root());
            cout << "\t Mirror Image of BST Created!!\n";
        }else if (op_choice == 9) {
            // Logic for checking equality of two BSTs
        }else if (op_choice == 10) {
            int value;
            cout << "\t Enter the Value to Insert in Binary Tree :: ";
            cin >> value;
            bt.insert_binary_tree(value);
        }else if (op_choice == 11) {
            int traversal_choice = 0;
            cout << "\n\t 1. PreOrder \t 2. InOrder \t 3. PostOrder \t 4. LevelOrder";
            cout << "\n\t Enter Your Choice :: ";
            cin >> traversal_choice;

            if (traversal_choice == 1) {
                cout << " -------------- PRE-ORDER TRAVERSAL ---------------- \n\t";
                cout << " ITERATIVE :: ";
                bt.preorder_iterative(bt.return_root());
                cout << endl;
            } else if (traversal_choice == 2) {
                cout << " -------------- IN-ORDER TRAVERSAL ---------------- \n\t";
                cout << " ITERATIVE :: ";
                bt.inorder_iterative(bt.return_root());
                cout << endl;
            } else if (traversal_choice == 3) {
                cout << " -------------- POST-ORDER TRAVERSAL ---------------- \n\t";
                cout << " ITERATIVE :: ";
                bt.postorder_iterative(bt.return_root());
                cout << endl;
            } else if (traversal_choice == 4) {
                cout << " -------------- LEVEL-ORDER TRAVERSAL ---------------- \n\t";
                bt.level_order();
                cout << endl;
            } else
                cout << "\n No Such Choice!!";
        }else if (op_choice == 12) {
            int n;
            cout << "\t Enter the number of Nodes in the Tree :: ";
            cin >> n;

            vector<int> inorder(n), preorder(n);
            cout << "\t Enter the Inorder Traversal :: ";
            for (int i = 0; i < n; ++i)
                cin >> inorder[i];

            cout << "\t Enter the Preorder Traversal :: ";
            for (int i = 0; i < n; ++i)
                cin >> preorder[i];

            bt.build_tree_from_inorder_preorder(inorder, preorder);
        }else if (op_choice == 13) {
            int v;
            cout << "\t Enter the Node to Delete in Binary Tree :: ";
            cin >> v;
            bt.delete_node(v);
        }else if (op_choice == 14) {
            int value;
            cout << "\t Enter the Value to Search in Binary Tree :: ";
            cin >> value;
            if (bst.search_node(bst.return_root(), value) != NULL) {
                cout << "\t Value is Present in the Binary Tree!! \n";
            } else {
                cout << "\t Value is Not Present in the Binary Tree!! \n";
            }
        }

    }

    return 0;
}