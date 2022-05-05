# Table of Contents
-[Table of Contents](#table-of-contents)
-[Overview](#overview)
-[API](#API)
-[How to Build](#how-to-build)


# Overview
Understanding of pthread APIs first and implement the same in the example to get acquainted with

# API

1. pthread_create()
    * Create thread with name, callback, arguments
2. pthread_join()
    * wait for the created threads to complete its execution before exiting the parent thread
    * similar to wait for functions concept
3. pthread_cancel()
    * delete the thread created as its no longer necessary
    * this is done in some instances such as when we create few threads to search database to query the particular string - if one thread return positive answer then we try to cancel other threads
    * This cancel concept introduced to 3 more APIs
        * pthread_setcancelstate() - explored
        * pthread_setcanceltype() - explored
        * pthread_testcancel() - explored
4. pthread_exit()
    * Graceful exit of thread
5. pthread_attr - needs to be analyzed

# How to Build
1. Checkout the repo from github website using git clone/sourcetree
2. Open the code workspace in visual studio code (Ubuntu 20.04 tested)
3. Use ctrl+shitf+b to build the default task
4. main.bin file would be generated and use terminal to run the same - ./main.bin > test.txt
5. Open the test.txt to see the printf debug logs for further analysis
