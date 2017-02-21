#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
struct treenode
{
  int data;
  struct treenode * left;
  struct treenode * right;
};
treenode * makeBST(int arr[], int length);
void preorder(treenode * a);
void inorder(treenode * b);
void postorder(treenode * c);
void menu(treenode * d);
int main(int argc, char const *argv[])
{
  
  int choice, n;

  cout << "1. User Entered BST" << endl;
  cout << "2. Randomly generated BST" << endl;
  cout << "Please select your choice" << endl;
  cin >> choice;
  if (choice == 1)
  {
    cout << "How many numbers do you want to enter?";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++)
    {
      cout << "Enter element" << endl;
      cin >> arr[i];
    }

  
  treenode * stuff = makeBST(arr, n);
  menu(stuff);
  }
  else if (choice == 2)
  {
    cout << "How  many random numbers do you wish generated?" << endl;  
    cin >> n;
    int arr[n];
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
    {
      arr[i] = (rand() % 10000) + 1;
    }

  treenode * stuff = makeBST(arr, n);
  menu(stuff);
  }

  return 0;
}


treenode * makeBST(int arr[], int length)
{
  struct treenode * head = NULL;
  struct treenode * root = NULL;
  struct treenode * parent = NULL;
  for (int k = 0; k < length; k++)
  {
    head = new treenode;
    head -> data = arr[k];
    head -> left = NULL;
    head -> right = NULL;
    parent = NULL;
    if (root == NULL)
    {
      root = head;
    }
    else
    {
      treenode * ptr = root;

      while (ptr != NULL)
      {
        parent = ptr;
        if ((head -> data) > (ptr -> data))
          ptr = ptr -> right;
        else
          ptr = ptr -> left;
      }
      if  ((head -> data) < (parent->data))
        parent -> left = head;
      else
        parent -> right = head;
    }
  }
  return root;
}

void preorder(treenode * ptr)
{
  if (ptr)
  {
    cout << ptr -> data << endl;
    preorder (ptr -> left);
    preorder (ptr -> right);
  }
}

void inorder(treenode * ptr)
{
  if (ptr)
  {
    inorder(ptr -> left);
    cout << ptr -> data << endl;
    inorder(ptr -> right);
  }
}

void postorder(treenode * ptr)
{
  if (ptr)
  {
    postorder(ptr->left);
    postorder(ptr->right);
    cout << ptr -> data << endl;
  }
}

void menu(treenode * node)
{
  treenode * temp = node;
  int c;
  cout << "1. Preorder traversal" << endl;
  cout << "2. Inorder traversal" << endl;
  cout << "3. Postorder traversal" << endl;
  cout << "4. Exit" << endl;
  cin >> c;
  if (c == 1)
  {
    cout << endl << "Preorder traversal:" << endl;
    preorder(node);
    menu(temp);
  }
  else if (c == 2)
  {
    cout << endl << "Inorder traversal:" << endl;
    inorder(node);
    menu(temp);
  }
  else if (c == 3)
  {
    cout << endl << "Postorder traversal:" << endl;
    postorder(node);
    menu(temp);
  }
  else
    return;

}