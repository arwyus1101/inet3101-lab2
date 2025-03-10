# INET 3101 Lab 2: Memory and Structures
# Names: Arwah Yusuf and Ahmed Gududow
# Overview
 This lab implements an in-memory database in C using dynamic memory allocation. It manages records without using fixed-size arrays by allocating and resizing memory with malloc(), realloc(), and free().

# Features
Records (Stored in a Structure):

Part Number (int)
Part Name (char[])
Part Size (float)
Part Size Metric (char[], e.g., "mm")
Part Cost (float)
Menu Options:

Print all records
Print number of records
Print size of database (in bytes)
Add a record
Delete the last record
Exit
# Dynamic Memory Management:

Uses malloc() to allocate memory for records.
Expands/shrinks memory dynamically with realloc().
Releases memory with free() when deleting records. 
