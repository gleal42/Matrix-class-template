#ifndef __MATRIX__
#define __MATRIX__

#include <array>
#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

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

	/**
	 * @brief 
	 * 1 2 3
	 * 4 5 6
	 * 
	 * to
	 * 
	 * 1 4
	 * 2 5
	 * 3 6
	 * @return Matrix<X, Y> 
	 */

	Matrix<X, Y> transposed( void ) const
	{
		Matrix<X, Y> t_matrix;
		// typename Matrix<X, Y>::iterator t_it = t_matrix.begin();
		for (size_t y = 0; y != this->_data.size(); y++) {
			for (size_t x = 0; x != this->_data[0].size(); x++) {
				t_matrix[x][y] = _data[y][x];
			}
		}
		return (t_matrix);
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
	typename std::array<std::array<int, X>, Y>::reference operator[](size_t n)
	{
		return(_data[n]);
	}
	template<size_t T>
	Matrix<Y, T> operator*(Matrix<X, T> other) const
	{
		Matrix<Y, T> result;
		// std::cout << "Resuls[" << Y << "][" << T << "]" << std::endl;
		for (size_t res_x = 0; res_x < T; res_x++)
		{
			for (size_t res_y = 0; res_y < Y; res_y++)
			{
				double sum = 0;
				for (size_t sum_it = 0; sum_it < X; sum_it++)
				{
					// std::cout << "Lets multiply: \n";
					// std::cout << _data[res_y][sum_it] << " * " << other[sum_it][res_x] << " (_data[" << res_y << "][" << sum_it << "]) * (other[" << sum_it << "][" << res_x << "])" << std::endl;
					// std::cout << _data[res_y][sum_it] * other[sum_it][res_x] << std::endl;
					sum += _data[res_y][sum_it] * other[sum_it][res_x];
					// std::cout << "SUM is now " << sum << std::endl;
				}
				// std::cout << "Resuls[" << res_x << "][" << res_y << "] = " << sum <<std::endl;
				result[res_y][res_x] = sum;
			}
		}
		return result;
	}
	// Destructor
	~Matrix(void) = default;
	typename std::array<std::array<int, X>, Y>::iterator begin() {return _data.begin();}
	typename std::array<std::array<int, X>, Y>::iterator end() {return _data.end();}
	typename std::array<std::array<int, X>, Y>::const_iterator cbegin() {return _data.cbegin();}
	typename std::array<std::array<int, X>, Y>::const_iterator cend() {return _data.cend();}
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