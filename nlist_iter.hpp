#ifndef NLIST_ITER_H
#define NLIST_ITER_H

#include <boost/mpl/deref.hpp>
// no pure header for next
#include <boost/mpl/next_prior.hpp>

namespace boost { namespace mpl {

template<typename Head, typename... Tail>
struct deref< nlist<Head, Tail...> > {
  typedef Head type;
};

template<typename Head, typename... Tail>
struct next< nlist<Head, Tail...> > {
  typedef nlist<Tail...> type;
};

} // mpl
} // boost


#endif /* NLIST_ITER_H */
