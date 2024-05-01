/**
***************************************************************
@file        memory_management.h
@version     1.0.0
@brief       memory management module.
@details     this file contains the memory management module which responsible for add or delete data from memory
@author      Mahmoud Ramzy Behilk.
@Created     on April 30, 2024, 6:42 PM
***************************************************************
*/

#ifndef _MEMORY_MANAGEMENT_H
#define _MEMORY_MANAGEMENT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char cName[50];
    float fTotal_Grade;
    unsigned int nUnique_Id;
    unsigned int nAge;
    char cGender[10];
    char cPassword;  // debug
    struct node_t* sNext;
}node_t;

          /**================  Helper Functions  =================**/

/*
 * Breif : This function used to get the length of the linked list (number of students)
 * Parameters : Pointer to linked list head
 * return : The length (number of students)
 */
unsigned int MMM_nGetStudentNumber(node_t *sHead);

/*
 * Breif : This function used to check if the ID is already exist or not
 * Parameters : Pointer to linked list head
 * Parameters : New ID
 * return : Return status 1 if it's already exist and 0 if it not exist
 */
unsigned int MMM_nCheckIfIdIsExist(node_t *sHead, unsigned int Local_nNew_Id);

        /**================  Basic Functions  =================**/

/*
 * Breif : This function used to display the data of all students
 * Parameters : Pointer to linked list head
 * return : void
 */
void MMM_vViewAllRecords(node_t *sHead);

/*
 * Breif : This function used to display data for specific student
 * Parameters : Pointer to linked list head
 * return : void
 */
void MMM_vVieSpecificRecords(node_t *sHead);


/*
 * Breif : This function used to add student at the beginning of the linked list
 * Parameters : Double pointer to linked list head
 * return : void
 */
void MMM_vAddStudentAtFrist(node_t** head); // Insert_Frist_Node


/*
 * Breif : This function used to delete specific student by his ID
 * Parameters : Double pointer to linked list head
 * return : void
 */
void MMM_vDeleteSpecificStudent(node_t** head);


#endif // _MEMORY_MANAGEMENT_H
