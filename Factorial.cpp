#include <iostream>
#include <chrono>
#include <vector>

// Iterative factorial function

 long long int factorial_iterative(int n) 
{  
   long long int result = 1;    
for (int i = 1; i <= n; ++i) 
      result *= i; 
return result;
}
// Recursive factorial function

 long long int factorial_recursive(int n) 
{    
if (n == 0)      
  return 1;    
else       
 return n * factorial_recursive(n - 1);
}
int main() {   

 std::vector<int> test_values = {5, 10, 20, 30, 40,1000}; 

    std::cout << "Factorial Calculation Performance\n\n";

    for (int n : test_values) {   
  
   std::cout << "n = " << n << "\n";  

      // Iterative      
  
auto start_iter = std::chrono::high_resolution_clock::now();

         long long result_iter = factorial_iterative(n);
   
     auto end_iter = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> elapsed_iter = end_iter - start_iter; 
 // Recursive 

       auto start_recur = std::chrono::high_resolution_clock::now(); 

        long long int result_recur = factorial_recursive(n);

        auto end_recur = std::chrono::high_resolution_clock::now(); 

       std::chrono::duration<double, std::milli> elapsed_recur = end_recur - start_recur; 

       std::cout << "Iterative: Result = " << result_iter << ", Time = " << elapsed_iter.count() << " ms\n";   

     std::cout << "Recursive: Result = " << result_recur << ", Time = " << elapsed_recur.count() << " ms\n\n";  
  }  
  return 0;
}
