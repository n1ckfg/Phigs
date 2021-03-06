/* geotxt.f -- translated by f2c (version of 22 July 1992  22:54:52).
   You must link the resulting object file with the libraries:
	-lF77 -lI77 -lm -lc   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer doutyp, dintyp, dstdnr, dstrid, pstrid, dtclim, scrmod, dtxci, 
	    specwt;
    real dsize, efrac, dyxrat, syxrat, mtrpdc, wcpdc, qvis;
} dialog_;

#define dialog_1 dialog_

/* Table of constant values */

static integer c__102 = 102;
static integer c__1 = 1;
#ifndef NO_PROTO
static real c_b6 = 1.f;
static real c_b7 = 0.f;
#else /* NO_PROTO */
static real c_b6 = (float)1.;
static real c_b7 = (float)0.;
#endif /* NO_PROTO */
static integer c__0 = 0;
static integer c__4 = 4;
static integer c__3 = 3;
#ifndef NO_PROTO
static real c_b22 = .15f;
#else /* NO_PROTO */
static real c_b22 = (float).15;
#endif /* NO_PROTO */
static integer c__5 = 5;
#ifndef NO_PROTO
static real c_b39 = -1.f;
static real c_b43 = .5f;
static real c_b44 = 1.5f;
static real c_b45 = .1f;
static real c_b48 = 10.f;
static real c_b54 = .3f;
static real c_b55 = 2.f;
static real c_b56 = 3.5f;
#else /* NO_PROTO */
static real c_b39 = (float)-1.;
static real c_b43 = (float).5;
static real c_b44 = (float)1.5;
static real c_b45 = (float).1;
static real c_b48 = (float)10.;
static real c_b54 = (float).3;
static real c_b55 = (float)2.;
static real c_b56 = (float)3.5;
#endif /* NO_PROTO */
static integer c__2 = 2;
#ifndef NO_PROTO
static real c_b64 = -5.f;
static real c_b65 = 5.f;
#else /* NO_PROTO */
static real c_b64 = (float)-5.;
static real c_b65 = (float)5.;
#endif /* NO_PROTO */
static integer c__201 = 201;
static integer c__202 = 202;
static integer c__203 = 203;

#ifndef NO_PROTO
/* Subroutine */ int geotxt_(logical *useneg, integer *numlin, integer *
	ngline)
