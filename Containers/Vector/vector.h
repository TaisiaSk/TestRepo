#pragma once
#include <iostream>
#include <exception>

template <class Type>
class Vector
{
private:
    Type* _data;
    size_t _size;
    size_t _capacity;
    static const size_t kDefCapacity = 10;
    static const double kDefMultiplier() { return  1.5; }

public:
    struct iterator
    {
        Type* _ptr;
        iterator(Type* ptr = nullptr) : _ptr(ptr) {}

        Type& operator*() const
        {
            if (!_ptr)
                throw std::runtime_error("empty iterator");
            return *_ptr;
        }

        bool operator==(iterator const& it)
        {
            return _ptr == it._ptr;
        }

        bool operator!=(iterator const& it)
        {
            return !(*this == it);
        }

        bool operator<(iterator const& it)
        {
            return (*this)._ptr < it._ptr;
        }

        bool operator>=(iterator const& it)
        {
            return !(*this < it);
        }

        iterator& operator++()
        {
            if (!_ptr)
                throw std::runtime_error("empty iterator");
            ++_ptr;
            return *this;
        }

        iterator operator++(int)
        {
            if (!_ptr)
                throw std::runtime_error("empty iterator");
            Type* tmp = _ptr;
            ++_ptr;
            return iterator(tmp);
        }

        iterator& operator--()
        {
            if (!_ptr)
                throw std::runtime_error("empty iterator");
            --_ptr;
            return *this;
        }

        iterator operator--(int)
        {
            if (!_ptr)
                throw std::runtime_error("empty iterator");
            Type* tmp = _ptr;
            --_ptr;
            return iterator(tmp);
        }
    };

    ~Vector();
    Vector(Vector const& vec) :Vector(vec._data, vec._size) {}
    Vector& operator=(Vector const& vec);

    Vector();
    Vector(size_t size);
    Vector(size_t size, Type const& val);
    Vector(Type* data, size_t size);

    Type& operator[](int idx);
    Type const& operator[](int idx)const;

    void push_back(Type const& val);
    void erase(iterator to_die);
    void insert(Type const& val, iterator it_after);

    void resize(size_t new_size);
    void clear();
    iterator find(Type const& to_find)
    {
        for (auto it = begin(); it != end(); ++it)
            if (*it == to_find)
                return it;
        return end();
    }


    iterator begin() { return iterator(_data); }
    iterator end() { return iterator(_data + _size); }

    void reserve(size_t new_capacity)
    {
        if (new_capacity > _capacity)
        {
            Type* tmp_data = reinterpret_cast<Type*>(::operator new(new_capacity * sizeof(Type)));
            for (size_t idx = 0; idx < _size; ++idx)
                new(tmp_data + idx) Type(_data[idx]);
            size_t prev_size = _size;
            clear();
            _data = tmp_data;
            _size = prev_size;
            _capacity = new_capacity;
        }
    }
};

template <class Type>
Vector<Type>::Vector() :_data(nullptr),
_size(0),
_capacity(0) {}

template <class Type>
Vector<Type>::Vector(size_t size) : _size(size), _capacity(size)
{
    _data = reinterpret_cast<Type*>(::operator new(_capacity * sizeof(Type)));
    for (size_t idx = 0; idx < _size; ++idx)
        new(_data + idx) Type();
}

template<class Type>
Vector<Type>::Vector(size_t size, Type const& val) : _size(size), _capacity(size), _data(nullptr)
{
    if (_capacity != 0)
    {
        _data = reinterpret_cast<Type*>(::operator new(_capacity * sizeof(Type)));
        for (size_t idx = 0; idx < _size; ++idx)
            new(_data + idx) Type(val);
    }
}

template <class Type>
Vector<Type>::Vector(Type* data, size_t size) : _capacity(size), _size(size)
{
    //_data = new Type[_capacity];
    _data = (Type*)::operator new(_capacity * sizeof(Type));
    for (size_t idx = 0; idx < _size; ++idx)
        new(_data + idx) Type(data[idx]);
    //_data[idx] = data[idx];
}

template <class Type>
Vector<Type>::~Vector()
{
    clear();
}



template<class Type>
Vector<Type>& Vector<Type>::operator=(Vector<Type> const& vec)
{
    clear();
    reserve(vec._size);

    for (size_t idx = 0; idx < vec._size; ++idx)
        new(_data + idx) Type(vec._data[idx]);

    _size = vec._size;
    return *this;
}

template<class Type>
Type const& Vector<Type>::operator[](int idx) const
{
    if (idx < 0 || idx >= _size)
        throw std::exception("index out of bounds");

    return _data[idx];
}

template<class Type>
Type& Vector<Type>::operator[](int idx)
{
    if (idx < 0 || idx >= _size)
        throw std::exception("index out of bounds");

    return _data[idx];
}



template <class Type>
void Vector<Type>::push_back(Type const& val)
{
    if (_size == _capacity)
    {
        size_t safe_capacity = _capacity <= 1 ? kDefCapacity : _capacity;
        reserve(safe_capacity * kDefMultiplier());
    }

    new(_data + (_size++)) Type(val);
}

template <class Type>
void Vector<Type>::erase(iterator to_die_it)
{
    if (to_die_it == nullptr)
        throw std::runtime_error("empty ptr");

    iterator last = --end();
    while (to_die_it != last)
    {
        (*to_die_it._ptr).~Type();
        new(to_die_it._ptr) Type(*(to_die_it._ptr + 1));
        ++to_die_it;
    }
    (*last._ptr).~Type();
    --_size;

    /*for (auto it = to_die; it != last; ++it)
    {
        it.~Type();
        new(it) Type(*(++it));
    }
    last.~Type();
    --_size;*/

    /*for (size_t idx = erase_idx; idx < _size - 1; ++idx)
    {
        _data[idx].~Type();
        new(_data + idx) Type(_data[idx + 1]);
    }

    _data[size-1].~Type();
    --_size;*/
}

template <class Type>
void Vector<Type>::insert(Type const& val, iterator it_after)
{
    if (it_after >= end())
        throw std::out_of_range("out of range");

    if (_size == _capacity)
        _capacity *= kDefMultiplier();

    Type* tmp_data = new Type[_capacity];
    iterator tmp_it(tmp_data);
    for (auto it = begin(); it != it_after; ++it)
        *(tmp_it++) = *it;

    //for (size_t idx = 0; idx < ptr_after; ++idx)
        //tmp_data[idx] = _data[idx];

    *(tmp_it++) = val;
    for (auto it = it_after; it != ++end(); ++it)
        *(tmp_it++) = *it;

    //for (size_t idx = ptr_after + 1; idx < _size + 1; ++idx)
        //tmp_data[idx] = _data[idx - 1];

    size_t size = _size + 1;
    size_t capacity = _capacity;
    clear();
    _data = tmp_data;
    _size = size;
    _capacity = capacity;
}

template<class Type>
void Vector<Type>::resize(size_t new_size)
{
    if (new_size > _capacity)
    {
        _capacity *= kDefMultiplier;
        Type* tmp_data = reinterpret_cast<Type*>(::operator new(_capacity * sizeof(Type)));
        for (size_t idx = 0; idx < _size; ++idx)
            new(tmp_data[idx]) Type(_data[idx]);
        clear();
        _data = tmp_data;
    }

    _size = new_size;
}

template<class Type>
void Vector<Type>::clear()
{
    if (_capacity != 0)
    {
        for (size_t idx = 0; idx < _size; ++idx)
            _data[idx].~Type();

        ::operator delete[](_data);
        _size = _capacity = 0;
    }
}
