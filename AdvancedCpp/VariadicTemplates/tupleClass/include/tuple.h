#pragma once
#include <iostream>


template <size_t idx, typename Ttuple>
// helper class for Tuple class
struct TupleElement;

template <typename... Ttypes>
// class to store actual structure
class Tuple;


template <size_t idx, typename... Ttypes>
typename TupleElement<idx, Tuple<Ttypes...>>::type_t& //return type from a helper class
get(Tuple<Ttypes...> &tuple);

template <typename... Ttypes>
// creates a tuple from values fill the end, increase the index
Tuple<Ttypes...> makeTuple(Ttypes... args);


template <size_t idx, typename Ttuple>
void fillTuple(Ttuple &toFill);

template <size_t idx, typename Ttuple, typename Tfirst, typename... Trest> 
void fillTuple(Ttuple &toFill, const Tfirst &first, Trest... rest);



template <typename Tvalue, typename... Trest>
struct TupleElement<0, Tuple<Tvalue, Trest...>>
{
    using type_t = Tvalue;                       //type of value at this index
    using TupleType_t = Tuple<Tvalue, Trest...>; //TupleType_t is a Tuple type with TupleType_t::value having the type type_t
};

template <size_t idx, typename Tvalue, typename... Trest>
struct TupleElement<idx, Tuple<Tvalue, Trest...>>
    : public TupleElement<idx - 1, Tuple<Trest...>>{/* empty */};


template <> class Tuple<>{};

template <typename Tvalue, typename... Trest>
class Tuple<Tvalue, Trest...> : public Tuple<Trest...>{
  public:
    Tvalue value;
};


template <size_t idx, typename... Ttypes>
typename TupleElement<idx, Tuple<Ttypes...>>::type_t & //return type from a helper class
// gets or sets the idx'th element in the Tuple
get(Tuple<Ttypes...> &tuple)
{
    using TupleType_t = typename TupleElement<idx, Tuple<Ttypes...>>::TupleType_t;
    return static_cast<TupleType_t &>(tuple).value;
}

template <typename... Ttypes>
Tuple<Ttypes...> makeTuple(Ttypes... args)
{
    Tuple<Ttypes...> result;
    fillTuple<0>(result, args...); //starting point
    return result;
}


template <size_t idx, typename Ttuple>
// helper function for makeTuple : base case
void fillTuple(Ttuple &toFill){/* empty */};

template <size_t idx, typename Ttuple, typename Tfirst, typename... Trest>
// helper function for makeTuple : recursive case
void fillTuple(Ttuple &toFill, const Tfirst &first, Trest... rest)
{
    get<idx>(toFill) = first;
    fillTuple<idx + 1>(toFill, rest...);
}
