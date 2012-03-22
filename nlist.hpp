//
//=======================================================================
// Author: Philipp Moeller
//
// Copyright 2012, Philipp Moeller
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================
//

#ifndef NLIST_H
#define NLIST_H

#include <boost/mpl/begin_end_fwd.hpp>
#include <boost/mpl/size_fwd.hpp>
#include <boost/mpl/empty_fwd.hpp>
#include <boost/mpl/front_fwd.hpp>
#include <boost/mpl/push_front_fwd.hpp>
#include <boost/mpl/pop_front_fwd.hpp>

#include <boost/mpl/int.hpp>
#include <boost/mpl/bool.hpp>

namespace nl {

struct nlist_tag {};

template<typename... Args>
struct nlist {
  typedef nlist_tag tag;
};

typedef nlist<> empty_nlist;

} // nlist

namespace boost { namespace mpl {

template<>
struct begin_impl< nl::nlist_tag > {
  template<typename T>
  struct apply {
      typedef T type;
  };
};

template<>
struct end_impl< nl::nlist_tag > {
  template<typename T>
  struct apply {
    typedef nl::empty_nlist type;
  };
};

template<>
struct size_impl< nl::nlist_tag > {
  template<typename T> struct apply;

  template<typename... Args>
  struct apply< nl::nlist<Args...> > {
    typedef int_< sizeof...(Args) > type;
  };
};

template<>
struct empty_impl< nl::nlist_tag > {
  template<typename> struct apply;

  template<typename... Args>
  struct apply< nl::nlist<Args...> > {
    typedef bool_<false> type;
  };
};

template<>
struct front_impl< nl::nlist_tag > {
  template<typename> struct apply;

  template<typename Head, typename... Args>
  struct apply< nl::nlist<Head, Args...> > {
    typedef Head type;
  };
};

// fwd declare deref and next
template<typename> struct deref;
template<typename> struct next;

template<typename Head, typename... Tail>
struct deref< nl::nlist<Head, Tail...> > {
  typedef Head type;
};

template<typename Head, typename... Tail>
struct next< nl::nlist<Head, Tail...> > {
  typedef nl::nlist<Tail...> type;
};

template<>
struct push_front_impl< nl::nlist_tag > {
  template<typename, typename> struct apply;

  template<typename... Args, typename T> 
  struct apply< nl::nlist<Args...>, T > {
    typedef nl::nlist<T, Args...> type;
  };
};

template<>
struct pop_front_impl< nl::nlist_tag > {
  template<typename> struct apply;
  template<typename Head, typename... Args> 
  struct apply< nl::nlist<Head, Args...> > {
    typedef nl::nlist<Args...> type;
  };
};


}}

#endif /* NLIST_H */
