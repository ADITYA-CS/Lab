#include <iostream>
using namespace std;

struct Node{
    int data;
    int count;
    Node *left, *right;
    Node(int);
};

class BinarySearchTree{
private:
    Node *root_;
private:
    void PreOrder(Node *);
    void InOrder(Node *);
    void PostOrder(Node *);

    void Insert(Node *,int);

    Node* Search(Node *, int) const;
    void Destroy(Node *root);
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void Destroy();
    void PreOrder();
    void PostOrder();
    void InOrder();

    void Insert(int);

    bool Search(int) const;
};

int main(){
    BinarySearchTree bst;
    int option, key, n;
    while(true){
        cout << "\n1. Create BST of n integer\n2. Traverse\n3. Search\n4. Exit\n";
        cout << "Enter option: ";
        cin >> option;
        switch (option) {
            case 1:
                bst.Destroy();
                cout << "Number of integer : ";
                cin >> n;
                cout << "Enter integers\n";
                while(n--){
                    cout << ": ";
                    cin >> key;
                    bst.Insert(key);
                }
                break;
            case 2:
                cout << '\n';
                bst.PreOrder();
                bst.InOrder();
                bst.PostOrder();
                break;
            case 3:
                cout << "Enter key : ";
                cin >> key;
                cout << "is "<< key << " in the binary search tree? "<< boolalpha << bst.Search(key) << "\n";
                break;
            case 4:
                exit(0);
            default:
                cout << "No such option\n";
        }

    }
}
Node :: Node(int el){
    data = el;
    count = 1;
    left = right = nullptr;
}

BinarySearchTree :: BinarySearchTree(){
    root_ = nullptr;
}
BinarySearchTree :: ~BinarySearchTree(){
    Destroy(root_);
}
void BinarySearchTree :: Destroy(){
    Destroy(root_);
    root_ = nullptr;
}
void BinarySearchTree :: Destroy(Node *root){
    if(!root) return;
    Destroy(root->left);
    Destroy(root->right);
    delete root;
}

void BinarySearchTree :: PreOrder(){
    cout << "PreOrder:\n";
    PreOrder(root_);
    cout << "\n";
}


void BinarySearchTree :: PreOrder(Node * root){
    if(root){
        for(int i = 0; i < root->count; i++)
            cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}


void BinarySearchTree :: PostOrder(){
    cout << "PostOrder:\n";
    PostOrder(root_);
    cout << "\n";
}


void BinarySearchTree :: PostOrder(Node * root){
    if(root){
        PostOrder(root->left);
        PostOrder(root->right);
        for(int i = 0; i < root->count; i++)
            cout << root->data << " ";
    }
}

void BinarySearchTree :: InOrder(){
    cout << "InOrder:\n";
    InOrder(root_);
    cout << "\n";
}


void BinarySearchTree :: InOrder(Node * root){
    if(root){
        InOrder(root->left);
        for(int i = 0; i < root->count; i++)
            cout << root->data << " ";
        InOrder(root->right);
    }
}


void BinarySearchTree :: Insert(int el){
    if(!root_){
        root_ = new Node(el);
        return;
    }
    Insert(root_, el);
}

void BinarySearchTree :: Insert(Node *root, int el){
    if(root->data == el){
        root->count += 1;
        return;
    } else if (el < root->data){
        if(root->left){
            Insert(root->left, el);
        } else{
            root->left = new Node(el);
        }
    } else {
        if(root->right){
            Insert(root->right, el);
        } else{
            root->right = new Node(el);
        }
    }
}


 bool BinarySearchTree :: Search(int el) const{
    auto ptr = Search(root_, el);
    return  ptr != nullptr;
 }


Node* BinarySearchTree :: Search(Node *root, int el) const{

    if(!root){
        return nullptr;
    } else if(root->data < el){
        return Search(root->right, el);
    } else if(root->data > el){
        return Search(root->left, el);
    }

    return root;
}
