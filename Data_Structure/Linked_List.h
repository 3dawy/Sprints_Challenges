/*
 * Linked_List.h
 *
 *  Created on: Feb 6, 2020
 *      Author: Khaled
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "std_types.h"
#include <stdlib.h>

typedef struct ST_Node{
	sint16_t Data;
	struct ST_Node * strp_Next_Node;
}ST_Node;


typedef struct ST_List {
	uint16_t stru16_Size;
	ST_Node * strp_List_Head;
}ST_List;

/*
 * Description:this function create a list by initializing iy's control structure
 * @param: It takes pointer to the list control structure
 */
void createList(ST_List * list);

/*
 * Description:this function insert a new node to the list
 * @param: It takes pointer to the list control structure
 * @param: It takes the position of the new node
 * @param: It takes the data that will insert in the new node
 */
void insertToList(ST_List * list, uint8_t position, sint16_t data);

/*
 * Description:this function delet node from the list
 * @param: It takes pointer to the list control structure
 * @param: It takes the position of the node
 * @param: It takes pointer return the data of this node before delete it
 */
void deleteFromList(ST_List * list, uint8_t position, sint16_t * data);

/*
 * Description:this function search about exact data in the list
 * @param: It takes pointer to the list control structure
 * @param: It takes the data that will search about
 * @return: this function return the address of the node that contain the data
 */
ST_Node* searchIntoList(ST_List * list, sint16_t data);


#endif /* LINKED_LIST_H_ */
