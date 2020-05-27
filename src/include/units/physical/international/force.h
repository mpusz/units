// The MIT License (MIT)
//
// Copyright (c) 2018 Mateusz Pusz
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <units/physical/dimensions.h>
#include <units/physical/international/acceleration.h>
#include <units/physical/international/mass.h>
#include <units/physical/si/prefixes.h>
#include <units/quantity.h>

namespace units::physical::international {

struct poundforce : named_unit<poundforce, "lbf", si::prefix> {};

struct dim_force : physical::dim_force<dim_force, poundforce, dim_mass, dim_acceleration> {};

template<Unit U, Scalar Rep = double>
using force = quantity<dim_force, U, Rep>;

inline namespace literals {

// dyn
constexpr auto operator"" q_lbf(unsigned long long l) { return force<poundforce, std::int64_t>(l); }
constexpr auto operator"" q_lbf(long double l) { return force<poundforce, long double>(l); }

}  // namespace literals

}  // namespace units::physical::international
