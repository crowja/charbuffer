#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "charbuffer.h"
#include "t/tinytest.h"
#include "t/tinyhelp.h"

static void
test_constr(void)
{
   struct charbuf *z;

   fprintf_test_info(stdout, "test_constr", "charbuf_new, charbuf_free");
   z = charbuf_new();
   ASSERT("Constructor test", z);
   charbuf_free(&z);
   ASSERT_EQUALS(NULL, z);
}

static void
test01(void)
{
   struct charbuf *z;
   unsigned  i, niter = 20000;

   fprintf_test_info(stdout, "test01", "The whole damn lot of them ...");
   z = charbuf_new();
   ASSERT("test01", z);

   ASSERT_EQUALS(0, charbuf_len(z));

   for (i = 0; i < niter; i++) {
      charbuf_push(z, 'a');
      charbuf_push(z, 'A');
      charbuf_push(z, 'B');
      ASSERT_EQUALS(3 + 3 * i, charbuf_len(z));
   }
   ASSERT_EQUALS(3 * niter, charbuf_len(z));

   for (i = 0; i < niter;) {
      ASSERT_EQUALS('a', (charbuf_expose(z))[i]);
      i++;
      ASSERT_EQUALS('A', (charbuf_expose(z))[i]);
      i++;
      ASSERT_EQUALS('B', (charbuf_expose(z))[i]);
      i++;
   }

   charbuf_reset(z);
   ASSERT_EQUALS(0, charbuf_len(z));

   charbuf_free(&z);
   ASSERT_EQUALS(NULL, z);
}

#if 0                                            /* 12 yy */
static void
test_stub(void)
{
   struct charbuf *z;

   fprintf_test_info(stdout, "test_stub", NULL);
   z = charbuf_new();
   ASSERT("Constructor test, pt 1", z);
   ASSERT_EQUALS(10, 10);
   charbuf_free(&z);
   ASSERT_EQUALS(NULL, z);
}
#endif

int
main(void)
{
   printf("%s\n", charbuf_version());

   RUN(test_constr);
   RUN(test01);

   return TEST_REPORT();
}
