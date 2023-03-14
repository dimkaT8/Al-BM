#include <iostream>
#include <string>

bool IsKPeriodic(const std::string &str, int K)
{
   std::string var_str{};
   for(size_t i=0 ;i < K ; i++) var_str += str[i];
   for(size_t i=0 ; i < str.size()/2 ; i+=K){
       for(size_t s=0 ; s < var_str.size(); s++){
           if(var_str[s] != str[K+s]) return false ;
       }
   }
   return true;
}
int main()
{
  std::string my_str{"qweqweqweqweqweqwe"};
  for(int i=1 ; i <= my_str.size()/2 ;i++){
    if(my_str.size() % i){
        std::cout << " "<< i <<" shares with the remainder" << std::endl;
    } else {
        if(IsKPeriodic(my_str,i)) std::cout << " K = " << i << std::endl;
    }
  }
  return 0;
}