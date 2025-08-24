#include <iostream>

class data {
    friend class attorney;
    int value{ 123 };
    void foo() {
        std::cout << "[data class] foo function called.\n";
    }
    void bar() {
        std::cout << "[data class] bar function called.\n";
    }
};

class attorney {
public:
    static int get_value(const data& d) {
        std::cout << "[attorney class] get_value function called.\n";
        return d.value;
    }

    static void call_foo(data& d) {
        std::cout << "[attorney class] call_foo function called.\n";
        d.foo();
    }

    static void call_bar(data& d) {
        std::cout << "[attorney class] call_bar function called.\n";
        d.bar();
    }
};

class client {
public:
    void access_data_value(const data& d) {
        std::cout << attorney::get_value(d) << "\n";
    }

    void access_foo(data& d) {
        attorney::call_foo(d);
    }

    void access_bar(data& d) {
        attorney::call_bar(d);
    }
};

int main() {
    data d;
    client c;

    c.access_data_value(d);
    c.access_foo(d);
    c.access_bar(d);
}
