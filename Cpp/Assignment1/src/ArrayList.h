#ifndef ARRAYLIST_H
#define ARRAYLIST_H

class ArrayList
{
public:
    ArrayList();
    ArrayList(const ArrayList& source);
    ArrayList(ArrayList&& source) noexcept;
    ArrayList& operator=(const ArrayList& rhs);
    ArrayList& operator=(ArrayList&& rhs) noexcept;
    ~ArrayList();

    bool empty() const;
    bool full() const;
    int size() const;
    void pushBack(int x);
    bool contains(int x) const;
    bool get(int position, int& value) const;
    int getCapacity() const;
    void print(std::ostream& sout) const;

    friend std::ostream& operator<<(std::ostream& out, const ArrayList& source);

private:
    void resize();
    int* pArray;
    int capacity;
    int used;
};

#endif