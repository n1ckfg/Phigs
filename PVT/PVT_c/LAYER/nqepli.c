#include <phigs.h>
#include "f2c.h"

/**************************************************************************
NAME
     INQUIRE LIST OF POLYLINE INDICES- obtain  list  of  polyline
     indices defined on specified workstation

  FORTRAN Syntax
     SUBROUTINE pqepli ( WKID, N, ERRIND, OL, PLI )
     INTEGER     WKID              workstation identifier
     INTEGER     N                 list element requested
     INTEGER     ERRIND            OUT error indicator
     INTEGER     OL                OUT number of polyline bundle table entries
     INTEGER     PLI               OUT Nth element of list of defined polyline
                                   indices
**************************************************************************/
#ifdef NO_PROTO
nqepli (wkid, n, errind, ol, pli)
   integer  *wkid,
            *n,
            *errind,
            *ol,
            *pli;
#else
nqepli (integer *wkid, integer *n, integer *errind, integer *ol, integer *pli)
#endif
{
   Pint_list indi;
   Pint      length, cerror, start;
   Pint      total_length;

/***  If n =  0, return size of the list  ***/
/***  If n != 0, return nth element  of the list  ***/

   start = *n - (*n > 0);
   length = (*n != 0);

   indi.ints = (Pint *) calloc (1, sizeof (Pint));

/**************************************************************************
  C Syntax
     void
     pinq_list_line_inds ( ws, length, start, errind, indices, total_length )
     Pint        ws;               workstation identifier
     Pint        length;           length of application list
     Pint        start;            starting position
     Pint        *errind;          OUT error indicator
     Pint_list   *indices;         OUT list of polyline indices
     Pint        *total_length;    OUT length of list in PHIGS
**************************************************************************/

   pinq_list_line_inds ((Pint) *wkid, length, start, &cerror, &indi, 
                        &total_length);
   *errind = cerror;

   *ol = total_length;
   if (indi.num_ints == 1)
      *pli = indi.ints[0];

   free (indi.ints);
}
