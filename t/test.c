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

   return TEST_REPORT();
}
