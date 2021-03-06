      SUBROUTINE E04152 (USEPRM)

C    E04152 tests the handling of error 152

      COMMON /GLOBNU/ CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT, DUMRL
      INTEGER         CTLHND, ERRSIG, ERRFIL, IERRCT, UNERR,
     1        TESTCT, IFLERR, PASSSW, ERRSW, MAXLIN,
     2        CONID, MEMUN, WKID, WTYPE, GLBLUN, INDLUN,
     3        DUMINT(20), ERRIND
      REAL    DUMRL(20)

      COMMON /ERRINF/ ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR,
     1                USRERR, ERRSAV,      FUNSAV,      FILSAV,
     2                EFCNT, EFID
      INTEGER         ERRCOM,FUNCOM,FILCOM, ERNMSW, EXPSIZ,EXPERR(10),
     1                USRERR, ERRSAV(200), FUNSAV(200), FILSAV(200),
     2                EFCNT, EFID(100)
      COMMON /ERRCHR/ CURCON,     ERRSRS,    ERRMRK,    ERFLNM,
     1                CONTAB
      CHARACTER       CURCON*200, ERRSRS*40, ERRMRK*20, ERFLNM*80,
     1                CONTAB(40)*150

      INTEGER   SPECWT, USEPRM, IDUM1,IDUM2,IDUM3, IDUM4
      REAL      WKVP(6),WKVP0(6),WKVP1(6),RDUMA(6),RDUMB(6),RDUMC(6)
      REAL      WKVP4(4),RDUMD(4),RDUME(4),RDUMF(4)
      REAL      DX,DY,DZ,XX,YY,ZZ
      LOGICAL   STREQ, APPEQ, RAREQ

      CURCON = 'the specified workstation viewport limits are '//
     1         'invalid: XMIN>=XMAX, YMIN>=YMAX, or ZMIN>ZMAX'
      CALL SETVS ('152', EXPERR, EXPSIZ)
      ERRSRS = '3'
      CALL ESETUP (USEPRM)

      CALL POPWK (WKID, CONID, WTYPE)
      CALL PQWKC (WKID, ERRIND, CONID, SPECWT)
      CALL CHKINQ ('pqwkc', ERRIND)

      CALL PQDSP3 (SPECWT,ERRIND,IDUM1,DX,DY,DZ,IDUM2,IDUM3,IDUM4)
      CALL CHKINQ ('pqdsp3', ERRIND)
      XX = DX/2.
      YY = DY/2.
      ZZ = DZ/2.

      CALL DS3 (0.,XX,0.,YY,0.,ZZ,WKVP0)
      CALL PSWKV3 (WKID, WKVP0)

      CALL DS3 (XX,0.,0.,DY,0.,DZ,WKVP)
      CALL RSWKV3 (WKID, WKVP)

      CALL DS3 (DX,DX,0.,YY,0.,DZ,WKVP)
      CALL RSWKV3 (WKID, WKVP)

      CALL DS3 (0.,DX,0.,DY,ZZ,0.,WKVP)
      CALL RSWKV3 (WKID, WKVP)

      CALL DS3 (0.,DX,YY,YY,ZZ,ZZ,WKVP)
      CALL RSWKV3 (WKID, WKVP)

      CALL PQWKT3 (WKID,ERRIND,IDUM1,RDUMA,RDUMB,WKVP1,RDUMC)
      CALL CHKINQ ('pqwkt3', ERRIND)
      CALL TSTIGN (STREQ('OO**')      .AND.
     1             RAREQ(6,WKVP1,WKVP0,0.01,0.01))

      CALL PQDSP (SPECWT,ERRIND,IDUM1,DX,DY,IDUM2,IDUM3)
      CALL CHKINQ ('pqdsp', ERRIND)
      XX = DX/2.
      YY = DY/2.

      CALL PSWKV (WKID, 0.,XX,0.,YY)

      CALL RSWKV (WKID, XX,0.,0.,DY)
      CALL RSWKV (WKID, 0.,DX,YY,0.)
      CALL RSWKV (WKID, 0.,XX,YY,YY)

      CALL PQWKT (WKID,ERRIND,IDUM1,RDUMD,RDUME,WKVP4,RDUMF)
      CALL CHKINQ ('pqwkt', ERRIND)
      CALL TSTIGN (STREQ('OO**')     .AND.
     1             APPEQ(WKVP4(1),0.,0.01,0.001)    .AND.
     2             APPEQ(WKVP4(2),XX,0.01,0.001)    .AND.
     3             APPEQ(WKVP4(3),0.,0.01,0.001)    .AND.
     4             APPEQ(WKVP4(4),YY,0.01,0.001))

      CALL PCLWK (WKID)

      CALL ENDERR

      END
