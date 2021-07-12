#pragma once

// std
#include <cstddef>
#include <algorithm>
// project
#include <callisto/framework/exception/string_holder_exception.hpp>

namespace callisto::framework
{
    template<typename type, size_t n>
    class mutable_array
    {
    public:
        using value_type = type;

        static const size_t array_size = n;

    private:
        value_type data_array[array_size];

        size_t mutable_size = 0;
        
    public:
        mutable_array() { }

        mutable_array(const mutable_array& array)
        {
            this->copy_from(array);
        }

        mutable_array(mutable_array&& array)
        {
            this->move_from(std::move(array));
        }

        // methods
        void copy_from(const mutable_array& array)
        {
            std::copy_n(array.data_array, array.mutable_size, this->data_array);
            this->mutable_size = array.mutable_size;
        }

        void move_from(mutable_array&& array)
        {
            this->copy_from(array);
            array.mutable_size = 0;
        }

        void resize(size_t new_size)
        {
            if(new_size > array_size) throw std::bad_alloc(
                "failed in mutable_array: resize > static_size"
            );
            this->mutable_size = new_size;
        }

        

        // getters and setters
        size_t size() const
        {
            return this->mutable_size;
        }

        value_type* data()
        {
            return this->data_array;
        }

        const value_type* data() const
        {
            return this->data_array;
        }

        value_type* begin() { return this->data_array; }

        const value_type* begin() const { return this->data_array; }


        value_type* end() { return this->data_array + this->mutable_size; }

        const value_type* end() const { return this->data_array + this->mutable_size; }


        std::reverse_iterator<value_type*> rbegin()
        {
            return std::reverse_iterator<value_type*>(this->data_array + this->mutable_size);
        }

        std::reverse_iterator<const value_type*> rbegin() const
        {
            return std::reverse_iterator<const value_type*>(this->data_array + this->mutable_size);
        }


        std::reverse_iterator<value_type*> rend()
        {
            return std::reverse_iterator<value_type*>(this->data_array);
        }

        std::reverse_iterator<const value_type*> rend() const
        {
            return std::reverse_iterator<const value_type*>(this->data_array);
        }

        // operators
        const mutable_array& operator=(const mutable_array& array)
        {
            this->copy_from(array);

            return *this;
        }

        const mutable_array& operator=(mutable_array&& array)
        {
            this->move_from(std::move(array));

            return *this;
        }

        value_type& operator[](std::size_t index)
        {
            return this->data_array[index];
        }

        const value_type& operator[](std::size_t index) const
        {
            return this->data_array[index];
        }
    };
}