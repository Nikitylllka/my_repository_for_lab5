// Copyright 2018 Nikitylllka <m.bonduel@ya.ru>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <iostream>
#include <cstdlib>

#define error_of_empty_stack -1
#define error_of_memory -2

using namespace std;


class Summa {
public:
    int rez;

    Summa() {}

    Summa(int v1, int v2, int v3) {
        rez = v1 + v2 + v3;
    }
};

ostream &operator<<(ostream &s, const Summa &v) {
    s << v.rez;
    return s;
}

template<typename T>
class stack2 {
public:
    T *Head;
    T *Top;
    int i = 0;

    stack2() {
        Head = nullptr;
        Top = nullptr;
    }

    template<typename ... Args>
    void push_emplace(Args &&... value) {
        T obj(value ...);
        Head = (T *) realloc(Head, (i + 1) * sizeof(obj));
        if(!Head)
        {
            exit(error_of_memory);
        }
        Top = &(Head)[i];
        Head[i] = obj;
        cout << "from Head : [" << (i) << "] = " << Head[i] << endl;
        cout << "            [" << (i) << "] = " << *Top << endl;
        i++;
    };

    void push(T &&value) {
        if (i < 10) {
            Head = (T *) realloc(Head, (i + 1) * sizeof(T));
            if(!Head)
            {
                exit(error_of_memory);
            }
            Top = &(Head)[i];
            Head[i] = value;
            cout << "from Head : [" << (i) << "] = " << Head[i] << endl;
            cout << "            [" << (i) << "] = " << *Top << endl;
            i++;

        } else {
            cout << "Stack is overflow" << endl;
        }
    };

    const T &head() const {
        if (i == 0) {
            cout << "stack is empty ";
            exit(error_of_empty_stack);
        }
        return *Top;
    }

    T pop() {
        if (i > 0) {
            T value_after_pop;
            value_after_pop = Head[i - 1];
            Head = (T *) realloc(Head, (i - 1) * sizeof(T));
            if (i == 1) {
                Head = nullptr;
                Top = nullptr;
                cout << "Stack is empty" << endl;
                i--;
                return value_after_pop;
            }
            Top = &(Head)[i - 2];
            cout << "last elem from Head : [" << (i - 2) << "] = " << Head[i - 2] << endl;

            cout << "last elem             [" << (i - 2) << "] = " << *Top << endl;
            i--;
            return value_after_pop;
        } else if (i < 1) {
            cout << "Error stack" << endl;
            exit(error_of_empty_stack);
        }
    };

    ~stack2() {
        while (i > 0) {
            Head = (T *) realloc(Head, (i - 1) * sizeof(T));
            if (i == 1) {
                Head = nullptr;
                Top = nullptr;
                cout << "Stack is empty" << endl;
                i--;
                return;
            }
            Top = &(Head)[i - 2];
            cout << "last elem from Head : [" << (i - 2) << "] = " << Head[i - 2] << endl;

            cout << "last elem             [" << (i - 2) << "] = " << *Top << endl;
            i--;
        }
    };
};

template<typename T>
class stack {
public:

    T *Head;
    T *Top;
    int i = 0;

    stack() {
        Head = nullptr;
        Top = nullptr;
    }

    void push(T &&value) {
        Head = (T *) realloc(Head, (i + 1) * sizeof(T));
        if(!Head)
        {
            exit(error_of_memory);
        }
        Top = &(Head)[i];
        Head[i] = value;
        cout << "from Head : [" << (i) << "] = " << Head[i] << endl;
        cout << "            [" << (i) << "] = " << *Top << endl;
        i++;
    };

    void push(const T &value) {
        Head = (T *) realloc(Head, (i + 1) * sizeof(T));
        if(!Head)
        {
            exit(error_of_memory);
        }
        Top = &(Head)[i];
        Head[i] = value;
        cout << "from Head : [" << (i) << "] = " << Head[i] << endl;
        cout << "            [" << (i) << "] = " << *Top << endl;
        i++;
    };

    void pop() {
        if (i > 0) {
            Head = (T *) realloc(Head, (i - 1) * sizeof(T));
            if (i == 1) {
                Head = nullptr;
                Top = nullptr;
                cout << "Stack is empty" << endl;
                i--;
                return;
            }
            Top = &(Head)[i - 2];
            cout << "last elem from Head : [" << (i - 2) << "] = " << Head[i - 2] << endl;

            cout << "last elem             [" << (i - 2) << "] = " << *Top << endl;
            i--;
        } else if (i < 1) {
            cout << "Error stack" << endl;
        }
    };

    const T &head() const {
        if (i == 0) {
            cout << "stack is empty ";
            exit(error_of_empty_stack);
        }
        return *Top;
    }

    ~stack() {
        while (i > 0) {
            Head = (T *) realloc(Head, (i - 1) * sizeof(T));
            if (i == 1) {
                Head = nullptr;
                Top = nullptr;
                cout << "Stack is empty" << endl;
                i--;
                return;
            }
            Top = &(Head)[i - 2];
            cout << "last elem from Head : [" << (i - 2) << "] = " << Head[i - 2] << endl;

            cout << "last elem             [" << (i - 2) << "] = " << *Top << endl;
            i--;
        }
    };

};

int main() {

    stack<int> my_stack;

    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int f = 6;
    int q = 7;
    int w = 8;
    int z = 9;
    int r = 10;

    my_stack.push(a);
    my_stack.push(b);
    my_stack.push(c);
    my_stack.push(d);
    my_stack.push(e);
    my_stack.push(f);
    my_stack.push(q);
    my_stack.push(w);
    my_stack.push(z);
    my_stack.push(r);

    cout << "value from head     " << my_stack.head() << endl;

    cout << " ---------------------------------------------------------------------POP" << endl;

    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();

    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Zad2" << endl;

    stack2<Summa> my_stack2;

    my_stack2.push_emplace(123, 1, 1);
    my_stack2.push_emplace(321, 1, 1);
    my_stack2.push_emplace(101, 1, 1);

    Summa test_pop(1,2,3);
    my_stack2.push(std::move(test_pop));

    test_pop = my_stack2.pop();

    cout << " value after pop() = " << test_pop << endl;

    my_stack2.pop();
    my_stack2.pop();
    my_stack2.pop();

    return 0;
}

#endif // INCLUDE_HEADER_HPP