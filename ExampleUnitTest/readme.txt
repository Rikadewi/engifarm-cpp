install CUnit
sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev

Cara buat Unit Test
1. buat namaFileTest.cpp
2. isi seperti template pada calculateTest.cpp
3. g++ -o namaFileTest namaFileTest.cpp namaFile.cpp -libcunit
4. ./namaFileTest

Example:
g++ -o calculateTest calculateTest.cpp calculate.cpp -lcunit
./calculateTest

======DOXYGEN======

install doxygen
sudo apt install doxygen

make config
doxygen -g config

run doxygen
doxygen config

======BONUS CPPCheck========
install CPP check
sudo apt-get install cppcheck

check calculate.cpp
cppcheck --enable=all --inconclusive --std=posix calculate.cpp --check-config 2> testErr.txt

