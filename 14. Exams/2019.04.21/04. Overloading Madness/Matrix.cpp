#include "Matrix.h"

Matrix& Matrix::operator=(const std::vector<std::vector<int>>& data) {
  _data = data;
  return *this;
}

Matrix& Matrix::operator+=(const Matrix& other) {
  for (size_t row = 0; row < other._data.size(); row++) {
    for (size_t col = 0; col < other._data[row].size(); ++col) {
      this->_data[row][col] += other._data[row][col];
    }
  }
  return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
  for (size_t row = 0; row < other._data.size(); row++) {
    for (size_t col = 0; col < other._data[row].size(); ++col) {
      this->_data[row][col] -= other._data[row][col];
    }
  }
  return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
  for (size_t row = 0; row < other._data.size(); row++) {
    for (size_t col = 0; col < other._data[row].size(); ++col) {
      this->_data[row][col] *= other._data[row][col];
    }
  }
  return *this;
}

Matrix& Matrix::operator/=(const Matrix& other) {
  for (size_t row = 0; row < other._data.size(); row++) {
    for (size_t col = 0; col < other._data[row].size(); ++col) {
      if (other._data[row][col] == 0) {
        this->_data[row][col] = 0;
      } else {
        this->_data[row][col] /= other._data[row][col];
      }
    }
  }
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
  for (const auto& row : matrix._data) {
    for (auto val : row) {
      os << val << ' ';
    }
    os << std::endl;
  }
  return os;
}
