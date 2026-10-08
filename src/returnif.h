#ifndef RETURNIF_H
#define RETURNIF_H

#define RETURNIF_1ARG(condition) {              \
  if ((condition)) {                            \
    return;                                     \
  }                                             \
}

#define RETURNIF_2ARG(condition, returnValue) { \
  if ((condition)) {                            \
    return (returnValue);                       \
  }                                             \
}

// ********************************************************

// Source - https://stackoverflow.com/a/11763277
// Posted by netcoder, modified by community. See post 'Timeline' for change history
// Retrieved 2026-10-08, License - CC BY-SA 4.0

#define RETURNIF_EXPAND(x) x
#define RETURNIF_GET_MACRO(_1, _2, name, ...) name
#define returnif(...)    RETURNIF_EXPAND( RETURNIF_GET_MACRO(__VA_ARGS__, RETURNIF_2ARG, RETURNIF_1ARG)(__VA_ARGS__) )

// ********************************************************

#define continueif(condition) { \
  if ((condition)) {            \
    continue;                   \
  }                             \
}

#define breakif(condition) { \
  if ((condition)) {         \
    break;                   \
  }                          \
}


#endif
