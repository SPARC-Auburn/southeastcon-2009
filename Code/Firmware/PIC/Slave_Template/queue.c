/*
 *  queue.c
 *  
 *
 *  Created by William Woodall on 1/17/09.
 *  Copyright 2009 Auburn University. All rights reserved.
 *
 */

#include "queue.h"

#define BUFFER_SIZE = 32
volatile unsigned char[BUFFER_SIZE] queue_buffer;
volatile int count = 0;
volatile int left = 0;
volatile int right = 0;

unsigned char isQueueEmpty() 
{
	if(count > 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

unsigned char isQueueFull()
{
	if(count == (BUFFER_SIZE - 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void pushQueue(unsigned char c)
{
	if(count == (BUFFER_SIZE - 1))
	{
		break;
	}
	else
	{
		queue_buffer[right] = c;
		if(right == (BUFFER_SIZE - 1))
		{
			right = 0;
		}
		else
		{
			right++;
		}
		count++;
	}
}

unsigned char popQueue()
{
	if(isQueueEmpty())
	{
		break;
	}
	else
	{
		count--;
		left++;
		return queue_buffer[left-1];
	}
}

