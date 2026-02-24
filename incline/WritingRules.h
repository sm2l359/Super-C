#if __INLINE_COMMENT__
//this macro is just to write down the writing rules for this library:

/// - Catalog.
//[Alphabetical] - Rules in the catalog.
//[Numeric] - Expressions for the rules.
//o - Conditions of the rules (if).
//-> Counter-conditions (else).
//E - Explanation.
// ! - important emphasis.

//  Uses:
//  E - [Use it when:]
//        ["In order to..."]
//          ["In case of..."]
//  ! - [Use it when:]
//        ["Specially if..."]
//          ["notice that..."]
//            ["it's important to..."]
//(the contents showed as examples
//right above may vary.)
//(Note: the first line doesn't
   //require the use of 'E - ')

   /// * SECTION I * ///
   /// SYNTAX & SEMANTICS RULES ///

    ///Standard types
    //the standard types
    //consists of [...]

    ///Including
    //A - when working with
    //the include keyword,
    //1 - you SHALL NOT use any
    //initial spacing with it.
    //leave it at column 0.
    //2 - instead it's highly
    //recommended to

    //B - in case a header needs to
    //borrow a function from a another
    //header. depending of the number
    //of functions that it's going
    //to borrow,
    //1 - it will either emit a error
    //that tells you to
    //2 - or it will emit a warning
    //recommending the user to include
    //the home function.

    //o - if the number of functions
    //exceed 2, the function should
    //be forcibly included into it.
    //-> otherwise it should be
    //implemented via in line.

    ///Comments
    //A - all the single line comments should be embraced by the
    //double line comments.

    /*
    //Like This
    */

    //E - In Order to prevent flaws caused by the C-89 Standard.

    //B - meanwhile comments that are not so important for the
    //understanding of the library and the users guiding of the
    //library should be discarded...
    // ! - Specially Comments that are, you know, comments.

    ///Defining
    //
    //
    //
    //in cases like this:

#ifndef _MATH_H_
    #define M_PI 3.14159265358979323846
#endif

    //it should be exactly 1 tab of spacing;
    //unless the content of the
    //definition token is too large.

//if it involves a typedef
//and an 'else',
//like this:

#if XSCCONF_HEADER_XTD > 0
 typedef void draws;
#else
 #define draws void
#endif

//...the spacing should be 1.

#ifndef M_PI
 #define M_PI 3.14159265358979323846
#endif

//...specially it it's a large number.

//both examples were extracted from draws.h

   /// * SECTION II * ///
   /// WRITING RULES ///

   /* COMMENTS

    in Super-C,

    comments should not be used to describe what something
    in the function does and if it do, make sure it's in a
    feature that won't be changed in the future, don't use
    it to refer directly to features that may be changed
    in the future, but if you still insist on doing that
    make sure to verify if the comment actually matches
    what the function is doing, if not, update it.

    comments should not be used to refer to anything directly
    at the library, it should only be used to set notes, give
    ideas for future implementations

    comments should only be used for notes, write down ideas
    and todos for future implementations, it should never be
    used to refer to anything directly in the library if you
    do that, IF not managed may cause huge problems later on
    based on the idea of: "what if you wanted to change that"
    and that's the main source problem, comments may not
    exactly describe what a certain content does because
    it was modified sometime later and the comment stays
    outdated, every time you change a feature, you also
    need to update the comment to make sure that it will
    properly describe the content right next to it.
    if you still insist on making comment that
    will refer directly and describe exactly what the
    content does, make sure the comment matches what
    the content (function, macro, etc...) is
    doing, if not, then update the comment to what
    it's actually doing.

   */

   /* OPTIMIZATION

        //PREMATURE OPTIMIZATOIN

        premature optimizations
        are a bad practice and
        should not be done.

        the programmer should
        code normally, don't
        try to be "smarter"
        to spare either
        size or speed.

        if you want, you
        can use the implemented
        cross compatible compiler
        features that super-C
        provides.

        avoid premature optimization
        at all costs and let the
        compiler do it's job.

        Remember: the compiler is
        way smarter than you.

   */

   /* NAMING THINGS

        //Hungarian Notation

        Hungarian Notation notation
        was a type of notation very
        commonly used in the older days
        of computing;

        this notation
        involving specifying
        the data type at the
        very beginning of the
        name:

        sName;
        bIsVisible;
        chLetter;

        this style
        was used
        back when C
        wasn't standardized
        and only had int.

        however, due
        to the evolution
        of technology,
        we have modern
        IDEs, and C-89
        forward added
        (standardized)
        multiple types
        and variations,
        rather than int.

        and therefore,
        these types are not
        necessary anymore,
        and forbidden by
        the Super-C writing standard.

        //"Generic" NAMES

        A Generic NAME is
        a type of name that,
        as the name implies,
        it's extremely common
        in small projects or
        novice programmers.

        It's entirely forbidden
        to use names that are too
        "Common" is easily mishandled
        in Super-C;

        the reason for that is much more
        safety-aligned rather than style;

        generic names are extremely bad
        practice and not recommended
        if you want compatibility;

        there is a important curve of when
        you should and when you SHOULDn't
        use them, and that is mostly when
        you're creating custom libraries.

        because using too common names
        may severely overwrite or cause
        name flaws in the future.

        the problem is not that they're ambiguous, it's the
        fault of the lack of concern of many people around
        there using these types in an irresponsible manner.

        and that's the problem i have with generic names.

        "Generic" names should always be available
        for the main.c project, and for the main.c
        project only.

        ex:
        in <windows.h>
        "#define SendMessage() WSendMessage"

        this is a bad thing to do.
        because it screws name variability.


        Generics, they should always be available
        for the user to use, and libraries / APIs
        should not eat names that are too commonly
        used.
   */

#endif /* 0 */


