/*
Developer: Hamed Mirlohi
Date: Aug 27th 2019
This is an Amazon technical interview question
there are two list of customer reviews. 5 star to 1 star
we want to merge both lists, starting with 1 stars.
 */


#include <iostream>

struct node
{
    int data;
    node* next;
};

node* populate_list(node* head, int d)
{
    if(head == nullptr)
    {
        head = new node;
        head->next = nullptr;
        head->data = d;
        return head;
    }

    node* tmp = head;
    head = new node;
    head->data = d;
    head->next = tmp;
    return head;
}

void display_node(node* head)
{
    while(head != nullptr)
    {
        std::cout<< head->data << std::endl;
        head = head->next;
    }
}


int main()
{
    node* list1 = nullptr;
    node* list2 = nullptr;

    list1 = populate_list(list1, 5);
    list1 = populate_list(list1, 4);
    list1 = populate_list(list1, 3);
    list1 = populate_list(list1, 2);
    list1 = populate_list(list1, 1);

    display_node(list1);
    

}