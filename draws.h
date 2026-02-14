#ifndef _XSC_ASCII_PAINT
#define _XSC_ASCII_PAINT
#define __XSC_ASCII_PAINT_TOOLS__ 1 /* _XSC_ASCII_PAINT_TOOLS */
#define __DRAWS__ 1

#line 6 "[draws.h]"
#include <super/stdbasic.h>
#include <stdint.h>

#if XSCCONF_SUPRESS_WARNINGS <= DISABLED
#ifndef __STDCON__
#warning Please, include "stdcon.h" in order to "draws.h" work correctly.
#endif
#endif

/**
    Library Name: draws.h,
    stands for "ASCII drawing system".
    General Purpose Library? yes;
    Child-Library? no;
    Experimental Library? no.
**/


#if XSCCONF_CUSTOM_ATTRIBUTES <= DISABLED && XSCCONF_CUSTOM_DRAWS_ATTRIBUTES <= DISABLED
#define __DRAWS_NOTNULL
#else
#define __DRAWS_NOTNULL(N) xsc_notnull(N)
#endif

#if  XSCCONF_EXCLUSIVE_HDR >= ENABLED
typedef void draws;
#else
#define draws void
#endif

draws drawShape(int32_t _X, int32_t _Y, uint32_t _W, uint32_t _H, uint8_t _Ch, uint16_t SCTX[], uint16_t SCTY[]);
draws drawCircle(int _X, int _Y, uint _R, char _Ch);
draws freeCircle(int _X, int _Y, uint _W, uint _H, const char _Ch); /* [ALT] 'drawEllipse' */
draws paintCircle(int _X, int _Y, uint _R, char _Ch);
draws fillSquare(int _X, int _Y, uint _W, uint _H, const char _Ch);
draws drawSquare(int _X, int _Y, uint _W, uint _H, const char _Ch);
draws drawLine(int _X, int _Y, int _X2, int _Y2, const char _Ch);

#ifdef __STDCON__
#define __xsc_draws_get_val(_VAL) _VAL
#else
#define __xsc_draws_get_val(_VAL)
#endif

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef __STDCON__
#undef CursorPosition /* in case stdbasic.h added it for EMIT_ERROR first... */
#if !defined(XSC_WINDOWS)
#define CursorPosition(_x, _y) printf("\x1b[%d;%dH", _x, _y)
#define placeChar(_x, _y, _Char) (CursorPosition(_x, _y), putchar(_Char))
#else
#define CursorPosition(_x, _y)
#define placeChar(_x, _y, _Char)
#endif
#endif

/* stablish the drawing/painting commands. */
#define DRAWS_SIN (1)
#define DRAWS_COS (2)
#define DRAWS_TAN (3)
#define DRAWS_END (0)

#ifndef XSC_ASC_PAINT_ANGLES
#define XSC_ASC_PAINT_ANGLES
#define ANGLE_LEFT  DRAWS_SIN
#define ANGLE_RIGHT DRAWS_COS
#endif

#ifndef XSC_ASC_PAINT_LSHAPE
#define XSC_ASC_PAINT_LSHAPE
#define LSHAPE_TRIANGLE    DRAWS_END
#define LSHAPE_HALFSQUARE  DRAWS_SIN
#define LSHAPE_COSTRIANGLE DRAWS_COS, DRAWS_END
#endif

#if defined(__GNUC__) || defined(__GNUG__) || defined(__clang__)
#pragma GCC push_options
#pragma GCC optimize("03")
#pragma GCC debug("off")
#elif defined(_MSC_VER)
#pragma optimize( "t", on )
#pragma optimize( "g", on )
#endif

#if LANG_VERSION >= CC99 /* [CUT][REM] change to XSC_LANGVERSION */

#ifndef XSC_ASC_PAINT_ODD_SHAPES
#define XSC_ASC_PAINT_ODD_SHAPES
#define UnformattedShape1 (int16_t[4]){1,1,3,0}, (int16_t[3]){2,1,0}
#define UnnamedShape1 (int16_t[4]){1,2,1,0}, (int16_t[4]){1,1,1,0}
#define UnnamedShape2 (int16_t[4]){1,1,1,0}, (int16_t[4]){1,2,1,0}
#define UnnamedShape3 (int16_t[4]){1,2,1,0}, (int16_t[4]){1,2,1,0}
#define UnnamedShape4 (int16_t[5]){3,2,2,1,0}, (int16_t[5]){1,2,1,3,0}
#endif

