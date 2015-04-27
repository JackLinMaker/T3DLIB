#include "stdafx.h"
#include "t3dlib1.h"
#include "t3dlib4.h"



float Fast_Sin(float theta)
{
	// convert angle to 0-359
	theta = fmodf(theta, 360);
	// make angle positive
	if(theta < 0)
		theta += 360.0;

	// compute floor of theta and fractional part to interpolate
	int theta_int = (int)theta;
	float theta_frac = theta - theta_int;

	// now compute the value of sin(angle) using the lookup tables
	// and interpolating the fractional part, note that if theta_int 
	// is equal to 359 then theta_int + 1 = 360, but this is fine since
	// table was made_with the entries 0-360 inclusive
	return (sin_look[theta_int] + theta_frac * (sin_look[theta_int + 1] - sin_look[theta_int]));


}

float Fast_Cos(float theta)
{
	// this function uses the cos_look[] lookup table, but
// has logic to handle negative angles as well as fractional
// angles via interpolation, use this for a more robust
// cos computation that the blind lookup, but with with
// a slight hit in speed

	// conver angle to 0-359
	theta = fmodf(theta, 360);

	// make angle positive
	if(theta < 0)
		theta += 360.0;

	// compute floor of theta and fractional part to interpolate
	int theta_int = (int)theta;
	float theta_frac = theta - theta_int;

	// now compute the value of sin(angle) using the lookup tables
// and interpolating the fractional part, note that if theta_int
// is equal to 359 then theta_int+1=360, but this is fine since the
// table was made with the entries 0-360 inclusive
return(cos_look[theta_int] + 
       theta_frac*(cos_look[theta_int+1] - cos_look[theta_int]));
}


void POLAR2D_To_POINT2D(POLAR2D_PTR polar, POINT2D_PTR rect)
{
	rect->x = polar->r * cosf(polar->theta);
	rect->y = polar->r * sinf(polar->theta);
}

void POLAR2D_To_RectXY(POLAR2D_PTR polar, float *x, float *y)
{
	*x = polar->r * cosf(polar->theta);
	*y = polar->r * sinf(polar->theta);
}

void POINT2D_To_POLAR2D(POINT2D_PTR rect, POLAR2D_PTR polar)
{
	polar->r = sqrtf((rect->x * rect->x) + (rect->y * rect->y));
	polar->theta = atanf(rect->y / rect->x);
}

void POINT2D_To_PolarRTH(POINT2D_PTR rect, float *r, float * theta)
{
	*r = sqrtf((rect->x * rect->x) + (rect->y * rect->y));
	*theta = atanf(rect->y / rect->x);
}

void CYLINDRICAL3D_To_POINT3D(CYLINDRICAL3D_PTR cyl, POINT3D_PTR rect)
{
	rect->x = cyl->r * cosf(cyl->theta);
	rect->y = cyl->r * sinf(cyl->theta);
	rect->z = cyl->z;
}

void CYLINDIRCAL3D_To_RectXYZ(CYLINDRICAL3D_PTR cyl, float *x, float *y, float *z)
{
	*x = cyl->r * cosf(cyl->theta);
	*y = cyl->r * sinf(cyl->theta);
	*z = cyl->z;
}

void POINT3D_To_CYLINDRICAL3D(POINT3D_PTR rect, CYLINDRICAL3D_PTR cyl)
{
	cyl->r = sqrtf((rect->x * rect->x) + (rect->y * rect->y));
	cyl->theta = atanf(rect->y / rect->x);
	cyl->z = rect->z;
}


void POINT3D_To_CylindricalRThZ(POINT3D_PTR rect, 
                                       float *r, float *theta, float *z)
{
// convert rectangular to cylindrical
*r     = sqrtf((rect->x * rect->x) + (rect->y * rect->y));
*theta = atanf(rect->y/rect->x);
*z     = rect->z;

} // end POINT3D_To_CylindricalRThZ

void SPHERICAL3D_To_POINT3D(SPHERICAL3D_PTR sph, POINT3D_PTR rect)
{
	float r;
	r = sph->p * sinf(sph->phi);
	rect->z = sph->p * cosf(sph->phi);
	rect->x = r * cosf(sph->theta);
	rect->y = r * sinf(sph->theta);
}


void POINT3D_To_SPHERICAL3D(POINT3D_PTR rect, SPHERICAL3D_PTR sph)
{
	sph->p = sqrtf((rect->x*rect->x)+(rect->y*rect->y)+(rect->z*rect->z));
	sph->theta = atanf(rect->y/rect->x);
	// we need r to compute phi
	float r = sph->p*sinf(sph->phi);
	sph->phi   = asinf(r/sph->p);
}

