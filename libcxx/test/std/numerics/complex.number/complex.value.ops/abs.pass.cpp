//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// SPDX-FileCopyrightText: Copyright (c) 2023 NVIDIA CORPORATION & AFFILIATES.
//
//===----------------------------------------------------------------------===//


// <complex>

// template<class T>
//   T
//   abs(const complex<T>& x);

#include <complex>
#include <cassert>

#include "test_macros.h"
#include "../cases.h"

template <class T>
void
test()
{
    std::complex<T> z(3, 4);
    assert(abs(z) == 5);
}

void test_edges()
{
    const unsigned N = sizeof(testcases) / sizeof(testcases[0]);
    for (unsigned i = 0; i < N; ++i)
    {
        double r = abs(testcases[i]);
        switch (classify(testcases[i]))
        {
        case zero:
            assert(r == 0);
            assert(!std::signbit(r));
            break;
        case non_zero:
            assert(std::isfinite(r) && r > 0);
            break;
        case inf:
            assert(std::isinf(r) && r > 0);
            break;
        case NaN:
            assert(std::isnan(r));
            break;
        case non_zero_nan:
            assert(std::isnan(r));
            break;
        }
    }
}

int main(int, char**)
{
    test<float>();
    test<double>();
    test<long double>();
    test_edges();

  return 0;
}
