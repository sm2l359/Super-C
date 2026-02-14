#ifndef __SCIOPAK_H__
#define __SCIOPAK_H__
#define __SCIOPAK_H__DEFINED__

#include <super/stdbasic.h>

#line 8 "[sciopak.h]"

/** (R) - This File Is Partially Free / Safe For Use.
*
*    -This File Is Restricted As Part of Super (C) Development Version,
*     And Can Be Used Under These Circumstances:
*
*    > debugging, testing, re-implementation of older functionalities
*      and as a normal super-C library file;
*
*    > snapshot for analysis, appraisal of future implementations
*      and as preview of features that are going to be added in future.
*
*    > please, note that this file is still not officially released,
*      totally Safe for use, and may have some weird / broken features.
*
*   -FILE-NAME- : SCIOPAK.H
**/


#if __INLINE_COMMENT__
//this is a special header file used for experiments.
//some features that go through this file may or may not be
//implemented in the final SuperC-Library.

//The same can also be used for debugging and compatibility with the First Build of the Original "XCD/XCM".

//Also, some preprocessor directives and functions that are still uncertain
//in which part of the Library should be included are included in this file
//as a temporary Solution.

//In Conclusion, this special "package" is like the draft of the whole SuperC set,
//this is also where the snapshots of future versions are mostly going to be.

//and while this file is mostly used to design features to push the boundaries of the c language,
//other uses said previously include: debugging, testing, experimenting, compatibility w/ build-1, etc.

//this is also where the removed content from build-1 goes before being re-implemented.

//-how does that implementation process works?
//the content missing from build-1 is re-added,
//the content is then refined, optimized, and then is officially added to the library.
#endif

/**
    Package Name: sciopak.h,
    (originally) stands for "super-C input/output pack".
    General Purpose Package? depends; read the documentation for more information;
    Child-Package? no;
    Experimental Package? yes.
**/

////////////////////////////////////////////////
#if 0

#define draws void
/* sociopack.h lol */
#define endl putchar('\n');
#define SNULL ""
#define bflip ^= 1
#define boolean bool
#define final const
#ifdef __KWPACK__
typedef histring high_string;
typedef lostring low_string;
#else
#define Function void
#define bin short
#endif
#define cycle resetCursor();

////////////////////////////////////////////////
/* [TEST] */
char analzek(final char externkey_) /* optional showk 1 = true 0 = false */
{
    char _k = kbhit() ? getch() : 0;
    return !externkey_ ? _k : externkey_ == _k ? 1 : 0;
}
////////////////////////////////////////////////

/* [TEST] */
typedef struct { void (*print)(void); } Object;
void printFunction(){ printf("hi!!11!!!1!"); }

Object function1(char b)
{
    putchar(b);
    Object obj = {printFunction};
    return obj;
}

/* [TEST] */
void p_clear(int _Sz) { //p-clear stands for provisional clear

    if(_Sz == NULL) _Sz = 120;
    char* _shit = (char*)calloc(_Sz, sizeof(char));
    memset(_shit, VK_SPACE, _Sz);
    printf("\r%s\r", _shit);
    free(_shit);

}

/* perhaps i should create a typedef called evoid (extern void)
    and add it for kwpack.h
*/

/*
    it means that a type is ... only; not that is ... .

    [REM]
    (forgot what i was gonna add here.)
    (i will probably remember since i already wrote that down.)
    (just under different words.)
    (maybe i wanted to refer to the switch to the multi-line
     comment model; nah i don't think so.)

*/

//stdcon-t.h [BUILD1]:
//typedef void stdconGetter;
//typedef void stdconSetter;
//typedef int stdconInt;
//typedef byte stdconByte;
//this would be more fitting..

#endif /* 0 */

#if 0
#include <-super->
#endif

#include <super/draws.h>

#if XSCSET_BUILD1 == 0

    #define CURX GlobalApi.Screen_Info.dwCursorPosition.X
    #define CURY GlobalApi.Screen_Info.dwCursorPosition.Y
    #define restoreBox __restore_box_defaults__()

    #ifdef _WIN32
    #define syscolor(_COL) system("color " #_COL);
    #else
    #define syscolor(_COL)
    #endif

    //almost certain to say this doesn't work.
    //(the idea here is the create new types of variables with different sizes)
    //example: create_dtype(trinary_t, int, 3) //should gen a 3-byte type;
    //even though this is technically possible, obviously this is not doable.

    //at this point, this is
    //mostly experimentation.

    /* [TEST] */
    #define create_dtype(name, type, size) XCM_T_MAKENEWTYPEALIAS(name, type, size)
    #define XCM_T_MAKENEWTYPEALIAS(type_name, type, type_size) \
    volatile typedef struct _new_t{ \
        type e : type_size \
    } type_name; \
    type_name type_name##_t (type type_name##_v) { \
        type_name _R = {type_name##_v}; \
        char * _dt = #type_name; \
        if(_R.e > (type_size*2) -1) \
        { \
            sleep(2); \
            printf("\x1b[31m[ERROR]\x1b[0m -> \x1b[0;4m0x5C005 (Data Type '%s' exceeds it's maximum size)\x1b[0m", _dt); \
            exit(0x5C002); \
        } \
        return _R; \
    }

