
#include <iostream>
#include <vector>
#include <optional>

/*
   developer part : what is the api? what is the design? what is the corner case?
*/

/*
YOU CANNOT USE IF-ELSE IN TRY-CATCH BLOCK
*/

/*
   scenario 1 : My input has at least 1 value
           some of the values in the input are odd

   scenario 2 : My input has at least 1 value. None of the values in the
               input are odd

   scenario 3 : input is empty
                   - NOTHING WILL WORK[Not my concern . Input invalid, Exception]

   My function may or may not be able to return SOMETHING VALID

   std::optional --> Indicate algebric data type that may
                    either contain valid value
                    or a symbol indicating "Absence Of information"
*/

// trash code
//  std::vector<int> FindOddNumber(std::vector<int>& data) noexcept {

//     std::vector<int> result;

//     for(int val :data){
//         if(val % 2 != 0){
//             result.push_back(val);
//         }
//     }

//     return result;
// }

/*
   FindOddNUmber is a function that optionally returns a std::vector

   or

   FindOddnumber may or may not return result
*/

std::optional<std::vector<int>> FindOddNumber(std::vector<int> &data) noexcept
{

    std::vector<int> result;

    for (int val : data)
    {
        if (val % 2 != 0)
        {
            result.push_back(val);
        }
    }

    if (result.empty())
    {
        return std::nullopt; // symbol to indicate No information
    }

    return result;
}

/*
   caller : the user who invokes or calls the functionality or accesses the Api
*/

int main()
{

    std::vector<int> data{1, 1, 3, 2, 4, 5};
    // the function may return empty container
    std::optional<std::vector<int>> result = FindOddNumber(data);

    // if(result.empty()){
    //     std::cout << "Mein he pagal hu\n";
    // }
    // else{
    //     for(int val : result){
    //         std::cout << val << '\n';
    //     }
    // }

    // if-initializer syntax --> need min. cpp 17
    //  if(std::vector<int> result = FindOddNumber(data); !result.empty()){
    //      std::cout << "Still bad, but a new to delete data as early as possible\n";
    //      for(int val : result){
    //          std::cout << val << '\n';
    //      }
    //  }//result data delete/free here

    // forcing user to do this with the help of optional
    if (result.has_value())
    {
        
        std::cout << result.value()[0] << "\n";
    }

    return 0;
}