#pragma once

#include <stdexcept>

// Concept Enumerator<T>
// o Implies:
//   o DefaultConstructible: http://en.cppreference.com/w/cpp/concept/DefaultConstructible
//   o MoveConstructible: http://en.cppreference.com/w/cpp/concept/MoveConstructible
//   o MoveAssignable: http://en.cppreference.com/w/cpp/concept/MoveAssignable
// o typename value_type
//   o value_type == T
// o bool move_first()
// o bool move_next()
//   o Returns true if and only if there is a next value
//   o Should call move_first the first time, and move_next subsequently
// o value_type current()
// o Starts "one before" first value

namespace linq {

// Does not (have to) implement concept Enumerator<T> - but inheriting types should
template <typename T>
class enumerator
{
public:
	typedef T value_type;
	virtual bool move_first() = 0;
	virtual bool move_next() = 0;
	virtual value_type current() = 0;
};

template <typename Enumerator>
void move_first_or_throw(Enumerator& e)
{
	if (!e.move_first())
		throw new std::logic_error("move_first returned false");
}

}