#ifdef __STDCON__

void ConsoleMode(byte _MODE, short CW, short CH)
{
    if(CW < 1 || CW > 9999 || CH > 9999 || CH < 1) (CW = 120, CH = 30);
    char _OUT[48] = "";
         if(_MODE == 0)sprintf(_OUT, "mode CON: COLS=%i LINES=%i", CW, CH);
    else if(_MODE == 1) strcpy(_OUT, "mode CON: COLS=120 LINES=9999");
    else if(_MODE == 2) strcpy(_OUT, "mode CON: COLS=9999 LINES=30");
    else if(_MODE == 3) strcpy(_OUT, "mode CON: COLS=9999 LINES=9999");
    system(_OUT);
}

void EditConsoleSize(uint16_t CONSL_WID, uint16_t CONSL_HEI)
{
    #ifdef XSC_WINDOWS
        SMALL_RECT R = {0, 0, CONSL_WID, CONSL_HEI};
        SetConsoleWindowInfo(GlobalApi.Handler, 1, &R);
        ConsoleMode(0, CONSL_WID, CONSL_HEI);
        EditConsoleSizeAE(CONSL_WID, CONSL_HEI);
    #else
        EditConsoleSizeAE(CONSL_WID, CONSL_HEI);
    #endif
}
#define CURX GlobalApi.Screen_Info.dwCursorPosition.X
#define CURY GlobalApi.Screen_Info.dwCursorPosition.Y
#define restoreBox __restore_box_defaults__()

#ifdef _WIN32
#define syscolor(_COL) system("color " #_COL);
#else
#define syscolor(_COL)
#endif

void EditConsoleSizeAE(uint16_t CONSL_WID, uint16_t CONSL_HEI) {
    printf("\x1b[8;%d;%dt", CONSL_HEI, CONSL_WID);
}

void ConsoleVisibility(_Bool _VIS) {
    ShowWindow(Console.GlobalApi.Window_Handler, !_VIS ? 0:1);
}

void SetResizableCon(_Bool _BOX, _Bool _WIN) {
    LONG GWLONG = GetWindowLong(Console.GlobalApi.Window_Handler, -16);
    GWLONG &= _BOX ? GWLONG : ~WS_MAXIMIZEBOX;
    GWLONG &= _WIN ? GWLONG : ~WS_THICKFRAME;
    SetWindowLong(Console.GlobalApi.Window_Handler, -16, GWLONG);
}

void EditConsole(short Width, short Height, _Bool SetResizable, _Bool Visibility, ubyte _Color, short CurSize, _Bool CurVisibility, ubyte SetMode, ...) {

    ConsoleVisibility(Visibility);
    SetResizableCon(SetResizable, SetResizable);
    EditConsoleSize(Width, Height);
    Color(_Color);

    EditCursor(CurVisibility, CurSize);
}

//still thinking if it is worth it to re-adding that cursor push/pop system.
/* you know what? gonna do it. */
/* but it's gonna be in 1.4 and it's gonna be like this: */

/* CursorPosition_psp(_Op, ...) _Op = Operation */
/* CursorPosition_psp(CP_PUSH, 32, 32) _Op = Operation */
/* CursorPosition_psp(CP_POP) */

#endif

#if defined(_XSC_ASCII_PAINT)
const ubyte _DEF_CHRS[8] = {0xC9, 0xCD, 0xBB, 0xBA, 0xBC, 0xCD, 0xC8, 0xBA};
/*/*/ ubyte _ASC_BXCH[8] = {0xC9, 0xCD, 0xBB, 0xBA, 0xBC, 0xCD, 0xC8, 0xBA};

typedef struct { int X, Y, W, H; } SetBox;


int CreateBox(SetBox BOX) {
    int x = BOX.X, w = BOX.W+x-1;
    int y = BOX.Y, h = BOX.H+y-1;
    placeChar(x, y, _ASC_BXCH[0]);
    while(++x < w) putchar(_ASC_BXCH[1]);
    placeChar(x, y, _ASC_BXCH[2]);
    while(++y < h) placeChar(x, y, _ASC_BXCH[3]);
    placeChar(x, y, _ASC_BXCH[4]);
    while(--x > BOX.X) placeChar(x, y, _ASC_BXCH[5]);
    placeChar(x, y, _ASC_BXCH[6]);
    while(--y > BOX.Y) placeChar(x, y, _ASC_BXCH[7]);
    return BOX.X + BOX.Y + w + h;
}

