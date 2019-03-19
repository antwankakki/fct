//
// Created by Antwan Ibraheem on 2019-03-18.
//

#ifndef FCT_TRANSFORMATIONS_HPP
#define FCT_TRANSFORMATIONS_HPP
/*
 *  Copyright (c) 2019 Antwan Gaggi. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
 *  http://www.boost.org/LICENSE_1_0.txt)
 */

#include "list.hpp"

namespace fct
{
namespace transformation
{

/**
 * apply a given function (func) to each element of the list, returning a list of results.
 * @tparam B     The type of the new list
 * @tparam Func  The function to transform each element
 * @tparam A     The type of the input list
 * @tparam Seq   The data in the input list
 * @param listA  The input list.
 * @param f      The function to apply.
 * @return       A list of the result of applying f to the elements of the input list.
 */
template <typename Func, typename A, A... Seq>
constexpr auto Map(List<A, Seq...> listA, Func f) noexcept {
    return List<decltype(f(Head(listA))), f(Seq)...>{};
}

}
}
#endif //FCT_TRANSFORMATIONS_HPP