#else /* NO_PROTO */
/* Subroutine */ int geotxt_(useneg, numlin, ngline)
logical *useneg;
integer *numlin, *ngline;
#endif /* NO_PROTO */
{
    /* System generated locals */
    integer i__1;
    real r__1, r__2, r__3, r__4, r__5;

    /* Builtin functions */
#ifndef NO_PROTO
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_len(char *, ftnlen);
#else /* NO_PROTO */
    /* Subroutine */ int s_copy();
    integer i_len();
#endif /* NO_PROTO */

    /* Local variables */
    static real ma[16]	/* was [4][4] */, mb[16]	/* was [4][4] */, mc[
	    16]	/* was [4][4] */;
    static integer ix;
    static real tx, ty, tz, xhi;
#ifndef NO_PROTO
    extern /* Subroutine */ int etp_(real *, real *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp_();
#endif /* NO_PROTO */
    static real tdx[2], tdy[2], tdz[2], xlo;
    static integer txp;
    static real tpx, tpy, tpz;
#ifndef NO_PROTO
    extern /* Subroutine */ int vec1_(real *, real *, real *, real *, real *, 
	    real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int vec1_();
#endif /* NO_PROTO */
    static real xf2d[9]	/* was [3][3] */, xf3d[16]	/* was [4][4] */;
#ifndef NO_PROTO
    extern /* Subroutine */ int etp3_(real *, real *, real *, real *, real *, 
	    real *, real *), etr3_(real *, real *, real *, real *), ntx3 (
	    real *, real *, real *, real *, real *, real *, char *, ftnlen);
#else /* NO_PROTO */
    extern /* Subroutine */ int etp3_(), etr3_(), ntx3 ();
#endif /* NO_PROTO */
    static real hinc, chht;
#ifndef NO_PROTO
    extern doublereal vecl_(real *, real *, real *);
#else /* NO_PROTO */
    extern doublereal vecl_();
#endif /* NO_PROTO */
    static real vang, vtab[5], chsp, vinc, xmid, chxp, llex, lley, llez, corx,
	     cory, hsiz, corz, ypos, ytop, vsiz, txrx[2], txry[2];
#ifndef NO_PROTO
    extern /* Subroutine */ int ecom3_(real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ecom3_();
#endif /* NO_PROTO */
    static real rdum1, rdum2, achht;
    static integer nchar;
#ifndef NO_PROTO
    extern /* Subroutine */ int idmat_(integer *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int idmat_();
#endif /* NO_PROTO */
    static real achxp;
    static integer rnalh[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int ebltm_(real *, real *, real *, real *, real *,
	     real *, real *, real *), nschh (real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int ebltm_(), nschh ();
#endif /* NO_PROTO */
    static real clngx, clngy, clngz;
    static integer txalh;
    static real chsiz;
    static integer rnalv[20];
    static real yincr;
#ifndef NO_PROTO
    extern doublereal rndrl_(real *, real *);
#else /* NO_PROTO */
    extern doublereal rndrl_();
#endif /* NO_PROTO */
    static char chstr[3];
    static real chupx, chupy, upchx, upchy, upchz, rtchx;
    static integer txalv;
    static real rtchy, rtchz, cshtx, cshty, cshtz, nxtcx, nxtcy, nxtcz;
#ifndef NO_PROTO
    extern /* Subroutine */ int unmsg_(char *, ftnlen), nemst (integer *), 
	    nexst (integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int unmsg_(), nemst (), nexst ();
#endif /* NO_PROTO */
    static integer rntxp[20];
#ifndef NO_PROTO
    extern /* Subroutine */ int nstxp (integer *), nqtxx (integer *, integer *
	    , real *, real *, real *, integer *, integer *, integer *, char *,
	     integer *, real *, real *, real *, real *, ftnlen), ebltm3_(real 
	    *, real *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *, real *);
    extern doublereal satan2_(real *, real *);
    extern /* Subroutine */ int nsgmt3 (real *), nslmt3 (real *, integer *);
    extern doublereal vecang_(real *, real *, real *, real *, real *, real *);

    extern /* Subroutine */ int chkinq_(char *, integer *, ftnlen), numlab_(
	    integer *, real *, real *, real *);
#else /* NO_PROTO */
    extern /* Subroutine */ int nstxp (), nqtxx (), ebltm3_();
    extern doublereal satan2_();
    extern /* Subroutine */ int nsgmt3 (), nslmt3 ();
    extern doublereal vecang_();
    extern /* Subroutine */ int chkinq_(), numlab_();
#endif /* NO_PROTO */
    static real mcmidx, mcmidy;
    static integer errind;
    static real nombht;
#ifndef NO_PROTO
    extern integer rndint_(integer *, integer *);
#else /* NO_PROTO */
    extern integer rndint_();
#endif /* NO_PROTO */
    static real nomwid, chmult, mcmidz;
    static logical exchsp;
#ifndef NO_PROTO
    extern /* Subroutine */ int rnbset_(integer *, integer *, integer *, 
	    integer *), crossp_(real *, real *, real *, real *, real *, real *
	    , real *, real *, real *), nschxp (real *), nschsp (real *), 
	    nschup (real *, real *), nstxal (integer *, integer *);
#else /* NO_PROTO */
    extern /* Subroutine */ int rnbset_(), crossp_(), nschxp (), nschsp (), 
	    nschup (), nstxal ();
#endif /* NO_PROTO */

/*  GEOTXT generates a display of NUMLIN text primitives, whose */
/*  geometric aspects have been highly randomized.  It then outlines */
/*  their expected position, except for the one in line #NGLINE. */

/*  Input parameters: */
/*    USENEG : whether to use negative values for character expansion */
/*             factor, character spacing, and character height */
/*    NUMLIN : number of text primitives to generate */
/*  Output parameter: */
/*    NGLINE : position of the incorrectly outlined primitive */
/* composition type */
/*                preconcatenate  postconcatenate  replace */
/* text alignment horizontal */
/* text alignment vertical */
/* text path */
/*  values assigned to RNALV assume at least 5 lines */
    if (*numlin < 5) {
	unmsg_("GEOTXT called with #lines < 5.", 30L);
    }
    nemst (&c__102);
/*  Throughout, use text string "ELF", because letters are simple to */
/*  outline, and asymmetric (to reveal reversals). */
    s_copy(chstr, "ELF", 3L, 3L);
    nchar = i_len(chstr, 3L);
/*  Use <inquire text extent> to determine */
/*    nomwid = nominal character width for font #1 */
/*    nombht = nominal character body height for font #1 */
/*    vtab   = list of nominal offsets for the various vertical */
/*             text alignments, relative to BASE. */
/*  nominal quantities are for char-ht=1, char-sp=0, char-xp=1 */
    nqtxx (&dialog_1.specwt, &c__1, &c_b6, &c_b7, &c_b6, &c__0, &c__1, &c__4, 
	    chstr, &errind, txrx, txry, &rdum1, &rdum2, 3L);
    chkinq_("pqtxx", &errind, 5L);
    nomwid = (r__1 = txrx[1] - txrx[0], dabs(r__1)) / nchar;
    nombht = (r__1 = txry[1] - txry[0], dabs(r__1));
    vtab[0] = txry[1];
#ifndef NO_PROTO
    vtab[1] = 1.f;
    vtab[3] = 0.f;
#else /* NO_PROTO */
    vtab[1] = (float)1.;
    vtab[3] = (float)0.;
#endif /* NO_PROTO */
    vtab[4] = txry[0];
    nqtxx (&dialog_1.specwt, &c__1, &c_b6, &c_b7, &c_b6, &c__0, &c__1, &c__3, 
	    chstr, &errind, txrx, txry, &rdum1, &rdum2, 3L);
    chkinq_("pqtxx", &errind, 5L);
    vtab[2] = vtab[4] - txry[0];
/*  ngline = random integer from 1 to NUMLIN */
    *ngline = rndint_(&c__1, numlin);
#ifndef NO_PROTO
    yincr = 1.f / (*numlin + 1);
#else /* NO_PROTO */
    yincr = (float)1. / (*numlin + 1);
#endif /* NO_PROTO */
    ytop = 1 - yincr;
    ypos = ytop;
/*  display text between 0.2 and 1.0 */
#ifndef NO_PROTO
    xlo = .2f;
    xhi = 1.f;
#else /* NO_PROTO */
    xlo = (float).2;
    xhi = (float)1.;
#endif /* NO_PROTO */
    xmid = (xlo + xhi) / 2;
    numlab_(numlin, &c_b22, &ytop, &yincr);
/*  random order for text paths, alignments - make sure each possible */
/*  value is chosen at least once */
    rnbset_(&c__4, &c__0, &c__3, rntxp);
    rnbset_(&c__3, &c__1, &c__3, rnalh);
    rnbset_(&c__5, &c__1, &c__5, rnalv);
/*  display NUMLIN text strings */
    i__1 = *numlin;
    for (ix = 1; ix <= i__1; ++ix) {
/*  random choices for text path, text alignment */
	if (*numlin <= 4) {
	    txp = rntxp[*numlin - 1];
	} else {
	    txp = rndint_(&c__0, &c__3);
	}
	if (*numlin <= 3) {
	    txalh = rnalh[*numlin - 1];
	} else {
	    txalh = rndint_(&c__1, &c__3);
	}
	if (*numlin <= 5) {
	    txalv = rnalv[*numlin - 1];
	} else {
	    txalv = rndint_(&c__1, &c__5);
	}
/*  random values for character up vector */
	chupx = rndrl_(&c_b39, &c_b6);
	chupy = rndrl_(&c_b39, &c_b6);
/*  pick random positive values for character expansion factor, */
/*  character spacing, and character height. */
	chxp = rndrl_(&c_b43, &c_b44);
	chsp = rndrl_(&c_b45, &c_b6);
	chht = rndrl_(&c_b45, &c_b48);
/*  is character spacing so excessive as to reverse order of character
s? */
	exchsp = FALSE_;
	if (*useneg) {
/*  set up some negative values for character expansion factor, */

/*  character spacing, and character height. */
	    if (rndint_(&c__1, &c__4) > 1) {
		chht = -(doublereal)chht;
	    }
	    if (rndint_(&c__1, &c__4) > 1) {
		chxp = -(doublereal)chxp;
	    }
	    if (txp == 0 || txp == 1) {
		chsiz = chxp;
	    } else {
		chsiz = nombht;
	    }
	    if (ix <= 2) {
/*  slight overlap */
		chsp = -(doublereal)(r__1 = chsiz * rndrl_(&c_b45, &c_b54), 
			dabs(r__1));
	    } else if (ix <= 4) {
/*  Very negative character spacing to reverse normal text pat
h */
		chsp = -(doublereal)(r__1 = chsiz * rndrl_(&c_b55, &c_b56), 
			dabs(r__1));
		exchsp = TRUE_;
	    }
	}
/*  effective character height and expansion factor; only magnitude */

/*  should be used */
	achht = dabs(chht);
	achxp = dabs(chxp);
/*  distort expected outline for NGLINE */
	if (ix == *ngline) {
#ifndef NO_PROTO
	    achht *= rndint_(&c__1, &c__2) - .5f;
#else /* NO_PROTO */
	    achht *= rndint_(&c__1, &c__2) - (float).5;
#endif /* NO_PROTO */
	}
/*  Represent position of text primitive in MC as follows: */
/*    LLE  : 3D location of lower-left corner (LEFT,BASE) of "E" */
/*    NXTC : vector to next character */
/*    UPCH : character up 3D vector (direction and length) */
/*    RTCH : character right 3D vector (direction and length) */
/*    COR  : 3D location of (LEFT,BASE) corner of text extent rectangl
e */
/*    CLNG : vector from corner along long dimension of rectangle */
/*    CSHT : vector from corner along short dimension of rectangle */
/*  Calculate expected TLC position of text primitive: apply */
/*  attributes in this order: */
/*     1: character expansion, character spacing, and text path */
/*     2: text alignment */
/*     3: character up */
/*     4: character height */
/*  First, assume alignment of LEFT,BASE, character height = 1, */
/*  and apply character expansion, character spacing, and text path. 
*/
/*  Default LLE, NXTC, UPCH, RTCH */
#ifndef NO_PROTO
	llex = 0.f;
	lley = 0.f;
	llez = 0.f;
	nxtcx = 0.f;
	nxtcy = 0.f;
	nxtcz = 0.f;
	upchx = 0.f;
	upchy = 1.f;
	upchz = 0.f;
#else /* NO_PROTO */
	llex = (float)0.;
	lley = (float)0.;
	llez = (float)0.;
	nxtcx = (float)0.;
	nxtcy = (float)0.;
	nxtcz = (float)0.;
	upchx = (float)0.;
	upchy = (float)1.;
	upchz = (float)0.;
#endif /* NO_PROTO */
	rtchx = nomwid * achxp;
#ifndef NO_PROTO
	rtchy = 0.f;
	rtchz = 0.f;
	clngx = 0.f;
	clngy = 0.f;
	clngz = 0.f;
	cshtx = 0.f;
	cshty = 0.f;
	cshtz = 0.f;
#else /* NO_PROTO */
	rtchy = (float)0.;
	rtchz = (float)0.;
	clngx = (float)0.;
	clngy = (float)0.;
	clngz = (float)0.;
	cshtx = (float)0.;
	cshty = (float)0.;
	cshtz = (float)0.;
#endif /* NO_PROTO */
/*  character increment for RIGHT path */
	hinc = rtchx + chsp;
/*  character increment for UP path */
	vinc = nombht + chsp;
/*  set NXTC and LLE within text rectangle, based on text path and */
/*  character increment */
	if (txp == 0) {
	    nxtcx = hinc;
	    if (exchsp) {
		llex = (r__1 = hinc * (nchar - 1), dabs(r__1));
	    }
	} else if (txp == 1) {
	    nxtcx = -(doublereal)hinc;
	    if (! exchsp) {
		llex = (r__1 = hinc * (nchar - 1), dabs(r__1));
	    }
	} else if (txp == 2) {
	    nxtcy = vinc;
	    if (exchsp) {
		lley = (r__1 = vinc * (nchar - 1), dabs(r__1));
	    }
	} else if (txp == 3) {
	    nxtcy = -(doublereal)vinc;
	    if (! exchsp) {
		lley = (r__1 = vinc * (nchar - 1), dabs(r__1));
	    }
	} else {
	    unmsg_("Illegal text path generated in GEOTXT.", 38L);
	}
/*  step 2: compute location of corner (LEFT,BASE of rectangle) */
/*  based on text alignment.  HSIZ,VSIZ is size of rectangle */
/*  from baseline to capline. */
	if (txp == 0 || txp == 1) {
/*  horizontal path */
	    hsiz = rtchx + dabs(hinc) * (nchar - 1);
	    vsiz = upchy;
	    cory = -(doublereal)vtab[txalv - 1];
	} else {
/*  vertical path */
	    hsiz = rtchx;
	    vsiz = upchy + dabs(vinc) * (nchar - 1);
	    if (txalv == 1 || txalv == 2) {
/*  align relative to top character */
		chmult = (real) (nchar - 1);
	    } else if (txalv == 3) {
/*  align relative to middle character */
#ifndef NO_PROTO
		chmult = (nchar - 1) / 2.f;
#else /* NO_PROTO */
		chmult = (nchar - 1) / (float)2.;
#endif /* NO_PROTO */
	    } else {
/*  align relative to bottom character */
#ifndef NO_PROTO
		chmult = 0.f;
#else /* NO_PROTO */
		chmult = (float)0.;
#endif /* NO_PROTO */
	    }
	    cory = -(doublereal)chmult * dabs(vinc) - vtab[txalv - 1];
	}
#ifndef NO_PROTO
	corx = -(doublereal)hsiz * (txalh - 1.f) / 2.f;
	corz = 0.f;
#else /* NO_PROTO */
	corx = -(doublereal)hsiz * (txalh - (float)1.) / (float)2.;
	corz = (float)0.;
#endif /* NO_PROTO */
/*  offset LLE by location of corner */
	llex += corx;
	lley += cory;
/*  find long, short axis of rectangle */
	if (hsiz > vsiz) {
	    clngx = hsiz;
	    cshty = vsiz;
	} else {
	    clngy = vsiz;
	    cshtx = hsiz;
	}
/* step 3 and 4: apply 2D character-up rotation and character height s
caling*/
/*  to rotate parameters within TLC plane. */
	r__2 = -(doublereal)chupx;
	r__1 = satan2_(&r__2, &chupy);
	ebltm_(&c_b7, &c_b7, &c_b7, &c_b7, &r__1, &achht, &achht, xf2d);
#ifndef NO_PROTO
	r__1 = llex + 0.f;
	r__2 = lley + 0.f;
#else /* NO_PROTO */
	r__1 = llex + (float)0.;
	r__2 = lley + (float)0.;
#endif /* NO_PROTO */
	etp_(&r__1, &r__2, xf2d, &llex, &lley);
#ifndef NO_PROTO
	r__1 = nxtcx + 0.f;
	r__2 = nxtcy + 0.f;
#else /* NO_PROTO */
	r__1 = nxtcx + (float)0.;
	r__2 = nxtcy + (float)0.;
#endif /* NO_PROTO */
	etp_(&r__1, &r__2, xf2d, &nxtcx, &nxtcy);
#ifndef NO_PROTO
	r__1 = upchx + 0.f;
	r__2 = upchy + 0.f;
#else /* NO_PROTO */
	r__1 = upchx + (float)0.;
	r__2 = upchy + (float)0.;
#endif /* NO_PROTO */
	etp_(&r__1, &r__2, xf2d, &upchx, &upchy);
#ifndef NO_PROTO
	r__1 = rtchx + 0.f;
	r__2 = rtchy + 0.f;
#else /* NO_PROTO */
	r__1 = rtchx + (float)0.;
	r__2 = rtchy + (float)0.;
#endif /* NO_PROTO */
	etp_(&r__1, &r__2, xf2d, &rtchx, &rtchy);
#ifndef NO_PROTO
	r__1 = corx + 0.f;
	r__2 = cory + 0.f;
#else /* NO_PROTO */
	r__1 = corx + (float)0.;
	r__2 = cory + (float)0.;
#endif /* NO_PROTO */
	etp_(&r__1, &r__2, xf2d, &corx, &cory);
#ifndef NO_PROTO
	r__1 = clngx + 0.f;
	r__2 = clngy + 0.f;
#else /* NO_PROTO */
	r__1 = clngx + (float)0.;
	r__2 = clngy + (float)0.;
#endif /* NO_PROTO */
	etp_(&r__1, &r__2, xf2d, &clngx, &clngy);
#ifndef NO_PROTO
	r__1 = cshtx + 0.f;
	r__2 = cshty + 0.f;
#else /* NO_PROTO */
	r__1 = cshtx + (float)0.;
	r__2 = cshty + (float)0.;
#endif /* NO_PROTO */
	etp_(&r__1, &r__2, xf2d, &cshtx, &cshty);
/*  Correct TLC values for LLE, NXTC, UPCH, RTCH, COR, CLNG, CSHT */
/*  now computed; */
/*  pick random values for text position and direction vectors */
	tpx = rndrl_(&c_b64, &c_b65);
	tpy = rndrl_(&c_b64, &c_b65);
	tpz = rndrl_(&c_b64, &c_b65);
L105:
	tdx[0] = rndrl_(&c_b64, &c_b65);
	tdy[0] = rndrl_(&c_b64, &c_b65);
	tdz[0] = rndrl_(&c_b64, &c_b65);
L110:
	tdx[1] = rndrl_(&c_b64, &c_b65);
	tdy[1] = rndrl_(&c_b64, &c_b65);
	tdz[1] = rndrl_(&c_b64, &c_b65);
/*  get fairly stable vectors - not too parallel - check angle */
/*  between vectors. */
#ifndef NO_PROTO
	vang = vecang_(tdx, tdy, tdz, &tdx[1], &tdy[1], &tdz[1]) * 180 / 
		3.14159265f;
	if ((r__1 = vang - 90, dabs(r__1)) > 87.f) {
#else /* NO_PROTO */
	vang = vecang_(tdx, tdy, tdz, &tdx[1], &tdy[1], &tdz[1]) * 180 / (
		float)3.14159265;
	if ((r__1 = vang - 90, dabs(r__1)) > (float)87.) {
#endif /* NO_PROTO */
	    goto L110;
	}
/*  set up matrix to do TLC -> MC rotation; start with identity matrix
 */
	idmat_(&c__4, xf3d);
/*  compute unit vectors expressing TLC directions within MC - */
/*  build these into columns of transformation matrix. */
/*  TLC X-direction = 1st vector, scaled to unit size */
	vec1_(tdx, tdy, tdz, xf3d, &xf3d[1], &xf3d[2]);
/*  TLC Z-direction = 1st x 2nd vector, scaled to unit size */
	crossp_(tdx, tdy, tdz, &tdx[1], &tdy[1], &tdz[1], &tx, &ty, &tz);
	vec1_(&tx, &ty, &tz, &xf3d[8], &xf3d[9], &xf3d[10]);
/*  make sure not too oblique (check z-component of TLC z-vector); */
/*  if so, retry */
/* Computing 2nd power */
	r__1 = xf3d[10];
#ifndef NO_PROTO
	if (r__1 * r__1 < .5f) {
#else /* NO_PROTO */
	if (r__1 * r__1 < (float).5) {
#endif /* NO_PROTO */
	    goto L105;
	}
/*  TLC Y-direction = Z-direction x X-direction */
	crossp_(&xf3d[8], &xf3d[9], &xf3d[10], xf3d, &xf3d[1], &xf3d[2], &
		xf3d[4], &xf3d[5], &xf3d[6]);
/*  Now, calculate expected MC position of text primitive. */
/*  rotate vectors from TLC to MC (rotate only, not shift): */
#ifndef NO_PROTO
	r__1 = nxtcx + 0.f;
	r__2 = nxtcy + 0.f;
	r__3 = nxtcz + 0.f;
#else /* NO_PROTO */
	r__1 = nxtcx + (float)0.;
	r__2 = nxtcy + (float)0.;
	r__3 = nxtcz + (float)0.;
#endif /* NO_PROTO */
	etp3_(&r__1, &r__2, &r__3, xf3d, &nxtcx, &nxtcy, &nxtcz);
#ifndef NO_PROTO
	r__1 = upchx + 0.f;
	r__2 = upchy + 0.f;
	r__3 = upchz + 0.f;
#else /* NO_PROTO */
	r__1 = upchx + (float)0.;
	r__2 = upchy + (float)0.;
	r__3 = upchz + (float)0.;
#endif /* NO_PROTO */
	etp3_(&r__1, &r__2, &r__3, xf3d, &upchx, &upchy, &upchz);
#ifndef NO_PROTO
	r__1 = rtchx + 0.f;
	r__2 = rtchy + 0.f;
	r__3 = rtchz + 0.f;
#else /* NO_PROTO */
	r__1 = rtchx + (float)0.;
	r__2 = rtchy + (float)0.;
	r__3 = rtchz + (float)0.;
#endif /* NO_PROTO */
	etp3_(&r__1, &r__2, &r__3, xf3d, &rtchx, &rtchy, &rtchz);
#ifndef NO_PROTO
	r__1 = clngx + 0.f;
	r__2 = clngy + 0.f;
	r__3 = clngz + 0.f;
#else /* NO_PROTO */
	r__1 = clngx + (float)0.;
	r__2 = clngy + (float)0.;
	r__3 = clngz + (float)0.;
#endif /* NO_PROTO */
	etp3_(&r__1, &r__2, &r__3, xf3d, &clngx, &clngy, &clngz);
#ifndef NO_PROTO
	r__1 = cshtx + 0.f;
	r__2 = cshty + 0.f;
	r__3 = cshtz + 0.f;
#else /* NO_PROTO */
	r__1 = cshtx + (float)0.;
	r__2 = cshty + (float)0.;
	r__3 = cshtz + (float)0.;
#endif /* NO_PROTO */
	etp3_(&r__1, &r__2, &r__3, xf3d, &cshtx, &cshty, &cshtz);
/*  add in shift to text position */
	xf3d[12] = tpx;
	xf3d[13] = tpy;
	xf3d[14] = tpz;
/*  transform points from TLC to MC: */
#ifndef NO_PROTO
	r__1 = llex + 0.f;
	r__2 = lley + 0.f;
	r__3 = llez + 0.f;
#else /* NO_PROTO */
	r__1 = llex + (float)0.;
	r__2 = lley + (float)0.;
	r__3 = llez + (float)0.;
#endif /* NO_PROTO */
	etp3_(&r__1, &r__2, &r__3, xf3d, &llex, &lley, &llez);
#ifndef NO_PROTO
	r__1 = corx + 0.f;
	r__2 = cory + 0.f;
	r__3 = corz + 0.f;
#else /* NO_PROTO */
	r__1 = corx + (float)0.;
	r__2 = cory + (float)0.;
	r__3 = corz + (float)0.;
#endif /* NO_PROTO */
	etp3_(&r__1, &r__2, &r__3, xf3d, &corx, &cory, &corz);
/*  Correct MC values for LLE, NXTC, UPCH, RTCH, COR, CLNG, CSHT */
/*  now computed */
/*  compute global modelling transform to re-locate text extent */
/*  rectangle (in MC) to display area for this line (in WC). */
	mcmidx = corx + clngx / 2 + cshtx / 2;
	mcmidy = cory + clngy / 2 + cshty / 2;
	mcmidz = corz + clngz / 2 + cshtz / 2;
/*  use MC midpoint as fixed point. */
/*  1st, rotate around Z-axis so as to make long axis horizontal */
	r__1 = -(doublereal)satan2_(&clngy, &clngx);
	ebltm3_(&mcmidx, &mcmidy, &mcmidz, &c_b7, &c_b7, &c_b7, &c_b7, &c_b7, 
		&r__1, &c_b6, &c_b6, &c_b6, mb);
/*  2nd, scale to fit in line area */
/*  3rd, shift to WC midpoint (= XMID,YPOS,0.5) */
	r__1 = xmid - mcmidx;
	r__2 = ypos - mcmidy;
#ifndef NO_PROTO
	r__3 = .5f - mcmidz;
	r__4 = (xhi - xlo) * .8f / vecl_(&clngx, &clngy, &c_b7);
	r__5 = yincr * .7f / vecl_(&cshtx, &cshty, &c_b7);
#else /* NO_PROTO */
	r__3 = (float).5 - mcmidz;
	r__4 = (xhi - xlo) * (float).8 / vecl_(&clngx, &clngy, &c_b7);
	r__5 = yincr * (float).7 / vecl_(&cshtx, &cshty, &c_b7);
#endif /* NO_PROTO */
	ebltm3_(&mcmidx, &mcmidy, &mcmidz, &r__1, &r__2, &r__3, &c_b7, &c_b7, 
		&c_b7, &r__4, &r__5, &c_b7, mc);
	ecom3_(mc, mb, ma);
	nsgmt3 (ma);
/*  re-set local transformation to identity; only global applies to */

/*  actual text primitive. */
	idmat_(&c__4, ma);
	nslmt3 (ma, &c__2);
/*  generate text primitive, with chosen attributes and geometry */
	nschxp (&chxp);
	nschsp (&chsp);
	nschh (&chht);
	nschup (&chupx, &chupy);
	nstxp (&txp);
	nstxal (&txalh, &txalv);
	ntx3 (&tpx, &tpy, &tpz, tdx, tdy, tdz, chstr, 3L);
/*  draw outline, using local transformations: */
/*    same scale, rotate and initial shift for all 3 letters - */
/*    use to transform nominal ELF outline to MC text locations. */
/*  after local transformations move outlines to MC, global */
/*  transformation, still in effect from above, will move them along 
*/
/*  with text to correct WC display area. */
	idmat_(&c__4, ma);
/*  rotate and scale nominal as per RTCH and UPCH. */
	ma[0] = rtchx;
	ma[1] = rtchy;
	ma[2] = rtchz;
	ma[4] = upchx;
	ma[5] = upchy;
	ma[6] = upchz;
/*  shift to position of "E" */
	ma[12] = llex;
	ma[13] = lley;
	ma[14] = llez;
/*  set up transformation for E: */
	nslmt3 (ma, &c__2);
	nexst (&c__201);
/*  set up shift over for next letter, as per NXTC */
	etr3_(&nxtcx, &nxtcy, &nxtcz, ma);
/*  set up transformation for L: */
	nslmt3 (ma, &c__1);
	nexst (&c__202);
/*  set up transformation for F: */
	nslmt3 (ma, &c__1);
	nexst (&c__203);
/*  next line */
	ypos -= yincr;
/* L100: */
    }
#ifndef NO_PROTO
    return 0;
#endif /* not NO_PROTO */
} /* geotxt_ */

