/*
Developer: Hamed Mirlohi
Date: Aug 27th 2019
This is an Amazon technical interview question
there are two list of customer reviews. 5 star to 1 star
we want to merge both lists, starting with 1 stars.
Assuming both lists are sorted coming in
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

    // if both lists are empty, return empty list
    if(l1 == nullptr && l2 == nullptr)
    {
        return nullptr;
    }

    // return list 2 if list 1 empty
    else if (l1 == nullptr)
    {
        return l2;
    }

    // return list 1 if list 2 empty
    else if (l2 == nullptr)
    {
        return l1;
    }

    // at this point we know both lists have elements

    node* tmp = new node;
    tmp->next = nullptr;
    node* mergedList = tmp;

    // while both lists have elements
    while (true)
    {
        // if element in l1 is smaller or equal than element in l2
        if(l1->data <= l2->data)
        {
            tmp->data = l1->data;
            tmp->name = l1->name;
            l1 = l1->next;

            // check if any elements left in l1
            if(l1 == nullptr)
                break;
        }
        else
        {
            tmp->data = l2->data;
            tmp->name = l2->name;
            l2 = l2->next;

            // check if any elements left in l2
            if(l2 == nullptr)
                break;        
        }

        // we still have elements in both list, create another node
        tmp->next = new node;
        tmp = tmp->next;
        tmp->next = nullptr;
    }

    // at this point, one of the lists are done, however one list has still elements

    // checking both lists
    while(l1 != nullptr)
    {
        tmp->next = new node;
        tmp = tmp->next;
        tmp->next = nullptr;
        tmp->data = l1->data;
        tmp->name = l1->name;
        l1 = l1->next;
    }
    
    while(l2 != nullptr)
    {
        tmp->next = new node;
        tmp = tmp->next;
        tmp->next = nullptr;
        tmp->data = l2->data;
        tmp->name = l2->name;
        l2 = l2->next;
    }

    return mergedList;
}


int main()
{
    node* list1 = nullptr;
    node* list2 = nullptr;
    node* combinedList = nullptr;

    list1 = populate_list(list1, 5, "Justin 5 Star Review");
    list1 = populate_list(list1, 4, "Harry 4 Star Review");
    list1 = populate_list(list1, 3, "Maven 3 Star Review");
    list1 = populate_list(list1, 2, "Rami 2 Star Review");
    list1 = populate_list(list1, 1, "Charles 1 Star Review");

    list2 = populate_list(list2, 5, "Bob 5 Star Review");
    list2 = populate_list(list2, 5, "Kate 5 Star Review");
    list2 = populate_list(list2, 5, "Nate 5 Star Review");
    list2 = populate_list(list2, 4, "Al 4 Star Review");
    list2 = populate_list(list2, 4, "Rahill 4 Star Review");
    list2 = populate_list(list2, 2, "Mila 2 Star Review");
    list2 = populate_list(list2, 1, "Hoda 1 Star Review");


    display_node(list1);
    printf("\n");
    display_node(list2);

    printf("-------------------\n");


    combinedList = mergeList(list1, list2);

    display_node(combinedList);
    

}