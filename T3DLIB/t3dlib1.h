#pragma once

#define SCREEN_WIDTH	640
#define SCREEN_HEIGHT	480
#define SCREEN_BPP		8
#define MAX_COLORS_PALETTE	256	

#define DEFAULT_PALETTE_FILE	"PALDATA2.PAL"

// used for selecting full screen/windowed mode
#define SCREEN_FULLSCREEN	0
#define SCREEN_WINDOWED		1

// bitmap defines
#define BITMAP_ID				0x4D42	// universal id for a bitmap
#define BITMAP_STATE_DEAD		0
#define BITMAP_STATE_ALIVE		1
#define BITMAP_STATE_DYING		2
#define BITMAP_ATTR_LOADED		128

#define BITMAP_EXTRACT_MODE_CELL	0
#define BITMAP_EXTRACT_MODE_ABS		1

// directdraw pixel format defines, used to help
// bitmap loader put data in proper format
#define DD_PIXEL_FORMAT8			8
#define DD_PIXEL_FORMAT555			15
#define DD_PIXEL_FORMAT565			16
#define DD_PIXEL_FORMAT888			24
#define DD_PIXEL_FORMAT888			32

// defines for BOBs
#define BOB_STATE_DEAD         0    // this is a dead bob
#define BOB_STATE_ALIVE        1    // this is a live bob
#define BOB_STATE_DYING        2    // this bob is dying
#define BOB_STATE_ANIM_DONE    1    // done animation state
#define MAX_BOB_FRAMES         64   // maximum number of bob frames
#define MAX_BOB_ANIMATIONS     16   // maximum number of animation sequeces

#define BOB_ATTR_SINGLE_FRAME   1   // bob has single frame
#define BOB_ATTR_MULTI_FRAME    2   // bob has multiple frames
#define BOB_ATTR_MULTI_ANIM     4   // bob has multiple animations
#define BOB_ATTR_ANIM_ONE_SHOT  8   // bob will perform the animation once
#define BOB_ATTR_VISIBLE        16  // bob is visible
#define BOB_ATTR_BOUNCE         32  // bob bounces off edges
#define BOB_ATTR_WRAPAROUND     64  // bob wraps around edges
#define BOB_ATTR_LOADED         128 // the bob has been loaded
#define BOB_ATTR_CLONE          256 // the bob is a clone

// screen transition commands
#define SCREEN_DARKNESS  0         // fade to black
#define SCREEN_WHITENESS 1         // fade to white
#define SCREEN_SWIPE_X   2         // do a horizontal swipe
#define SCREEN_SWIPE_Y   3         // do a vertical swipe
#define SCREEN_DISOLVE   4         // a pixel disolve
#define SCREEN_SCRUNCH   5         // a square compression
#define SCREEN_BLUENESS  6         // fade to blue
#define SCREEN_REDNESS   7         // fade to red
#define SCREEN_GREENNESS 8         // fade to green

// defines for Blink_Colors
#define BLINKER_ADD           0    // add a light to database  
#define BLINKER_DELETE        1    // delete a light from database
#define BLINKER_UPDATE        2    // update a light
#define BLINKER_RUN           3    // run normal

// pi defines
#define PI         ((float)3.141592654f)
#define PI2        ((float)6.283185307f)
#define PI_DIV_2   ((float)1.570796327f)
#define PI_DIV_4   ((float)0.785398163f) 
#define PI_INV     ((float)0.318309886f) 

// fixed point mathematics constants
#define FIXP16_SHIFT     16
#define FIXP16_MAG       65536
#define FIXP16_DP_MASK   0x0000ffff
#define FIXP16_WP_MASK   0xffff0000
#define FIXP16_ROUND_UP  0x00008000

// MARCOS	///////////////////////////////////

// these read the keyboard asynchronously
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vk_code)   ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

// this builds a 16 bit color value in 5,5,5 format 1-bit alpha mode
#define _RGB16BIT555(r, g, b) ((b & 31) + ((g & 31) << 5) + ((r & 31) << 10))

// this builds a 16 bit color value in 5,6,5 format (green dominate mode)
#define _RGB16BIT565(r, g, b) ((b & 31) + ((g & 63) << 5) + ((r & 31) << 11))

// this build a 24 bit color value in 8,8,8 format
#define _RGB24BIT(a, r, g, b) ((b) + (g) << 8) + ((r) << 16) )

// this builds a 32 bit color value in A.8.8.8 format (8 bit alpha mode)
#define _RGB32BIT(a,r,g,b) ((b) + ((g) << 8) + ((r) << 16) + ((a) << 24))

