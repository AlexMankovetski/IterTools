#pragma once
#include <functional>

using namespace std;
namespace itertools{
    auto _sum = [](auto x, auto y) { return x + y; };

    template <typename C, typename F = decltype(_sum)>
    class accumulate{
        C container;
        F function;
    public:
        accumulate(C c, F f = _sum) : container(c), function(f) {}

        class iterator{
            F function;
            typename C::iterator it;
            typename C::iterator last;
            typename decay<decltype(*(container.begin()))>::type aggr;//aggregated value
        public:
            iterator(typename C::iterator first, typename C::iterator l, F fun) : it(first), last(l), function(fun){
                if (it != last)
                    aggr = *it;
            }
            //Post Increment i++
            iterator &operator++(){
                ++it;
                if (it != last)
                    aggr = function(aggr, *it);
                return *this;
            }
            //Pre Increment ++i
            iterator operator++(int){
                iterator i = *this;
                ++(*i);
                return i;
            }
            bool operator==(const iterator &other) const{return (it == other.it);}//Returns true if other points to the same item as this iterator; otherwise returns false
            bool operator!=(const iterator &other) const{return (it != other.it);}//Returns true if other points to a different item then this iterator; otherwise returns false
            auto operator*() const{return aggr;}//Returns a reference to the current item

            iterator &operator=(const iterator &other){
                if (*this != other){
                    this->it = other.it;
                    this->last = other.last;
                    this->aggr = other.aggr;
                    this->function = other.function;
                }
                return *this;
            }
        };//iterator
        iterator begin(){return iterator(container.begin(), container.end(), function);}

        iterator end(){return iterator(container.end(), container.end(), function);}
    };//accumulate
} // namespace itertools