result: output
	~/cse420/simplesim-3.0/sim-outorder -config ~/cse420/simplesim-3.0/config/default.cfg ./output

output: random_read.c
	~/cse420/gcc/local/bin/alpha-dec-osf4-gcc -Wall -o output random_read.c -lm
