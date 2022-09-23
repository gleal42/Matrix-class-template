#ifndef __MATRIX__
#define __MATRIX__

#include <array>
#include <list>
#include <vector>
#include <iostream>

template <size_t Y, size_t X>
class Matrix
{
public:
	using columns = std::array<int, X>;
	using rows_of_columns = std::array<columns, Y>;
	// Constructors and assignments
	Matrix(void) = default;

	// TODO: prevent matrices and lists that don't match to be constructed
	Matrix(std::initializer_list<std::initializer_list<double> > list)
	{
		std::cout << "Creating matrix <" << _data.size() << ", " << _data[0].size() << "> number " << (++count) << std::endl;
		for (auto it1 = std::pair(_data.begin(), list.begin()); it1.first != _data.end(); it1.first++, it1.second++)
		{
			for (auto it2 = std::pair(it1.first->begin(), it1.second->begin());
				it2.first != it1.first->end();
				it2.first++, it2.second++)
			{
				*it2.first = *it2.second;
			}
		}
		std::cout << *this;
	}
	Matrix<Y, X> operator+(const Matrix<Y, X>& other) const
	{
		Matrix<Y, X> result(*this);
		Matrix<Y, X> other_temp(other);

		for (auto it1 = std::pair(result.begin(), other_temp.begin());
			it1.first != result.end();
			it1.first++, it1.second++)
		{
			for (auto it2 = std::pair(it1.first->begin(), it1.second->begin());
				it2.first != it1.first->end();
				it2.first++, it2.second++)
			{
				*it2.first += *it2.second;
			}
		}
		return result;
	}
	// Destructor
	~Matrix(void) = default;
	typename std::array<std::array<int, X>, Y>::iterator begin() {return _data.begin();}
	typename std::array<std::array<int, X>, Y>::iterator end() {return _data.end();}
protected:
private:
	rows_of_columns	_data;
	// std::array<std::array<int, X>, Y> _data;
	static size_t	count;
	// friends
	friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
	{
		for (auto i = matrix._data.begin(); i != matrix._data.end(); i++)
		{
			for (auto j = i->begin(); j != i->end(); j++)
			{
				os << *j << " ";
			}
			os << std::endl;
		}
		os << std::endl;
		return os;
	}
};

template <size_t X, size_t Y>
size_t Matrix<X, Y>::count = 0;

#endif // __MATRIX__

/**
 * @brief Another way to initialize static member variable
 * 
 * static size_t	initcount();
 * template <size_t X, size_t Y>
 * size_t Matrix::count = Matrix::initcount();
 * template <size_t X, size_t Y>
 * size_t Matrix<X, Y>::initcount(void) {return(0);}
 * 
 */

/**
 * @brief using keyword versus typedef
 * https://en.cppreference.com/w/cpp/language/type_alias
 * 
 * using columns = std::array<int, X>;
 * using rows_of_columns = std::array<columns, Y>;
 * // typedef std::array<int, X>			columns;
 * // typedef std::array<columns, Y>		rows_of_columns;
 */

/**
 * @brief Getters and Setters (maybe add later)
 * // Getters | Setters
 * // const std::array<std::array<int, X>, Y> &getData() const {return _data;}
 * // void setData(typename std::array<int, X>::iterator it, a) {}
*/
	
/* 	template <size_t T1, size_t T2>
	Matrix<T1, T2> operator+(const Matrix<T1, T2>& other) const
	{
		Matrix<T1, T2> result(*this);
		Matrix<T1, T2> other_temp(other);

		for (auto it1 = std::pair(result.begin(), other_temp.begin());
			it1.first != result.end();
			it1.first++, it1.second++)
		{
			for (auto it2 = std::pair(it1.first->begin(), it1.second->begin());
				it2.first != it1.first->end();
				it2.first++, it2.second++)
			{
				*it2.first += *it2.second;
			}
		}
		return result;
	} */