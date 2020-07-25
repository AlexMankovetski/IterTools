#pragma once

namespace itertools{
    template <typename C , typename B>
    class compress
    {
    protected:
        C container;
        B b_container; // boolean container

    public:
        compress(C c, B b) : container(c), b_container(b) {}

        class iterator{
        protected:
            typename C::iterator it;
            typename C::iterator last;
            typename B::iterator b_it; //boolean iterator

        public:
            iterator(typename C::iterator first, typename C::iterator l, typename B::iterator b) : it(first), last(l), b_it(b){
                while (it != last && !(*b_it)){
                    ++it;
                    ++b_it;
                }
            }

            //Post Increment i++
            iterator &operator++(){
                ++it;
                ++b_it;
                while (it != last && !(*b_it)){
                    ++it;
                    ++b_it;
                }
                return *this;
            }
            //Pre Increment ++i
            iterator operator++(int){
                iterator i = *this;
                ++(*this);
                return i;
            }
            bool operator==(const iterator &other) const{return it == other.it;}//Returns true if other points to the same item as this iterator; otherwise returns false
            bool operator!=(const iterator &other) const{return it != other.it;}//Returns true if other points to a different item then this iterator; otherwise returns false
            auto operator*(){return *it;}//Returns a reference to the current item

            iterator &operator=(const iterator &other){
                if (*this != other){
                    this->it = other.it;
                    this->last = other.last;
                    this->b_it = other.b_it;
                }
                return *this;
            }
        };//iterator
        iterator begin(){return iterator(container.begin(), container.end(), b_container.begin());}
        iterator end(){return iterator(container.end(), container.end(), b_container.end());}
    };//compress


}//namespace itertool