#pragma once

namespace itertools{
    template <typename F , typename C>
    class filterfalse{
        C container;
        F filter;
        public:
        filterfalse(F f, C c) : filter(f), container(c){}

        class iterator{
            F filter;
            typename C::iterator it;
            typename C::iterator last;

            public:
                iterator(F filt, typename C::iterator first, typename C::iterator l) : filter(filt), it(first), last(l){
                    while (it != last && filter(*it))
                    ++it;
                }
            //Post Increment i++
            iterator &operator++(){
                ++it;
                while (it != last && filter(*it))
                    ++it;
                return *this;
            }
            //Pre Increment ++i
            iterator operator++(int){
                iterator i = *this;
                ++(*this);
                return i;
            }
            bool operator==(const iterator &other) const {return it == other.it;}//Returns true if other points to the same item as this iterator; otherwise returns false
            bool operator!=(const iterator &other) const {return it != other.it;}//Returns true if other points to a different item then this iterator; otherwise returns false
            auto operator*() {return *it;}//Returns a reference to the current item

            iterator &operator=(const iterator &other){
                if (*this != other)
                {
                    this->it = other.it;
                    this->last = other.last;
                    this->filter = other.filter;
                }
                return *this;
            }
        };//iterator
        iterator begin() {return iterator(filter, container.begin(), container.end());}

        iterator end() {return iterator(filter, container.end(), container.end());}
    };//filterfalse
} // namespace itertools