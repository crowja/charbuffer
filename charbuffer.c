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
   unsigned  idx;
   unsigned  size;
   unsigned  extend;
};

struct charbuf *
charbuf_new(void)
{
   struct charbuf *tp;

   tp = (struct charbuf *) malloc(sizeof(struct charbuf));
   if (IS_NULL(tp))
      return NULL;

   tp->buffer = NULL;
   tp->idx = 0;
   tp->size = 0;
   tp->extend = 1024;

   return tp;
}

void
charbuf_free(struct charbuf **pp)
{

   FREE((*pp)->buffer);
   FREE(*pp);
   *pp = NULL;
}

const char *
charbuf_version(void)
{
   return "0.0.0";
}

const char *
charbuf_expose(struct charbuf *p)
{
   return (const char *) p->buffer;
}

unsigned
charbuf_len(struct charbuf *p)
{
   return p->idx;
}

int
charbuf_push(struct charbuf *p, char c)
{
   if (p->idx == p->size) {
      unsigned  need = p->size + p->extend;
      char     *tp = realloc(p->buffer, need * sizeof(char));

      if (IS_NULL(tp))
         return 1;

      p->buffer = tp;
      p->size = need;
   }

   (p->buffer)[p->idx] = c;
   p->idx += 1;

   return 0;
}

void
charbuf_reset(struct charbuf *p)
{
   p->idx = 0;
}


#undef  IS_NULL
#undef  FREE