#ifndef XSC_ASC_PAINT_MAIN_SHAPES
#define XSC_ASC_PAINT_MAIN_SHAPES
#define LineShapeX    (int16_t[3]){1,1,0},   (int16_t[1]){0}
#define LineShapeY    (int16_t[1]){0},       (int16_t[3]){1,1,0}
#define CrowbarShape  (int16_t[4]){2,2,2,0}, (int16_t[4]){1,2,1,0}
#define InfinityShape (int16_t[4]){1,1,1,0}, (int16_t[4]){1,2,1,0}
#define CircleShape   (int16_t[3]){1,1,0},   (int16_t[3]){1,2,0}
#define UCircleShapeX (int16_t[2]){2,0},     (int16_t[2]){1,0} /** Unformatted Circle Shape (Broken Circle) **/
#define UCircleShapeY (int16_t[2]){1,0},     (int16_t[2]){2,0} /** Unformatted Circle Shape (Broken Circle) **/
#define EightShape    (int16_t[4]){1,2,1,0}, (int16_t[4]){1,1,1,0}
#define DripShape(A)  (int16_t[4]){3,2,1,0}, (int16_t[4]){1,2,A,0}
#define CurveShape(A) (int16_t[4]){3,2,1,0}, (int16_t[2]){A,0}
#define LineShape     (int16_t[3]){1,1,0},   (int16_t[3]){1,1,0}
#define CrossShape    (int16_t[4]){1,2,1,0}, (int16_t[4]){2,1,2,0}
#endif

#else

#define _type_inline static const

#ifndef XSC_ASC_PAINT_ODD_SHAPES
#define XSC_ASC_PAINT_ODD_SHAPES
        _type_inline int16_t UnformattedShape1_0[4] = {1,1,3,0};
        _type_inline int16_t UnformattedShape1_1[3] = {2,1,0};
    #define UnformattedShape1 UnformattedShape1_0, UnformattedShape1_1

        _type_inline int16_t UnnamedShape1_0[4] = {1,2,1,0};
        _type_inline int16_t UnnamedShape1_1[4] = {1,1,1,0};
#define UnnamedShape1 UnnamedShape1_0, UnnamedShape1_1

        _type_inline int16_t UnnamedShape2_0[4] = {1,1,1,0};
        _type_inline int16_t UnnamedShape2_1[4] = {1,2,1,0};
#define UnnamedShape2 UnnamedShape2_0, UnnamedShape2_1

        _type_inline int16_t UnnamedShape3_0[4] = {1,1,3,0};
        _type_inline int16_t UnnamedShape3_1[4] = {2,1,0};
#define UnnamedShape3 UnnamedShape3_0, UnnamedShape3_1

        _type_inline int16_t UnnamedShape4_0[5] = {3,2,2,1,0};
        _type_inline int16_t UnnamedShape4_1[5] = {1,2,1,3,0};
#define UnnamedShape4 UnnamedShape4_0, UnnamedShape4_1

#endif

#ifndef XSC_ASC_PAINT_MAIN_SHAPES
#define XSC_ASC_PAINT_MAIN_SHAPES

    _type_inline int16_t LineShapeX_0[3] = {1,1,0};
    _type_inline int16_t LineShapeX_1[1] = {0};
#define LineShapeX LineShapeX_0, LineShapeX_1

    _type_inline int16_t LineShapeY_0[1] = {0};
    _type_inline int16_t LineShapeY_1[3] = {1,1,0};
#define LineShapeY LineShapeY_0, LineShapeY_1

    _type_inline int16_t CrowBarShape_0[4] = {2,2,2,0};
    _type_inline int16_t CrowBarShape_1[3] = {1,2,1,0};
#define CrowBarShape CrowBarShape_0, CrowBarShape_1

    _type_inline int16_t InfinityShape_0[4] = {1,1,1,0};
    _type_inline int16_t InfinityShape_1[3] = {1,2,1,0};
#define InfinityShape InfinityShape_1, InfinityShape_1

    _type_inline int16_t CircleShape_0[4] = {1,1,1,0};
    _type_inline int16_t CircleShape_1[3] = {1,2,1,0};
#define CircleShape CircleShape_0, CircleShape_1

    static int16_t DripShape_0[4] = {1,1,1,0};
    static int16_t DripShape_1[4] = {1,2,0,0};
#define DripShape(A) DripShape_0, DripShape_1[2] = (A)

    static int16_t CurveShape_0[4] = {3,2,1,0};
    static int16_t CurveShape_1[2] = {0,0};
#define CurveShape(A) CurveShape_0, CurveShape_1[1] = (A)

    _type_inline int16_t LineShape_0[3] = {1,1,0};
    _type_inline int16_t LineShape_1[3] = {1,1,0};
#define LineShape LineShape_0, LineShape_1

    _type_inline int16_t CrossShape_0[4] = {1,2,1,0};
    _type_inline int16_t CrossShape_1[4] = {2,1,2,0};
#define CrossShape CrossShape_0, CrossShape_1

#endif

#undef _type_inline

#endif

