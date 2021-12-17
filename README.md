# charbuffer 0.0.0.

A pretty limited-purpose C scrap, but handy in the right places.

```c
z = charbuf_new()      /* return a charbuf */
charbuf_push(z, 'a')    /* push a char onto the buffer */
charbuf_expose(z)       /* returns the pointer to the internal buffer */
charbuf_reset(z)        /* restart/reuse the charbuff */
charbuf_free(&z)        /* free memory associated with z */
```

`charbuf_expose()` lets you access what you've accumulated. The address it
returns may change in subsequent calls to `charbuf_push()`. It's not 
a null-terminated string.
