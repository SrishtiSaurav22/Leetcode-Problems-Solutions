/*
 You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

 You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 EXAMPLE 1:
 Input: l1 = [2,4,3], l2 = [5,6,4]
 Output: [7,0,8]
 Explanation: 342 + 465 = 807.

 EXAMPLE 2:
 Input: l1 = [0], l2 = [0]
 Output: [0]

 EXAMPLE 3:
 Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 Output: [8,9,9,9,0,0,0,1]

 CONSTRAINTS:
 1) The number of nodes in each linked list is in the range [1, 100].
 2) 0 <= Node.val <= 9
 3) It is guaranteed that the list represents a number that does not have leading zeros.
*/

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

/*
 Here, the inconsequential print statements were included for debugging.
 They're useful to check num's value and the flow of the program.
*/
ListNode* addTwoNumbersNaive(ListNode* l1, ListNode* l2)
{
    cout<<"Entered the function!"<<endl;

    ListNode *ptr1=l1, *ptr2=l2;
    // I had to put the * to both the variables
    // 'ListNode*' was not recognized as a data type

    ListNode* l3=nullptr;

    int num=0,carry=0;

    cout<<"Declared variables"<<endl;

    while(ptr1 || ptr2)
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

        if(ptr1)
            ptr1=ptr1->next;

        if(ptr2)
            ptr2=ptr2->next;
    }

    if(carry!=0)
        l3=insertNodeToBack(l3,carry);
        // add remaining carry to a new node in the result list

    cout<<"Included the final carry!"<<endl;

    return l3;
}

// This is the faster solution. I wrote it following another solution from the 'Details' section.
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* head=new ListNode;
    ListNode* temp=new ListNode;
    temp=head;

    int carry=0;

    while(l1 || l2 || carry)
    {
        int sum=0;

        if(l1)
        {
            sum+=l1->val;
            l1=l1->next;
        }

        if(l2)
        {
            sum+=l2->val;
            l2=l2->next;
        }

        sum+=carry;
        carry=sum/10;
        ListNode* node=new ListNode(sum%10);

        temp->next=node;
        temp=node;
    }

    return head->next;
    // I skipped the actual first node having val=0
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

    // ListNode* l3=new ListNode;
    // I was getting an extra zero node in the beginning because of this initialization in the addTwoNumbers function

    ListNode* l3=nullptr; // This is the right way

    l3=addTwoNumbers(l1,l2);

    printList(l3);
    cout<<endl;

    cout<<"Hoof! What a ride!"<<endl;

    cout<<endl;
    return 0;
}
