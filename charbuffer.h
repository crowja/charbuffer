/**
 *  @file charbuffer.h
 *  @version 0.0.0
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
 *  @brief Initialize a charbuf object.
 *  @details FIXME longer description here ...
 *  @param[in,out] p Pointer to a charbuf object
 *  @param[in] x FIXME
    @returns FIXME
 */
int       charbuf_init(struct charbuf *p, void *x);

/**
 *  @brief Return the version of this package.
 *  @returns Version string.
 */
const char *charbuf_version(void);

#endif
