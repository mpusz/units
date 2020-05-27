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
#include <units/physical/international/area.h>
#include <units/physical/international/force.h>
#include <units/physical/si/prefixes.h>
#include <units/quantity.h>

namespace units::physical::international {

struct poundforce_per_square_inch : named_unit<poundforce_per_square_inch, "psi", si::prefix> {};

struct dim_pressure : physical::dim_pressure<dim_pressure, poundforce_per_square_inch, dim_force, dim_area> {};

template<Unit U, Scalar Rep = double>
using pressure = quantity<dim_pressure, U, Rep>;

inline namespace literals {

// Ba
constexpr auto operator"" q_psi(unsigned long long l) { return pressure<poundforce_per_square_inch, std::int64_t>(l); }
constexpr auto operator"" q_psi(long double l) { return pressure<poundforce_per_square_inch, long double>(l); }

}  // namespace literals

}  // namespace units::physical::international
