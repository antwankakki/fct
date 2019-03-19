/*
 *  Copyright (c) 2019 Antwan Gaggi. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
 *  http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef FCT_LIBRARY_H
#define FCT_LIBRARY_H

#include <cstdlib>
#include <cstddef>

namespace fct
{

/**
 * A homogenous data structure that stores several elements of the same type, T.
 * @tparam T     The type of the elements this list holds
 * @tparam Seq   The elements of the first list
 */
template <typename T, T... Seq>
struct List {

    /**
     * returns the number of elements currently in the list.
     * @return the number of elements in the list
     */
    constexpr size_t size() const noexcept { return sizeof...(Seq); };
};

/**
 * Append two lists i.e Append([1, 2, 3], [4]) -> [1, 2, 3, 4]
 * @tparam T     The type of the elements this list holds
 * @tparam SeqA  The elements of the first list
 * @tparam SeqB  The elements of the second list
 * @param ListA  The first list
 * @param ListB  The second list
 * @return A list with the elements of the two above i.e [A_0, A_1, A_2... A_N, B_0, B_1... B_M]
 */
template <typename T, T... SeqA, T... SeqB>
constexpr auto Append(List<T, SeqA...>, List<T, SeqB...>) {
    return List<T, SeqA..., SeqB...>{};
}

/**
 * Extract the first element of a list, which must be non-empty.
 * @tparam T     The type of the elements this list holds
 * @tparam head  The head of the list
 * @tparam Seq   The rest of the list
 * @param list   The list itself.
 * @return       head.
 */
template <typename T, T head, T... Seq>
constexpr auto Head(List<T, head, Seq...> list) {
    static_assert(list.size() > 0, "Can't get head from an empty list.");
    return head;
}

/**
 * Extract the elements after the head of a list, which must be non-empty.
 * @tparam T     The type of element the list holds
 * @tparam head  The head of the list
 * @tparam Seq   The rest of the list
 * @param list   The list itself.
 * @return       The list without its head.
 */
template <typename T, T Head, T... Seq>
constexpr auto Tail(List<T, Head, Seq...> list) {
    static_assert(list.size() > 0, "Can't get tail from an empty list.");
    return List<T, Seq...>{};
}

}
#endif //FCT_LIBRARY_H