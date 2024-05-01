/**
***************************************************************
@file        memory_management.c
@version     1.0.0
@brief       memory management module.
@details     this file contains the memory management module which responsible for add or delete data from memory
@author      Mahmoud Ramzy Behilk.
@Created     on April 30, 2024, 7:07 PM
***************************************************************
*/

#include "memory_management.h"

unsigned int MMM_nGetStudentNumber(node_t *sHead)
{
    node_t* Local_sLast = NULL;
    unsigned int Local_nLength = 0;

    if(!sHead) // checks if linked list is empty or not
    {
        printf("Linked list is empty\nNumber of students is 0\n");
    }
    else
    {
        Local_sLast = sHead;
        while(Local_sLast != NULL)
        {
            Local_nLength++;
            Local_sLast = Local_sLast->sNext;
        }
        //printf("Number of students is : %i \n", Local_nLength);
    }
    return Local_nLength;
}


unsigned int MMM_nCheckIfIdIsExist(node_t *sHead, unsigned int Local_nNew_Id) // test it ??
{
    node_t* Local_sLast = NULL;
    unsigned int Local_nLength = 0;
    unsigned int Local_nReturn_Status = 1;

    if(!sHead)
    {
        Local_nReturn_Status = 0; //this means no student added yet
    }
    else
    {
        Local_sLast = sHead;
        while(Local_sLast != NULL)
        {
            if(Local_sLast->nUnique_Id == Local_nNew_Id)
            {
                Local_nReturn_Status = 1;
                break;
            }
            else
            {
                Local_nReturn_Status = 0;
            }
            Local_sLast = Local_sLast->sNext;
        }
    }
    return Local_nReturn_Status;
}

            /*********************************************/


void MMM_vViewAllRecords(node_t *sHead)
{
    node_t* Local_sCurrent_Node = NULL;
    unsigned int Local_nLength = 0;

    if(NULL == sHead) // if list is empty
    {
        printf("Can't display, linked list is empty \n");
    }
    else
    {
        Local_sCurrent_Node = sHead;

        printf("Students records are \n\n");
        while(Local_sCurrent_Node != NULL)
        {
            Local_nLength++;
            printf("Student(%i) name is         : %s \n", Local_nLength, Local_sCurrent_Node->cName);
            printf("Student(%i) total degree is : %0.2f \n", Local_nLength, Local_sCurrent_Node->fTotal_Grade);
            printf("Student(%i) unique ID is    : %i \n", Local_nLength, Local_sCurrent_Node->nUnique_Id);
            printf("Student(%i) age is          : %i \n", Local_nLength, Local_sCurrent_Node->nAge);
            printf("Student(%i) gender is       : %s \n", Local_nLength, Local_sCurrent_Node->cGender);
            printf("Student(%i) password is     : %i \n", Local_nLength, Local_sCurrent_Node->cPassword);
            printf("============================================\n");
            Local_sCurrent_Node = Local_sCurrent_Node->sNext;
        }
        printf("\n");
    }
}

void MMM_vVieSpecificRecords(node_t *sHead)
{
    node_t* Local_sCurrent_Node = NULL;
    unsigned int Local_nNew_Id = 0;

    if(NULL == sHead) // if list is empty
    {
        printf("Can't display, linked list is empty \n");
    }

    else
    {
        Local_sCurrent_Node = sHead;

        printf("Please enter student ID you want to display: ");
        scanf("%i", &Local_nNew_Id);
        if(MMM_nCheckIfIdIsExist(sHead, Local_nNew_Id)) //this function will return 1 if ID exist
        {
            while(Local_sCurrent_Node->nUnique_Id != Local_nNew_Id)
            {
                Local_sCurrent_Node = Local_sCurrent_Node->sNext;
            }
            printf("Students records are \n");
            printf("Student name is         : %s \n", Local_sCurrent_Node->cName);
            printf("Student total degree is : %0.2f \n", Local_sCurrent_Node->fTotal_Grade);
            printf("Student unique ID is    : %i \n", Local_sCurrent_Node->nUnique_Id);
            printf("Student age is          : %i \n", Local_sCurrent_Node->nAge);
            printf("Student gender is       : %s \n", Local_sCurrent_Node->cGender);
            printf("Student password is     : %i \n", Local_sCurrent_Node->cPassword);
        }
        else
        {
            printf("This ID does not exist !!\n");
        }
    }
}


void MMM_vAddStudentAtFrist(node_t** sHead) // this student will be added at the beginning of the linked list
{
    node_t* Local_sNew_node = NULL;
    unsigned int Local_nNew_Id = 0;
    unsigned int Local_nReturn_Status = 1;

    Local_sNew_node = (node_t *)malloc(sizeof(node_t));

    if(NULL == Local_sNew_node)
    {
        printf("Failed to reserve this space in memory!!\n");
    }
    else
    {
        printf("Please enter student data : \n");

        printf("Please enter student unique ID : ");
        scanf("%i", &Local_nNew_Id);
        Local_nReturn_Status = MMM_nCheckIfIdIsExist(*sHead, Local_nNew_Id);// test it ?? you can make this function take double pointer or remove this function and search with while loop like in delete specific node

        if(0 == Local_nReturn_Status)
        {
            Local_sNew_node->nUnique_Id = Local_nNew_Id;

            printf("Please enter student name : ");
            scanf("%s", &Local_sNew_node->cName);
            fflush(stdin);
            printf("Please enter student total degree : ");
            scanf("%f", &Local_sNew_node->fTotal_Grade);
            printf("Please enter student age : ");
            scanf("%i", &Local_sNew_node->nAge);
            printf("Please enter student gender : ");
            scanf("%s", &Local_sNew_node->cGender);
            fflush(stdin);
            printf("Please enter student password : ");
            scanf("%d", &Local_sNew_node->cPassword);

            Local_sNew_node->sNext = *sHead;
            *sHead = Local_sNew_node;
        }
        else
        {
            printf("This ID is already exist !!\n");
        }
    }
    printf("\n");
}

void MMM_vDeleteSpecificStudent(node_t** sHead) //Delete_Specific_Node
{
    node_t* Local_sCurrent = *sHead;
    node_t* Local_sPrevious = *sHead;
    unsigned int Local_nNew_Id = 0;

    if (!Local_sCurrent)
    {
        printf("Can't delete, linked list is empty!\n");
        return;
    }
    else
    {
        printf("Please enter student ID you want to delete : ");
        scanf("%i", &Local_nNew_Id);

        if (Local_sCurrent->nUnique_Id == Local_nNew_Id) /* If the first node matches the ID */
        {
            *sHead = Local_sCurrent->sNext;
            free(Local_sCurrent);
            Local_sCurrent = NULL; // added
            return;
        }

        while(Local_sCurrent != NULL && Local_sCurrent->nUnique_Id != Local_nNew_Id)
        {
            Local_sPrevious = Local_sCurrent;
            Local_sCurrent = Local_sCurrent->sNext;
        }
        if (Local_sCurrent == NULL)
        {
            printf("Student with such ID not found in the linked list!\n");
            return;
        }
        Local_sPrevious->sNext = Local_sCurrent->sNext;
        Local_sCurrent->sNext = NULL;
        free(Local_sCurrent);
        Local_sCurrent = NULL; // added
    }
}
