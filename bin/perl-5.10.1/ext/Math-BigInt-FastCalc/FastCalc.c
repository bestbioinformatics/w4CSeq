/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.2002 from the
 * contents of FastCalc.xs. Do not edit this file, edit FastCalc.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "FastCalc.xs"
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

/* for Perl prior to v5.7.1 */
#ifndef SvUOK
#  define SvUOK(sv) SvIOK_UV(sv)
#endif

double XS_BASE = 0;
double XS_BASE_LEN = 0;

#line 23 "FastCalc.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)	S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage		S_croak_xs_usage
#endif

#endif

#line 66 "FastCalc.c"
#define RETURN_MORTAL_INT(value)		\
      ST(0) = sv_2mortal(newSViv(value));	\
      XSRETURN(1);
#define RETURN_MORTAL_BOOL(temp, comp)			\
      ST(0) = sv_2mortal(boolSV( SvIV(temp) == comp));
#define CONSTANT_OBJ(int)			\
    RETVAL = newAV();				\
    sv_2mortal((SV*)RETVAL);			\
    av_push (RETVAL, newSViv( int ));

XS(XS_Math__BigInt__FastCalc__set_XS_BASE); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__BigInt__FastCalc__set_XS_BASE)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "BASE, BASE_LEN");
    {
	SV*	BASE = ST(0);
	SV*	BASE_LEN = ST(1);
#line 51 "FastCalc.xs"
    XS_BASE = SvNV(BASE); 
    XS_BASE_LEN = SvIV(BASE_LEN); 
#line 93 "FastCalc.c"
    }
    XSRETURN_EMPTY;
}


XS(XS_Math__BigInt__FastCalc__new); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__BigInt__FastCalc__new)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "class, x");
    {
	SV*	x = ST(1);
	AV *	RETVAL;
#line 61 "FastCalc.xs"
    STRLEN len;
    char* cur;
    STRLEN part_len;

#line 117 "FastCalc.c"
#line 66 "FastCalc.xs"
    /* create the array */
    RETVAL = newAV();
    sv_2mortal((SV*)RETVAL);
    if (SvUOK(x) && SvUV(x) < XS_BASE)
      {
      /* shortcut for integer arguments */
      av_push (RETVAL, newSVuv( SvUV(x) ));
      }
    else
      {
      /* split the input (as string) into XS_BASE_LEN long parts */
      /* in perl:
		[ reverse(unpack("a" . ($il % $BASE_LEN+1)
		. ("a$BASE_LEN" x ($il / $BASE_LEN)), $_[1])) ];
      */
      cur = SvPV(x, len);			/* convert to string & store length */
      cur += len;				/* doing "cur = SvEND(x)" does not work! */
      while (len > 0)
        {
        /* use either BASE_LEN or the amount of remaining digits */
        part_len = (STRLEN) XS_BASE_LEN;
        if (part_len > len)
          {
          part_len = len;
          }
        /* processed so many digits */
        cur -= part_len;
        len -= part_len;
        /* printf ("part '%s' (part_len: %i, len: %i, BASE_LEN: %i)\n", cur, part_len, len, XS_BASE_LEN); */
        if (part_len > 0)
	  {
	  av_push (RETVAL, newSVpvn(cur, part_len) );
	  }
        }
      }
#line 154 "FastCalc.c"
	ST(0) = newRV((SV*)RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Math__BigInt__FastCalc__copy); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__BigInt__FastCalc__copy)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "class, x");
    {
	SV*	x = ST(1);
#line 112 "FastCalc.xs"
    AV*	a;
    AV*	a2;
    I32	elems;

#line 179 "FastCalc.c"
#line 117 "FastCalc.xs"
    a = (AV*)SvRV(x);			/* ref to aray, don't check ref */
    elems = av_len(a);			/* number of elems in array */
    a2 = (AV*)sv_2mortal((SV*)newAV());
    av_extend (a2, elems);		/* pre-padd */
    while (elems >= 0)
      {
      /* av_store( a2,  elems, newSVsv( (SV*)*av_fetch(a, elems, 0) ) ); */

      /* looking and trying to preserve IV is actually slower when copying */
      /* temp = (SV*)*av_fetch(a, elems, 0);
      if (SvIOK(temp))
        {
        av_store( a2,  elems, newSViv( SvIV( (SV*)*av_fetch(a, elems, 0) )));
        }
      else
        {
        av_store( a2,  elems, newSVnv( SvNV( (SV*)*av_fetch(a, elems, 0) )));
        }
      */
      av_store( a2,  elems, newSVnv( SvNV( (SV*)*av_fetch(a, elems, 0) )));
      elems--;
      }
    ST(0) = sv_2mortal( newRV_inc((SV*) a2) );
#line 204 "FastCalc.c"
    }
    XSRETURN(1);
}


