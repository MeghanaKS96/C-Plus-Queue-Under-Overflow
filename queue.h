#include<exception>
#include<vector>
#include<iostream>

using namespace std;


namespace queue {

//Defining exceptions 2.1
class QOverflow: public exception
{
    public:
    char * what()
    {
        return "Cannot add more items to the Queue due to Overflow";
    }
    
};

class QUnderflow: public exception  {
    public:
    char * what()
    {
        return "Cannot remove items from the Queue due to Underflow";
    }
};

template<typename T, int N>
class Queue
{
private:
    std::vector<T> elems;

public:
    Queue() {
        elems.reserve(N);
    }

    ~Queue()
    {
        elems.clear();
    }

//addinf exceptions in functions 1.1
    void enqueue(T value)
    {
        if(this->size()>=elems.capacity())
        {
            QOverflow Q;
            throw Q;
        }
         else
        {
            elems.push_back(value);
        }
    }

    T dequeue()
    {
        if (this->size()==0)
        {
            QUnderflow Q;
            throw Q;
        }
        else
        {
        T value = elems.front();
        elems.erase(elems.begin());
        return value;
        }
    }

    size_t size()
    {
        return elems.size();
    }

    bool isEmpty()
    {
       return elems.empty();
    }

    friend std::ostream& operator<<(std::ostream& os, const Queue<T, N>& q)
    {
        for (auto& i : q.elems)
        {
            std::cout << i << " ";
        }
        return os;
    }

//typecasting from T to U 2.2
    template<typename U>
    Queue<U,N> cast() 
    {  
       Queue<U,N> queue1;
       for(auto& i: elems)
       {queue1.enqueue(static_cast<U>(i));}
       return queue1;
     }
};

}
