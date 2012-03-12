#include "nlist.hpp"

#include <type_traits>

int main()
{
  
  typedef nlist<int, float, char> list;
  typedef nlist<int> singular_list;
  using namespace boost::mpl;

  // empty and front
  static_assert(std::is_same< front<list>::type, int >::value, "Front broken");
  static_assert(! empty<list>::type::value, "Not empty");
  static_assert(empty<empty_nlist>::type::value, "empty_nlist not empty");

  //size
  static_assert(size<list>::type::value == 3, "list size is not 3");
  static_assert(size<singular_list>::type::value == 1, "list size is not 1");
  static_assert(size< nlist<> >::type::value == 0, "list size is not 0");
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
  typedef nlist<int, float, char> A;
  typedef nlist<float, char> B;
  static_assert(std::is_same< push_front<int, B>::type, A >::value, "push_front");
  static_assert(std::is_same< pop_front<A>::type, B >::value, "pop_front");

  return 0;
}