XS(XS_Math__BigInt__FastCalc___strip_zeros); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__BigInt__FastCalc___strip_zeros)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "x");
    {
	SV*	x = ST(0);
#line 148 "FastCalc.xs"
    AV*	a;
    SV*	temp;
    I32	elems;
    I32	index;

#line 228 "FastCalc.c"
#line 154 "FastCalc.xs"
    a = (AV*)SvRV(x);			/* ref to aray, don't check ref */
    elems = av_len(a);			/* number of elems in array */
    ST(0) = x;				/* we return x */
    if (elems == -1)
      { 
      av_push (a, newSViv(0));		/* correct empty arrays */
      XSRETURN(1);
      }
    if (elems == 0)
      {
      XSRETURN(1);			/* nothing to do since only one elem */
      }
    index = elems;
    while (index > 0)
      {
      temp = *av_fetch(a, index, 0);	/* fetch ptr to current element */
      if (SvNV(temp) != 0)
        {
        break;
        }
      index--;
      }
    if (index < elems)
      {
      index = elems - index;
      while (index-- > 0)
        {
        av_pop (a);
        }
      }
    XSRETURN(1);
#line 261 "FastCalc.c"
    }
    XSRETURN(1);
}


XS(XS_Math__BigInt__FastCalc__dec); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__BigInt__FastCalc__dec)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "class, x");
    {
	SV*	x = ST(1);
#line 193 "FastCalc.xs"
    AV*	a;
    SV*	temp;
    I32	elems;
    I32	index;
    NV	MAX;

#line 286 "FastCalc.c"
#line 200 "FastCalc.xs"
    a = (AV*)SvRV(x);			/* ref to aray, don't check ref */
    elems = av_len(a);			/* number of elems in array */
    ST(0) = x;				/* we return x */

    MAX = XS_BASE - 1;
    index = 0;
    while (index <= elems)
      {
      temp = *av_fetch(a, index, 0);	/* fetch ptr to current element */
      sv_setnv (temp, SvNV(temp)-1);	/* decrement */
      if (SvNV(temp) >= 0)
        {
        break;				/* early out */
        }
      sv_setnv (temp, MAX);		/* overflow, so set this to $MAX */
      index++;
      } 
    /* do have more than one element? */
    /* (more than one because [0] should be kept as single-element) */
    if (elems > 0)
      {
      temp = *av_fetch(a, elems, 0);	/* fetch last element */
      if (SvIV(temp) == 0)		/* did last elem overflow? */ 
        {
        av_pop(a);			/* yes, so shrink array */
        				/* aka remove leading zeros */
        }
      }
    XSRETURN(1);			/* return x */
#line 317 "FastCalc.c"
    }
    XSRETURN(1);
}


XS(XS_Math__BigInt__FastCalc__inc); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__BigInt__FastCalc__inc)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "class, x");
    {
	SV*	x = ST(1);
#line 237 "FastCalc.xs"
    AV*	a;
    SV*	temp;
    I32	elems;
    I32	index;
    NV	BASE;

#line 342 "FastCalc.c"
#line 244 "FastCalc.xs"
    a = (AV*)SvRV(x);			/* ref to aray, don't check ref */
    elems = av_len(a);			/* number of elems in array */
    ST(0) = x;				/* we return x */

    BASE = XS_BASE;
    index = 0;
    while (index <= elems)
      {
      temp = *av_fetch(a, index, 0);	/* fetch ptr to current element */
      sv_setnv (temp, SvNV(temp)+1);
      if (SvNV(temp) < BASE)
        {
        XSRETURN(1);			/* return (early out) */
        }
      sv_setiv (temp, 0);		/* overflow, so set this elem to 0 */
      index++;
      } 
    temp = *av_fetch(a, elems, 0);	/* fetch last element */
    if (SvIV(temp) == 0)		/* did last elem overflow? */
      {
      av_push(a, newSViv(1));		/* yes, so extend array by 1 */
      }
    XSRETURN(1);			/* return x */
#line 367 "FastCalc.c"
    }
    XSRETURN(1);
}


