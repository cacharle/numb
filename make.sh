set -x trace
chicken-csc  foreign.scm -L$(pwd)/build -Wl,-rpath=$(pwd)/build -L -lnumb
