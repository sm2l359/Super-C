#ifndef __STDCON__
#define __STDCON__
#include <super/stdbasic.h>

#line 6 "[stdcon.h]"

/**
    Package Name: stdcon.h / stdcon,
    stands for "standard-console".
    General Purpose Package? yes;
    Child-Package? no;
    Experimental Package? no.
**/

#if XSC_OS == OsID_WINDOWS
typedef struct _GlobalWinStats GlobalInterface;
#elif XSC_OS == OsID_LINUX
typedef struct _GlobalLnxStats GlobalInterface;
#elif XSC_OS == OsID_MAC
typedef struct _GlobalMacStats GlobalInterface;
#else
typedef struct _GlobalStats GlobalInterface;
#endif

#if XSC_OS == OsID_WINDOWS

struct _GlobalWinStats {
    HANDLE Handler;
    POINT Point;
    COORD Coords;
    HWND Window_Handler;
    CHAR_INFO Char_Info;
    CONSOLE_SCREEN_BUFFER_INFO Screen_Info;
};

#if LANG_VERSION >= CC99
GlobalInterface GlobalApi = {0};

#else
GlobalInterface GlobalApi = {NULL,NULL,NULL,NULL,NULL,NULL};
#endif

#elif XSC_OS == OsID_LINUX

struct _GlobalLnxStats {
    struct COORD {
        int16_t X, Y;
    } Coords;
};

/* --> [CUT HERE] */
#ifndef NCURSES_LINKED /* <--- Or change the value to 0 */
# warning ____________________________________________________________
# warning | Remember To Link the ncurses Library with '-lncurses' or |
# warning | '-lncursesw' in Order To Work, when Finished, create a   |
# warning | define called 'NCURSES_LINKED' and place it before this  |
# warning | library or remove this section of the header instead.    |
# warning ------------------------------------------------------------
#endif
/* [CUT HERE] */

#elif XSC_OS == OsID_MAC

struct _GlobalMacStats {

};

#if LANG_VERSION >= CC99
GlobalInterface GlobalApi = {0};
#else
GlobalInterface GlobalApi = {NULL};
#endif

#else

typedef char CHARACTER_DT;
typedef void* FUNCTION_DT;

struct _GlobalStats {
    CHARACTER_DT CHR_DATA; /* store used/read character on buffer */
    FUNCTION_DT FUNC_DATA; /* store a function on buffer so it can be used by one or multiple functions. */
};

    #if LANG_VERSION >= CC99
    GlobalInterface GlobalApi = {0};
    #else
    GlobalInterface GlobalApi = {NULL};
    #endif

#endif

typedef struct _STDCON {
    /* insert global api here as a sub struct */
    GlobalInterface GlobalApi;
    /* insert all stdcon functions here */
    int W, H;
    int w, h;
    int X, Y;
    int x, y;
    int CX, CY;
    uchar Color;
} STDCON;

STDCON Console;

#define __STDCON __extpack(xscs_stdcon)

/*
// / / / / printfln() / / / / //
*/
#ifdef XSC_LINUX
    #define _sysprintfln89 int printwln(char * _Main, ...)
    #define _sysprintfln99(_Main, ...) printw(_Main "\n", __VA_ARGS__)
#else
    #define _sysprintfln89 int printfln(char * _Main, ...)
    #define _sysprintfln99(_Main, ...) printf(_Main "\n", __VA_ARGS__)
#endif

#if C_VERSION >= CC99
        #define printfln(_Text, ...) _sysprintfln99(_Text "\n", __VA_ARGS__)
    #ifdef XSC_LINUX
        #define printwln(_Text, ...) printfln(_Text, __VA_ARGS__)
    #endif
#else
    __STDCON _sysprintfln89;
#endif /* C_VERSION */

