#pragma once

namespace itertools{
    class range{
        int start;
        int finish;

        public:
        //range constructor 
            range(int s , int f) : start(s) ,finish(f){}
    
        class iterator{
            private:
                int current;
        
            public:
                //iterator constructor 
                iterator(int c = 0) : current(c){}

                //Post Increment i++
                iterator &operator ++(){
                    current += 1;
                    return *this;
                }
                //Pre Increment ++i
                const iterator operator ++(int){
                    iterator temp = *this;
                    current += 1;
                    return temp;
            }
            bool operator ==(const iterator &other ) const{return current == other.current;}//Returns true if other points to the same item as this iterator; otherwise returns false
            bool operator !=(const iterator &other) const{return current != other.current;}//Returns true if other points to a different item then this iterator; otherwise returns false
            int operator *(){return current;}//Returns a reference to the current item
            iterator &operator=(const iterator &other){
                if (*this != other){
                    this->current = other.current;
                }
                return *this;
            }
        };//iterator
        iterator begin() const{return iterator(start);}
        iterator end() const{return iterator(finish);}
    };//range
};//namespace itertools