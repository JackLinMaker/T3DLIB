#pragma once

#define EPSILON_E3 (float)(1E-3)
#define EPSILON_E4 (float)(1E-4)
#define EPSILON_E5 (float)(1E-5)
#define EPSILON_E6 (float)(1E-6)

// defines for parametric line intersections
#define PARM_LINE_NO_INTERSECT			0
#define PARM_LINE_INTERSECT_IN_SEGMENT	1
#define PARM_LINE_INTERSECT_OUT_SEGMENT	2
#define PARM_LINE_INTERSECT_EVERYWHERE  3

// TYPES	//////////

// 2x2 matrix
typedef struct MATRIX2X2_TYP
{
	union{
		float M[2][2]; // array indexed data storage

		// storage in row majopr form with explicit names
		struct 
		{
			float M00, M01;
			float M10, M11;
		};
	};
} MATRIX2X2, *MATRIX2X2_PTR;

// 1X4 matrix
typedef struct MATRIX1X4_TYP
{
	union {
		float M[4]; // array indexed data storage

		// storage in row major form with explicit names
		struct {
			float M00, M01, M02, M03;
		};
	};
}MATRIX1X4, *MATRIX1X4_PTR;

// 4X4 matrix
typedef struct MATRIX4X4_TYP
{
	union
	{
		float M[4][4];	// array indexed data storage

		// storage in row major form with explicit names
		struct {
			float M00, M01, M02, M03;
			float M10, M11, M12, M13;
			float M20, M21, M22, M23;
			float M30, M31, M32, M33;
		};
	};
}MATRIX4X4, *MATRIX4X4_PTR;

// 4X3 matrix
typedef struct MATRIX4X3_TYP
{
	union{
		float M[4][3]; // array indexed data storage

		// storage in row major form with explicit names
		struct {
			float M00, M01, M02;
			float M10, M11, M12;
			float M20, M21, M22;
			float M30, M31, M32;
		};
	};
}MATRIX4X3, *MATRIX4X3_PTR;

// vector types	/////////////

// 2D vector, point without the w /////////
typedef struct	VECTOR2D_TYP
{
	union {
		float M[2];

		struct {
			float x, y;
		};
	};
}VECTOR2D, POINT2D, *VECTOR2D_PTR, *POINT2D_PTR;

// 3D vector, point without the w
typedef struct VECTOR3D_TYP
{
	union {
		float M[3];

		struct {
			float x, y, z;
		};
	};
}VECTOR3D, POINT3D, *VECTOR3D_PTR, *POINT3D_PTR;

// 4D homogenous vector, point with w
typedef struct VECTOR4D_TYP
{
	union 
	{
		float M[4];	// array indexed stroage

		// explicit names
		struct
		{
			float x, y, z, w;
		};
	};
}VECTOR4D, POINT4D, *VECTOR4D_PTR, *POINT4D_PTR;

// 2D parametric line
typedef struct PARMLINE2D_TYP
{
	POINT2D p0;	// start point of parametric line
	POINT2D	p1;	// end point of parametric line
	VECTOR2D v;	// direction vector of line segment
				// |v| = |p0->p1|
}PARMLINE2D, *PARMLINE2D_PTR;

// 3D parametric line
typedef struct PARMLINE3D_TYP
{
	POINT3D p0;	// start point of parametric line
	POINT3D p1; // end point of parametric line
	VECTOR3D v;	// direction vector of line segment;
				// |v| = |p0->p1|
}PARMLINE3D, *PARMLINE3D_PTR; 

// 3D plane
typedef struct PLANE3D_TYP
{
	POINT3D p0;	// point on the plane
	VECTOR3D n;	// normal to the plane (not necessarily a unit vector)
}PLANE3D, *PLANE3D_PTR;

// 2D polar coordinates
typedef struct POLAR2D_TYP
{
	float r;	// the radi of the point
	float theta;	// the angle in rads
}POLAR2D, *POLAR2D_PTR;

// 3D cylindrical coordinates
typedef struct CYLINDIRCAL3D_TYP
{
	float r;	// the radi of the point
	float theta;	// the angle in degrees about the z axis
	float z;	// the z-height of the point
}CYLINDIRCAL3D, *CYLINDRICAL3D_PTR;

// 3D spherical coordinatates
typedef struct SPHERICAL3D_TYP
{
	float p;		// rho, the distance to the point from the origin
	float theta;	// the angle from the z-axis and the line segment o->p
	float phi;		// he angle from the projection if o->p onto the x-y plane and the x-axis
}SPHERICAL3D, *SPHERICAL3D_PTR;

class t3dlib4
{
public:
	t3dlib4(void);
	~t3dlib4(void);
};

