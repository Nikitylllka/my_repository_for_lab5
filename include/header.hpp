// Copyright 2018 Nikitylllka <m.bonduel@ya.ru>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <iostream>
#include <cstdlib>

#define error_of_empty_stack -1
#define error_of_memory -2

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
        using std::cout << "from Head : [" << (i) << "] = " << Head[i] << using std::endl;
        using std::cout << "            [" << (i) << "] = " << *Top << using std::endl;
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
            using std::cout << "from Head : [" << (i) << "] = " << Head[i] << using std::endl;
            using std::cout << "            [" << (i) << "] = " << *Top << using std::endl;
            i++;

        } else {
            using std::cout << "Stack is overflow" << using std::endl;
        }
    };

    const T &head() const {
        if (i == 0) {
            using std::cout << "stack is empty ";
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
                using std::cout << "Stack is empty" << using std::endl;
                i--;
                return value_after_pop;
            }
            Top = &(Head)[i - 2];
            using std::cout << "last elem from Head : [" << (i - 2) << "] = " << Head[i - 2] << using std::endl;

            using std::cout << "last elem             [" << (i - 2) << "] = " << *Top << using std::endl;
            i--;
            return value_after_pop;
        } else if (i < 1) {
            using std::cout << "Error stack" << using std::endl;
            exit(error_of_empty_stack);
        }
    };

    ~stack2() {
        while (i > 0) {
            Head = (T *) realloc(Head, (i - 1) * sizeof(T));
            if (i == 1) {
                Head = nullptr;
                Top = nullptr;
                using std::cout << "Stack is empty" << using std::endl;
                i--;
                return;
            }
            Top = &(Head)[i - 2];
            using std::cout << "last elem from Head : [" << (i - 2) << "] = " << Head[i - 2] << using std::endl;

            using std::cout << "last elem             [" << (i - 2) << "] = " << *Top << using std::endl;
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
        using std::cout << "from Head : [" << (i) << "] = " << Head[i] << using std::endl;
        using std::cout << "            [" << (i) << "] = " << *Top << using std::endl;
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
        using std::cout << "from Head : [" << (i) << "] = " << Head[i] << using std::endl;
        using std::cout << "            [" << (i) << "] = " << *Top << using std::endl;
        i++;
    };

    void pop() {
        if (i > 0) {
            Head = (T *) realloc(Head, (i - 1) * sizeof(T));
            if (i == 1) {
                Head = nullptr;
                Top = nullptr;
                using std::cout << "Stack is empty" << using std::endl;
                i--;
                return;
            }
            Top = &(Head)[i - 2];
            using std::cout << "last elem from Head : [" << (i - 2) << "] = " << Head[i - 2] << using std::endl;

            using std::cout << "last elem             [" << (i - 2) << "] = " << *Top << using std::endl;
            i--;
        } else if (i < 1) {
            using std::cout << "Error stack" << using std::endl;
        }
    };

    const T &head() const {
        if (i == 0) {
            using std::cout << "stack is empty ";
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
                using std::cout << "Stack is empty" << using std::endl;
                i--;
                return;
            }
            Top = &(Head)[i - 2];
            using std::cout << "last elem from Head : [" << (i - 2) << "] = " << Head[i - 2] << using std::endl;

            using std::cout << "last elem             [" << (i - 2) << "] = " << *Top << using std::endl;
            i--;
        }
    };

};

#endif // INCLUDE_HEADER_HPP