/* __xsc_ignoreparam(), __xsc_iparam(), __xsc_useparam() */
__STDCON void GetCursorPosition(__xsc_decideparam(int * _x, int * _y));
__STDCON void GetConsoleStats();
__STDCON void CursorPosition(uint _x, uint _y) xsc_hot;
__STDCON void CursorPositionAE(uint _x, uint _y) xsc_hot;
__STDCON void placeChar(const uint _x, const uint _y, const char _Char) xsc_hot;
__STDCON void placeText(const uint _x, const uint _y, const String restrict _Text, ...);
__STDCON void EditCursor(_Bool _Visibility, short _Size) xsc_optimize(02);
__STDCON void ActivateAE();
__STDCON char stdconOS();
__STDCON char conch(short _X, short _Y);
__STDCON char* stdconOSName();
__STDCON void xclear();
__STDCON void xclearln(uint16_t _lineBeg, uint16_t _lineEnd);

/** Alternative Spellings For Functions (usually related to the first uppercase letter). **/
#if !defined(XSC_STDC_ALT) && XSCCONF_FUNCTION_ALT_SPELLINGS >= ENABLED
    #define XSC_STDC_ALT
    /* EditCursor is redefined for compatibility reasons. */
    #define XClear() xclear()
    #define editCursor(_Visibility, _SIZE, ...) EditCursor(_Visibility, _SIZE)
    #define StdconOSName() stdconOSName()
    #define getCursorPosition GetCursorPosition
    #define getConsoleStats GetConsoleStats
    #define Color256(_256Color) ColorAE(_256Color)
#endif


#if defined(XSC_WINDOWS)

char _stdc_main_intro = 1;

void __STDCON_AUTO__() {

        GlobalApi.Handler = GetStdHandle(STD_OUTPUT_HANDLE);
        GlobalApi.Window_Handler = GetConsoleWindow();
        #if XSCCONF_ANSI_ESCAPE >= ENABLED
            #if XSCSET_OPTIMIZE <= XSCOPT_OPTIMIZELEVELI
                system("");
            #else
                ActivateAE();
            #endif
        #endif
        GetConsoleStats();

        #if XSCCONF_STDCON_NOCLEANUP <= DISABLED
        clear;
        #endif

        Console.GlobalApi = (GlobalApi);

        /* beyond this point, everything must be related to the intro. */

        if (_stdc_main_intro == 0) {
            return;
        }

        #define is_kbhit _sh_shared_len /* alias for the global shared variable. */

        #if XSCCONF_SUPER_C_SPLASH_SCREEN >= ENABLED
        if(!setlocale(LC_ALL, "en_US.UTF-8")) {
            SetConsoleOutputCP(CP_UTF8);

            FILE* _intro = fopen(
                "ILM.txt",
                "rb"
                );

            fseek(_intro, 0, SEEK_END);
            char* _introIMage = (char*)calloc(ftell(_intro), sizeof *_introIMage);
            rewind(_intro);


            is_kbhit = 0;
            int _Ln;
            int _Col;
            char _Mod;

            _Mod = 1;
            _Ln = 0;
            _Col = 0;

            while(fgets(_introIMage, (_Mod == 0 ? 120 * sizeof(char) : sizeof(_introIMage)), _intro)) {
                printf("%s", _introIMage);

                if(!XSCCONF_READ_LICENSE && _Ln >= 15) break;

                if(is_kbhit == 0) {
                    if(_Mod == 0) usleep(50000);
                    else          usleep(30000);
                }

                if(kbhit()) {
                    is_kbhit = 1;
                }

                if(!XSCCONF_READ_LICENSE) {
                    if(_Col >= 30) { ++ _Ln; _Col = 0; };
                    ++_Col;
                }
            }

            free(_introIMage);
            SetConsoleOutputCP(CP_WINANSI);

            fclose(_intro);

        } else {
            printf("\t\t\t[error while playing the intro.] (Couldn't Load UTF-8)");
        }
        /* beep. (remember). */

        sleep(3);
        #endif

        #undef __is_kbhit

        #if XSCCONF_STDCON_NOCLEANUP >= ENABLED
        GetCursorPosition(&Console.CX, Console.CY);
        xclearln(0, Console.CY);
        #endif

}

#elif defined(XSC_LINUX)

