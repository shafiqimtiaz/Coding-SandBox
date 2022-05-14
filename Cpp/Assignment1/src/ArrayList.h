#ifndef ARRAYLIST_H_

#include <iostream>
#define ARRAYLIST_H_

class ArrayList
{
private:
    int *pArray;
    int *temp;
    int capacity;
    int used;

public:
    ArrayList();
    ArrayList(const ArrayList& arr);
    ~ArrayList();
    void pushBack(int value);
    int size() const;
    bool empty() const;
    bool full() const;
    void print();
    void resize();
    int getCapacity() const;


    //friend ostream& operator<<(ostream& output, const ArrayList& arr) {
    //    output << arr.pArray[used];
    //    return output;
    //}
};


#endif