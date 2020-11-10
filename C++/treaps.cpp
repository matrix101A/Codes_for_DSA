#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <time.h>
#define read freopen("input.txt", "r", stdin);
using namespace std;

struct Node
{
    int key;
    int priority;
    struct Node *parent;
    struct Node *left;
    struct Node *right;

    Node(int val, int p)
    {
        key = val;
        priority = p;
        left = NULL; // Left and right child for node
                     // will be initialized to null
        right = NULL;
        parent = NULL;
    }
}; // end of str

class Treap
{
public:
    struct Node *root;
    struct Node *nil;
    Treap()
    {
        this->nil = NULL;
        this->root = NULL;
    }
    ~Treap()
    {
        destroy_recursively(this->root);
        delete this->nil;
    }

    void destroy_recursively(struct Node *x)
    {
        if (x == NULL)
            return;
        else
        {
            destroy_recursively(x->left);
            destroy_recursively(x->right);
            delete x;
        }
    }
};

void left_rotate(Treap *T, struct Node *x) // perform left rotation on node x
{
    struct Node *y = x->right;
    if (x == T->root)
    {
        T->root = y;
        y->parent = NULL;
    }
    else
    {
        y->parent = x->parent;
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    }
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    x->parent = y;
    y->left = x;
}

void right_rotate(Treap *T, struct Node *x) //// perform right rotation on node x
{
    struct Node *y = x->left;
    if (x == T->root)
    {
        T->root = y;
        y->parent = NULL;
    }
    else
    {
        y->parent = x->parent;
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    }
    x->left = y->right;
    if (y->right != NULL)
        y->right->parent = x;
    x->parent = y;
    y->right = x;
}
void Ifixup(Treap *T, struct Node *x)
{
    if (x != T->root)
    {
        while (x != T->root && x->priority < x->parent->priority)
        {
            if (x == x->parent->left)
                right_rotate(T, x->parent);
            else
                left_rotate(T, x->parent);
        }
    }
}

void insert(Treap *T, struct Node *x)
{
    if (T->root == NULL)
    {
        T->root = x;
        // cout << "Root changed" << T->root << endl;
        // T.setRoot(x);
    }
    else
    {
        struct Node *curr = T->root;
        struct Node *curr1 = T->root;
        while (curr != NULL)
        {
            curr1 = curr;
            if (x->key < curr->key)
                curr = curr->left;
            else
                curr = curr->right;
        }
        x->parent = curr1;

        if (x->key < curr1->key)
            curr1->left = x;
        else
            curr1->right = x;
    }

    Ifixup(T, x); //call Ifixup on the current node

} // insert ends
void insert1(Treap *T, int key)
{
    int priority = rand() % 100;
    struct Node *x = new Node(key, priority);
    insert(T, x);
}

void inorder_traversal(struct Node *n)
{
    if (n->left != NULL)
        inorder_traversal(n->left);
    cout << n->key << " " << n->priority << "\n";
    if (n->right != NULL)
        inorder_traversal(n->right);
}
void preorder_traversal(struct Node *n)
{
    cout << n->key << " " << n->priority << "\n";
    if (n->left != NULL)
        preorder_traversal(n->left);
    if (n->right != NULL)
        preorder_traversal(n->right);
}
int maxDepth(struct Node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    srand(time(NULL));
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int key_array[n];
        int p_array[n];
        for (int j = 0; j < 2; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (j == 0)
                    cin >> key_array[i];
                else
                    cin >> p_array[i];
            }

        } // endfor
        Treap *T = new Treap();
        for (int i = 0; i < n; i++)
        {
            struct Node *n = new Node(key_array[i], p_array[i]);
            insert(T, n);
        }
        cout << "Inorder\n";
        inorder_traversal(T->root);
        cout << "Preorder\n";
        preorder_traversal(T->root);
        cout << "Height\n"
             << maxDepth(T->root) << "\n";
        T->~Treap();

    } // endwhile

    return 0;
}
