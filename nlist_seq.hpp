#ifndef NLIST_SEQ_H
#define NLIST_SEQ_H

#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/front.hpp>

// aux
#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>

namespace boost { namespace mpl {

template<typename... Args>
struct begin< nlist<Args...> > {
  typedef nlist<Args...> type;
};

template<typename... Args>
struct end< nlist<Args...> > {
  typedef empty_nlist type;
};

template<typename... Args>
struct size< nlist<Args...> > {
  typedef int_< sizeof...(Args) > type;
};

template<typename... Args>
struct empty< nlist<Args...> > {
  typedef bool_<false> type;
};

template<>
struct empty< empty_nlist > {
  typedef bool_<true> type;
};

template<typename Head, typename... Args>
struct front< nlist<Head, Args...> > {
  typedef Head type;
};

} // mpl 
} // boost

#endif /* NLIST_SEQ_H */
