#pragma once

//incomplete declaration
template<typename...Ttypes> class Tuple;

//empty Tuple
template<>
class Tuple<>{/* empty */}

template<typename Tvalue, typename... Trest>
class Tuple<Tvalue, Trest...>:public Tuple<Trest...>{
public:
    Tvalue value;
};

//get function to access the idxth element in the Tuple
template<size_t idx, typename... Ttypes>
typename TupleElement<idx,Tuple<Ttypes...>>::type_t&    //return type
get(Tuple<Ttypes...>& Tuple){

    using TupleType_t = typename TupleElement<idx, Tuple<Ttypes...>>::TupleType_t;
    return static_cast<TupleType_t&>(Tuple).value;
}
//usage get<1>(myTuple) = 'd';

/* helper class*/
//incomplete declaration
template<size_t idx, typename Ttuple> struct TupleElement;

//access the 0th element
template<typename Tvalue, typename... Trest>
struct TupleElement<0, Tuple<Tvalue,Trest...> >{
    using type_t = Tvalue;                          //type of value at this index
    using TupleType_t = Tuple<Tvalue, Trest...>;    //TupleType_t is a Tuple type with Type
};

//recursive Tuple element definition
template<size_t idx, typename Tvalue, typename... Trest>
struct TupleElement<idx, Tuple<Tvalue,Trest...>>
    :public TupleElement<idx-1, Tuple<Trest...>>{/* empty */};

void testTupleAssignment(){
    Tuple<int,char> tuple;
    get<0>(tuple) = 32;     //assign to the tuple
    get<1>(tuple) = 'M';

    auto v1 = get<0>(tuple);    //assign from the tuple
    auto v2 = get<1>(tuple);
    assert(v1 == 32);
    assert(v2 == 'M');
}

/* Create a tuple from values 
fill the thing, increase the index
*/
template<typename... Ttypes>
Tuple<Ttypes...> makeTuple(Ttypes... args){
    Tuple<Ttypes...> result;
    fillTuple<0>(result,args);  //starting point
    return result;
}

template<size_t idx, typename Ttuple>
void fillTuple(Ttuple& toFill){};

//resucrsive def
template<size_t idx, typename Ttuple,typename Tfirst, typename... Trest>
void fillTuple(Ttuple& toFill, const Tfirst& first, Trest... rest){
    get<idx>(toFill) = first;
    fillTuple<idx+1>(toFill,rest...);
}

