cd $(dirname $0)

echo "With virtual functions:"
g++ -DWITH_VIRTUAL_FUNCTIONS test.cpp -o test && ./test
echo -e "\n"

echo "Without virtual functions:"
g++                          test.cpp -o test && ./test
echo -e "\n"