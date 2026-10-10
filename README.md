## ReturnIf

The header file `src/returnif.h` provides the following macros:
* `returnif`
* `continueif`
* `breakif`

These provide a means of collapsing, e.g.
```
if (condition) {
  return;
}
```
into
```
returnif(condition);
```

This is done with a set of macros; `continueif` and `breakif` function identically to the above. The macro `returnif` is overloaded so it can take either one or two arguments. The two-argument case is used for cases like:
```
if (condition) {
  return retval;
}
```
which becomes
```
returnif(condition, retval);
```

For some example of usages, see [test.c](test/test.c).

Moreover, `makefile` is endowed with the command `make test` which builds the tests and runs them.
Note that building was designed only with Linux in mind.

## Acknowledgements
The code for overloading the `returnif` macro was taken from [here](https://stackoverflow.com/a/11763277).
This is documented in `src/returnif.h`.
All other code was written by me, but an identical implementation of the single-argument `returnif` can be found [here](https://github.com/serbe-hindert/returnif). A similar implementation of an overloaded `returnif` statement can be found [here](https://github.com/azoyan/return_if-macro). The advantage here over both of these is the inclusion of analagous `continueif` and `breakif` statements.