// bit manipulation marcos
#define SET_BIT(word, bit_flag) ((word) = ((word) | (bit_flag)))
#define RESET_BIT(word, bit_flag) ((word) = ((word) & (~bit_flag)))

// initalizes a direct draw struct, basically zeros it and sets the dwSize field
#define DDRAW_INIT_STRUCT(ddstruct) { memset(&ddstruct,0,sizeof(ddstruct)); ddstruct.dwSize=sizeof(ddstruct); }

// used to compute the min and max of two expressions
#define MIN(a, b)  (((a) < (b)) ? (a) : (b)) 
#define MAX(a, b)  (((a) > (b)) ? (a) : (b)) 

// used for swapping algorithm
#define SWAP(a, b, t) { t = a; a = b; b = t; }

// some match marcos
#define DEG_TO_RAD(ang) ((ang) * PI / 180.0)
#define RAD_TO_DEG(rads) ((rads) * 180.0 / PI)

#define RAND_RANGE(x, y) ((x) + (rand() % ((y) - (x) + 1)))

// types

// basic unsigned types
typedef unsigned short USHORT;
typedef unsigned short WORD;
typedef unsigned char  UCHAR;
typedef unsigned char  BYTE;
typedef unsigned char  QUAD;
typedef unsigned int   UINT;

// container structure for bitmaps .BMP file
typedef struct BITMAP_FILE_TAG
{
	BITMAPFILEHEADER bitmapfileheader; // this contains the bitmapfile header
	BITMAPINFOHEADER bitmapfoheader;	// this is all the info including pallete
	PALETTEENTRY	 palette[256];		// we will store the pallete here
	UCHAR			 *buffer;			// this is a pointer to the data

}BITMAP_FILE, *BITMAP_FILE_PTR;

// the blitter objecet structure BOB
typedef struct BOB_TYP
{
	int state; 
}BOB, *BOB_PTR;

// a 2d vertex
typedef struct VERTEX2DI_TYP
{
	int x,y;	// the vertex
}VERTEX2DI, *VERTEX2DI_PTR;

// a 2D vertex
typedef struct VERTEX2DF_TYP
{
	float x, y;	// the vertex
}VERTEX2DF, *VERTEX2DF_PTR;

// a 2D polygon
typedef struct POLYGON2D_TYP
{
	int state;	// state of poygon
	int num_verts;	// number of vertices
	int x0, y0;	// poisiton of center of polygon
	int xv, yv;	// initial velocity
	DWORD color;	// could be index of PALETTENTRY
	VERTEX2DF *vlist;	// pointer to vertex list
}POLYGON2D, *POLYGON2D_PTR;


// matrix defines

// 3x3 matrix /////////////////////////////////////////////
typedef struct MATRIX3X3_TYP
{
union
{
float M[3][3]; // array indexed data storage

// storage in row major form with explicit names
struct
        {
        float M00, M01, M02;
        float M10, M11, M12;
        float M20, M21, M22;
        }; // end explicit names

}; // end union
} MATRIX3X3, *MATRIX3X3_PTR;


// 1x3 matrix /////////////////////////////////////////////
typedef struct MATRIX1X3_TYP
        {
        union
        {
        float M[3]; // array indexed data storage

        // storage in row major form with explicit names
        struct
             {
             float M00, M01, M02;

             }; // end explicit names
        }; // end union
        } MATRIX1X3, *MATRIX1X3_PTR;

// 3x2 matrix /////////////////////////////////////////////
typedef struct MATRIX3X2_TYP
        {
        union
        {
        float M[3][2]; // array indexed data storage

        // storage in row major form with explicit names
        struct
             {
             float M00, M01;
             float M10, M11;
             float M20, M21;
             }; // end explicit names

        }; // end union
        } MATRIX3X2, *MATRIX3X2_PTR;

// 1x2 matrix /////////////////////////////////////////////
typedef struct MATRIX1X2_TYP
        {
        union
        {
        float M[2]; // array indexed data storage

        // storage in row major form with explicit names
        struct
             {
             float M00, M01;

             }; // end explicit names
        }; // end union
        } MATRIX1X2, *MATRIX1X2_PTR;

// storage for our lookup tables
extern float cos_look[361]; // 1 extra so we can store 0-360 inclusive
extern float sin_look[361]; // 1 extra so we can store 0-360 inclusive


void Build_Sin_Cos_Tables(void);

// math functions
int Fast_Distance_2D(int x, int y);
float Fast_Distance_3D(float x, float y, float z);



class t3dlib1
{
public:
	t3dlib1(void);
	~t3dlib1(void);
};

