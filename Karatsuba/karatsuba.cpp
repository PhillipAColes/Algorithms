#include <iostream>
#include <math.h>
#include <string>

using namespace std;

std::string operator+(std::string x, std::string y){

    if(x.length()>y.length()){
        y = std::string( x.length()-y.length(),'0').append(y);
    }else if(x.length()<y.length()){
        x = std::string(y.length()-x.length(),'0').append(x);
    }   

    std::string sum = "";
    int carry = 0;    
    
    for(int i=x.length()-1;i>=0;i--){
        long long int x_int = x[i] - '0';
        long long int y_int = y[i] - '0';
        long long int z = x_int + y_int + carry;
        carry = 0;
        if(z >= 10){
            z = z%10;
            carry = 1;
        }
        sum.insert(0,to_string(z));
    }    
  
    if(carry==1){
        return sum.insert(0,"1");
    }else{
        return sum;
    }
    
}


std::string multiply(std::string x, std::string y){
    
    if(x.length()<=2 && y.length()<=2){
        long long xy = stoll(x) * stoll(y);
        return std::to_string(xy);
    }
    
    long long int n = x.length();
    long long int m = y.length();
    long long int a_pow = n/2+(n%2);
    long long int c_pow = m/2+(m%2);

    // Splitting our string representation of the integer
    std::string a = x.substr(0,n/2);
    std::string b = x.substr(n/2,n-1);
    std::string c = y.substr(0,m/2);
    std::string d = y.substr(m/2,m-1);
    
    // Multiplying
    std::string ac = multiply(a,c);
    std::string bd = multiply(b,d);
    std::string ad = multiply(a,d);
    std::string bc = multiply(b,c);
    
    // Back-pad the strings with zeros
    ac.append(size_t (a_pow+c_pow),'0');
    ad.append(size_t (a_pow),'0');
    bc.append(size_t (c_pow),'0');
    
    std::string product = ac + ad + bc + bd;
    
    // Return result for X times Y
    return product;

}


void tests(){
    
    int pass = 0;
    int total = 0;
    
    if( multiply("1234","5678") == "7006652")pass++; total++;
    if( multiply("123456","234567") == "28958703552")pass++; total++;
    if( multiply("987654321","789012345") == "779271451861592745")pass++; total++;
    if( multiply("400040093432542342","400040093432542342") == "160032076353517206627328489622844964" )pass++; total++;
    if( multiply("12345678901234567890","98765432109876543210") == "1219326311370217952237463801111263526900" )pass++; total++;
    
    cout << pass << "/" << total << "  test cases passed" << endl;   
    
}

int main(){
    
    printf("Enter two integers to be multiplied\n");
    
    std::string x, y;
    
    std::cin >> x >> y;
    
    int factor = 0;
    if(x.length()>y.length()){
        factor = x.length()-y.length();
        y.append(size_t (factor),'0');
    }else if(y.length()>x.length()){
        factor = y.length()-x.length();
        x.append(size_t (factor),'0');
    }
    
    std::string product = multiply(x,y);
    
    product.erase(size_t (product.length()-factor));
    
    cout << x << " x " << y << " = " << product << endl;
    
    tests();
    
    return 0;
    
}