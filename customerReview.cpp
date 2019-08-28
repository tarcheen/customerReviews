/*
Developer: Hamed Mirlohi
Date: Aug 27th 2019
This is an Amazon technical interview question
there are two list of customer reviews. 5 star to 1 star
we want to merge both lists, starting with 1 stars.
 */


#include <iostream>
#include <string>

struct node
{
    int data;
    std::string name;
    node* next;
};

node* populate_list(node* head, int d, std::string n)
{
    if(head == nullptr)
    {
        head = new node;
        head->next = nullptr;
        head->data = d;
        head->name = n;
        return head;
    }

    node* tmp = head;
    head = new node;
    head->data = d;
    head->name = n;
    head->next = tmp;
    return head;
}

void display_node(node* head)
{
    while(head != nullptr)
    {
        std::cout<< head->name << ": ";
        std::cout<< head->data << std::endl;
        head = head->next;
    }
}

node* mergeList(node* l1, node* l2)
{
    node* mergedList = nullptr;
    return mergedList;
}


int main()
{
    node* list1 = nullptr;
    node* list2 = nullptr;

    list1 = populate_list(list1, 5, "A");
    list1 = populate_list(list1, 4, "B");
    list1 = populate_list(list1, 3, "C");
    list1 = populate_list(list1, 2, "D");
    list1 = populate_list(list1, 1, "F");

    list2 = populate_list(list2, 2, "B1");
    list2 = populate_list(list2, 2, "B2");
    list2 = populate_list(list2, 2, "B3");
    list2 = populate_list(list2, 1, "A1");
    list2 = populate_list(list2, 1, "A2");
    list2 = populate_list(list2, 1, "A3");
    list2 = populate_list(list2, 1, "A4");


    display_node(list1);
    printf("\n");
    display_node(list2);

    

}