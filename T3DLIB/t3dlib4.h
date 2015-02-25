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




class t3dlib4
{
public:
	t3dlib4(void);
	~t3dlib4(void);
};