void __STDCON_AUTO__(void) {

        #if (XSC_OS == OsID_LINUX || XSC_OS == OsID_MAC) && !defined(NCURSES_LINKED)

            void* nc_handler = dlopen("libncurses.so.6", RTLD_LAZY);

            if (!nc_handler) {
                printfln(
                        #if XSCCONF_ANSI_ESCAPE >= ENABLED
                        "\x1b[31;4mError loading ncurses:\n__________________\n%s\x1b[0m",
                        #else
                        "Error loading ncurses:\n__________________\n%s",
                        #endif
                        dlerror());
                getchar();
                return;
            }

            //printw_sc (*xsc_printw)() = dlsym(nc_handler, "printw");
            //xsc_printw("%i", 55);
            //*(void**)(&func) = dlsym(nc_handler, "func");
            xsc_initscr = dlsym(nc_handler, "initscr");
            xsc_stdscr = dlsym(nc_handler, "stdscr");
            xsc_curs_set = dlsym(nc_handler, "curs_set");
            xsc_addch = dlsym(nc_handler, "addch");
            xsc_addstr = dlsym(nc_handler, "addstr");
            xsc_printw = dlsym(nc_handler, "printw");
            xsc_vwprintw = dlsym(nc_handler, "vwprintw");
            xsc_move = dlsym(nc_handler, "move");
            xsc_wmove = dlsym(nc_handler, "wmove");
            xsc_refresh = dlsym(nc_handler, "refresh");
            xsc_getch = dlsym(nc_handler, "getch");
            xsc_raw = dlsym(nc_handler, "raw");
            xsc_cbreak = dlsym(nc_handler, "cbreak");
            xsc_nocbreak = dlsym(nc_handler, "nocbreak");
            xsc_getyx = dlsym(nc_handler, "getyx");
            xsc_endwin = dlsym(nc_handler, "endwin");
        #endif /* (XSC_OS == OsID_LINUX || XSC_OS == OsID_MAC) && !defined(NCURSES_LINKED) */


        xsc_initscr();

        #if defined(XSC_MAC)
        xsc_curs_set(1);
        #endif
        Console.GlobalApi = (GlobalApi);

        /* __stdcn_Intro(); (fake function) */

        #if XSCCONF_SUPER_C_SPLASH_SCREEN >= ENABLED
        FILE* _intro = fopen(
                "C:\\Program Files\\CodeBlocks\\MinGW\\x86_64-w64-mingw32\\include\\super\\s\\fp.txt",
                "rb"
                );

        fseek(_content, 0, SEEK_END);
        char* _introIMage = (char*)calloc(ftell(_intro), sizeof(char));
        rewind(_intro);

        while(fgets(_introIMage, sizeof(_introIMage), _intro)) {
            printf("%s", _introIMage);
            usleep(30000);
        }

        fclose(_intro);

        #endif /* XSCCONF_SUPER_C_SPLASH_SCREEN */
}

#else

void __STDCON_AUTO__() {

}

#endif

#if XSCCONF_HEADER_XTD <= DISABLED
 typedef void stdcon;
 typedef  int stdcon_int;
 typedef char stdcon_byte;
#else
 #define stdcon void
 #define stdcon_int int
 #define stdcon_byte char
#endif

/* OS Standard printf model */
/* for oses that use other models that are derivative from the conventional model. */
#if C_VERSION > CC99
    #if defined(XSC_WINDOWS)
        #define _osprintv(_Text, ...) vprintf(_Text, __VA_ARGS__)
    #elif defined(XSC_LINUX) || defined(XSC_MAC)
        #define _osprintv(_Text, ...) vwprintw(_Text, __VA_ARGS__)
    #else
        #define _osprintv(_Text, ...) printf(_Text, __VA_ARGS__)
    #endif
#endif

STDCON Console = {
    #ifdef XSC_LINUX
    .GlobalApi = {0},
    #else
    .GlobalApi = &GlobalApi,
    #endif
    .Color = 0x07
};

const typedef struct _CURSOR_STRUCT {

    int Full, DefaultSz, Block;
    _Bool Show, Hide, Static, Moving;

} StdCursor;

#if defined(XSC_WINDOWS)
    #define CURSOR_VALS 100, 0, 50, 1, 0, 1, 0
#elif defined(XSC_LINUX)
    #define CURSOR_VALS 100, 0, 50, 1, 0, 1, 0
