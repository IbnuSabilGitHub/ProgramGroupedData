
#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>
#include <cmath>
#include <algorithm>

typedef std::vector<std::vector<int>> Matrix;


template <typename T>
void printVector(const std::vector<T> &vec);

template <typename T>
auto countList(const std::vector<T> &list);

template <typename T, typename U>
std::vector<T> multiplyList(const std::vector<T> &X, const std::vector<U> &Y);

int max(const std::vector<int> &rawData);

int min(const std::vector<int> &rawData);

int rangeData(const std::vector<int> &rawData);

int interval(int n);

int classLength(const std::vector<int> &rawData, int n);

std:: vector<double> dataCenter(const Matrix &classRoom, int class_lenght);


std::vector<int> countFrequency(const std::vector<int> &rawData, const Matrix &classUpAndDown);

std::vector<double> Ui(const std::vector<double> &classCenter, auto Xs, int classLenght)

#endif