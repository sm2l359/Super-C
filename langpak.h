#ifndef __LANGPAK_DEFINED
#define __LANGPAK_DEFINED

#ifndef __xsc_lang_identifiers_are_defined
    #define XID_CLANGUAGE       0
    #define XID_CPPLANGUAGE     1
    #define XID_ACID_LANGUAGE   2
    #define XID_BASIC_LANGUAGE  3

    #define XSC_CLANGUAGE 1
    #define XSC_CPPLANGUAGE 2
    #define __xsc_lang_identifiers_are_defined 1
#endif

#ifndef __cplusplus
    #define XSC_LANGID 0 /* alt names: XSC_LANGID, XSC_LANG_ID, LANG_ID, XSC_LANGUAGE, XSC_LANGUAGEID */
    #define XSC_LANGUAGE 1
#else
    #define XSC_LANGID 1
    #define XSC_LANGUAGE 2
#endif

#ifdef __DETECT_CLANG_MODEL
    #undef __LANG_PACKAGE
#else

    #if XSC_LANGUAGE == XSC_CLANGUAGE
        #define XSC_STDC 1
        #define XSC_LANGNAME "C"
    #elif XSC_LANGUAGE == XSC_CPPLANGUAGE
        #define XSC_STDCPP 1
        #define XSC_LANGNAME "C++"
    #else
        #define XSC_UNKNOWNLANG
        #define XSC_LANGNAME "Unknown-CLanguage"
    #endif

#endif /* __DETECT_CLANG_MODEL */

#endif /* __LANGUAGE_PACKAGE */
