/* Perform Queue operation using array implementation */

#include <iostream>

class Queue
{
private:
    int size;
    int *queue_arr;
    int curr;

public:
    Queue()
    {
        this->size = 10;
        this->queue_arr = new int[this->size];
        int curr = -1;
    }

    Queue(int size)
    {
        this->size = size;
        this->queue_arr = new int[this->size];
        int curr = -1;
    }

    ~Queue()
    {
        delete[] this->queue_arr;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