draws CreateInputBox(SetBox BOX, char * _INPUT_TEXT, char * _RLT, ubyte _MAX);


////////////////////////////////////////////////
    #ifdef resetCursor
      #define _TRANSIT_RESET resetCursor()
    #else
      #define _TRANSIT_RESET printf("\x1b[0;0H")
    #endif

    #if 0

    //Original Reversion transition and standarized transition.//
    Function revtransit(int _COL, int _SZW, int _SZH) {
        Color(0x7E);
        resetCursor();
        for(int I = 0; I < _SZW * _SZH; ++I) {
            putchar(0x20);
            usleep(999);
        }
        Color(_COL);
        for(int I = 0; I < _SZW * _SZH; ++I) {
            putchar(0x20);
            usleep(999);
        }
        resetCursor();
    }


    Function transit(int _COL, int _SZW, int _SZH) {
        Color(0x7E);
        resetCursor();
        for(int I = 0; I < _SZW * _SZH; ++I) {
            putchar(0x20);
            usleep(999);
        }
        Color(_COL);
        resetCursor();
        for(int I = 0; I < _SZW * _SZH; ++I) {
            putchar(0x20);
            usleep(999);
        }
        resetCursor();
    }

    #else

    Function revtransit(ubyte _COL1, ubyte _COL2, ushort _SZH) {
        unsigned char _lp = 0;
        unsigned long _prop = Console.W * _SZH;
        if(_COL1 == NULL) _COL1 = 0x3f;
        if(_COL2 == NULL) _COL2 = 0x2f; //original color: 0x7E
        Color(_COL2);
        resetCursor();
        for(int I = 0; I < _prop; ++I) {
            putchar(0x20);
            if(_lp == 0 && I == _prop -1) {
                _lp = 1;
                I = 0;
                Color(_COL1);
            }
        }
        resetCursor();
    }

    Function transit(ubyte _COL1, ubyte _COL2, ushort _SZH) {
        if(_COL1 == NULL) _COL1 = 0x3f;
        if(_COL2 == NULL) _COL2 = 0x2f; //original color: 0x7E

        ubyte _REV_COL1 = (_COL1 << 4) | (_COL1 >> 4);
        Color(_COL2);
        resetCursor();
        unsigned char _lp = 0;
        unsigned long _prop = (Console.W * _SZH);
        for(int I = 0; I < _prop +1; ++I) {
            putchar(0xDB);
            if(!_lp && I == _prop) {
                (I = !(_lp = 1));
                Color(_REV_COL1);
                resetCursor();
            }
        }
        Color(_COL1);
        resetCursor();
    }

    #endif
#include <super/arrays.h>
Function __restore_box_defaults__ () {
    for(int I = 0; I < arrelm(_DEF_CHRS); ++I)
        _ASC_BXCH[I] = _DEF_CHRS[I];
}


draws FillBox(SetBox BOX) {
    GetCursorPosition();
    CreateBox(BOX);
    drawSquare(BOX.X +2, BOX.Y +2, BOX.W -2, BOX.H -2, VK_SPACE);
    CursorPosition(CURX, CURY);
}
xsc_forceinline draws DestroyBox(SetBox CLR){ drawSquare(CLR.X +1, CLR.Y +1, CLR.W +1, CLR.H +1, VK_SPACE); }
draws ClearBox(SetBox _KILL) {
    memset(_ASC_BXCH, 0x20, sizeof *_ASC_BXCH);
    CreateBox(_KILL);
    restoreBox;
}
#endif

#endif /* XSCSET_BUILD1 */

