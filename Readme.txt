*******************************************************
*  Name      :      Bryant Wong    
*  Student ID:      107571009           
*  Class     :  CSC 2421           
*  HW#       :  8   
*  Due Date  :  March 29, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

This program uses member functions to add and delete nodes, print preorder, inorder, and postorder, and find
the successor and predecessor of a node of a binary search tree class.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This calls all the functions to carry out the steps in the description


Name:  BSTree.cpp
   Contains all the member functions for everything in the description for a binary search tree class containing
nodes with integer data.

Name:  BSTree.h
   Contains the declarations for all of the member functions needed for using a binary search tree.

Name:  Node.h
   Contains the functionality of the nodes used in the binary search tree, namely the pointers to the left
and right of the tree, the pointers to the parent, the variable to hold the data and the setters and getters
for all of the above.

   
*******************************************************
*  Circumstances of programs
*******************************************************
The program is complete and compiles and runs on visual studio community and csegrid.



Developed on Visual Studio Community 2015 14.0.25431.01 Update 3.



*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [WongHW8]

   Now you should see a directory named homework with the files:
	main.cpp
	BSTree.cpp
	Node.h
	BSTree.h


2. Build the program.

    Change to the directory that contains the file by:
    % cd [WongHW8] 

    Compile the program by:
    % make

3. Run the program by:
   % ./hw8

4. Delete the obj files, executables, and core dump by
   %./make clean
