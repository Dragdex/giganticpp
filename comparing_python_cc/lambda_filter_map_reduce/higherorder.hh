#ifndef __HIGERORDER__
#define __HIGERORDER__

#include <algorithm>
#include <utility>
#include <iterator>
#include <tuple>
#include <functional>
#include <type_traits>

#include <vector>

namespace giganticpp {

    using namespace std;

    template <typename T>
        auto minsize(const T & t) {
            return t.size();
        }

    template <typename T, typename... Ts>
        auto minsize(const T & t, const Ts & ... ts) {
            auto m = minsize<>(t);
            auto n = minsize(ts...);

            return m <= n ? m : n;
        }

    template <class Tuple, class F, size_t... Is>
        constexpr auto apply_impl(Tuple && t, F && f, index_sequence<Is...>) {
            return invoke(forward<F>(f), get<Is>(forward<Tuple>(t))...);
        }

    template <class Tuple, class F>
        constexpr auto apply(Tuple & t, F && f) {
            return apply_impl(t, f, make_index_sequence<tuple_size<Tuple>{}>{});
            return apply_impl(
                    forward<Tuple>(t),
                    forward<F>(f),
                    // make_index_sequence<tuple_size<Tuple>{}>{});
                   make_index_sequence<tuple_size<decay_t<Tuple>>::value> {});  
        }

    template <typename T, typename Rt = vector<typename T::value_type>, typename F, typename... Ts>
        auto mapf(F f, const T & t, const Ts & ... ts) {
            auto m = minsize(t, ts...);
            Rt r; 
            r.resize(m);
            for(auto i = 0u; i < m; i++) {
                auto tuples =  make_tuple(*next(begin(t),i), *next(begin(ts),i)...);
                auto v = apply<tuple<typename T::value_type, typename Ts::value_type ...>>(tuples, forward<F>(f));
                *next(begin(r),i) = move(v);
            }    
            return r;
        }

}


#endif  // #ifndef __HIGERORDER__
