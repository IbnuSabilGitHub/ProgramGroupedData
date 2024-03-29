#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;

typedef vector<vector<int>> Matrix;

int classLength(vector<int> rawData, int n);
int interval(int n);
int rangeData(vector<int> rawData);
int min(vector<int> rawData);
int max(vector<int> rawData);
vector<int> countFrequency(const vector<int> rawData, const Matrix &classUpAndDown);
vector<double> dataCenter(const Matrix classRoom, int class_lenght);
vector<double> Ui(const vector<double> classCenter, auto Xs, int classLenght);

template <typename T>
void printVector(const vector<T> &vec)
{
    for (const auto &value : vec)
    {
        cout << value << endl;
    }
}

template <typename T>
auto countList(const vector<T> &list)
{
    auto total = 0;
    for (auto &value : list)
    {
        total += value;
    }
    return total;
}

template <typename T>
vector<T> multiplyList(const vector<T> &X, const vector<int> &Y)
{
    if (X.size() == Y.size())
    {
        throw "Hanya bisa mengalikan dengan n(panjang) list yang sama";
    }

    vector<T> buffer(X.size());
    for (int i = 0; i < X.size(); ++i)
    {
        buffer[i] = X[i] * Y[i];
    }
    return buffer;
}

auto MEAN(auto Xs, auto SigmaFrequencyU, auto SigmaFrequency, int classLenght);

int main()
{

    int n, nClass, numRows, numCols;
    double class_Length;
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

    int buffer = (min(rawData) - 1); // meyimpan data yang telah di jumlahkan  dan

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

    cout << "Frequency" << endl;
    vector<int> frequencyClass = countFrequency(rawData, classUpAndDown);
    printVector(frequencyClass);

    cout << "Xi" << endl;
    vector<double> classCenter = dataCenter(classUpAndDown, class_Length);
    printVector(classCenter);

    auto TempMean = classCenter[(classCenter.size() / 2)];

    cout << "Ui" << endl;
    vector<double> ui = Ui(classCenter, TempMean, class_Length);
    printVector(ui);

    cout << "F(Ui)" << endl;
    vector<double> result = multiplyList(ui, frequencyClass);
    try
    {
        for (int value : result)
        {
            cout << value << endl;
        }
        
    }
    catch (const char *message)
    {
        cout << "Error: " << message << endl;
    }

    cout << "SigmaFrequencyU = " << countList(result) <<endl;

    return 0;
}

auto MEAN(auto Xs, auto SigmaFrequencyU, auto SigmaFrequency, int classLenght){
    return  Xs + (SigmaFrequencyU * classLenght) / SigmaFrequency;
}

vector<double> Ui(const vector<double> classCenter, auto Xs, int classLenght)
{
    vector<double> buffer;
    for (int xi : classCenter)
    {
        buffer.push_back((xi - Xs) / classLenght);
    }
    return buffer;
}

vector<int> countFrequency(const vector<double> rawData, const Matrix &classUpAndDown)
{
    int row = classUpAndDown[0].size();
    int col = classUpAndDown.size();
    vector<int> buffer;
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

vector<double> dataCenter(const Matrix classRoom, int class_lenght)
{
    int lenght = classRoom.size();
    vector<double> xi(lenght);
    xi[0] = (classRoom[0][0] + classRoom[0][1]) / 2;
    for (int i = 1; i < lenght; i++)
    {
        xi[i] = static_cast<double>(xi[i - 1] + class_lenght);
    }
    return xi;
}

int classLength(vector<int> rawData, int n)
{

    double temp = static_cast<double>(rangeData(rawData)) / interval(n);
    return round(temp);
}

int interval(int n)
{
    return round(1 + (3.3 * (log10(n))));
}

int rangeData(vector<int> rawData)
{
    return max(rawData) - min(rawData);
}

int min(vector<int> rawData)
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

int max(vector<int> rawData)
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
