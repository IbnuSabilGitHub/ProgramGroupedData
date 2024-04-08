#pragma once

#include "headerFunction.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>


// Function tempalte untuk print vector
template <typename T> // template untuk 
void printVector(const std::vector<T> &vec) //Parameter(vector/Array)
{
    for (const auto &value : vec) //  range-based for loop(for each loop)
    {
        std::cout << value << std::endl; // print value
    }
}

// Function Template untuk menghitung total value dari vector 
template <typename T>
T countList(const std::vector<T> &list) // Pareanter(Vector)
{
    auto total = 0; // variabel untuk menyimpan hasil perjumlahan
    for (auto &value : list) // foreach loop
    {
        total += value; // value total akan di perbarui dengan total sebelumnya di tambah ba
    }
    return total;
}

// Function Tamplate untuk mengkalikan masing maing value i dari  kedua vector.
template <typename T, typename U>
std::vector<T> multiplyList(const std::vector<T> &X, const std::vector<U> &Y)//Paranter(Vector X, Vector Y)aaaaaaaaaaaaaaaaaaaa
{
    if (X.size() != Y.size()) // jika n dari kedua vector sama maka akan eror
    {
        throw "Hanya bisa mengalikan dengan n(panjang) list yang sama";
    }

    std::vector<T> buffer(X.size()); // vector untuk menghitung oprasi
    for (int i = 0; i < X.size(); ++i)
    {
        buffer[i] = X[i] * Y[i]; // Lakukan perkalian dan simpan hasilnya di arr buffer
    }
    return buffer;
}



//Function Untuk mecari nilai terkecil dari kupulan data
int max(const std::vector<int> &rawData)
{
    int max = rawData[0];
    for (int i = 0; i < rawData.size(); i++)
    {
        if (rawData[i] > max)
        {
            max = rawData[i];
        }
    }
    return max;
}


// Function untuk mecari nilai terbesar dari kumpulan data
int min(const std::vector<int> &rawData)
{

    int min = rawData[0];
    for (int i = 0; i < rawData.size(); i++)
    {
        if (rawData[i] < min)
        {
            min = rawData[i];
        }
    }
    return min;
}

int rangeData(const std::vector<int> &rawData) {
    if (rawData.empty()) {
        // Mengembalikan 0 jika vektor kosong
        return 0;
    } else {
        // Menggunakan std::max_element dan std::min_element untuk mencari nilai maksimum dan minimum
        return *std::max_element(rawData.begin(), rawData.end()) - *std::min_element(rawData.begin(), rawData.end());
    }
}


int interval(int n)
{
    return std::round(1 + (3.3 * (std::log10(n))));
}

int classLength(const std::vector<int> &rawData, int n)
{

    double temp = static_cast<double>(rangeData(rawData)) / interval(n);
    return round(temp);
}

std:: vector<double> dataCenter(const Matrix &classRoom, int class_lenght)
{
    int lenght = classRoom.size();
    std::vector<double> xi(lenght);
    xi[0] = (classRoom[0][0] + classRoom[0][1]) / 2;
    for (int i = 1; i < lenght; i++)
    {
        xi[i] = static_cast<double>(xi[i - 1] + class_lenght);
    }
    return xi;
}

std::vector<int> countFrequency(const std::vector<int> rawData, const Matrix classUpAndDown)
{
    int row = classUpAndDown[0].size();
    int col = classUpAndDown.size();
    std::vector<int> buffer;
    int frequency = 0;
    for (int i = 0; i < col; i++)
    {
        for (int valData : rawData)
        {
            if (valData >= classUpAndDown[i][0] && valData <= classUpAndDown[i][1])
            {
                frequency++;
            }
        }
        buffer.push_back(frequency);
        frequency = 0;
    }

    return buffer;
}

std::vector<double> Ui(const std::vector<double> &classCenter, int Xs, int classLenght)
{
    std::vector<double> buffer;      
    for (int xi : classCenter)
    {
        buffer.push_back((xi - Xs) / classLenght);
    }
    return buffer;
}

template<typename T>
std::vector<T> sigmaF(const std::vector<T> &Frequency){
    std::vector<T> buffer;
    buffer.push_back(Frequency[0]);
    for (int i = 1; i < Frequency.size(); i++)
    {
        buffer.push_back(buffer[i - 1] + Frequency[i]);
    }
    return buffer;
}

double mean(double &Xs, int &total_f, double &total_sigma_Fu, int &classLenght){
    return Xs + ((total_sigma_Fu * classLenght) / total_f);
}


