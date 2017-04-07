#ifndef PATHFINDING_H
#define PATHFINDING_H
#include <cmath>
#include <queue>
#include <ctime>
#include <string>
#include <iomanip>

// http://code.activestate.com/recipes/577457-a-star-shortest-path-algorithm/

// TODO: get these these from map.h
const int mapHorizontial = 60;
const int mapVertical = 60;
static int map[mapHorizontial][mapVertical];

// number of possible directions from any position
const int direction = 8;
static int dx[direction] = { 1, 1, 0, -1, -1, -1, 0, 1 };
static int dy[direction] = { 0, 1, 1, 1, 0, -1, -1, -1 };

// closed out (tried out) and open (not yet tried) nodes
static int closed_nodes_map[mapHorizontial][mapVertical];
static int open_nodes_map[mapHorizontial][mapVertical];



class Node
{
public:
	Node() {}
	~Node() {}
	float PathFinding(const float & xStart, const float & yStart, const float & xFinish, const float & yFinish);

	Node(float xpos_, float ypos_, float level_, float priority_) {
		xPos = xpos_; 
		yPos = ypos_;  
		Level = level_; 
		Priority = priority_;
	}
	float GetXPos() const {
		return xPos;
	}
	float GetYPos() const{ 
		return yPos;
	}
	float GetLevel() const {
		return Level;

	}

	float GetPriority() const {
		return Priority;

	}

	void updatePriority(const float & xDest, const float & yDest) {
		Priority = Level + Estimate(xDest, yDest) * 10;

	}
	void nextLevel(const int & dir) {
		Level += (direction == 8 ? (dir % 2 == 0 ? 10 : 14) : 10);
	}
	// Estimates the remaining distance to the targer
	const int &Estimate(const float & xDest, const float &yDest) {
		static float xd, yd, d;
		xd = xDest - xPos;
		yd = yDest - yPos;

		// distance
		d = static_cast<int>(sqrt(xd*xd + yd*yd));

		return d;

	}



	// Current position
	float xPos, yPos;
	// totla distance already travelled
	float Level;
	//priority
	float Priority;


};

bool operator<(const Node & a, const Node & b) {
	return a.GetPriority() > b.GetPriority();

}


#endif