#elif defined(XSC_MAC)
    #define CURSOR_VALS 100, 0, 50, 1, 0, 1, 0 /* temp. switch to the proper values based on the OS later. */
#else
    #define CURSOR_VALS 0, 0, 0, 0, 0, 0
#endif

StdCursor Cursor = { CURSOR_VALS };

#if (XSC_OS == OsID_LINUX || XSC_OS == OsID_MAC)

    #if !defined(NCURSES_LINKED)
        #define initscr() xsc_initscr()
        #define stdscr xsc_stdscr
        #define curs_set(_Mod) xsc_curs_set(_Mod)
        #define addch(_Ch) xsc_addch(_Ch)
        #define addstr(_Str) xsc_addstr(_Str)
        #define printw(...) xsc_printw(__VA_ARGS__) /* will not work with C89 */
        #define vwprintw(_Win, _Format, ...) xsc_vwprintw(_Win, _Format, __VA_ARGS__) /* will not work with C89 */
        #define move(_y, _x) xsc_move(_y, _x)
        #define wmove(_y, _x) xsc_wmove(_y, _x)
        #define refresh() xsc_refresh()
        #define getch() xsc_getch()
        #define raw() xsc_raw() //raw_scs() [NIP]
        #define cbreak() xsc_cbreak()
        #define nocbreak() xsc_nocbreak()
        #define getyx(_Win, _cx, _cy) xsc_getyx(_Win, _cx, _cy)
        #define endwin() xsc_endwin()
    #elif
        #define xsc_initscr() initscr()
        #define xsc_stdscr stdscr
        #define xsc_curs_set(_Mod) curs_set(_Mod)
        #define xsc_addch(_Ch) addch(_Ch)
        #define xsc_addstr(_Str) addstr(_Str)
        #define xsc_printw(...) printw(__VA_ARGS__) /* will not work with C89 */
        #define xsc_vwprintw(_Win, _Format, ...) vwprintw(_Win, _Format, __VA_ARGS__) /* will not work with C89 */
        #define xsc_move(_y, _x) move(_y, _x)
        #define xsc_wmove(_y, _x) wmove(_y, _x)
        #define xsc_refresh() refresh()
        #define xsc_getch() getch()
        #define xsc_raw() raw() //raw_scs() [NIP]
        #define xsc_cbreak() cbreak()
        #define xsc_nocbreak() nocbreak()
        #define xsc_getyx(_Win, _cx, _cy) getyx(_Win, _cx, _cy)
        #define xsc_endwin() endwin()
    #endif /* NCURSES_LINKED */

    #if !defined(NCURSES_H)
        static void (*xsc_initscr)(void);
        static WINDOW* xsc_stdscr;
        static void (*xsc_curs_set)(int _Mod);
        static int (*xsc_addch)(const char _Ch);
        static void (*xsc_addstr)(const char * _Str);
        static int (*xsc_printw)(const char * restrict _Format, ...);
        static int (*xsc_vwprintw)(WINDOW* _Win, const char * restrict _Format, va_list _VA);
        static int (*xsc_move)(int _y, int _x);
        static int (*xsc_wmove)(int _y, int _x);
        static int (*xsc_refresh)(void);
        static int (*xsc_getch)(void);
        static void (*xsc_raw)(void);
        static void (*xsc_cbreak)(void);
        static void (*xsc_nocbreak)(void);
        static void (*xsc_getyx)(WINDOW * _Win, int _ln, int _col);
        static void (*xsc_endwin)(void);
    #elif !defined(NCURSES_LINKED)
        void (*xsc_initscr)(void);
        #define xsc_stdscr stdscr
        void (*xsc_curs_set)(int _Mod);
        int (*xsc_addch)(const char _Ch);
        void (*xsc_addstr)(const char * _Str);
        int (*xsc_printw)(const char * restrict _Format, ...);
        int (*xsc_vwprintw)(WINDOW* _Win, const char * restrict _Format, va_list _VA);
        int (*xsc_move)(int _y, int _x);
        int (*xsc_wmove)(int _y, int _x);
        int (*xsc_refresh)(void);
        int (*xsc_getch)(void);
        void (*xsc_raw)(void);
        void (*xsc_cbreak)(void);
        void (*xsc_nocbreak)(void);
        void (*xsc_getyx)(WINDOW * _Win, int _ln, int _col);
        void (*xsc_endwin)(void);
    #endif
