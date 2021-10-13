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
    long BIG_ING = get_pow(2, 30);
    int n, k;
    std::cin >> n >> k;
    std::vector<long> a;
    int left_pointer = 0;
    int right_pointer = n - 1;

    for (int i = 0; i < n; ++i){
        long tmp;
        std::cin >> tmp;
        a.push_back(tmp);
    }

    if (n == 1){
        std::cout << "0";
    }
    else{
        for (int i = 0; i < k; i += 1){
            long x = a[left_pointer];
            long y = a[right_pointer];
            if (x < y){
                long new_value = mod(x+y, BIG_ING);
                a[left_pointer] = new_value;

                if (right_pointer == n - 1){
                    right_pointer = 0;
                }
                else{
                    right_pointer += 1;
                }

                if (left_pointer == n - 1){
                    left_pointer = 0;
                }
                else{
                    left_pointer += 1;
                }
            }
            else{
                long new_value = mod(y-x, BIG_ING);
                a[right_pointer] = new_value;

                if (right_pointer == 0){
                    right_pointer = n - 1;
                }
                else{
                    right_pointer -= 1;
                }

                if (left_pointer == 0){
                    left_pointer = n - 1;
                }
                else{
                    left_pointer -= 1;
                }
            }
        }
        if (left_pointer < right_pointer){
            for (int j = left_pointer; j < right_pointer; j += 1){
                std::cout << a[j] << " ";
            }
            for (int j = right_pointer; j < n; j += 1){
                std::cout << a[j] << " ";
            }
        }
        else{
            for (int j = left_pointer; j < n; j += 1){
                std::cout << a[j] << " ";
            }
            for (int j = 0; j < right_pointer + 1; j += 1){
                std::cout << a[j] << " ";
            }
        }
    }
}
