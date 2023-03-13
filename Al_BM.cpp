#include <iostream>
#include <string>
# define ASCII_CHARS 256

int IsKPeriodic(const std::string &str , const std::string &pattern)
{
    int arr_ascii[ASCII_CHARS];
    int len_str = str.size();
    int len_pattern = pattern.size();

    for(size_t i=0 ; i < ASCII_CHARS ; i++) arr_ascii[i]=len_pattern;

    for(size_t i=0 ; i < len_pattern-1 ; i++)
        arr_ascii[(unsigned char)pattern[i]] = len_pattern-i-1;
    
    //--------------- Search ----------------------------
    int i = len_pattern-1;
    int coincidences = 0;
    do{
        int j = len_pattern-1;
        int k = i;
        while ((j >= 0) && (pattern[j] == str[k])){
            k--;
            j--;
        }
        if(j < 0) coincidences++;
        i += arr_ascii[(unsigned)str[i]];

    } while (i < len_str);
    if (coincidences > 0) return coincidences;
    return 0;
}

int main()
{
    std::string my_str{"qwerqwerqwerqwerqwerqwerqwerqwer"};
    std::string my_pattern{"qwer"};

    std::cout << IsKPeriodic(my_str, my_pattern) << " matches" << std::endl;

    return 0;
}