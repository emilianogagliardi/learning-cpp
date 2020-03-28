#ifndef ENABLE_IF_EXAMPLE_H
#define ENABLE_IF_EXAMPLE_H

#include <string>
#include <type_traits>

template<typename T>
using enable_if_string = 
    std::enable_if_t<std::is_convertible_v<T, std::string>>;

class Person {
public:
    // construct from name
    template<typename STR, typename = enable_if_string<STR>>
    explicit Person(STR&& n) :
        name(std::forward<STR>(n)) {}
    // copy and move constructor:
    Person(Person const& p) : name(p.name) 
    {
        std::cout << "COPY-CONSTR Person '" << name << "'\n";
    }
    Person(Person && p) : name(std::move(p.name)) 
    {
        std::cout << "MOVE-CONSTR Person '" << name << "'\n";
    }
private:
    std::string name;
};

void use_person()
{
    std::string s = "sname";
    Person p1(s); // init with string object => calls TMPL-CONSTR
    Person p2("tmp"); // init with string literal => calls TMPL-CONSTR
    // STR is a better match than const Person& for the Person type, 
    // thus this would lead to compilation error if the template constructor
    // was not disabled with enable_if
    Person p3(p1);
    Person p4(std::move(p1));
}

#endif // !ENABLE_IF_EXAMPLE_H
