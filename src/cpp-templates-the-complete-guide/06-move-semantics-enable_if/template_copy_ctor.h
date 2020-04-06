#ifndef DELETE_COPY_CTOR_H
#define DELETE_COPY_CTOR_H

class TemplCopyCtor {
public:
    TemplCopyCtor() : x(1) {}
    
    // Prevents another copy contstructor to be implicitly declared, without
    // actually deleting TemplCopyCtor(const TemplCopyCtor&)
    TemplCopyCtor(const volatile TemplCopyCtor&) = delete;
    
    template<typename T>
    TemplCopyCtor(const T& o) { x = o.getX(); }
    
    int getX() const { return x; }

private:
    int x;
};

struct AnotherGetX {
    int getX() const { return x; }
    int x;
};

void use_templ_copyctor()
{
    std::cout << "USE TEMPLATE COPY CONSTRUCTOR\n";
    TemplCopyCtor t;
    TemplCopyCtor t1 = AnotherGetX{ 2 };
    TemplCopyCtor t2 = t;
    std::cout << t1.getX() << " " << t2.getX() << "\n";
    std::cout << "\n";
}

#endif // !DELETE_COPY_CTOR_H
