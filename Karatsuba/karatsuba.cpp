#include <iostream>
#include <math.h>
#include <stdexcept>
#include <errno.h>
#include <limits.h>
#include <string>

using namespace std;

std::string multiply(std::string x, std::string y){
    
    cout << "Now to multiply x = " << x << "  and y = "  << y << endl;
    
    if(x.length()<=2 && y.length()<=2){
        cout << "just multiply numeric values" << endl;
        long long xy = stoll(x) * stoll(y);
        return std::to_string(xy);
    }
    
    int n = x.length();
    int m = y.length();
    int a_pow = n/2+(n%2);
    int c_pow = m/2+(m%2);
    
    cout << "they have lengths " << n << " and " << m << " digits respectively" << endl;

    // splitting our string representation of the integer
    std::string a = x.substr(0,n/2);
        cout << "a = " << a << std::endl;
    std::string b = x.substr(n/2,n-1);
        cout << "b = " << b << std::endl;
    std::string c = y.substr(0,m/2);
        cout << "c = " << c << std::endl;
    std::string d = y.substr(m/2,m-1);
        cout << "d = " << d << std::endl;
    
    // multiplying
    std::string ac = multiply(a,c);
        cout << "ac = " << ac << std::endl;
    std::string bd = multiply(b,d);
        cout << "bd = " << bd << std::endl;
    std::string ad = multiply(a,d);
        cout << "ad = " << ad << std::endl;
    std::string bc = multiply(b,c);
        cout << "bc = " << bc << std::endl;
    
    std::cout << "returning ac*10^(n+m)/2 + ad*10^(n/2) + bc*10^(m/2) + bd" << endl;
    
    printf("first term = %lld", stoll(ac)*((long long)pow(10,a_pow+c_pow)));
    printf(", second term = %lld", stoll(ad)*((long long)pow(10,a_pow)));
    printf(", third term = %lld", stoll(bc)*((long long)pow(10,c_pow)));
    printf(", fourth term = %lld\n",stoll(bd));
           
    std::string result = to_string(stoll(ac)*((long long)pow(10,a_pow+c_pow)) + 
                                   stoll(ad)*((long long)pow(10,a_pow)) + 
                                   stoll(bc)*((long long)pow(10,c_pow)) +
                                   stoll(bd));
        
    cout << "returning result: " << result << endl;
    if(stoll(result) != stoll(x)*stoll(y)){
        cout << "uh oh... " << " true value is " << stoll(x)*stoll(y) << endl;
        exit(0);
    }
    
    
    return result;
    
}


int main(){
    
    printf("Enter two integers to be multiplied\n");
    
    unsigned long long x, y;
    unsigned long long ull_int = pow(2.0, (int)(sizeof(unsigned long long))*8);
    
    std::string x_str, y_str;
    
    //std::cin >> x_str >> y_str;
    x_str = "1234";
    y_str = "5678";
    
    cout << "size of a long long int is " << (int) sizeof(unsigned long long)*8 << " bits" << endl;
    cout << "maximum integer value that can be held is " << ull_int << endl;

    x = strtoull(x_str.c_str(), nullptr, 0);
    if (x == ULLONG_MAX && errno == ERANGE) { std::cout << "shit son" << endl;}
    
    std::cout << "----------" << endl;
    std::cout << "x = 321,  y = 78" << endl;
    std::cout << "predicted: " << multiply("321","78") << std::endl;
    std::cout << "actual: " << (long long) 321*78 << endl;
    
    std::cout << "----------" << endl;
    std::cout << "x = " << x_str << ",  y = " << y_str << endl;
    std::cout << "predicted: " << multiply(x_str,y_str) << std::endl;
    std::cout << "actual: " << 1234*5678 << endl;
    
    std::cout << "----------" << endl;
    std::cout << "x = 123456,  y = 234567" << endl;
    std::cout << "predicted: " << multiply("123456","234567") << std::endl;
    std::cout << "actual: " << (long long) 123456*234567 << endl;
    
    std::cout << "----------" << endl;
    std::cout << "x = 123,  y = 567" << endl;
    std::cout << "predicted: " << multiply("123","567") << std::endl;
    std::cout << "actual: " << (long long) 123*567 << endl;
    
    std::cout << "----------" << endl;
    std::cout << "x = 987654321,  y = 789012345" << endl;
    std::cout << "predicted: " << multiply("987654321","789012345") << std::endl;
    std::cout << "actual: " << (long long) 987654321*789012345 << endl;
    
    std::cout << "----------" << endl;
    std::cout << "x = 10001,  y = 78976" << endl;
    std::cout << "predicted: " << multiply("10001","78976") << std::endl;
    std::cout << "actual: " << (long long) 10001*78976 << endl;
    
    return 0;
    
}