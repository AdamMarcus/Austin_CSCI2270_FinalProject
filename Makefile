# Makefiles! Build an executable for the Student example
# Author: Adam Austin
# -Wall = extra warnings


# Macros/variables
OBJS = Person.o FamilyTree.o FinalProject.o
CPPFLAGS = -Wall -std=c++11
PROG = finalProg_Austin
CC = g++

# Target: Dependancys
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)
	
#Actions
Person.o: Person.h Person.cpp
	$(CC) $(CPPFLAGS) -c Person.cpp
	
FamilyTree.o: FamilyTree.h FamilyTree.cpp
	$(CC) $(CPPFLAGS) -c FamilyTree.cpp
	
FinalProject.o: FinalProject.cpp
	$(CC) $(CPPFLAGS) -c FinalProject.cpp
	
clean:
	$(RM) $(PROG) $(OBJS)

