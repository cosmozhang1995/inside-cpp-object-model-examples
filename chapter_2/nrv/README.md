As described in the book, defining an explicit copy constructor will lead to NRV optimization. And will save the time of calling a function which returns an object and holding the returned object into a newly declared variable, as the variable is constructed directly in the function.

However, GCC seems to be always making NRV optimization no matter whether there is an explicit copy constructor. See our test:

```shell
$ ./run.sh
copy_count: 0.  time usage: 4141 usecs
copy_count: 0.  time usage: 4222 usecs
```

The first program has no copy constructor. The second program has a copy constructor which will accumulate a counter (`copy_count`). See that, the copy constructor in the second program is never called, which means in the second program NRV optimization is operated. While the first program takes almost as much time as the second, which implies that the same optimization is operated too.
