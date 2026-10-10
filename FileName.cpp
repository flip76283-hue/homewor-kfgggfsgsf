#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdexcept>

using namespace std;

class IOutput {
public:
    virtual void Show() = 0;
    virtual void Show(string info) = 0;
    virtual ~IOutput() = default;
};

class IMath {
public:
    virtual int Max() = 0;
    virtual int Min() = 0;
    virtual float Avg() = 0;
    virtual bool Search(int valueToSearch) = 0;
    virtual ~IMath() = default;
};

class ISort {
public:
    virtual void SortAsc() = 0;
    virtual void SortDesc() = 0;
    virtual void SortByParam(bool isAsc) = 0;
    virtual ~ISort() = default;
};

class Array : public IOutput, public IMath, public ISort {
private:
    vector<int> data;

public:
    Array(vector<int> values) {
        data = values;
    }

    void Show() override {
        for (int value : data) {
            cout << value << " ";
        }
        cout << endl;
    }

    void Show(string info) override {
        cout << info << endl;
        Show();
    }

    int Max() override {
        if (data.empty()) {
            throw runtime_error("Array is empty");
        }
        return *max_element(data.begin(), data.end());
    }

    int Min() override {
        if (data.empty()) {
            throw runtime_error("Array is empty");
        }
        return *min_element(data.begin(), data.end());
    }

    float Avg() override {
        if (data.empty()) {
            throw runtime_error("Array is empty");
        }

        float sum = 0;

        for (int value : data) {
            sum += value;
        }

        return sum / data.size();
    }

    bool Search(int valueToSearch) override {
        return find(data.begin(), data.end(), valueToSearch) != data.end();
    }

    void SortAsc() override {
        sort(data.begin(), data.end());
    }

    void SortDesc() override {
        sort(data.begin(), data.end(), greater<int>());
    }

    void SortByParam(bool isAsc) override {
        if (isAsc) {
            SortAsc();
        }
        else {
            SortDesc();
        }
    }
};

class IShape {
public:
    virtual double CalculateArea() = 0;
    virtual double CalculatePerimeter() = 0;
    virtual ~IShape() = default;
};

class Circle : public IShape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double CalculateArea() override {
        return 3.141592653589793 * radius * radius;
    }

    double CalculatePerimeter() override {
        return 2 * 3.141592653589793 * radius;
    }
};

class Rectangle : public IShape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    double CalculateArea() override {
        return width * height;
    }

    double CalculatePerimeter() override {
        return 2 * (width + height);
    }
};

class Triangle : public IShape {
private:
    double a;
    double b;
    double c;

public:
    Triangle(double sideA, double sideB, double sideC) {
        if (sideA <= 0 || sideB <= 0 || sideC <= 0 ||
            sideA + sideB <= sideC ||
            sideA + sideC <= sideB ||
            sideB + sideC <= sideA) {
            throw invalid_argument("Invalid triangle sides");
        }

        a = sideA;
        b = sideB;
        c = sideC;
    }

    double CalculateArea() override {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    double CalculatePerimeter() override {
        return a + b + c;
    }
};

class IDrivable {
public:
    virtual void StartEngine() = 0;
    virtual void StopEngine() = 0;
    virtual void Drive() = 0;
    virtual ~IDrivable() = default;
};

class Car : public IDrivable {
public:
    void StartEngine() override {
        cout << "Car engine started" << endl;
    }

    void StopEngine() override {
        cout << "Car engine stopped" << endl;
    }

    void Drive() override {
        cout << "Car is driving" << endl;
    }
};

class Motorcycle : public IDrivable {
public:
    void StartEngine() override {
        cout << "Motorcycle engine started" << endl;
    }

    void StopEngine() override {
        cout << "Motorcycle engine stopped" << endl;
    }

    void Drive() override {
        cout << "Motorcycle is driving" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "");

    cout << "===== TASK 1 =====" << endl;

    Array arr({ 5, 2, 9, 1, 7 });

    arr.Show();
    arr.Show("Elements of the array:");

    cout << "\n===== TASK 2 =====" << endl;

    cout << "Maximum: " << arr.Max() << endl;
    cout << "Minimum: " << arr.Min() << endl;
    cout << "Average: " << arr.Avg() << endl;
    cout << "Search 9: " << (arr.Search(9) ? "Found" : "Not found") << endl;
    cout << "Search 4: " << (arr.Search(4) ? "Found" : "Not found") << endl;

    cout << "\n===== TASK 3 =====" << endl;

    cout << "Ascending: ";
    arr.SortAsc();
    arr.Show();

    cout << "Descending: ";
    arr.SortDesc();
    arr.Show();

    cout << "Sort by parameter (true): ";
    arr.SortByParam(true);
    arr.Show();

    cout << "Sort by parameter (false): ";
    arr.SortByParam(false);
    arr.Show();

    cout << "\n===== TASK 4 =====" << endl;

    Circle circle(5);
    Rectangle rectangle(4, 6);
    Triangle triangle(3, 4, 5);

    cout << "Circle area: " << circle.CalculateArea() << endl;
    cout << "Circle perimeter: " << circle.CalculatePerimeter() << endl;

    cout << "Rectangle area: " << rectangle.CalculateArea() << endl;
    cout << "Rectangle perimeter: " << rectangle.CalculatePerimeter() << endl;

    cout << "Triangle area: " << triangle.CalculateArea() << endl;
    cout << "Triangle perimeter: " << triangle.CalculatePerimeter() << endl;

    cout << "\n===== TASK 5 =====" << endl;

    Car car;
    car.StartEngine();
    car.Drive();
    car.StopEngine();

    cout << endl;

    Motorcycle motorcycle;
    motorcycle.StartEngine();
    motorcycle.Drive();
    motorcycle.StopEngine();

    return 0;
}