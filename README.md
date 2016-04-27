# Austin_CSCI2270_FinalProject
Team: Adam Austin

ProjectSummary:
This program requires a user to put in data on specific people and then builds a family tree based on the input. It matches new people with existing people and searches for links between the two. For example, if a new person is added, it will search for that persons mother, father, spouse, siblings, and children to link as existing nodes. The program uses a tree to link all of this data. The tree is unordered since family connections are unordered.

How to Run:
You run this application in the command line. First you must download the code, then you can compile the code using the "Makefile" by simply typing "make" in the terminal. You can then run the code by entering "./finalProg_Austin". From there you will be prompted for user input on how to enter people and run the program

Dependencies:
This application has no dependencies

System Requirements:
Your system needs to be able to run and compile C++ code.

Group Members:
Adam Austin

Contributors:

Open issues/bugs:
When a new Person is made their temporary parent nodes do not add them as a child

----------------------------------------------------------------------------------------------------------------

For my assignment, I am going to make a program that allows you to input information on a person and it will build a family tree. The user will enter personal information, including their parents, children, and siblings. The program will build family trees out of this information and allow you to look up trees and peoples relationships.