XS(XS_Math__BigInt__FastCalc__num); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__BigInt__FastCalc__num)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "class, x");
    {
	SV*	x = ST(1);
#line 275 "FastCalc.xs"
    AV*	a;
    NV	fac;
    SV*	temp;
    NV	num;
    I32	elems;
    I32	index;
    NV	BASE;

#line 394 "FastCalc.c"
#line 284 "FastCalc.xs"
    a = (AV*)SvRV(x);			/* ref to aray, don't check ref */
    elems = av_len(a);			/* number of elems in array */

    if (elems == 0)			/* only one element? */
      {
      ST(0) = *av_fetch(a, 0, 0);	/* fetch first (only) element */
      XSRETURN(1);			/* return it */
      }
    fac = 1.0;				/* factor */
    index = 0;
    num = 0.0;
    BASE = XS_BASE;
    while (index <= elems)
      {
      temp = *av_fetch(a, index, 0);	/* fetch current element */
      num += fac * SvNV(temp);
      fac *= BASE;
      index++;
      }
    ST(0) = newSVnv(num);
#line 416 "FastCalc.c"
    }
    XSRETURN(1);
}


XS(XS_Math__BigInt__FastCalc__zero); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__BigInt__FastCalc__zero)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "class");
    {
	AV *	RETVAL;
#line 310 "FastCalc.xs"
    CONSTANT_OBJ(0)
#line 436 "FastCalc.c"
	ST(0) = newRV((SV*)RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Math__BigInt__FastCalc__one); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__BigInt__FastCalc__one)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "class");
    {
	AV *	RETVAL;
#line 319 "FastCalc.xs"
    CONSTANT_OBJ(1)
#line 458 "FastCalc.c"
	ST(0) = newRV((SV*)RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Math__BigInt__FastCalc__two); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__BigInt__FastCalc__two)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "class");
    {
	AV *	RETVAL;
#line 328 "FastCalc.xs"
    CONSTANT_OBJ(2)
#line 480 "FastCalc.c"
	ST(0) = newRV((SV*)RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Math__BigInt__FastCalc__ten); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__BigInt__FastCalc__ten)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 1)
       croak_xs_usage(cv,  "class");
    {
	AV *	RETVAL;
#line 337 "FastCalc.xs"
    CONSTANT_OBJ(10)
#line 502 "FastCalc.c"
	ST(0) = newRV((SV*)RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS(XS_Math__BigInt__FastCalc__is_even); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__BigInt__FastCalc__is_even)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "class, x");
    {
	SV*	x = ST(1);
#line 347 "FastCalc.xs"
    AV*	a;
    SV*	temp;

#line 526 "FastCalc.c"
#line 351 "FastCalc.xs"
    a = (AV*)SvRV(x);		/* ref to aray, don't check ref */
    temp = *av_fetch(a, 0, 0);	/* fetch first element */
    ST(0) = sv_2mortal(boolSV((SvIV(temp) & 1) == 0));
#line 531 "FastCalc.c"
    }
    XSRETURN(1);
}


XS(XS_Math__BigInt__FastCalc__is_odd); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__BigInt__FastCalc__is_odd)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "class, x");
    {
	SV*	x = ST(1);
#line 361 "FastCalc.xs"
    AV*	a;
    SV*	temp;

#line 553 "FastCalc.c"
#line 365 "FastCalc.xs"
    a = (AV*)SvRV(x);		/* ref to aray, don't check ref */
    temp = *av_fetch(a, 0, 0);	/* fetch first element */
    ST(0) = sv_2mortal(boolSV((SvIV(temp) & 1) != 0));
#line 558 "FastCalc.c"
    }
    XSRETURN(1);
}


XS(XS_Math__BigInt__FastCalc__is_one); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__BigInt__FastCalc__is_one)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "class, x");
    {
	SV*	x = ST(1);
#line 375 "FastCalc.xs"
    AV*	a;
    SV*	temp;

#line 580 "FastCalc.c"
#line 379 "FastCalc.xs"
    a = (AV*)SvRV(x);			/* ref to aray, don't check ref */
    if ( av_len(a) != 0)
      {
      ST(0) = &PL_sv_no;
      XSRETURN(1);			/* len != 1, can't be '1' */
      }
    temp = *av_fetch(a, 0, 0);		/* fetch first element */
    RETURN_MORTAL_BOOL(temp, 1);
#line 590 "FastCalc.c"
    }
    XSRETURN(1);
}


