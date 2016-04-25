/*
	Adam Austin
	4/22/2016
	TA: Quesada
*/

#include "Person.h"
#include "FamilyTree.h"
#include <iostream>
#include <string>
#include <queue>

using namespace std;

FamilyTree::FamilyTree()
{
	
}

FamilyTree::~FamilyTree()
{
	
}

Person* FamilyTree::findPerson(string _name)
{
	/*queue<PathTracker*> pathQueue;
	vector<PathTracker*> finalPaths;
	_startingCity -> visited = true;
	PathTracker *newPath = new PathTracker(_startingCity);
	pathQueue.push(newPath);
	while (!pathQueue.empty())
	{
		PathTracker *currentPath = pathQueue.front();
		pathQueue.pop();
		Vertex *lastInPath = currentPath -> path.back();
		for (int i = 0; i < lastInPath -> adj.size(); i++)
		{
			Vertex *currentVertex = lastInPath -> adj[i].v;
			PathTracker *newTracker = new PathTracker(currentPath, currentVertex);
			if (currentVertex == _endingCity)
			{
				newTracker -> edges++;
				finalPaths.push_back(newTracker);
			}
			else if (currentVertex -> visited != true)
			{
				newTracker -> edges++;
				currentVertex -> visited = true;
				pathQueue.push(newTracker);
			}
		}
	}*/
	return NULL;
}
