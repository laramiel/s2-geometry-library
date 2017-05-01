# s2-geometry-library

* License: Apache 2.0 (see `COPYING`)
* Upstream: https://code.google.com/archive/p/s2-geometry-library/ (unmaintained)
* Branched from: <https://github.com/yjwong/s2-geometry-library>
* With fixes from [micolous](https://github.com/micolous/), [silicontrip](https://github.com/silicontrip/) and [yjwong](https://github.com/yjwong/).

This package is pruned to build with bazel and to use with as a C++ experiment.
It is not inteded for general use/


## Dependencies

You'll need the development (-dev or -devel) versions of these libraries in order to build the library.

- OpenSSL (used for [BIGNUM](https://www.openssl.org/docs/manmaster/crypto/bn.html) functions)

You'll need these build-time dependencies:

- Bazel

A C++ compiler supporting C++11 (g++ 4.8 or later, clang 3.3 or later) is also required.

