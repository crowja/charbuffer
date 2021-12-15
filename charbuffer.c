/**
 *  @file charbuffer.c
 *  @version 0.0.0
 *  @date
 *  @copyright
 *  @license Unlicense <http://unlicense.org/>
 */

#include <stdlib.h>
#include <stdio.h>                               /* FIXME */
#include <string.h>                              /* FIXME */
#include "charbuffer.h"

#ifdef  IS_NULL
#undef  IS_NULL
#endif
#define IS_NULL(p)   ((NULL == (p)) ? (1) : (0))

#ifdef  FREE
#undef  FREE
#endif
#define FREE(p)      ((NULL == (p)) ? (0) : (free((p)), (p) = NULL))

struct charbuf {
   char     *buffer;
   unsigned  len;
   unsigned  size;
};

struct charbuf *
charbuf_new(void)
{
   struct charbuf *tp;

   tp = (struct charbuf *) malloc(sizeof(struct charbuf));
   if (IS_NULL(tp))
      return NULL;

   tp->buffer = NULL;

   return tp;
}

void
charbuf_free(struct charbuf **pp)
{

   /* Do some magic here ... */

   FREE(*pp);
   *pp = NULL;
}

int
charbuf_init(struct charbuf *p, void *x)
{

   /* Do some magic here ... */

   return 0;
}

const char *
charbuf_version(void)
{
   return "0.0.0";
}

#undef  IS_NULL
#undef  FREE
