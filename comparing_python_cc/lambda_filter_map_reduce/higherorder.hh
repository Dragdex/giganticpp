#ifndef __HIGERORDER__
#define __HIGERORDER__

#include <algorithm>
#include <utility>
#include <iterator>
#include <tuple>

#include <vector>

namespace giganticpp {

    using namespace std;

    template <typename T>
        auto minsize(const T & t) {
            return make_pair<>(t, t.size());
        }

    template <typename T, typename... Ts>
        auto minsize(const T & t, const Ts & ... ts) {
            auto m = minsize<>(t);
            auto n = minsize(ts...);

            return m.second <= n.second ? m : n;
        }

    struct mapf {
        template <typename F, typename T, typename... Ts>
            auto operator ()(F f, const T & t, const Ts & ... ts) {
                //auto tuplesv =  make_tuple(t, ts...);
                auto m = minsize(t, ts...);
                auto r(m.first); 
                for(auto i = 0u; i < m.second; i++) {
                    auto tuples =  make_tuple(*next(begin(t),i), *next(begin(ts),i)...);
                    auto v = apply(tuples, f);
                    *next(begin(r),i) = move(v);
                }    
                return r;
            }

        private:
        template <class Tuple, class F, size_t... Is>
            constexpr auto apply_impl(Tuple t, F f, index_sequence<Is...>) {
                return f(get<Is>(t)...);
            }

        template <class Tuple, class F>
            constexpr auto apply(Tuple t, F f) {
                return apply_impl(t, f, make_index_sequence<tuple_size<Tuple>{}>{});
            }

    };

    }


#endif  // #ifndef __HIGERORDER__
