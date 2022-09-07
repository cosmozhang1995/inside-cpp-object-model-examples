cd $(dirname $0)

echo "Single inherit:"
g++ test_single_inherit.cpp -o test && ./test
echo -e "\n"

echo "Multi inherit. With virtual function A:"
g++ \
    -DWITH_VIRTUAL_FUNCTION_A \
    test_multi_inherit.cpp -o test && ./test
echo -e "\n"

echo "Multi inherit. With virtual function B:"
g++ \
    -DWITH_VIRTUAL_FUNCTION_B \
    test_multi_inherit.cpp -o test && ./test
echo -e "\n"

echo "Multi inherit. With virtual function A and B:"
g++ \
    -DWITH_VIRTUAL_FUNCTION_A \
    -DWITH_VIRTUAL_FUNCTION_B \
    test_multi_inherit.cpp -o test && ./test
echo -e "\n"

echo "Multi inherit. Without virtual functions:"
g++ test_multi_inherit.cpp -o test && ./test
echo -e "\n"

echo "Virtual inherit:"
g++ test_virtual_inherit.cpp -o test && ./test
echo -e "\n"