#endif /* (XSC_OS == OsID_LINUX || XSC_OS == OsID_MAC) */

/* OS Exclusive Content */
#if XSC_OS == OsID_WINDOWS

    stdcon GetConsoleStats()
    {
        RECT R = {NULL};
        GetConsoleScreenBufferInfo(GlobalApi.Handler, &GlobalApi.Screen_Info);
        GetWindowRect(GlobalApi.Window_Handler, &R);
        Console.X = GlobalApi.Screen_Info.srWindow.Left;
        Console.Y = GlobalApi.Screen_Info.srWindow.Top;
        Console.W = GlobalApi.Screen_Info.srWindow.Right - Console.X + 1;
        Console.H = GlobalApi.Screen_Info.srWindow.Bottom - Console.Y + 1;
        Console.x = R.left;
        Console.y = R.top;
        Console.w = R.right - R.left;
        Console.h = R.bottom - R.top;
        Console.CX = GlobalApi.Screen_Info.dwCursorPosition.X;
        Console.CY = GlobalApi.Screen_Info.dwCursorPosition.Y;
    }

    #if XSCSET_OPTIMIZE < 1
    stdcon ActivateAE() {
        DWORD _DW_MOD = 0x00;
        GetConsoleMode(GlobalApi.Handler, &_DW_MOD);
        SetConsoleMode(GlobalApi.Handler, _DW_MOD |= 0x0004);
    }
    #else
        #define ActivateAE() system("")
    #endif

    stdcon GetCursorPosition(__xsc_decideparam(int * _x, int * _y)) {
        if(GetConsoleScreenBufferInfo(GlobalApi.Handler, &GlobalApi.Screen_Info)) {
        } else {
            printf("[WINAPI:ErrorCode=%i]\n", GetLastError());
        }
        #if XSCCONF_STDCON_NO_RETURN_CPOS >= ENABLED
            *_x = (GlobalApi.Coords.X = GlobalApi.Screen_Info.dwCursorPosition.X);
            *_y = (GlobalApi.Coords.Y = GlobalApi.Screen_Info.dwCursorPosition.Y);
        #else
            Console.CX = (GlobalApi.Coords.X = GlobalApi.Screen_Info.dwCursorPosition.X);
            Console.CY = (GlobalApi.Coords.Y = GlobalApi.Screen_Info.dwCursorPosition.X);
        #endif
        Console.GlobalApi = (GlobalApi);
    }

#if XSCCONF_STDCON_NO_RETURN_CPOS >= ENABLED
    #define GetCursorPosition(_CX, _CY) GetCursorPosition()
