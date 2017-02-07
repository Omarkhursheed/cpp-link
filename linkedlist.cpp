#include <iostream>
using namespace std;
char affirm;
int i;
struct node 
{
  int data;
  struct node * next;
};
void menu();

class linkedList
{
  protected:
    struct node * head = NULL;
    struct node * first = NULL;
    struct node * curr = NULL;
    struct node * temp = NULL;
    int listLength;
  public:
    void createList();
    void insertNode();
    void deleteNode();
    void displayList();
};
void linkedList :: createList()
{
  
  listLength = 0;
  do
  {
    
    head = new node;
    cout << "Enter an element" << endl; 
    cin >>  head -> data;
    if (first == NULL)
    {
      first = head;
      curr = head;
    }
    else
    {
      curr -> next = head;
      curr = head;
    }
    listLength++;
    cout << "Do you want to enter another element?" << endl;
    cin >> affirm;
  }
  while(affirm == 'y' || affirm == 'Y');
}

void linkedList :: insertNode()
{
  int n;
  cout << "Position at which you wish to enter the new node? (Starts from zero)" << endl;
  cin >> n;
  if (n < listLength + 1)
  {
    head = new node;
    cout << "Enter element of new node" << endl;
    cin >> head -> data;
    temp = head;
    curr = first;
    if ( n == 0)
    {
      head -> next = first;
      first = head;
      curr = first;
    }
    else if (n == listLength)
    {
      for (i = 0; i < listLength - 1; i++)
      {
        curr = curr -> next;
      }
      curr -> next = head;
      head -> next = NULL;
    }
    else
    {
      for (i = 0; i < n; i++)
      {
        curr = curr -> next;
      }
      temp = curr -> next;
      curr -> next = head;
      head -> next = temp;
    }
    listLength++;
  }
  else
  {
    cout << "Sorry. You seem to be placing an element that goes beyond the list length" << endl;
  }
}

void linkedList :: displayList()
{
  cout << "Linked List:" << endl; 
  curr = first;
 
    while (curr != NULL)
    {
      cout << curr -> data << endl;
      curr = curr -> next;
    }
}

void linkedList :: deleteNode()
{
  int n;
  cout << "Node at what position should be deleted?(starting from zero)" << endl;
  cin >> n;
  if (listLength != 0 && n < listLength )
  {
    if (n == 0)
    {
      curr = first;
      temp = first;
      curr = curr -> next;
      first = curr;
      delete temp;
    }
    else
    {
      curr = first;
      for (i = 0; i < n - 1; i++)
      {
        curr = curr -> next;
      }
      temp = curr -> next;
      curr -> next = temp -> next;
      delete temp;
    }
    listLength--;
  }
  else
  {
    cout << "There is no element to be deleted or the list is empty" << endl;
  }
}

class cLinkedList : public linkedList
{
  public:
    void createList()
    {
      listLength = 0;
      do
      {
        
        head = new node;
        cout << "Enter an element" << endl; 
        cin >>  head -> data;
        if (first == NULL)
        {
          first = head;
          curr = head;
        }
        else
        {
          curr -> next = head;
          curr = head;
        }
        listLength++;
        cout << "Do you want to enter another element?" << endl;
        cin >> affirm;
      }
      while(affirm == 'y' || affirm == 'Y'); 
      curr -> next = first;
    }
    void insertNode()
    {
      int n;
      cout << "Position at which you wish to enter the new node? (Starts from zero)" << endl;
      cin >> n;
      head = new node;
      cout << "Enter element of new node" << endl;
      cin >> head -> data;
      if (n < listLength + 1)
      {
        if (n == 0)
        {
          curr = first;
          for(i = 0; i < listLength - 1; i++)
          {
            curr = curr -> next;
          }
          temp = curr;
          temp -> next = head;
          head -> next = first;
          first = head;
        }
        else if (n == listLength)
        {
          curr = first;
          for(i = 0; i < listLength - 1; i++)
          {
            curr = curr -> next;
          }
          temp = curr;
          temp -> next = head;
          head -> next = first;
        }
        else
        {
          curr = first;
          for (i = 0; i < n -1; i++)
        {
          curr = curr -> next;
        }
        temp = curr -> next;
        curr -> next = head;
        head -> next = temp;

        }
        listLength++;
      }
      else
      {
        cout << "Sorry. You seem to be placing an element that goes beyond the list length" << endl;
      }
    }
    void displayList()
    {
      cout << "Linked List: " << endl;
      curr = first;
      for(i = 0; i < listLength ; i++)
      {
        cout << curr -> data << endl;
        curr = curr -> next;
      }
      
    }

    void deleteNode()
    {
      int n;
      cout << "Node at what position should be deleted?(starting from zero)" << endl;
      cin >> n;
      if (n < listLength && listLength != 0)
      {
        if (n == 0 && listLength == 2)
        {
          temp = first;
          first = first -> next;
          delete temp;
        }
        else if (n == 0 && listLength > 2)
        {
          curr = first;
          temp = first;
          for (i = 0; i < listLength; i++)
          {
            curr = curr -> next;
          }
          
          
          curr -> next = temp -> next;
          
          first = temp -> next;
          delete temp;
        }
        else if (n == 0 && listLength == 1)
        {
          temp = first;
          first = NULL;
          delete temp;
        }

        else
        {
          curr = first;
          for (i = 0; i < n -1; i++)
          {
            curr = curr -> next;
          }
          temp = curr -> next;
          curr -> next = temp -> next;
          delete temp;
        }
        listLength--;
      }
      else
      {
        cout << "Sorry. You seem to be deleting an element that goes beyond the list length or the list is empty" << endl;
      }
    }

};

void menu1(linkedList);
void menu2(cLinkedList);
int main(int argc, char const *argv[])
{
  menu();
  return 0;
}

void menu()
{
  int a;
  cout << "1. Linked List" << endl;
  cout << "2. Circular Linked List" << endl;
  cout << "Enter your selection" << endl;
  cin >> a;
  if (a == 1)
  {
    linkedList list1;
    cout << "Create linked list" << endl;
    list1.createList();
    menu1(list1);
  }
  else if (a == 2)
  {
    cLinkedList list1;
    cout << "Create circular linked list" << endl;
    list1.createList();
    menu2(list1);
  }
}

void menu1(linkedList list)
{
  int select;
  cout << "MENU:" << endl;
  cout << "1. Insert Node" << endl;
  cout << "2. Delete Node" << endl;
  cout << "3. Display List" << endl;
  cout << "4. Exit" << endl;
  cout << "Enter your selection" << endl;
  cin >> select;
  if (select == 1)
  {
    list.insertNode();
    menu1(list);
  }
  else if (select == 2)
  {
    list.deleteNode();
    menu1(list);
  }
  else if (select == 3)
  {
    list.displayList();
    menu1(list);
  }
  else
  {
    return;
  }
}

void menu2(cLinkedList list)
{
  int select;
  cout << "MENU:" << endl;
  cout << "1. Insert Node" << endl;
  cout << "2. Delete Node" << endl;
  cout << "3. Display List" << endl;
  cout << "4. Exit" << endl;
  cout << "Enter your selection" << endl;
  cin >> select;
  if (select == 1)
  {
    list.insertNode();
    menu2(list);
  }
  else if (select == 2)
  {
    list.deleteNode();
    menu2(list);
  }
  else if (select == 3)
  {
    list.displayList();
    menu2(list);
  }
  else
  {
    return;
  }
}