#pragma once
/* Ring buffer: values allocated on heap
    iterable class with iterator
 */
namespace RingBuffer
{
template<class T>
class ringA{
  private:
    T m_nullvalue;
    int m_pos;
    int m_size;
    T *m_values;
  
  public:
    class iterator; //friend class

  public:
    ringA(int size):m_nullvalue{},m_pos(0),m_size(size),m_values(new T[size]){}

    int size(){
      return m_size;
    }
    
    T& get(int pos){
      if(pos<m_size) return m_values[pos];
      else{
        std::cerr << "error: value out of range\n";
        return m_nullvalue;
      }
    }

    void add(T value){
      m_values[m_pos] = value;
      m_pos++;

      if (m_pos == m_size) {
        m_pos = 0;
      }
    }

    iterator begin(){
      return iterator(0, *this);
    }

    iterator end(){
      return iterator(m_size, *this);
    }

    ~ringA(){
        delete[] m_values;
    }
};

template<class T>
class ringA<T>::iterator{
  private:
    int m_itpos;
    ringA& m_ring;

  public:  
    iterator(int pos,ringA& aring):m_itpos(pos),m_ring(aring){}

    iterator& operator++(){
      m_itpos++;
      return *this;
    }

    iterator& operator++(int){
      m_itpos++;
      return *this;
    }

    T& operator*(){
      return m_ring.get(m_itpos);
    }

    bool operator!=(const iterator& otherit){
      return m_itpos!=otherit.m_itpos;
    }

    bool operator==(const iterator& otherit){
      return m_itpos==otherit.m_itpos;
    }
};


} // namespace RingBuffer
