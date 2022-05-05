/**
 * @file thread_handler.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "thread_handler.h"


/******************************
 * 
 * ****************************/

void threadhandler_CreateThread( pthread_t* thread, void* callback, void* arg )
{
    if(pthread_create(thread, NULL, callback, arg) == -1)
    {
        printf("\n Failed in creation of thread %ld", *thread);
    }
}

void threadhandler_CancelThread(pthread_t* thread)
{
    // ignore the return value for now
    (void)pthread_cancel(*thread);
}