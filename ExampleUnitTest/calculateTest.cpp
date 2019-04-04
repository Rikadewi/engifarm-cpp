// #include "calculate.h"
#include "CUnit/Basic.h"
#include <sstream>
#include <iostream>
using namespace std;
void unit_test(std::ostream& os = std::cout) 
{ 
  os << "Hello" << std::endl; 
} 

int main(){
    stringstream ss;
    unit_test(ss);
}

// void egifunc() {
//     stringstream ss;
//     unit_test(ss);
//     CU_ASSERT_EQUAL(ss.str(), "Hello\n");
// }

// int main() {
//     // Initialize the CUnit test registry
//     if (CUE_SUCCESS != CU_initialize_registry())
//         return CU_get_error();

//     CU_basic_set_mode(CU_BRM_VERBOSE);
//     CU_pSuite pSuite = NULL;

//     // Add a suite to the registry
//     pSuite = CU_add_suite("vivi", 0, 0);

//     // Always check if add was successful
//     if (NULL == pSuite) {
//         CU_cleanup_registry();
//         return CU_get_error();
//     }

//     // Add the test to the suite
//     if (NULL == CU_add_test(pSuite, "egi", egifunc)) {
//         CU_cleanup_registry();
//         return CU_get_error();
//     }

//     // if (NULL == CU_add_test(pSuite, "garda", gardafunc)) {
//     // if (NULL == CU_add_test(pSuite, "garda", gardafunc)) {
//     //     CU_cleanup_registry();
//     //     return CU_get_error();
//     // }

//     // Run the tests and show the run summary
//     CU_basic_run_tests();
//     return CU_get_error();
// }