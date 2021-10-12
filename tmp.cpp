#include <iostream>
#include <vector>
#include <numeric>



int mod(int a, int b)
{
    return (a%b + b)%b;
}
long get_pow(int a, int b){
    int res = 1;
    for (int i = 0; i < b; i += 1){
        res = res * a;
    }
    return res;
}
int main()
{
    int n, k;
    long x, y;
    std::vector <long> a = {};
    std::vector <long> a1 = {};
    int left_pointer = 0;
    int right_pointer = n - 1;
    long BIG_ING = get_pow(2, 30);
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i){
        int tmp;
        std::cin >> tmp;
        a.push_back(tmp);
        a1.push_back(NULL);
    }

    for (int i = 0; i < k; i += 1){
        if (right_pointer == -1){
            for (int j = 0; j < n; j += 1){
                a[j] = a1[j];
                a1[j] = NULL;
            }
            right_pointer = n - 1;
            left_pointer = 0;
        }
        if (left_pointer >= 0){x = a[left_pointer];}
        else {x = a1[left_pointer];}

        if (right_pointer >= 0) {y = a[right_pointer];}
        else {y = a1[right_pointer];}

        if (x < y){
            if (left_pointer >= 0){
                a[left_pointer] = NULL;
                left_pointer += 1;
            }
            else{
                a1[left_pointer] = NULL;
                left_pointer += 1;
            }
            right_pointer += 1;
            if (right_pointer >= 0){
                if (right_pointer < a.size()){
                    a[right_pointer] = mod(x+y, BIG_ING);
                }
                else{
                    a.push_back(mod(x+y, BIG_ING));
                }
            }
            else{
                a1[right_pointer] = mod(x+y, BIG_ING);
            }
        }
        else{
            if (right_pointer >= 0){
                a[right_pointer] = NULL;
                right_pointer -= 1;
            }
            else{
                a1[right_pointer] = NULL;
                right_pointer -= 1;
            }
            if (left_pointer > 0){
                a[left_pointer - 1] = mod(y-x, BIG_ING);
                left_pointer -= 1;
            }
            else{
                if (left_pointer < 0){
                    a1[left_pointer - 1] = (y - x) % BIG_ING;
                    left_pointer -= 1;
                }
                else{
                    a1[-1] = mod(y-x, BIG_ING);
                    left_pointer = -1;
                }
            }
        }
    }
    std::cout << a.size();
    std::cout << a1.size();
    for (int i = 0; i < a1.size(); i += 1){
        std::cout << a1[i] << " ";
    }
    for (int i = 0; i < a.size(); i += 1){
        std::cout << a[i] << " ";
    }
}
