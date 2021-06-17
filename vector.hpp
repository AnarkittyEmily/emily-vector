#include <initializer_list>
#include <iostream>


namespace emily {

    template<typename _VectorType> class vector { 

        private:
            // necessary stuff for the vector
            _VectorType* _Vector; int _Size; 

        public:

            // constructors
            vector() { 
                // if the vector is uninitialized, just set the vector to a null pointer; 
                _Vector = nullptr; 
            }

            vector(int _Size) {
                this->_Size = _Size; 
                _Vector = new _VectorType[this->_Size];
            }

            vector(std::initializer_list<_VectorType> init) {
               
                // setting the count and the size 
                int count = 0;
                _Size = init.size(); 

                // allocating memory 
                _Vector = new _VectorType[_Size]; 

                // setting values
                for (const auto init_Elems : init) { 
                    _Vector[count] = init_Elems; 
                    count++;
                }
            }


            // destructor 
            ~vector() { 
                delete[] _Vector; 
            }

            // operator stuff
            _VectorType& operator[](int _VectorIndex) { 
                return _Vector[_VectorIndex]; 
            }


            // iterators
            
            // returns a pointer to the beginning of the vector 
            auto begin() { 
                
                return &_Vector[0]; 
            }  

            auto end() { 
                return &_Vector[this->_Size]; 
            }
            
            const auto cbegin() { 
                return &_Vector[0];
            }

            const auto cend() { 
                return &_Vector[this->_Size];
            }

            auto rbegin() { 
                return &_Vector[this->_Size];
            }
            
            auto rend() { 
                return &_Vector[0];
            }

            const auto crbegin() { 
                return &_Vector[this->_Size]; 
            }

            const auto crend() { 
                return &_Vector[0];
            }

            // returns the index, with error handling. 
            _VectorType at(int index) { 
                if (index > _Size)
                    throw std::out_of_range("Cannot access an element beyond the size of the vector."); 

                return _Vector[index]; 
            }

            // increase the size by _Size
            void push(int _Size) { 
                int old_Size = this->_Size; 
                _VectorType old_Vector[this->_Size]; 
                
                for (int i = 0; i < this->_Size; i++) { 
                    old_Vector[i] = _Vector[i]; 
                }

                delete[] _Vector; 
                _Vector = nullptr; 

                this->_Size += _Size; 
                _Vector = new _VectorType[this->_Size];

                for (int i = 0; i < old_Size; i++) { 
                    _Vector[i] = old_Vector[i]; 
                }

            }
            
            // resize the vector
            void resize(int _Size) {    
                int old_Size = this->_Size; 
                _VectorType old_Vector[this->_Size]; 
                
                for (int i = 0; i < this->_Size; i++) { 
                    old_Vector[i] = _Vector[i]; 
                }

                delete[] _Vector; 
                _Vector = nullptr; 

                _Vector = new _VectorType[_Size];
                for (int i = 0; i < this->Size; i++) { 
                    _Vector[i] = old_Vector[i]; 
                } 

                this->_Size = _Size; 
            }


            void assign(int index, const _VectorType value) { 
                if (index > _Size || index < 0) 
                {
                    throw std::out_of_range("Cannot assign a value beyond the size of the vector"); 
                } 

                _Vector[index] = value; 
            }

            constexpr unsigned long int size() { 
                return _Size; 
            }

    };

};

