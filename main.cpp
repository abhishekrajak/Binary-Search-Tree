#include <iostream>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* insertNode(node* ptr, int data){
    if(ptr==NULL){
        ptr = new node;
        ptr->data = data;
        ptr->left = ptr->right = NULL;
        return ptr;
    }
    if(data < ptr->data){
        ptr->left = insertNode(ptr->left, data);
    }
    if(data > ptr->data){
        ptr->right = insertNode(ptr->right, data);
    }
    return ptr;
}

node* deleteNode(node* ptr, int data){
    if(ptr==NULL){
        return NULL;
    }
    if(data < ptr->data){
        ptr->left = deleteNode(ptr->left, data);
        return ptr;
    }
    else if(data > ptr->data){
        ptr->right = deleteNode(ptr->right, data);
        return ptr;
    }
    else{
        if(ptr->left!=NULL){
            ptr->data = ptr->left->data;
            ptr->left = deleteNode(ptr->left, ptr->data);
            return ptr;
        }
        if(ptr->right!=NULL){
            ptr->data = ptr->right->data;
            ptr->right = deleteNode(ptr->right, ptr->data);
            return ptr;
        }
        delete ptr;
        return NULL;
    }
}

void preorder(node* ptr){
    if(ptr!=NULL){
        cout << ptr->data << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void inorder(node* ptr){
    if(ptr!=NULL){
        inorder(ptr->left);
        cout << ptr->data << " ";
        inorder(ptr->right);
    }
}

void postorder(node* ptr){
    if(ptr!=NULL){
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data << " ";
    }
}

bool search(node* ptr, int data){
    if(ptr==NULL){
        return false;
    }
    if(data < ptr->data){
        return search(ptr->left, data);
    }
    if(data > ptr->data){
        return search(ptr->right, data);
    }
    return true;
}

int main(){

    node* ptr = NULL;
    int x, y;

    do{
        cin >> x >> y;
        if(x==0){
            ptr = insertNode(ptr, y);
        }
        if(x==1){
            ptr = deleteNode(ptr, y);
        }
        if(x==2){
            search(ptr, y)?cout<<"found\n":cout<<"not found\n";
            continue;
        }
        cout << "elements : ";
        preorder(ptr);
        cout << endl;

    }while (x != -1);


    return 0;
}