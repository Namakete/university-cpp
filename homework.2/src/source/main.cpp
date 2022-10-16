#include <iostream>
#include <string>
#include <cmath>

bool decimalNumberSearch(int a, int b){
  std::string sub = std::to_string(b);
  
  return sub.find(std::to_string(a)) != std::string::npos;
}

bool primeNumberSearch(int a) {
  for (size_t i = 2; i <= sqrt(a); i++)
    if (a % i == 0 ) 
      return false;
  
  return true;
}

double f(double x){
  return x * x;
}

double leftRectabgle(double a, double b, int n){
  double step = (b - a) / n;
  double x = a + step / 2.0;
  double res = 0.0;

  for (int i = 0; i < n; i++) {
    res += f(x);
    x += step;
  }

  return res * step;
}

double rightRectangle(double a, double b, int n){
  double step =  (b - a) / n;
  double res = 0.0;

  for (int i = 1; i < n; i++) {
    res += step * f(a + i * step);
  }
  
  return res;
}

double methodRunge(double a, double b, int n){
  double step =  (b - a) / n;
  double res = f(a) + f(b);

  for (int i = 1; i < n - 1; i++) {
    res += 2 * f(a + i * step);
  }

  res *= step / 2;

  return res;
}

int main(int argc, char **argv){

  std::cout << decimalNumberSearch(12, 156123245) << std::endl;

  int values[] = { 2, 3, 4, 5, 6, 7 };

  for (int number : values) {
    std::cout << primeNumberSearch(number) << std::endl;
  }

  std::cout << leftRectabgle(2, 5, 10000) << std::endl; 
  std::cout << rightRectangle(2, 5, 10000) << std::endl; 
  std::cout << methodRunge(2, 5, 10000) << std::endl; 

  return 0;
}