#endif

    stdcon UpdateCSBI() {
        GetConsoleScreenBufferInfo(GlobalApi.Handler, &Console.GlobalApi.Screen_Info);
        Console.W = GlobalApi.Screen_Info.srWindow.Right - Console.X + 1;
        Console.H = GlobalApi.Screen_Info.srWindow.Bottom - Console.Y + 1;
        Console.GlobalApi = (GlobalApi);
    }

    stdcon UpdateAPI() {
        GlobalApi.Handler = GetStdHandle(STD_OUTPUT_HANDLE);
        GlobalApi.Window_Handler = GetConsoleWindow();
        GetConsoleScreenBufferInfo(GlobalApi.Handler, &GlobalApi.Screen_Info);
        Console.GlobalApi = (GlobalApi);
    }

    #if XSCSET_USEBUILD1 <= DISABLED
      void Color(unsigned char _PreferredColor) {
    #else
      unsigned char Color(unsigned char _PreferredColor) {
    #endif
        __UPDATE_COLOR;
        SetConsoleTextAttribute(GlobalApi.Handler, _PreferredColor);
    }

    void ColorAE(unsigned char _AnsiColor) { /* 256Color */
        __UPDATE_AECOLOR;
        #if XSCCONF_ANSI_ESCAPE >= ENABLED
        printf("\x1b[38;5;%im", _AnsiColor);
        #else
        printf("\rPlease, Set XSCCONF_ANSI_ESCAPE to 1 if you want to use ColorAE().");
        #endif
    }

#elif XSC_OS == OsID_LINUX

    stdcon UpdateCSBI() {} /* maybe replace w/ macro that redirects to the proper function? */

    stdcon GetConsoleStats() {

    }

    stdcon ActivateAE() {

    }

    stdcon GetCursorPosition() {
        xsc_getyx(stdscr, Console.CX, Console.CY);
    }

    int printwln(const char * restrict TXT, ...) {
        va_list V;
        va_start(V, TXT);
        int __res = 0;/*vwprintw(stdscr, TXT, V);*/
        va_end(V);
        addch('\n');
        return __res;
    }

    void ColorAE(unsigned char _AnsiColor){ printf("\x1b[%im", _AnsiColor); }

    void Color(unsigned char _PreferredColor)
    {

    }

#elif XSC_OS == OsID_MAC

    stdcon GetConsoleStats() {

    }

    stdcon ActivateAE() {

    }

    stdcon CursorPosition(uint _x, uint _y) {

    }

    stdcon GetCursorPosition() {

    }

    int printwln(const char * restrict TXT, ...) {
        va_list V;
        va_start(V, TXT);
        int __res = vwprintw(stdscr, TXT, V);
        va_end(V);
        addch('\n');
        return __res;
    }

    void ColorAE(int _AnsiColor){ printf("\x1b[%im", _AnsiColor); }

    void Color(int _PreferredColor)
    {

    }

#else

    stdcon ActivateAE() {
    }

#endif
/* End Of OS Exlusive Content */

#if XSCCONF_USE_ANSI_ONLY >= ENABLED
    #define CursorPosition(_x, _y) CursorPositionAE(_y, _x)
#endif

/* OS Exlusive (inline) Functions (essential functions in which the #defining happens inside of them.) */
#ifndef _XSC_FUNCTIONS_INLINE_ESSENTIALS

    stdcon placeChar(const uint _x, const uint _y, const char _Char) {
        #if XSC_OS == OsID_WINDOWS
        CursorPosition(_x, _y);
        putchar(_Char);
        #elif XSC_OS == OsID_LINUX
        move(_y, _x);
        addch(_Char);
        #elif XSC_OS == OsID_MAC /* Temporary. */
        move(_y, _x);
        addch(_Char);
        #endif
    }

xsc_notnull(3)
    stdcon placeText(const uint _x, const uint _y, const String restrict _Text, ...) {
        va_list V;
        va_start(V, _Text);
        #if XSC_OS == OsID_WINDOWS || XSC_OS == OsID_OTHER
        CursorPosition(_x, _y);
        vprintf(_Text, V);
        #elif XSC_OS == OsID_LINUX
        move(_y, _x);
        vwprintw(stdscr, _Text, V);
        #elif XSC_OS == OsID_MAC /* Also Temporary. */
        move(_y, _x);
        vwprintw(stdscr, _Text, V);
        #endif
        va_end(V);
    }

    stdcon EditCursor(_Bool _Visibility, short _Size)
    {

        #if XSC_OS == OsID_WINDOWS
        CONSOLE_CURSOR_INFO Cursor_Data;

          Cursor_Data.bVisible = _Visibility;
          Cursor_Data.dwSize = (_Size < 50 && !_Visibility) ? 100 : _Size;
          SetConsoleCursorInfo(GlobalApi.Handler, &Cursor_Data);
        #elif XSC_OS == OsID_LINUX
          curs_set(_Visibility * (_Size > 50 ? 2 : 1));
        #elif XSC_OS == OsID_MAC
          curs_set(_Visibility * (_Size > 50 ? 2 : 1));
        #else

        #endif
    }

    stdcon_byte conch(short _X, short _Y)
    {
        #if XSC_OS == OsID_WINDOWS
          GlobalApi.Coords.X = _X;
          GlobalApi.Coords.Y = _Y;
          ReadConsoleOutputCharacter(GlobalApi.Handler,&GlobalApi.Char_Info,1,GlobalApi.Coords,&GlobalApi.Coords);
          return GlobalApi.Char_Info.Char.AsciiChar;
        #elif XSC_OS == OsID_LINUX
          /* soon. */
        #elif XSC_OS == OsID_MAC
          /* soon. */
        #else
          return 0;
        #endif
    }

    stdcon CursorPosition(uint _x, uint _y) {

        /* Optional: automatic coordinates update system. */
        #if XSCCONF_STDCON_UPDATE_COORDS >= ENABLED
            GlobalApi.Coords.X = _x;
            GlobalApi.Coords.Y = _y;
        #endif

        #if XSC_OS == OsID_WINDOWS
            GlobalApi.Coords.X = _x;
            GlobalApi.Coords.Y = _y;
            SetConsoleCursorPosition(GlobalApi.Handler, GlobalApi.Coords);
        #elif XSC_OS == OsID_LINUX
            move(_y, _x);
        #elif XSC_OS == OsID_MAC
            move(_y, _x);
        #else
            printf("\x1b[%d;%dH", _y +1, _x +1);
        #endif
    }

#else

#endif
/* End Of OS Exclusive Functions */

char stdconOS() {
    return
    #if XSC_OS == OsID_WINDOWS
        1;
    #elif XSC_OS == OsID_LINUX
        2;
    #elif XSC_OS == OsID_MAC
        3;
    #else
        0;
    #endif
}

xsc_forceline char stdconArch() { return XSC_ARCH; }

char* stdconOSName() {
    return
    #if XSC_OS == OsID_WINDOWS
        "Windows";
    #elif XSC_OS == OsID_LINUX
        "Linux";
    #elif XSC_OS == OsID_MAC
        "Mac";
    #elif XSC_OS == OsID_OTHER
        "[Not-Found]";
    #endif
}

stdcon CursorPositionAE(uint _x, uint _y) {
    #if XSCCONF_ANSI_ESCAPE >= ENABLED
    printf("\x1b[%d;%dH", _x, _y);
    #else
    printf("\rPlease, Set XSCCONF_ANSI_ESCAPE to 1 if you want to use CursorPositionAE().");
    #endif
}

stdcon xclear() {
    GetCursorPosition(&Console.CX, &Console.CY);

    CursorPosition(NULL, NULL);
    uint16_t _sz = (Console.CY > Console.H) ? Console.CY : Console.H;
    _sh_gblst = (char*)calloc(Console.W * _sz +1, sizeof(char));
    memset(_sh_gblst, VK_SPACE, Console.W * _sz);
    printf("%s", _sh_gblst);
    free(_sh_gblst);
    CursorPosition(NULL, NULL);
}

stdcon xclearln(uint16_t _lineBeg, uint16_t _lineEnd) {
    __UPDATE_CSBI;
    CursorPosition(NULL, _lineBeg);
    _sh_gblst = (char*)calloc(Console.W * (Console.H + _lineEnd) +1, sizeof(char));
    memset(_sh_gblst, VK_SPACE, Console.W * (Console.H + _lineEnd));
    printf("%s", _sh_gblst);
    free(_sh_gblst);
    CursorPosition(NULL, NULL);
}

/* [INV] */
stdcon consl(_Bool _SOL) { /* Save Or Load.. (scrstate, consl, conch...) */
    char* _scr = NULL;

    /*
        0 = Load.
        1 = Save.
                    */

    if(_SOL == 1) {

    } else {

    }

}

stdcon retl() {
    GetCursorPosition(&Console.CX, &Console.CY);
    CursorPosition(Console.CX, Console.CY - 2);
    printf("\r");
}

#if C_VERSION < CC99
_sysprintfln89 {
    va_list _VA;
    va_start(_VA, _Main);
    _Main = strdup(_Main);
    strcat(_Main, "\n");
    int _res =
    #if defined(XSC_LINUX) || defined(XSC_MAC)
        vprintw(_Main, _VA);
    #else
        vprintf(_Main, _VA);
    #endif
    free(_Main);
    va_end(_VA);
    return _res;
}
#endif

#include <super/sub/stdcrt.h>

#endif /* __STDCON__ */
