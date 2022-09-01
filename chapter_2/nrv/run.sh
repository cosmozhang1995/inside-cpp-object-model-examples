cd $(dirname $0)

CXX=g++

CXX_OPTIONS="-DITERATIONS=1000000"

$CXX                           $CXX_OPTIONS test.cpp -o test && ./test
$CXX -DENABLE_COPY_CONSTRUCTOR $CXX_OPTIONS test.cpp -o test && ./test
