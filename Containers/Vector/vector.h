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
    const double kDefMultiplier = 1.5;

public:
    ~Vector();
    Vector(Vector const& vec) :Vector(vec._data, vec._size) {}
    Vector& operator=(Vector const& vec);

    Vector();
    Vector(size_t capacity);
    Vector(Type* data, size_t size);

    Type& operator[](int idx);
    Type const& operator[](int idx)const;

    void push_back(Type const& val);
    void erase(Type* element);
    void insert(Type const& val, Type* before);

    void resize(size_t new_size);
    void clear();
    Type* find(Type const& to_find);
};

template <class Type>
Vector<Type>::Vector()
{
    _data = nullptr;
    _size = 0;
    _capacity = 0;
}

template <class Type>
Vector<Type>::Vector(size_t capacity)
{
    _capacity = capacity;
    _data = new Type[_capacity];
    _size = 0;
}

template <class Type>
Vector<Type>::Vector(Type* data, size_t size)
{
    _capacity = kDefCapacity;
    while (size > _capacity)
        _capacity *= kDefMultiplier;

    _size = size;
    _data = new Type[_capacity];
    for (size_t idx = 0; idx < size; ++idx)
        _data[idx] = data[idx];
}

template <class Type>
Vector<Type>::~Vector()
{
    clear();
}



template<class Type>
Vector<Type>& Vector<Type>::operator=(Vector<Type> const& vec)
{
    if (_capacity < vec._capacity)
    {
        _data = new Type[vec.capacity];
        _capacity = vec._capacity;
    }

    for (size_t idx = 0; idx < vec.size; ++idx)
        _data[idx] = vec._data[idx];

    _size = vec.size;
    return *this;
}

template<class Type>
Type const& Vector<Type>::operator[](int idx) const
{
    if (idx < 0 || idx >= _size)
        throw std::out_of_range;

    return _data[idx];
}

template<class Type>
Type& Vector<Type>::operator[](int idx)
{
    if (idx < 0 || idx >= _size)
        throw std::out_of_range;

    return _data[idx];
}



template <class Type>
void Vector<Type>::push_back(Type const& val)
{
    if (_capacity == 0)
    {
        _capacity = 1;
        _data = new Type[_capacity];
        _data[0] = val;
        _size = 1;
        return;
    }

    if (_size == _capacity)
    {
        _capacity *= kDefMultiplier;
        Type* tmp_data = new Type[_capacity];
        for (size_t idx = 0; idx < _size; ++idx)
            tmp_data[idx] = _data[idx];
        delete[] _data;
        _data = tmp_data;
    }

    _data[_size++] = val;
}

template <class Type>
void Vector<Type>::erase(Type* element)
{
    if (element >= _size)
        throw std::out_of_range;

    for (size_t idx = element; idx < _size - 1; ++idx)
        _data[idx] = _data[idx + 1];

    --_size;
}

template <class Type>
void Vector<Type>::insert(Type const& val, Type* before)
{
    if (before >= _size)
        throw std::out_of_range;

    _capacity *= kDefMultiplier;
    Type* tmp_data = new Type[_capacity];
    for (size_t idx = 0; idx <= before; ++idx)
        tmp_data[idx] = _data[idx];

    tmp_data[before+1] = val;
    for (size_t idx = before + 2; idx < _size + 1; ++idx)
        tmp_data[idx] = _data[idx - 1];

    delete[] _data;
    _data = tmp_data;
    ++_size;
}

template<class Type>
void Vector<Type>::resize(size_t new_size)
{
    if (new_size > _capacity)
    {
        _capacity *= kDefMultiplier;
        Type* tmp_data = new Type[_capacity];
        for (size_t idx = 0; idx < _size; ++idx)
            tmp_data[idx] = _data[idx];
        delete[] _data;
        _data = tmp_data;
    }

    _size = new_size;
}

template<class Type>
void Vector<Type>::clear()
{
    if (_capacity != 0)
    {
        delete[] _data;
        _size = 0;
        _capacity = 0;
    }
}

template<class Type>
Type* Vector<Type>::find(Type const& to_find)
{
    for (size_t idx = 0; idx < _size; ++idx)
        if (_data[idx] == to_find)
            return _data[idx];

    return nullptr;
}
