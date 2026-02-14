#ifndef __ARRAYS_H
#define __ARRAYS_H
#define __XCM__ARRAY__FUNCTIONS__DEFINED__ 1

#include <super/stdbasic.h>

#line 8 "[arrays.h]"

/**
    Package Name: arrays.h,
    stands for "Array System".
    General Purpose Package? yes;
    Child-Package? no;
    Experimental Package? no.
**/

#if __INLINE_COMMENT__
//fun fact: all functions in here are O(n) or higher... (unless binary search is included.)

//arrelm, Also Known as "find the size of my array because C doesn't provide a way of doing it".
//even with this macro, it doesn't help at all if your array size is bigger than the total elements in it.
#endif

#define arrelm(Array) sizeof(Array) / sizeof(* Array)

__attribs( xsc_nonull(1) xsc_format(printf, 1, 2) xsc_hot )
    int aprintf(const String restrict _STR, ...)
{
    char* _tok_ = strchr(_STR, '%');
    char* _next_ = NULL;
    char* _sep_ = NULL;
    unsigned int _Length = 0;
    unsigned char _Mode = 0x1E; /* 00011110b */

    va_list _VA;
    va_start(_VA, _STR);

    if(_tok_) {
        printf("%.*s", _tok_ - _STR, _STR);

        while(_tok_) {

            _Mode = 0x1E;

            _next_ = strchr(_tok_ + 1, '%'); /* the issue occurs here */
            if(_next_ == NULL) {
                _next_ = strchr(_tok_, '\0');
            }

            if(isdigit(*(_tok_ + 1))) {

                _sep_ = strchr(_tok_, '.');

                _Length = _next_ - _tok_;
                _tok_ = "*&"; /* set tmp modes. */

                while(_sep_ > _next_ || _sep_ == NULL) {

                    _sep_ = strchr(_next_ - _Length, *_tok_);

                    _Mode = (*_tok_ == '*') ? 0x01 :
                            (*_tok_ == '&') ? 0x00 : 0x1E;
                    ++_tok_;
                }

                if(_sep_ > _next_ || _sep_ == NULL) {
                    return 1;
                }

                _tok_ = _next_ - _Length;

                if(strncmp(_tok_ + 1, "0", _sep_ - _tok_ - 1) == 0) {
                    _Length = va_arg(_VA, size_t);
                } else {
                    _next_ = _tok_ + 1;
                    while(_next_ < _sep_) {
                        if(!isdigit(*_next_)) {
                            return 2;
                        }
                        _next_++;
                    }
                    _next_ = _tok_ + _Length;

                    _Length = (unsigned int)strtol(_tok_ + 1, NULL, 10);
                }

                if(*(_sep_ + 1) == 'l') {

                    _Mode = (*(_sep_ + 2) == *(_sep_ + 1)) ? _Mode | (1 << 7) : _Mode | (1 << 6);

                }

                _tok_ = (char*)calloc(((_Mode >> 6) + 2), sizeof(char));
                _tok_[0] = '%';
                strncpy(_tok_ + 1, _sep_ + 1, (_Mode >> 6) + 1);

                unsigned char _Fmt = tolower(_tok_[(_Mode >> 6) + 1]);

                /* issue with this system, fix later. */
                const void* _t = va_arg(_VA, const void*);

                if(((_Mode >> 1) & 1) == 1) putchar('(');

                for(int I = 0; I < _Length; ++I) {

                    if(((_Mode) & 1) == 1) {
                        printf("[%i]: ", I);
                    }

#define __GET_FTYPE (_Mode >> 6)
                    if(_Fmt == 'd' || _Fmt == 'i') {
                        _tok_[__GET_FTYPE + 1] = 'd';
                             if(__GET_FTYPE == 0) printf(_tok_, *((int*)_t + I));
                        else if(__GET_FTYPE == 1) printf(_tok_, *((long*)_t + I));
                        else if(__GET_FTYPE == 2) printf(_tok_, *((long long int*)_t + I));
                    } else if(_Fmt == 'b') {
                        _tok_[__GET_FTYPE + 1] = 'd';
                        printf(_tok_, *((bool*)_t + I));
                    } else if(_Fmt == 'y' || _Fmt == 'u') { /* %by, fix later. */
                        _tok_[__GET_FTYPE + 1] = 'u';
                        printf(_tok_, *((unsigned char*)_t + I));
                    } else if(_Fmt == 'f') {
                             if(__GET_FTYPE == 0) printf(_tok_, *((float*)_t + I));
                        else if(__GET_FTYPE == 1) printf(_tok_, *((double*)_t + I));
                        else if(__GET_FTYPE == 2) printf(_tok_, *((long double*)_t + I));
                    } else if(_Fmt == 'c') {
                        printf(_tok_, *((char*)_t + I));
                    } else if(_Fmt == 'p') {
                        printf(_tok_, ((void*)_t + I));
                    } else if(_Fmt == 'e' || _Fmt == 'o') {
                        printf(_tok_, *((long long int*)_t + I));
                    }

                    if(((_Mode) & 1) == 1) {
                        putchar('\n');
                    } else if(((_Mode) & 1) == 0 && I < _Length - 1) {
                        if(((_Mode >> 3) & 1) == 1) printf(", ");
                    }

                }

                if(((_Mode >> 2) & 1) == 1) putchar(')');

                free(_tok_);

            } else {

            }

            if(*_next_ == '\0') break;
            _tok_ = _next_;
        }
    } else {
        return vprintf(_STR, _VA);
    }

    va_end(_VA);
#undef __GET_FTYPE
}

__attribs( xsc_nonnull(1) xsc_format(printf, 1, 3) )
int listput(const restrict String _type, int _ctr, ...) {
    va_list _VA;
    va_start(_VA, _ctr);
    int _res;
    for(int I = 0; I < _ctr; ++I)
        _res = vprintf(_type, _VA);
    va_end(_VA);
    return _res;
}

#include <super/sub/stdcrt.h>

#endif /* __ARRAYS_H */
