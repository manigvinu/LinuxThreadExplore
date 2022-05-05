/**
 * @file thread_handler.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef THREAD_HANDLER_H
#define THREAD_HANDLER_H

#include <pthread.h>
#include <stdio.h>

/**
 * @brief 
 * 
 * @param thread 
 * @param callback 
 * @param arg 
 */
void threadhandler_CreateThread( pthread_t* thread, void* callback, void* arg );

/**
 * @brief 
 * 
 * @param thread 
 */
void threadhandler_CancelThread(pthread_t* thread);


#endif