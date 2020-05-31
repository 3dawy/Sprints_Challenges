/*
 * Queue.h
 *
 *  Created on: Feb 5, 2020
 *      Author: Khaled
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "std_types.h"

#define ZERO 0

typedef struct ST_Queue
{
	uint8_t stru8_Rear_Counter;
	uint8_t stru8_Front_Counter;
	uint8_t stru8_Queue_Size;
	uint8_t stru8_Queue_Counter;
	uint8_t * strpu8_Queue;
}ST_Queue;


/*
 * Description:this function check if the queue is empty
 * @param: It takes pointer to queue structure control
 * @return: true if the queue empty and false if not
 */
uint8_t Is_Queue_Empty (ST_Queue * Ptr);

/*
 * Description:this function check if the queue is full
 * @param: It takes pointer to queue structure control
 * @return: true if the queue full and false if not
 */
uint8_t Is_Queue_Full (ST_Queue * Ptr);

/*
 * Description:this function create a queue with specific size
 * @param: It takes pointer to queue structure control
 * @param: it takes the size of the queue
 */
void createQueue(ST_Queue * Ptr, uint8_t maxSize);

/*
 * Description:this function enqueue a data to rear of the queue
 * @param: It takes pointer to queue structure control
 * @param: it takes the data that will enqueue in the queue
 */
void enqueue(ST_Queue * Ptr, uint8_t data);

/*
 * Description:this function dequeue a data from the front the queue
 * @param: It takes pointer to queue structure control
 * @return: it returns the data that find in the front of the queue
 */
uint8_t dequeue(ST_Queue * Ptr);


#endif /* QUEUE_H_ */
