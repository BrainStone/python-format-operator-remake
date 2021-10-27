# python-format-operator-remake

An attempt to recreate the python format operator syntax as good as possible in modern C++

The syntax in question is this:

```py
"foo%s %d" % ("bar", 42) # -> "foobar 42"
```

## Goals

1. Make the syntax look as similar as possible.
2. Pass the arguments to C's `printf`-family functions. Do not reimplement the functionality (the challenge is about using the built in functions. Recreating `printf` as closely as possible would certainly also be an interesting challenge, but that's not what this about)
3. Convert `std::string` to `char*`, so they can be used with `printf`
4. Convert objects that can be streamed into an `std::ostream` into `char*` as well

## Status

1. Current syntax looks like `"foo%s %d" % _("bar", 42)`, which is impressively close, considering C++ doesn't have a raw list syntax.
2. This is currently the main issue. I haven't found a way to covert objects inside a container into multiple arguments or a `va_list` object
3. Blocked by 2, but should be fairly easy with template magic
4. Same as 3
