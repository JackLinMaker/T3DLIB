#include "stdafx.h"
#include "t3dlib1.h"


// storage for our lookup tables
float cos_look[361]; // 1 extra element so we can store 0-360 inclusive
float sin_look[361];


void Build_Sin_Cos_Tables(void)
{
	// create sin/cos lookup table
	// note the creation of one extra element; 360
	// this helps with logic in using the tables

	// genrate the tables 0-360 inclusive
	for(int ang = 0; ang <= 360; ang++)
	{
		// convert ang to radians
		float theta = (float)ang * PI / (float)180;

		// insert next entry into table
		cos_look[ang] = cos(theta);
		sin_look[ang] = sin(theta);
	}
}


int Fast_Distance_2D(int x, int y)
{
	// this function computes the distance from 0,0 to x,y with 3.5% error
	// first compute the absolute value of x, y
	x = abs(x);
	y = abs(y);
	
	// compute the minimum of x, y
	int mn = MIN(x, y);
	// return the distance
	return (x + y - (mn >> 1) - (mn >> 2) + (mn >> 4));
}

float Fast_Distance_3D(float fx, float fy, float fz)
{
	// this function computes the distance from the origin to x, y, z
	int temp; // used for swaping
	int x, y, z; // used for algorithm

	// make sure values are all positive
	x = fabs(fx) * 1024;
	y = fabs(fy) * 1024;
	z = fabs(fz) * 1024;

	// sort values
	if(y < x) SWAP(x, y, temp);
	if(z < y) SWAP(y, z, temp);
	if(y < x) SWAP(x, y ,temp);

	int dist = (z + 11 * (y >> 5) + (x >> 2));
	return ((float)(dist >> 10));
}

t3dlib1::t3dlib1(void)
{
}


t3dlib1::~t3dlib1(void)
{
}
