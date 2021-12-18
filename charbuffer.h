/**
 *  @file charbuffer.h
 *  @version 0.0.1-dev0
 *  @date
 *  @copyright
 *  @license Unlicense <http://unlicense.org/>
 */

#ifndef CHARBUFFER_H
#define CHARBUFFER_H

struct charbuf;

/**
 *  @brief Constructor.
 *  @details Create and return a new charbuf object.
 *  @returns New charbuf object.
 */
struct charbuf *charbuf_new(void);

/**
 *  @brief Destructor.
 *  @details Clean up and free a charbuf structure.
 *  @param[in, out] p.
 */
void      charbuf_free(struct charbuf **pp);

/**
 *  @brief Return the version of this package.
 *  @returns Version string.
 */
const char *charbuf_version(void);


const char *charbuf_expose(struct charbuf *p);
unsigned  charbuf_len(struct charbuf *p);
char      charbuf_pop(struct charbuf *p);
int       charbuf_push(struct charbuf *p, char c);
void      charbuf_reset(struct charbuf *p);

#endif
