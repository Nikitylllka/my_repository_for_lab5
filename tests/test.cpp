// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <header.hpp>

using std::ostream;

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

TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

int main() {
    stack<int> my_stack;
    //Попробовать заменить на шаблон int

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
//    int qwq = 11;

    my_stack.push(a);
    my_stack.push(b);
    my_stack.push(c);
    my_stack.push(d);
    my_stack.push(e);
//    my_stack.push(f);
//    my_stack.push(q);
//    my_stack.push(w);
//    my_stack.push(z);
//    my_stack.push(r);

//  OF  my_stack.push(qwq);

    cout << "value from head     " << my_stack.head() << endl;

    cout << " --------------------------------------------POP" << endl;

    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();

    cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Zad2" << endl;

    stack2<Summa> my_stack2;

    my_stack2.push_emplace(123, 1, 1);
    my_stack2.push_emplace(321, 1, 1);
    my_stack2.push_emplace(101, 1, 1);

    Summa test_pop(1, 2, 3);
    my_stack2.push(std::move(test_pop));

    test_pop = my_stack2.pop();

    cout << " value after pop() = " << test_pop << endl;

    my_stack2.pop();
    my_stack2.pop();
    my_stack2.pop();

    return 0;
}
