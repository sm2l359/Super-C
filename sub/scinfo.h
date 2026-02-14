#ifndef __SCIFI_H__
#define __SCIFI_H__

#define _XSC_SCLINKER 1

#if XSCSET_OPTIMIZE >= XSCOPT_OPTIMIZELEVELI
#define _scifi_optm_t char
#define _scifi_lang_t int
#define _scifi_date_t char*
#define _scifi_last_t int
#define _scifi_vers_t char*
#define _scifi_buil_t char

#define __SCIFI_OPTIMIZE XSCSET_OPTIMIZE
#define __SCIFI_LANGUAGE XSC_LANGUAGE
#define __SCIFI_DATE __DATE__
#define __SCIFI_LAST XSCINF_DATE
#define __SCIFI_VERS tostr(XSCINF_VERSION)
#define __SCIFI_BUIL XSCINF_BUILD

#define _scifi_frels_t char
#define _scifi_gthub_t char
#define _scifi_lcnse_t char*

#define __SCIFI_LICENSE "GPL-3.0"
#define __SCIFI_GITHUB TRUE
#define __SCIFI_RELEASE XSCINF_RELEASE

#define __convr
#elif XSCSET_OPTIMIZE >= XSCOPT_OPTIMIZELEVELII
#define _scifi_optm_t char
#define _scifi_lang_t int
#define _scifi_date_t char*
#define _scifi_last_t int
#define _scifi_vers_t float
#define _scifi_buil_t char

#define __SCIFI_OPTIMIZE XSCSET_OPTIMIZE
#define __SCIFI_LANGUAGE XSC_LANGUAGE
#define __SCIFI_DATE __DATE__
#define __SCIFI_LAST XSCINF_DATEVER
#define __SCIFI_VERS tostr(XSCINF_VERSION)
#define __SCIFI_BUIL XSCINF_BUILD

#define _scifi_frels_t char
#define _scifi_gthub_t char
#define _scifi_lcnse_t char*

#define __SCIFI_LICENSE  "GPL-3.0" /* gonna get it's own XSCINF later on. [R][C] */
#define __SCIFI_GITHUB TRUE /* also gonna get it's own XSCINF later on. [R][C] */
#define __SCIFI_RELEASE XSCINF_RELEASE

#define __convr _sh_gblst = __SCIFI_VERS; \
                __VERSION = (float)strtod(_sh_gblst +1, NULL) /* [ALT] convf, convt, conv */
#endif

#define __scdat_embd __attribs(xscs_data volatile) /* emb/embd= embedded */
#define __scinf_embd __attribs(xscs_info volatile) /* emb/embd= embedded */

    __scdat_embd _scifi_buil_t  __BUILD;
    __scdat_embd _scifi_vers_t __VERSION;
    __scdat_embd _scifi_last_t   __LASTMOD;
    __scdat_embd _scifi_date_t __DATE;
    __scdat_embd _scifi_lang_t __LANGUAGE;
    __scdat_embd _scifi_optm_t __OPTIMIZE;

    __scinf_embd _scifi_frels_t __FOR_RELEASE;
    __scinf_embd _scifi_gthub_t __GITHUB_ACQUIRED;
    __scinf_embd _scifi_lcnse_t __LICENSE;

    __scinf_embd uint32_t scL_general_info[] =
    #include <super/SUPERCINF>

void __SCLINK_AUTO__(void) {

    __convr;

    __BUILD    = __SCIFI_BUIL;
    __VERSION  = __SCIFI_VERS;
    __LASTMOD  = __SCIFI_LAST;
    __DATE     = __SCIFI_DATE;
    __LANGUAGE = __SCIFI_LANGUAGE;
    __OPTIMIZE = __SCIFI_OPTIMIZE;


    /* general info */
    __FOR_RELEASE = __SCIFI_RELEASE;
    __GITHUB_ACQUIRED = __SCIFI_GITHUB;
    __LICENSE = __SCIFI_LICENSE;



}

#undef __SCIFI_OPTIMIZE
#undef __SCIFI_LANGUAGE
#undef __SCIFI_DATE
#undef __SCIFI_LAST
#undef __SCIFI_VERS
#undef __SCIFI_BUIL

#undef __convr

#undef __scdat_embd
#undef __scinf_embd

#endif /* __SCIFI_H__ */