XS(XS_Math__BigInt__FastCalc__is_two); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__BigInt__FastCalc__is_two)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "class, x");
    {
	SV*	x = ST(1);
#line 394 "FastCalc.xs"
    AV*	a;
    SV*	temp;

#line 612 "FastCalc.c"
#line 398 "FastCalc.xs"
    a = (AV*)SvRV(x);			/* ref to aray, don't check ref */
    if ( av_len(a) != 0)
      {
      ST(0) = &PL_sv_no;
      XSRETURN(1);			/* len != 1, can't be '2' */
      }
    temp = *av_fetch(a, 0, 0);		/* fetch first element */
    RETURN_MORTAL_BOOL(temp, 2);
#line 622 "FastCalc.c"
    }
    XSRETURN(1);
}


XS(XS_Math__BigInt__FastCalc__is_ten); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__BigInt__FastCalc__is_ten)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "class, x");
    {
	SV*	x = ST(1);
#line 413 "FastCalc.xs"
    AV*	a;
    SV*	temp;

#line 644 "FastCalc.c"
#line 417 "FastCalc.xs"
    a = (AV*)SvRV(x);			/* ref to aray, don't check ref */
    if ( av_len(a) != 0)
      {
      ST(0) = &PL_sv_no;
      XSRETURN(1);			/* len != 1, can't be '10' */
      }
    temp = *av_fetch(a, 0, 0);		/* fetch first element */
    RETURN_MORTAL_BOOL(temp, 10);
#line 654 "FastCalc.c"
    }
    XSRETURN(1);
}


XS(XS_Math__BigInt__FastCalc__is_zero); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__BigInt__FastCalc__is_zero)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "class, x");
    {
	SV*	x = ST(1);
#line 432 "FastCalc.xs"
    AV*	a;
    SV*	temp;

#line 676 "FastCalc.c"
#line 436 "FastCalc.xs"
    a = (AV*)SvRV(x);			/* ref to aray, don't check ref */
    if ( av_len(a) != 0)
      {
      ST(0) = &PL_sv_no;
      XSRETURN(1);			/* len != 1, can't be '0' */
      }
    temp = *av_fetch(a, 0, 0);		/* fetch first element */
    RETURN_MORTAL_BOOL(temp, 0);
#line 686 "FastCalc.c"
    }
    XSRETURN(1);
}


XS(XS_Math__BigInt__FastCalc__len); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__BigInt__FastCalc__len)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 2)
       croak_xs_usage(cv,  "class, x");
    {
	SV*	x = ST(1);
#line 451 "FastCalc.xs"
    AV*	a;
    SV*	temp;
    IV	elems;
    STRLEN len;

#line 710 "FastCalc.c"
#line 457 "FastCalc.xs"
    a = (AV*)SvRV(x);			/* ref to aray, don't check ref */
    elems = av_len(a);			/* number of elems in array */
    temp = *av_fetch(a, elems, 0);	/* fetch last element */
    SvPV(temp, len);			/* convert to string & store length */
    len += (IV) XS_BASE_LEN * elems;
    ST(0) = sv_2mortal(newSViv(len));
#line 718 "FastCalc.c"
    }
    XSRETURN(1);
}


