#include <memory>
#include <iostream>
#include <string> 
 
void observe(std::weak_ptr<int>& weak)
{
    std::cout << "weak count = " << weak.use_count() << "\n";

    // we need to convert the weak ptr passed to a shared ptr 
    // What should be done here be to create a p that is a shared_ptr?
    std::shared_ptr<int> p = weak.lock();

    //explicit operator bool() const noexcept;
    //return get() != nullptr
    if (p)
        std::cout << "\tobserve() is able to lock weak_ptr<>, value=" << *p << " with count = " << p.use_count() << " weak_count = " << weak.use_count() << '\n';
    else
        std::cout << "\tobserve() is unable to lock weak_ptr<>\n";
}

int main()
{
    std::weak_ptr<int> weak;
    std::cout << "weak_ptr<> is not yet initialized\n";
    observe(weak);

    /* would this work? why? */
    // No because the weak ref counter ==0 so the expired ==0 then the lock returns shared_ptr with default constructor which is nullptr
    //std::unique_ptr<int> p1 = std::make_unique<int>(42);
    //weak = p1;

    // no beacuse weak_ptr = operator accepts weak or shared_ptr only (no unique) 
    /*CPP Reference*/
    //template< class Y > 
    //weak_ptr& operator=( const weak_ptr<Y>& r ) noexcept;
    //weak_ptr& operator=( const shared_ptr<Y>& r ) noexcept;
 
    // what do the curly braces imply? what is their use in this case?

    // As we construct the shared pointer it will be Dtor leaving the scope

    {
        auto shared = std::make_shared<int>(42);
        weak = shared;
        std::cout << "weak_ptr<> is initialized with shared_ptr\n";
        observe(weak);
    }
 
    std::cout << "shared_ptr<> has been destructed due to scope exit\n";
    observe(weak);

    return 0;
}