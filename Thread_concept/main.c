/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "thread_handler.h"
#include <unistd.h>


static void* thread_printing(void* data);
static void* thread_printing(void* data);
static void test_CreateCancelThread(void);

/*****************************************/
static void* thread_printing(void* data)
{
    printf("Printing thread Hi there focusing on Thread concepts\n");
    sleep(1);
    pthread_exit(NULL);
}

static void* thread_accessing(void* data)
{
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
    int i=0;
    while(i++<50)
        printf("accessing thread Hi there focusing on Thread concepts : %d\n", i);
    sleep(2);    
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);    
    printf("\n Deferred cancellation execute this \n ");
    pthread_testcancel();
    //pthread_exit(NULL);
}

static void test_CreateCancelThread(void)
{
    void* res;
    //test for creating thread
    pthread_t firstone, secondone;
    threadhandler_CreateThread(&firstone, thread_printing, NULL);
    threadhandler_CreateThread(&secondone, thread_accessing, NULL);

    // cancel the thread
    //threadhandler_CancelThread(&firstone);
    threadhandler_CancelThread(&secondone);
    //kill the thread
    pthread_join(firstone, NULL);
    pthread_join(secondone, &res);    
    if(res == PTHREAD_CANCELED)
        printf("Second One Cancelled status"); 
    else
        printf("other reason \n");
}

/*****************************************/

int main(void)
{
    test_CreateCancelThread();
    return 0;
}