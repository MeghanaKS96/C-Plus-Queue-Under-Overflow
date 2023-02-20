#include "queue.h"
#include <iostream>

int main()
{
    queue::Queue<int, 2> q;
    queue::Queue<int, 2> y;
    for (int i = 0; i < 3; i++)
    {
        try
        {
            q.enqueue(67+i);
        }
        catch (queue::QOverflow &e)
        {
            std::cout << "Queue overflow" << std::endl;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        try
        {
            std::cout << q.dequeue() << std::endl;
        }
        catch (queue::QUnderflow &e)
        {
            std::cout << "Queue is empty" << std::endl;
        }
    }
    std::cout << q << std::endl;
    std::cout << q.size() << std::endl;

     q.enqueue(67);
     q.enqueue(68);
     queue::Queue<char,2> nq=q.cast<char>();

     for (int i = 0; i < 3; i++)
    {
        try
        {
            std::cout << nq.dequeue() << std::endl;
        }
        catch (queue::QUnderflow &e)
        {
            std::cout << "Queue is empty" << std::endl;
        }
    }

    
}
