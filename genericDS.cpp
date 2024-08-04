#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////
//
// Code of Singly Linear
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
private:
    struct nodeSL<T> *First;
    int iCount;

public:
    SinglyLL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    cout << "Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> *temp = First;

    while (temp != NULL)
    {
        cout << "| " << temp->data << "|-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> *newn = NULL;

    newn = new nodeSL<T>; // malloc

    newn->data = No;
    newn->next = NULL;

    if (First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> *newn = NULL;
    struct nodeSL<T> *temp = First;

    newn = new nodeSL<T>; // malloc

    newn->data = No;
    newn->next = NULL;

    if (First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> *newn = NULL;
    int i = 0;
    struct nodeSL<T> *temp;

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> *temp = First;

    if (First == NULL)
    {
        cout << "LL is empty\n";
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> *temp = First;

    if (First == NULL)
    {
        cout << "LL is empty\n";
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> *temp1;
    struct nodeSL<T> *temp2;

    if ((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Circular
//
/////////////////////////////////////////////////////////////
template <class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL
{
private:
    struct nodeDC<T> *First;
    struct nodeDC<T> *Last;
    int iCount;

public:
    DoublyCL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL<T>::DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    if (First == NULL && Last == NULL)
    {
        cout << "Linked List is emprty\n";
        return;
    }

    cout << "<=> ";
    do
    {
        cout << "| " << First->data << "| <=> ";
        First = First->next;
    } while (Last->next != First);

    cout << "\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> *newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last->next = First;
    First->prev = Last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> *newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last->next = First;
    First->prev = Last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T> *temp = NULL;
    struct nodeDC<T> *newn = NULL;

    int i = 0;

    if (iPos < 1 || iPos > iCount + 1)
    {
        cout << "Invalid postion\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if (First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if (First == Last) // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else // More than one node
    {
        First = First->next;
        delete Last->next;
        First->prev = Last;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if (First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if (First == Last) // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else // More than one node
    {
        Last = Last->prev;
        delete First->prev;

        Last->next = First;
        First->prev = Last;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> *temp = NULL;

    int i = 0;

    if (iPos < 1 || iPos > iCount)
    {
        cout << "Invalid postion\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Liear
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeLL
{
    T data;
    struct nodeLL *next;
    struct nodeLL *prev;
};

template <class T>
class DoublyLL
{
private:
    nodeLL<T> *First;
    int iCount;

public:
    DoublyLL();
    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int Pos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int Pos);
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
    nodeLL<T> *temp = First;
    while (temp != NULL)
    {
        cout << " | " << temp->data << " |->  ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    nodeLL<T> *newn = NULL;

    newn = new nodeLL<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    nodeLL<T> *newn = NULL;

    newn = new nodeLL<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        nodeLL<T> *temp = First;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int Pos)
{
    if (Pos < 1 || Pos > iCount + 1)
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (Pos == 1)
    {
        InsertFirst(No);
    }
    else if (Pos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        nodeLL<T> *newn = NULL;

        newn = new nodeLL<T>;
        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        nodeLL<T> *temp = First;
        for (int i = 1; i < Pos - 1; ++i)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if (First == NULL)
    {
        return;
    }

    if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        nodeLL<T> *temp = First;
        First = First->next;
        First->prev = NULL;
        delete temp;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if (First == NULL)
    {
        return;
    }

    if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        nodeLL<T> *temp = First;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int Pos)
{
    if (Pos < 1 || Pos > iCount)
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (Pos == 1)
    {
        DeleteFirst();
    }
    else if (Pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        nodeLL<T> *temp1 = First;
        for (int i = 1; i < Pos - 1; ++i)
        {
            temp1 = temp1->next;
        }
        nodeLL<T> *temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        delete temp2;

        iCount--;
    }
}

/////////////////////////////////////////////////////////////
//
// Code of Singly Circular
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeCL
{
    T data;
    struct nodeCL *next;
};

template <class T>
class SinglyCL
{
private:
    struct nodeCL<T> *First;
    struct nodeCL<T> *Last;
    int iCount;

public:
    SinglyCL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T>::Display()
{
    if (First == NULL && Last == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    cout << "Elements of linked list are: ";
    struct nodeCL<T> *temp = First;
    do
    {
        cout << " | " << temp->data << " |->";
        temp = temp->next;
    } while (temp != Last->next);
    cout << endl;
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T No)
{
    struct nodeCL<T> *newn = NULL;

    newn = new nodeCL<T>;
    newn->data = No;
    newn->next = NULL;

    if (First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T No)
{
    struct nodeCL<T> *newn = NULL;

    newn = new nodeCL<T>;
    newn->data = No;
    newn->next = NULL;

    if (First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = newn;
    }
    Last->next = First;
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T No, int iPos)
{
    if (iPos < 1 || iPos > iCount + 1)
    {
        cout << "Invalid Position" << endl;
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        struct nodeCL<T> *newn = new nodeCL<T>;
        newn->data = No;
        newn->next = NULL;

        struct nodeCL<T> *temp = First;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if (First == NULL && Last == NULL)
    {
        return;
    }
    else if (First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        struct nodeCL<T> *temp = First;
        First = First->next;
        delete temp;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if (First == NULL && Last == NULL)
    {
        return;
    }
    else if (First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        struct nodeCL<T> *temp = First;
        while (temp->next != Last)
        {
            temp = temp->next;
        }
        delete Last;
        Last = temp;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    if (iPos < 1 || iPos > iCount)
    {
        cout << "Invalid Position" << endl;
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeCL<T> *temp = First;
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        struct nodeCL<T> *temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
        iCount--;
    }
}

/////////////////////////////////////////////////////////////
//
// Code of Stack
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

template <class T>
class Stack
{
private:
    nodeS<T> *First;
    int iCount;

public:
    Stack();
    void Display();
    int Count();
    void Push(T No); // InsertFirst()
    int Pop();       // DeleteFirst
};

template <class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Stack<T>::Display()
{
    cout << "Elements of stack are: \n";
    nodeS<T> *temp = First;

    while (temp != NULL)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
    cout << "\n";
}

template <class T>
int Stack<T>::Count()
{
    return iCount;
}

template <class T>
void Stack<T>::Push(T No)
{
    nodeS<T> *newn = NULL;
    newn = new nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
int Stack<T>::Pop()
{
    int iValue = 0;
    nodeS<T> *temp = NULL;
    if (First == NULL)
    {
        cout << "Unable to pop the element as stack is empty \n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First->data;
        First = First->next;
        delete temp;

        iCount--;
    }

    return iValue;
}

/////////////////////////////////////////////////////////////
//
// Code of Queue
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeQ
{
    T data;
    struct nodeQ *next;
};

template <class T>
class Queue
{
private:
    nodeQ<T> *First;
    int iCount;

public:
    Queue();
    void Display();
    int Count();
    void EnQueue(T No); // InsertLast()
    int DeQueue();      // DeleteFirst()
};

template <class T>
Queue<T>::Queue()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Queue<T>::Display()
{
    cout << "Elements of Queue are : \n";
    nodeQ<T> *temp = First;

    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << "\n";
}

template <class T>
int Queue<T>::Count()
{
    return iCount;
}

template <class T>
void Queue<T>::EnQueue(T No)
{
    nodeQ<T> *newn = NULL;
    nodeQ<T> *temp = NULL;

    newn = new nodeQ<T>;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    iCount++;
}

template <class T>
int Queue<T>::DeQueue()
{
    int iValue = 0;
    nodeQ<T> *temp = NULL;

    if (First == NULL)
    {
        cout << "Unable to remove the element as queue is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First->data;
        First = First->next;
        delete temp;

        iCount--;
    }

    return iValue;
}

int main()
{
    //...................................................Singly LinkedList.......................................................
    // LL of integer
    cout << "-------------- LinkdList of Integers --------------\n";    
    SinglyLL<int> *iobj = new SinglyLL<int>();
    int iRet = 0;

    iobj->InsertFirst(51);
    iobj->InsertFirst(21);
    iobj->InsertFirst(11);

    iobj->Display();
    iRet = iobj->Count();
    cout << "Number of elemensts are : " << iRet << endl;

    iobj->InsertLast(101);
    iobj->InsertLast(111);
    iobj->InsertLast(121);

    iobj->Display();
    iRet = iobj->Count();
    cout << "Number of elemensts are : " << iRet << endl;

    iobj->InsertAtPos(105, 5);

    iobj->Display();
    iRet = iobj->Count();
    cout << "Number of elemensts are : " << iRet << endl;

    iobj->DeleteAtPos(5);
    iobj->Display();
    iRet = iobj->Count();
    cout << "Number of elemensts are : " << iRet << endl;

    // LL of character
    cout << "-------------- LinkdList of Chracters --------------\n";

    SinglyLL<char> *cobj = new SinglyLL<char>();

    cobj->InsertFirst('D');
    cobj->InsertFirst('F');
    cobj->InsertFirst('R');

    cobj->Display();
    iRet = cobj->Count();
    cout << "Number of elemensts are : " << iRet << endl;

    cobj->InsertLast('E');
    cobj->InsertLast('Y');
    cobj->InsertLast('U');

    cobj->Display();
    iRet = cobj->Count();
    cout << "Number of elemensts are : " << iRet << endl;

    cobj->InsertAtPos('W', 5);

    cobj->Display();
    iRet = cobj->Count();
    cout << "Number of elemensts are : " << iRet << endl;

    cobj->DeleteAtPos(5);
    cobj->Display();
    iRet = cobj->Count();
    cout << "Number of elemensts are : " << iRet << endl;

    // LL of float
    cout << "-------------- LinkdList of Floats --------------\n";

    SinglyLL<float> *fobj = new SinglyLL<float>();

    fobj->InsertFirst(90.78f);
    fobj->InsertFirst(78.99f);
    fobj->InsertFirst(67.99f);

    fobj->Display();
    iRet = fobj->Count();
    cout << "Number of elemensts are : " << iRet << endl;

    fobj->InsertLast(45.67f);
    fobj->InsertLast(54.78f);
    fobj->InsertLast(77.89f);

    fobj->Display();
    iRet = fobj->Count();
    cout << "Number of elemensts are : " << iRet << endl;

    fobj->InsertAtPos(88.56, 5);

    fobj->Display();
    iRet = fobj->Count();
    cout << "Number of elemensts are : " << iRet << endl;

    fobj->DeleteAtPos(5);
    fobj->Display();
    iRet = fobj->Count();
    cout << "Number of elemensts are : " << iRet << endl;

    // LL of double

    cout << "-------------- LinkdList of Doubles --------------\n";

    SinglyLL<double> *dobj = new SinglyLL<double>();

    dobj->InsertFirst(90.78978);
    dobj->InsertFirst(78.99645);
    dobj->InsertFirst(67.9934);

    dobj->Display();
    iRet = dobj->Count();
    cout << "Number of elemensts are : " << iRet << endl;

    dobj->InsertLast(45.67867);
    dobj->InsertLast(54.78534);
    dobj->InsertLast(77.89324);

    dobj->Display();
    iRet = dobj->Count();
    cout << "Number of elemensts are : " << iRet << endl;

    dobj->InsertAtPos(88.56987, 5);

    dobj->Display();
    iRet = dobj->Count();
    cout << "Number of elemensts are : " << iRet << endl;

    dobj->DeleteAtPos(5);
    dobj->Display();
    iRet = dobj->Count();
    cout << "Number of elemensts are : " << iRet << endl;

    //...................................................Doubly Circular LinkedList.......................................................
    
    DoublyCL<int> *idobj = new DoublyCL<int>();

    idobj->InsertFirst(51);
    idobj->InsertFirst(21);
    idobj->InsertFirst(11);

    idobj->InsertLast(101);
    idobj->InsertLast(111);
    idobj->InsertLast(121);

    idobj->Display();
    iRet = idobj->Count();

    idobj->DeleteAtPos(5);

    idobj->Display();
    iRet = idobj->Count();

    //...................................................Singly Circular LinkedList..............................................

    SinglyCL<int> *obj = new SinglyCL<int>;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();
    iRet = obj->Count();
    cout << "Number of elements are " << iRet << endl;

    obj->InsertAtPos(105, 3);
    obj->Display();
    iRet = obj->Count();
    cout << "Number of elements are " << iRet << endl;

    obj->DeleteAtPos(3);
    obj->Display();
    iRet = obj->Count();
    cout << "Number of elements are " << iRet << endl;

    //...................................................Doubly LinkedList.......................................................

    DoublyLL<int> *objd = new DoublyLL<int>();

    objd->InsertFirst(51);
    objd->InsertFirst(21);
    objd->InsertFirst(11);

    objd->Display();
    iRet = objd->Count();
    cout << "Number of elements are: " << iRet << endl;

    objd->InsertLast(101);
    objd->InsertLast(111);
    objd->InsertLast(121);

    objd->Display();
    iRet = objd->Count();
    cout << "Number of elements are: " << iRet << endl;

    objd->InsertAtPos(105, 5);
    objd->Display();
    iRet = objd->Count();
    cout << "Number of elements are: " << iRet << endl;

    objd->DeleteFirst();
    objd->Display();
    iRet = obj->Count();
    cout << "Number of elements are: " << iRet << endl;

    objd->DeleteLast();
    objd->Display();
    iRet = objd->Count();
    cout << "Number of elements are: " << iRet << endl;

    objd->DeleteAtPos(5);
    objd->Display();
    iRet = objd->Count();
    cout << "Number of elements are: " << iRet << endl;

    //.........................................................Stackt............................................................

    Stack<int> *objs = new Stack<int>();
    objs->Push(10);
    objs->Push(20);
    objs->Push(30);
    objs->Push(40);

    objs->Display();

    iRet = objs->Count();

    cout << "Number of elements in stack are:" << iRet << "\n";

    iRet = objs->Pop();

    cout << "Poped elements is : " << iRet << "\n";

    iRet = objs->Pop();

    obj->Display();
    iRet = objs->Count();
    cout << "Poped elements is : " << iRet << "\n";

    objs->Push(50);
    objs->Display();

    iRet = objs->Count();
    cout << "Number of elements in stack are:" << iRet << "\n";
    //.........................................................Queue.............................................................

    Queue<int> *objq = new Queue<int>();
    int iChoice = 0;
    int iNo = 0;

    cout << "----------- Implementaion of Queue -----------\n";
    while (iChoice != 5)
    {
        cout << "Please select your choice : \n";
        cout << "1 : Insert new element in Queue\n";
        cout << "2 : Remove the element from Queue\n";
        cout << "3 : Display the elements form Queue\n";
        cout << "4 : Count number of elements in Queue\n";
        cout << "5 : Exit\n";
        cin >> iChoice;

        switch (iChoice)
        {
        case 1:
            cout << "Enter the element that you want to insert : \n";
            cin >> iNo;
            objq->EnQueue(iNo);
            break;

        case 2:
            iNo = objq->DeQueue();
            if (iNo != -1)
            {
                cout << "Removed element from Queue is : " << iNo << "\n";
            }
            break;

        case 3:
            objq->Display();
            break;

        case 4:
            iNo = objq->Count();
            cout << "Number of elements in Queue are : " << iNo << "\n";
            break;

        case 5:
            cout << "Thank you for using our application\n";
            break;
        }
    }
    return 0;
}