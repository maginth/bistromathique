# Bistromathique

This is a fast calculator for arbitrary base, symbole arithmetic and number size.    
It is design for 64 bits architecture yet run pretty fast on 32 bits too.   

Run "make" in a terminal to compile.    
>/!\ Big endian robot and other computer stuff, pass your way, your are not welcome /!\    
>/!\   This is a Little endian bistro, you might get seriously drunk results here   /!\    


## Usage :
> ./calc <base_symboles> <operators> <operation_size>  <  <operation_file> 

## Supported operation :
()+-*/% Symboles must be defined by typing them in the same order


## Examples :
> echo '30-2*(4-1234%17)' | ./calc '0123456789' '()+-*/%' 16
	output : 42

> echo '10001x[~00011+00101]\01011' | ./calc '01' '[]+~x/\' 26
	output : 1

## I provide 3 additional script using ./calc :

* ./bc_vs_calc <operation>     
compute <operation> with classical symbole,
compare performance and result with the UNIX calculator bc

* ./ultimate_bc_vs_calc :    
benchmark test for both calc and bc with a giant random operation

* ./simple_calc <operation> :    
simply compute <operation> without need to specify anything else


## About :

This program is originaly an exercice for entrance in the school 42 (france)
The original compilation flag have been turn off and replace with -O3 for performance.    
In addition of creating temporay table to optimize multiplication and division, the main trick is to compute addition and substraction 8 digits by 8 digits over 64 bits.    
(each digit stands in a byte, max base size is 128). Some binary trick propagate the carry instantly over the 8 digits.

If you are interested in documentation over the code, send me a message with your motivation at math.guin@gmail.com    

PS : I will not help student to cheat, I am far too expensive