XS(XS_Math__BigInt__FastCalc__acmp); /* prototype to pass -Wmissing-prototypes */
XS(XS_Math__BigInt__FastCalc__acmp)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 3)
       croak_xs_usage(cv,  "class, cx, cy");
    {
	SV*	cx = ST(1);
	SV*	cy = ST(2);
#line 471 "FastCalc.xs"
    AV* array_x;
    AV* array_y;
    I32 elemsx, elemsy, diff;
    SV* tempx;
    SV* tempy;
    STRLEN lenx;
    STRLEN leny;
    NV diff_nv;
    I32 diff_str;

#line 748 "FastCalc.c"
#line 482 "FastCalc.xs"
    array_x = (AV*)SvRV(cx);		/* ref to aray, don't check ref */
    array_y = (AV*)SvRV(cy);		/* ref to aray, don't check ref */
    elemsx =  av_len(array_x);
    elemsy =  av_len(array_y);
    diff = elemsx - elemsy;		/* difference */

    if (diff > 0)
      {
      RETURN_MORTAL_INT(1);		/* len differs: X > Y */
      }
    else if (diff < 0)
      {
      RETURN_MORTAL_INT(-1);		/* len differs: X < Y */
      }
    /* both have same number of elements, so check length of last element
       and see if it differes */
    tempx = *av_fetch(array_x, elemsx, 0);	/* fetch last element */
    tempy = *av_fetch(array_y, elemsx, 0);	/* fetch last element */
    SvPV(tempx, lenx);			/* convert to string & store length */
    SvPV(tempy, leny);			/* convert to string & store length */
    diff_str = (I32)lenx - (I32)leny;
    if (diff_str > 0)
      {
      RETURN_MORTAL_INT(1);		/* same len, but first elems differs in len */
      }
    if (diff_str < 0)
      {
      RETURN_MORTAL_INT(-1);		/* same len, but first elems differs in len */
      }
    /* same number of digits, so need to make a full compare */
    diff_nv = 0;
    while (elemsx >= 0)
      {
      tempx = *av_fetch(array_x, elemsx, 0);	/* fetch curr x element */
      tempy = *av_fetch(array_y, elemsx, 0);	/* fetch curr y element */
      diff_nv = SvNV(tempx) - SvNV(tempy);
      if (diff_nv != 0)
        {
        break; 
        }
      elemsx--;
      } 
    if (diff_nv > 0)
      {
      RETURN_MORTAL_INT(1);
      }
    if (diff_nv < 0)
      {
      RETURN_MORTAL_INT(-1);
      }
    ST(0) = sv_2mortal(newSViv(0));		/* X and Y are equal */
#line 801 "FastCalc.c"
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Math__BigInt__FastCalc); /* prototype to pass -Wmissing-prototypes */
XS(boot_Math__BigInt__FastCalc)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    const char* file = __FILE__;

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
    XS_VERSION_BOOTCHECK ;

        newXS("Math::BigInt::FastCalc::_set_XS_BASE", XS_Math__BigInt__FastCalc__set_XS_BASE, file);
        newXS("Math::BigInt::FastCalc::_new", XS_Math__BigInt__FastCalc__new, file);
        newXS("Math::BigInt::FastCalc::_copy", XS_Math__BigInt__FastCalc__copy, file);
        newXS("Math::BigInt::FastCalc::__strip_zeros", XS_Math__BigInt__FastCalc___strip_zeros, file);
        newXS("Math::BigInt::FastCalc::_dec", XS_Math__BigInt__FastCalc__dec, file);
        newXS("Math::BigInt::FastCalc::_inc", XS_Math__BigInt__FastCalc__inc, file);
        newXS("Math::BigInt::FastCalc::_num", XS_Math__BigInt__FastCalc__num, file);
        newXS("Math::BigInt::FastCalc::_zero", XS_Math__BigInt__FastCalc__zero, file);
        newXS("Math::BigInt::FastCalc::_one", XS_Math__BigInt__FastCalc__one, file);
        newXS("Math::BigInt::FastCalc::_two", XS_Math__BigInt__FastCalc__two, file);
        newXS("Math::BigInt::FastCalc::_ten", XS_Math__BigInt__FastCalc__ten, file);
        newXS("Math::BigInt::FastCalc::_is_even", XS_Math__BigInt__FastCalc__is_even, file);
        newXS("Math::BigInt::FastCalc::_is_odd", XS_Math__BigInt__FastCalc__is_odd, file);
        newXS("Math::BigInt::FastCalc::_is_one", XS_Math__BigInt__FastCalc__is_one, file);
        newXS("Math::BigInt::FastCalc::_is_two", XS_Math__BigInt__FastCalc__is_two, file);
        newXS("Math::BigInt::FastCalc::_is_ten", XS_Math__BigInt__FastCalc__is_ten, file);
        newXS("Math::BigInt::FastCalc::_is_zero", XS_Math__BigInt__FastCalc__is_zero, file);
        newXS("Math::BigInt::FastCalc::_len", XS_Math__BigInt__FastCalc__len, file);
        newXS("Math::BigInt::FastCalc::_acmp", XS_Math__BigInt__FastCalc__acmp, file);
    if (PL_unitcheckav)
         call_list(PL_scopestack_ix, PL_unitcheckav);
    XSRETURN_YES;
}

