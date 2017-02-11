result: output
	~/cse420/simplesim-3.0/sim-outorder -config ~/cse420/simplesim-3.0/config/default.cfg ./output

output: linear_read.c
	~/cse420/gcc/local/bin/alpha-dec-osf4-gcc -Wall -o output linear_read.c
