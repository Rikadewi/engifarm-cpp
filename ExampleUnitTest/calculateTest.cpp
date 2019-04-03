#include "calculate.h"
#include "CUnit/Basic.h"

//fungsi untuk check function pada calculate.cpp
//ubah tambahTest jadi namaFunctionTest
//ubah tambah jadi namaFuntion
void tambahTest() {
//   Check if first param matches with second[2]
  CU_ASSERT_EQUAL(tambah(2, 14), 16);
  CU_ASSERT_EQUAL(tambah(0, 0), 0);
  CU_ASSERT_EQUAL(tambah(-1 ,6), 4); //contoh tes yang gagal
}

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_pSuite pSuite = NULL;

    // ubah testCalculateSuite jadi namaFileSuite
    // Add a suite to the registry
    pSuite = CU_add_suite("calculateTestSuite", 0, 0);

    // Always check if add was successful
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Ubah tambahTest jadi namaFunctionTest 
    // Add the test to the suite
    if (NULL == CU_add_test(pSuite, "tambahTest", tambahTest)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run the tests and show the run summary
    CU_basic_run_tests();
    return CU_get_error();
}