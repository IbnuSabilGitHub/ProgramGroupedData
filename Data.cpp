// #include <functionGroupedData.h> // Import Function
#include <iostream>
#include "headerFunction.h"
using namespace std;

int main()
{
    int n, nClass, numRows, numCols, class_Length;
    // cout << "Masukan jumlah Data (n) : " << endl;
    // cin >> n;
    vector<int> rawData = {58, 53, 56, 64, 50, 50, 55, 57, 56, 56,
                           71, 72, 50, 77, 83, 80, 88, 43, 60, 68,
                           70, 71, 60, 55, 42, 58, 83, 92, 95, 47,
                           51, 82, 70, 57, 67, 82, 55, 69, 72, 65}; // raw data yang akan di jadi kan data kelompok
    n = rawData.size();                                             // jumlah data

    class_Length = classLength(rawData, n);                  // Mendapatkan panjang dari class dengan membangi jarak data dengan interval Class
    numRows = 2;                                             // batas bawah dan batas atas
    numCols = interval(n);                                   // Jumlah Kolom data kelompok
    Matrix classUpAndDown(numCols, vector<int>(numRows, 0)); // Initialize with 0 for example
    int buffer = (min(rawData) - 1);                         // meyimpan data yang telah di jumlahkan  dan

    // Looping Untuk Memasukan data bawah dan atas
    for (int i = 0; i < numCols; i++)
    {
        for (int j = 0; j < numRows; j++)
        {
            if (j == 0) // Jika j sama dengan nol maka tambakan value buffer yang tealah di tambah satu ke arr saat ini
            {
                classUpAndDown[i][j] = buffer + 1;
            }
            else // jika tidak maka tambakan value yg telah di oprasikan
            {
                classUpAndDown[i][j] = buffer + (class_Length - 1); // nilai variabek buffer di atas akan ditambah dengan panjang kelas  di kurang satu
            }
            buffer = classUpAndDown[i][j]; // update value buffer
        }
    }

    cout << "Interval Class" << endl;
    for (int i = 0; i < numCols; i++)
    {
        for (int j = 0; j < numRows; j++)
        {
            cout << classUpAndDown[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "-----------------Frequency-----------------" << endl;
    vector<int> frequencyClass = countFrequency(rawData, classUpAndDown);
    printVector(frequencyClass);

    cout << "---------------Sigma Frequency---------------" << endl;
    vector<int> sigmaFrequency = sigmaF(frequencyClass);
    printVector(sigmaFrequency);

    cout << "---------------------Xi---------------------" << endl;
    vector<double> classCenter = dataCenter(classUpAndDown, class_Length);
    printVector(classCenter);

    auto TempMean = classCenter[(classCenter.size() / 2)];

    cout << "---------------------Ui---------------------" << endl;
    vector<double> ui = Ui(classCenter, TempMean, class_Length);
    printVector(ui);

    cout << "--------------------F(Ui)--------------------" << endl;
    vector<double> sigFiUi = multiplyList(ui, frequencyClass);
    try
    {
        for (int value : sigFiUi)
        {
            cout << value << endl;
        }
    }
    catch (const char *message)
    {
        cout << "Error: " << message << endl;
    }

    int F = countList(frequencyClass);
    auto Fu = countList(sigFiUi);
    cout << "Mean dari data kelompok = " << mean(TempMean, F, Fu, class_Length) << endl;

    return 0;
}