/* EOF pragmas */
#if defined(__GNUC__) || defined(__GNUG__) || defined(__clang__)
#pragma GCC push_options
#pragma GCC optimize("03")
#pragma GCC debug("off")
#elif defined(_MSC_VER)
#pragma optimize( "", on )
#endif

#if XSCCONF_DRAWS_BOUNDS > 0 && defined(__STDCON__)
#define _ANS_BOUNDS(_x, _y) _x < Console.W && _y < Console.H
#else
#define _ANS_BOUNDS(_x, _y) 1
#endif

#ifndef __STRINGS_H
#define __STRINGS_H_CHP_DEFINED 1 /* in case strings.h is not defined in the first place. */

void chprint(unsigned short _size, unsigned char _CHR)
{
    char* _strset = (char*)calloc(_size, sizeof(char));
    memset(_strset, _CHR, _size);
    printf("%s", _strset);
    free(_strset);
}

#endif

/* [C][R]
//draw.Line()
//draw.Square()
//draw.Circle()
//draw.Polygon()
//draw.FillSquare()
//draw.Iterations = ?
//draw.Char = ?
*/

typedef struct Properties {
    draws (*Line)();
    draws (*Circle)();
    float GFI;
    char LastChar;
    struct Position { int X; int Y; };
} draws_Properties;

draws_Properties draw = {
    .Line = drawLine,
    .Circle = drawCircle,
    .LastChar = 0x0,
    .GFI = 0.1f /* GFI = General Function Iteratations [ [+] = Iterate Less, [-] = Iterate More. ] */
};

/* [CUT]
//sin(x) = 0.707 (x = sqrt(2) / 2)
//sin(x) * 10^3 = 707
*/

/* works only if stdcon is included, and stdc-autoupdate and asc-autoupdate are enabled. */
#ifdef XSCCONF_UPDATE_DRAWS
xsc_section(".PreservedDrawing") /* [CUT] stored, allocated, preserved, change to allocated */
char* _AllocatedDrawing;

#define __DRAWS_UPDATE_CSBI __UPDATE_CSBI

#define __UPDATE_DRAWS \
                     draw.LastChar = C; \
                     draw.Position.X = _X; \
                     draw.Position.Y = _Y;
                     __DRAWS_UPDATE_CSBI

#define __UPDATE_DRAWS_ONLOOP /* update the drawing here. [UNC] */

#else

#define __DRAWS_UPDATE_CSBI (0)
#define __UPDATE_DRAWS (0)
#define __UPDATE_ON_LOOP (0)
#endif

/* [NOTE] if someday i find something better to name into __CXX_DECL than this,
  gonna replace __CXX_DECL with __CXX_DECL_LOOP
*/

xscs_draws
void drawLine(int _X, int _Y, int _X2, int _Y2, char _Ch) {
    /* X - cos
      Y - sin */
    const int16_t dx = _X2 - _X;
    const int16_t dy = _Y2 - _Y;
    int length = sqrt(dx * dx + dy * dy) * 1000;
    int angle = atan2(dy, dx) * 1000;
    __c89_decl_loop(T = 0);
    for (__c99_decl_loop(T = 0); T <= length * 0.001f; ++T) {
        int x = _X + (int)(T * cos(angle * 0.001f));
        int y = _Y + (int)(T * sin(angle * 0.001f));
        placeChar(x, y, _Ch);
    }
}

xscs_draws
static int _DRAWS_SCT_ (const int16_t SinCosTan[], const int16_t _Val)
{
    int _Result = 1000;
    __c89_decl;
    for(__c99_decl; SinCosTan[I] != 0; ++I)
    {
        _Result = _Result*(SinCosTan[I] == 1 ? sin(_Val) :
                            SinCosTan[I] == 2 ? cos(_Val) :
                             SinCosTan[I] == 3 ? tan(_Val) : 1);
    }
    return _Result;
}

xscs_draws
void drawShape(int32_t _X, int32_t _Y, uint32_t _W, uint32_t _H, uint8_t _Ch, uint16_t SCTX[], uint16_t SCTY[])
{
    /* Sin = 1; Cos = 2; Tan = 3; End = 0 / [> 3]; */

#ifdef __STDCON__
    const int_fast32_t X0 = GlobalApi.Coords.X, Y0 = GlobalApi.Coords.Y;
#else
    const int_fast32_t X0 = NULL, Y0 = NULL;
#endif

    _Y = _Y >> 1;
    _H = _H >> 1;
    /* _W * _H * (_av <= 15 ? _av <= 10 ? 4 : 3 : 2) */
    /** [NOTE][CUT] _W * _H / (0.01 * (I * 0.1)) --Original **/
    /* _R * _R * (1 / (_R * 0.1f)) */
    /* _W * _H * (1 / (_av * 0.1f)) */
    int CX, SY;
    int B = 0;
    __c89_decl;
    for(__c99_decl; I < _W * _H * (1 / (((_W + _H) >> 1) * (0.133f - draw.GFI))); ++I, ++B)
    {
        CX = _X + (_DRAWS_SCT_(SCTX, I) * 0.001f) * _W;
        SY = _Y + (_DRAWS_SCT_(SCTY, B) * 0.001f) * _H;
        if(CX >= 0 && SY >= 0 && _ANS_BOUNDS(CX, SY)) {
            placeChar(CX, SY, _Ch);
        }
    }
    CursorPosition(X0, Y0);
}

