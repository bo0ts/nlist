#include "nlist.hpp"

#include <boost/mpl/begin_end.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/push_front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/clear.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/insert.hpp>

#include <type_traits>

int main()
{
  using namespace boost::mpl;
  using namespace nl;
  
  typedef nl::nlist<int, float, char> list;
  typedef nl::nlist<float, char> list2;


  typedef nl::nlist<int> singular_list;

  // empty and front
  static_assert(std::is_same< front<list>::type, int >::value, "Front broken");
  static_assert(! empty<list>::type::value, "Not empty");
  // static_assert(empty<empty_nlist>::type::value, "empty_nlist not empty");

  //size
  static_assert(size<list>::type::value == 3, "list size is not 3");
  static_assert(size<singular_list>::type::value == 1, "list size is not 1");
  // wot?
  static_assert(size< nl::nlist<> >::type::value == 0, "list size is not 0");
  static_assert(size<empty_nlist>::type::value == 0, "list size is not 0");

  // begin and end
  static_assert(std::is_same < begin<empty_nlist>::type, end<empty_nlist>::type >::value,
                "begin/end on empty_nlist are not the same");

  // iterator test
  static_assert(std::is_same< deref< begin< list >::type >::type, front<list>::type >::value,
                "Deref does not work");

  static_assert(std::is_same< next< begin<singular_list>::type >::type, end<singular_list>::type >::value,
                "next on singular breaks");
  
  // push_pop
  typedef nl::nlist<int, float, char> A;
  typedef nl::nlist<float, char> B;
  static_assert(std::is_same< push_front<B, int>::type, A >::value, "push_front");
  static_assert(std::is_same< pop_front<A>::type, B >::value, "pop_front");

  // push_back 
  typedef nl::nlist<int, float> C;
  static_assert(std::is_same< push_back<C, char>::type, A >::value, "push_back");
//  static_assert(std::is_same< pop_back<A>::type, B >::value, "pop_front");

  // clear
  static_assert(std::is_same< clear<B>::type, empty_nlist >::value, "clear");
  static_assert(std::is_same< clear<empty_nlist>::type, empty_nlist >::value, "clear");

  // insert

  typedef find< B, float >::type pos;

  typedef insert< B, pos, int >::type D;
  typedef find< A, float >::type pos2;
  typedef insert< A, pos2, int >::type D2;
  static_assert(std::is_same< A, D>::value, "insert");
  static_assert(std::is_same< D2, nlist<int, int, float, char> >::value, "insert");

  return 0;
}