#ifdef __ARRAYS_H
#if 0
/* [TEST] */
xsc_nonull(1) xsc_hot Function aprintf(const String restrict _STR, ...)
{
    if(strchr(_STR, '%') == NULL) {
        fprintf(stdout, "%s", _STR);
        return;
    }

    char* _TAR = (char*)malloc(strlen(_STR) * sizeof(char));
    uint16_t _ArrSize = 0;
    bool _OutputMode = 0;

    /*This Function is Still In Development and
    can (And Will) be Improved In The Future.*/

    va_list VA;

    strcpy(_TAR, strchr(_STR, '%'));

    for(int I = 0; _STR[I] != '%'; ++I)
    {
        putchar(_STR[I]);
    }

    if(!isdigit(_TAR[1]))
    {
        _ArrSize = 5;
    }
    else {
        while(!ispunct(_TAR[1]))
        {
            _ArrSize = _ArrSize * 10 + (_TAR[1] - '0');
            strcpy(_TAR +1, _TAR +2);
        }
        _OutputMode = (_TAR[1] == '*');
        strcpy(_TAR +1, _TAR +2);
    }

    va_start(VA, _ArrSize);

    const void* _BUF_GENERAL = va_arg(VA, const void*);

    putchar('(' * !_OutputMode);

    for(int I = 0; I < _ArrSize; ++I)
    {
        if(_OutputMode) printf("[%u]: ", I);
        /* */if(!strcasecmp(_TAR, "%by"))printf("%u", *((ubyte*) _BUF_GENERAL + I));
        else if(!strcasecmp(_TAR, "%g")) printf("%g", *((double*) _BUF_GENERAL + I));
        #if XSC_OPTIMIZE <= 2
        else if(!strcmp(_TAR, "%LF"))printf("%lf",*((double*) _BUF_GENERAL + I));
        else if(!strcmp(_TAR, "%F")) printf("%f", *((float*) _BUF_GENERAL + I));
        else if(!strcmp(_TAR, "%lf"))printf("%g", *((double*) _BUF_GENERAL + I));
        else if(!strcmp(_TAR, "%f")) printf("%g", *((float*) _BUF_GENERAL + I));
        #else
        else if(!strcasecmp(_TAR, "%LF"))printf("%lf",*((double*) _BUF_GENERAL + I));
        else if(!strcasecmp(_TAR, "%F")) printf("%f", *((float*) _BUF_GENERAL + I));
        #endif
        else if(!strcasecmp(_TAR, "%b")) printf("%d", *((_Bool*) _BUF_GENERAL + I));
        else if(!strcasecmp(_TAR, "%c")) printf("%c", *((char*) _BUF_GENERAL + I));
        else if(!strcasecmp(_TAR, "%s")) printf("%s", *((char**) _BUF_GENERAL + I));
        #if XSC_OPTIMIZE <= 2
        else if(!strcmp(_TAR, "%P")) printf("%p", _BUF_GENERAL + I);
        else if(!strcmp(_TAR, "%p")) printf("%X", _BUF_GENERAL + I);
        #else
        else if(!strcasecmp(_TAR, "%p")) printf("%X", _BUF_GENERAL + I);
        #endif
        else /* ***************** */ printf(_TAR, *((long*)_BUF_GENERAL + I));
        if(!_OutputMode) printf("%s", I == _ArrSize -1 ? ")" : ", "); else putchar('\n');
    }

    va_end(VA);
    free(_TAR);
}
#endif
#endif

///-////////////////NOTE//////////////////-///

    //both mode -
    //editing the string and
    //at execution doesn't allow for
    //keeping the original string without
    //creating a backup.

    //theres no actual point in using both methods for the string,
    //its just a waste of space.

    //because if the string is already going to be modified at function
    //execution via pointer, there's no need to return that same already
    //modified string.

    //the returning method only happens to be way more convenient.
    //because you got to keep the original string without the need
    //to create a backup.

    //EDIT: forget what i said about the backup thing earlier.

    //- + pointer directed result. - +

    //-occupies less size.
    //-perfect if you don't need to re-use the original string.

    //-Unideal order of modification events.
    //-you need to create a backup for the original string.
    //-pontentially unsafer.

    //+ - function directed result. - +

    //-no need to create a backup string.
    //-ideal order of modification: original String -> new String -> modified copy of String.
    //-pontentially safer.


    //-function orinted: -space, or -speed

    //-occupies more size because of function data type.
    //-can't do _Str1 = strfunc1(_Str1); needs to do strcpy(_Str1, strfunc1(_Str1))

    ///-///////////////////////////////////////-///

    //XSCCONF_DISABLE_ERROR_CODES - Disables all error codes for optimization.
    //-can be used after all the program has been fully built.

    ///-///////////////////////////////////////-///

    //code_test_debugger("abr", -DEBUGGER_MODE)
    //code_test_debugger("abr", DEBUGGER_MODE)

    //-the '-' sign changes the dynamic of the
    //code.

    ///-///////////////////////////////////////-///

    //Name Idea Dump Area:

    //lbr, lbrcrt, lbrstd, *scpot,

    //<lbr.h>

    //* = the name has no particular meaning at all
    //and it's not an abbreviation.

    //NIP = NothingInParticular. it means the content
    //has no particular meaning at all but it might
    //be an abbreviation.

#include <super/sub/stdcrt.h>

#endif /* __SCIOPAK_H__ */
