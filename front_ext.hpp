#ifndef FRONT_EXT_H
#define FRONT_EXT_H

#include <boost/mpl/push_front.hpp>
#include <boost/mpl/pop_front.hpp>

namespace boost { namespace mpl {

template<typename T, typename... Args>
struct push_front< T, nlist<Args...> > {
  typedef nlist<T, Args...> type;
};

template<typename Head, typename... Args>
struct pop_front< nlist<Head, Args...> > {
  typedef nlist<Args...> type;
};

} // mpl
} // boost

#endif /* FRONT_EXT_H */
