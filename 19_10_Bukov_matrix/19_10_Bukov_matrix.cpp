#include <iostream>
#include <type_traits>

template <class T, int rows = 3, int cols = 3>
class Matrix
{
private:
    T *data;
public:
    Matrix()
    {
        data = new T[rows*cols];
    }

    ~Matrix()
    {
        delete[] data;
    }

    void fill() //  заполнение матрицы вводом значений с клавиатуры
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                std::cin >> data[i*cols + j];
            }
        }
    }

    void print()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                std::cout << data[i*cols + j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    void fillRandom() // заполнение матрицы случайными значениями
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // Проверка типа данных T
                if(std::is_floating_point <T>::value)
                {
                    // Если T - число с плавающей точкой, генерирую случайные значения в диапазоне 0, 1
                    data[i * cols + j] = static_cast<double>(rand()) / RAND_MAX;
                }
                else
                {
                    // Если T - целое число, генерирую случайные целочисленные значения в диапазоне 0, 99
                    data[i * cols + j] = rand() % 100;
                }
            }
        }
    }

    //нахождение минимального и максимального значений
    void MinMax(T& min, T& max) 
    {
        if (rows * cols > 0) 
        {
            min = max = data[0];
        }

        for (int i = 1; i < rows * cols; ++i) 
        {
            if (data[i] < min) 
            {
                min = data[i];
            }
            if (data[i] > max) 
            {
                max = data[i];
            }
        }

        std::cout << "Минимальное значение: " << min << std::endl;
        std::cout << "Максимальное значение: " << max << std::endl;
    }

    
    Matrix<T, rows, cols> operator -(const Matrix& m)
    {
        Matrix<T, rows, cols> result;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i * cols + j] = data[i * cols + j] - m.data[i * cols + j];
            }
        }
        return result;
    }

    Matrix<T, rows, cols> operator +(const Matrix &m)
    {
        Matrix<T, rows, cols> result;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i*cols + j] = data[i*cols + j] + m.data[i*cols + j];
            }
        }
        return result;
    }

    Matrix<T, rows, cols> operator *(const Matrix &m)   
    {
        Matrix<T, rows, cols> result;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i*cols + j] = data[i*cols + j] * m.data[i*cols + j];
            }
        }
        return result;
    }

    Matrix<T, rows, cols> operator /(const Matrix &m)
    {
        Matrix<T, rows, cols> result;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i*cols + j] = data[i*cols + j] / m.data[i*cols + j];
            }
        }
        return result;
    }
};



int main()
{   
    setlocale(LC_ALL, "Rus");
    Matrix<int> matrixint1, matrixint2;
    std::cout << "Введите значения типа int, для заполнения матрицы" << std::endl;
    matrixint1.fill();
    matrixint1.print();
    matrixint1.fillRandom();
    matrixint2.fillRandom();
    std::cout << "\nМатрица (matrixint1) случайных значений" << std::endl; 
    matrixint1.print();
    std::cout << "\nМатрица (matrixint2) случайных значений" << std::endl;
    matrixint2.print();
    Matrix<int> resultAdditionInt = matrixint1 + matrixint2;
    std::cout << "\nРезультат сложения:\n";
    resultAdditionInt.print();
    Matrix<int> resultSubtractionInt = matrixint1 - matrixint2;
    std::cout << "\nРезультат вычитания:\n";
    resultSubtractionInt.print();
    Matrix<int> resultMultiplicationInt = matrixint1 * matrixint2;
    std::cout << "\nРезультат умножения:\n";
    resultMultiplicationInt.print();
    std::cout << "\nРезультат деления:\n";
    Matrix<int> resultDivisionInt = matrixint1 / matrixint2;
    resultDivisionInt.print();
    int minInt, maxInt;
    std::cout << "Минимальное и максимальное значение в матрице(matrix1)" << std::endl;
    matrixint1.MinMax(minInt, maxInt);


    Matrix<double> matrixdouble1, matrixdouble2;
    std::cout << "Введите значения типа double, для заполнения матрицы" << std::endl;
    matrixdouble1.fill();
    matrixdouble1.print();
    matrixdouble1.fillRandom();
    std::cout << "\nМатрица случайных значений типа double(matrixdouble1)" << std::endl; 
    matrixdouble1.print();
    matrixdouble2.fillRandom();
    std::cout << "\nМатрица случайных значений типа double(matrixdouble2)" << std::endl;
    matrixdouble2.print();
    Matrix<double> resultAdditionDouble = matrixdouble1 + matrixdouble2;
    std::cout << "\nРезультат сложения:\n";
    resultAdditionDouble.print();
    Matrix<double> resultSubtractionDouble = matrixdouble1 - matrixdouble2;
    std::cout << "\nРезультат вычитания:\n";
    resultSubtractionDouble.print();
    Matrix<double> resultMultiplicationDouble = matrixdouble1 * matrixdouble2;
    std::cout << "\nРезультат умножения:\n";
    resultMultiplicationDouble.print();
    Matrix<double> resultDivisionDouble = matrixdouble1 / matrixdouble2;
    std::cout << "\nРезультат деления:\n";
    resultDivisionDouble.print();
    double minDouble, maxDouble;
    std::cout << "Минимальное и максимальное значение в матрице(matrixdouble1)" << std::endl;
    matrixdouble1.MinMax(minDouble, maxDouble);


    Matrix<char> matrixchar1, matrixchar2;
    std::cout << "Введите значения типа char, для заполнения матрицы" << std::endl;
    matrixchar1.fill();
    matrixchar1.print();
    matrixchar1.fillRandom();
    std::cout << "\nМатрица случайных значений типа char(matrixchar1)" << std::endl;
    matrixchar1.print();    
    matrixchar2.fillRandom();
    std::cout << "\nМатрица случайных значений типа char(matrixchar2)" << std::endl;
    matrixchar2.print();
    
return 0;
}
