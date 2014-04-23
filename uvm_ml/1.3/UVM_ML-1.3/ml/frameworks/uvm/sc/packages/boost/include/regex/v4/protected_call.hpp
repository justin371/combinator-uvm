/*
 *
 * Copyright (c) 2004
 * John Maddock
 *
 * Use, modification and distribution are subject to the 
 * Boost Software License, Version 1.0. (See accompanying file 
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 *
 */

 /*
  *   LOCATION:    see http://www.boost.org for most recent version.
  *   FILE         basic_regex_creator.cpp
  *   VERSION      see <packages/boost/include/version.hpp>
  *   DESCRIPTION: Declares template class basic_regex_creator which fills in
  *                the data members of a regex_data object.
  */

#ifndef UVMSC_BOOST_REGEX_V4_PROTECTED_CALL_HPP
#define UVMSC_BOOST_REGEX_V4_PROTECTED_CALL_HPP

#ifdef UVMSC_BOOST_MSVC
#pragma warning(push)
#pragma warning(disable: 4103)
#endif
#ifdef UVMSC_BOOST_HAS_ABI_HEADERS
#  include UVMSC_BOOST_ABI_PREFIX
#endif
#ifdef UVMSC_BOOST_MSVC
#pragma warning(pop)
#endif

namespace uvmsc_boost{
namespace re_detail{

class UVMSC_BOOST_REGEX_DECL abstract_protected_call
{
public:
   bool UVMSC_BOOST_REGEX_CALL execute()const;
   // this stops gcc-4 from complaining:
   virtual ~abstract_protected_call(){}
private:
   virtual bool call()const = 0;
};

template <class T>
class concrete_protected_call
   : public abstract_protected_call
{
public:
   typedef bool (T::*proc_type)();
   concrete_protected_call(T* o, proc_type p)
      : obj(o), proc(p) {}
private:
   virtual bool call()const;
   T* obj;
   proc_type proc;
};

template <class T>
bool concrete_protected_call<T>::call()const
{
   return (obj->*proc)();
}

}
} // namespace uvmsc_boost

#ifdef UVMSC_BOOST_MSVC
#pragma warning(push)
#pragma warning(disable: 4103)
#endif
#ifdef UVMSC_BOOST_HAS_ABI_HEADERS
#  include UVMSC_BOOST_ABI_SUFFIX
#endif
#ifdef UVMSC_BOOST_MSVC
#pragma warning(pop)
#endif

#endif