/* Instruction set:
//cos(((I % 360) + 1) * (M_PI / 90)) --Boomerang

//recommended minimal number of iterations: 2-3
//1 iteration has 5% - 8% mistake boundary.
//2 iterations has 1% - 3% mistake boundary.
//3 iterations or more has < 1% mistake boundary.

//Iterations: [> 15] = 1, [< 15] = 2.
//by Default, The Number of Iterations Is Going To be (1): Itself + 0.50f;

//f(W, H)
//f(30, 30) = ~0.1s : 30px/30px
//f(50, 50) = ?s : 52px/52px
*/

xscs_draws
void drawCircle(int _X, int _Y, uint _R, char _Ch)
{
    __DRAWS_UPDATE_CSBI;
    _Y = _Y >> 1;
    int CX, SY;
    __c89_decl;
    for(__c99_decl; I < _R * _R * (1 / (_R * draw.GFI)); ++I) {
        CX = _X + cos(I * 4.815f) * _R * 0.54f;
        SY = _Y + sin(I * 4.815f) * (_R >> 1) * 0.54f;
        if(CX >= 0 && SY >= 0 && _ANS_BOUNDS(CX, SY)) {
            placeChar(CX, SY, _Ch);
        }
    }
}

xscs_draws
void paintCircle(int _X, int _Y, uint _R, char _Ch)
{
    /* 0 = ~0.055; [R=32] */
    /* 1 = ~0.056-0.057; */
    __DRAWS_UPDATE_CSBI;
    _Y = _Y >> 1;
    int CX, SY;
    __c89_decl;
    for(__c99_decl; I <= 360; ++I) {
        CX = _X + cos(I * M_PI / 180) * _R * 0.54f;
        SY = _Y + sin(I * M_PI / 180) * (_R >> 1) * 0.54f;
        if(CX >= 0 && SY >= 0 && _ANS_BOUNDS(CX, SY)) {
            placeChar(CX, SY, _Ch);
        }
    }

}

xscs_draws
void freeCircle(int _X, int _Y, uint _W, uint _H, const char _Ch)
{
    _H = _H >> 1;
    _Y = _Y >> 1;
    int CX, SY;
    __c89_decl;
    for(__c99_decl; I < _W * _H * (1 / (((_W + _H) >> 1) * draw.GFI)); ++I) {
        CX = _X + cos(I * 4.815f) * _W * 0.54f;
        SY = _Y + sin(I * 4.815f) * _H * 0.54f;
        if(CX >= 0 && SY >= 0 && _ANS_BOUNDS(CX, SY)) {
            placeChar(CX, SY, _Ch);
        }
    }
}

char* _loct; /* _location */

void fillSquare(int _X, int _Y, uint _W, uint _H, const char _Ch) {
    _H = _H >> 1;
    _Y = _Y >> 1;
    _W = _W - 0.4f;
    _loct = (char*)malloc(_W * sizeof *_loct);
    memset(_loct, _Ch, _W);
    _loct[_W] = '\0';
    __c89_decl_loop(I = _Y);
    for (__c99_decl_loop(I = _Y); I < (_Y + _H); ++I) {
        CursorPosition(_X, I);
        printf("%s", _loct);
    }
    free(_loct);
}

xscs_draws
void drawSquare(int X, int Y, uint W, uint H, const char _Ch) {
    H = H >> 1;
    Y = Y >> 1;
    _loct = (char*)calloc(W, sizeof *_loct);
    memset(_loct, _Ch, W);
    CursorPosition(X, Y);
    printf("%s", _loct);
    CursorPosition(X, Y + H);
    printf("%s", _loct);
    free(_loct);
    _loct = (char*)calloc(H, sizeof *_loct);
    memset(_loct, _Ch, H);
    __c89_decl_loop(I = Y);
    for(__c99_decl_loop(I = Y); I < H; ++I) {
        CursorPosition(X, I);
        putchar(_loct[(I - X)]);
    }
    __c89_decl_sr_loop(I = Y);
    for(__c99_decl_loop(I = Y); I < H; ++I) {
        CursorPosition(W-1, I);
        putchar(_loct[(I - X)]);
    }
    free(_loct);
}

#undef draws
#undef _ANS_BOUNDS
#undef __xsc_draws_get_val

#include <super/sub/stdcrt.h>

#endif /* _XSC_ASCII_PAINT */
