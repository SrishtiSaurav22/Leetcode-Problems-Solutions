#include<bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode()
    {
        val=0;
        next=nullptr;
    }

    ListNode(int x)
    {
        val=x;
        next=nullptr;
    }

    ListNode(int x, ListNode *next)
    {
        this->val=x;
        this->next=next;
    }
};

// insert nodes to the end of the list
ListNode* insertNodeToBack(ListNode* head, int x)
{
    ListNode* temp=new ListNode(x);

    if(head==nullptr)
    {
        head=temp;
        return head;
    }

    ListNode* ptr=head;

    while(ptr->next)
    {
        ptr=ptr->next;
    }

    ptr->next=temp;
    return head;
}

void printList(ListNode* head)
{
    while(head)
    {
        cout<<head->val<<"\t";
        head=head->next;
    }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    cout<<"Entered the function!"<<endl;

    ListNode *ptr1=l1, *ptr2=l2;
    // I had to put the * to both the variables
    // 'ListNode*' was not recognized as a data type

    ListNode* l3=new ListNode;

    int num=0,carry=0;

    cout<<"Declared variables"<<endl;

    while(1)
    // this is not actually required because the two given lists will be NON-EMPTY
    {
        cout<<"Entered the loop (again?)"<<endl;

        num=0; // for every digit sum, num is back to zero

        if(ptr1!=nullptr)
            num=num+ptr1->val;

        if(ptr2!=nullptr)
            num=num+ptr2->val;

        num=num+carry;
        // add carry of the previous sum to the new sum

        cout<<"Got num ready! num="<<num<<endl;

        int onesDigit=num%10;
        int tensDigit=num/10;
        // num will be max. two digits

        l3=insertNodeToBack(l3,onesDigit);

        carry=tensDigit;

        if(ptr1->next && ptr2->next)
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }

        else if(ptr1->next)
            ptr1=ptr1->next;

        else if(ptr2->next)
            ptr2=ptr2->next;

        else
            break;
    }

    if(carry!=0)
        l3=insertNodeToBack(l3,carry);
        // add remaining carry to a new node in the result list

    cout<<"Included the final carry!"<<endl;

    return l3;
}

int main()
{
    ListNode* l1=new ListNode(9);

    l1=insertNodeToBack(l1,9);
    l1=insertNodeToBack(l1,9);
    l1=insertNodeToBack(l1,9);
    l1=insertNodeToBack(l1,9);
    l1=insertNodeToBack(l1,9);
    l1=insertNodeToBack(l1,9);

    printList(l1);
    cout<<endl;

    ListNode* l2=new ListNode(9);

    l2=insertNodeToBack(l2,9);
    l2=insertNodeToBack(l2,9);
    l2=insertNodeToBack(l2,9);

    printList(l2);
    cout<<endl;

    ListNode* l3=new ListNode;

    l3=addTwoNumbers(l1,l2);

    printList(l3);
    cout<<endl;

    cout<<"Hoof! What a ride!"<<endl;

    cout<<endl;
    return 0;
}