////////////////////////////////////////////////////////////

void POINT3D_To_SphericalPThPh(POINT3D_PTR rect, 
                                      float *p, float *theta, float *phi)
{
// convert rectangular to spherical
*p     = sqrtf((rect->x*rect->x)+(rect->y*rect->y)+(rect->z*rect->z));
*theta = atanf(rect->y/rect->x);

// we need r to compute phi
float r = sqrtf((rect->x * rect->x) + (rect->y * rect->y));
*phi    = asinf(r / (*p));

} // end POINT3D_To_SphericalPThPh



//////////////////////////////////////////////

void VECTOR2D_Add(VECTOR2D_PTR va, VECTOR2D_PTR vb, VECTOR2D_PTR vsum)
{
	// this function adds va + vb and return it in vsum
	vsum->x = va->x + vb->x;
	vsum->y = va->y + vb->y;
}

VECTOR2D VECTOR2D_Add(VECTOR2D_PTR va, VECTOR2D_PTR vb)
{
	VECTOR2D vsum;
	vsum.x = va->x + vb->x;
	vsum.y = va->y + vb->y;
	return vsum;
}

void VECTOR2D_Sub(VECTOR2D_PTR va, VECTOR2D_PTR vb, VECTOR2D_PTR vdiff)
{
	vdiff->x = va->x - vb->x;
	vdiff->y = va->y - vb->y;

}

VECTOR2D VECTOR2D_Sub(VECTOR2D_PTR va, VECTOR2D_PTR vb)
{
	VECTOR2D vdiff;
	vdiff.x = va->x - vb->x;
	vdiff.y = va->y - vb->y;
	return vdiff;
}

void VECTOR2D_Scale(float k, VECTOR2D_PTR va, VECTOR2D_PTR vscaled)
{
	vscaled->x = k * va->x;
	vscaled->y = k * va->y;
}

void VECTOR2D_Scale(float k, VECTOR2D_PTR va)
{
	va->x *= k;
	va->y *= k;
}

float VECTOR2D_Dot(VECTOR2D_PTR va, VECTOR2D_PTR vb)
{
	return ( (va->x * vb->x) + (va->y * vb->y) );
}

float VECTOR2D_Length(VECTOR2D_PTR va)
{
	return (sqrtf(va->x * va->x + va->y * va->y));
}

float VECTOR2D_Length_Fast(VECTOR2D_PTR va)
{
	return ((float)Fast_Distance_2D(va->x, va->y));
}


void VECTOR2D_Normalize(VECTOR2D_PTR va)
{
	// normalizes the sent vector in place
	// compute length
	float length = sqrtf(va->x * va->x + va->y * va->y);

	// test for zero length vector
	// if found return zero vector
	if(length < EPSILON_E5)
		return;

	float length_inv = 1 / length;

	// compute normalized version of vector
	va->x = va->x * length_inv;
	va->y = va->y * length_inv;
}

void VECTOR2D_Normalize(VECTOR2D_PTR va, VECTOR2D_PTR vn)
{
	// normalizes the sent vector and returns the result in vn
	VECTOR2D_ZERO(vn);

	// compute length
	float length = (float)sqrtf(va->x * va->x + va->y * va->y);

	// test for  zero length vector
	// if found return zero vector
	if(length < EPSILON_E5)
		return;

	float length_inv = 1 / length;

	// compute normalized version of vector
	vn->x = va->x * length_inv;
	vn->y = va->y * length_inv;
}

void VECTOR2D_Build(VECTOR2D_PTR init, VECTOR2D_PTR term, VECTOR2D_PTR result)
{
	// this function creates a vector from two vectors (or points) in 3d space
	result->x = term->x - init->x;
	result->y = term->y - init->y;
}

float VECTOR2D_CosTh(VECTOR2D_PTR va, VECTOR2D_PTR vb)
{
	// this function returns the cosine of the angle between
	// two vectors, note, we could compute the actual angle,
	// many many times, 
	return (VECTOR2D_Dot(va, vb) / (VECTOR2D_Length(va) * VECTOR2D_Length(vb)));
}

void VECTOR2D_Print(VECTOR2D_PTR va, char *name = "v")
{
	// this function prints out a VECTOR2D

/*Write_Error("\n%s=[",name);
for (int index=0; index<2; index++)
    Write_Error("%f, ",va->M[index]);
Write_Error("]");*/
}


t3dlib4::t3dlib4(void)
{
}


t3dlib4::~t3dlib4(void)
{
}
