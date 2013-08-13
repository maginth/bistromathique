# Bistromathique

This is a fast calculator (faster than bc on big operation!). It deal with arbitrary base, arbitrary symbole arithmetic and arbitrary number size.    
It is design for 64 bits architecture yet run pretty fast on 32 bits too.   

Run "make" in a terminal to compile.    
>/!\ Big endian robot or other computing stuff, pass your way, your are not welcome /!\    
>/!\   This is a Little endian bistro, you might get seriously drunk results here   /!\    


## Usage :
	./calc   <base_symboles>   <operators>   <operation_size>    <    <operation_file>     
Note that every symbole in the operation must be defined in \<base_symboles\> or \<operators\>, even space. Otherwise calc throws Syntax error.

## Supported operations :
()+-*/% Symboles must be defined by typing them in the same order


## Examples :
	echo '30-2*(4-1234%17)' | ./calc '0123456789' '()+-*/%' 16    
> output : 42

	echo '10001x[~00011+00101]\01011' | ./calc '01' '[]+~x/\' 26    
> output : 1

## 3 additional scripts using ./calc :

*	./bc_vs_calc   \<operation\>     
compute \<operation\> with classical symbole,
compare performance and result with the UNIX calculator bc

*	./ultimate_bc_vs_calc :    
benchmark test for both calc and bc with a giant random operation

*	./simple_calc    \<operation\>  [\<base_symboles\> [\<operators\>]]:    
simply compute \<operation\> without need to specify anything else if you dont want to.   


## About :

This program is originaly an exercice for entrance in the school 42 (france)   
The original compilation flag have been turn off and replace with -O3 for performance.    
The team failed epically to debug the program in time,    
hopefully after changing one line and 3 character you can now enjoy it.    

In addition of temporay table to optimize multiplication and division, the main trick is to compute addition and substraction 8 digits by 8 digits instantly over 64 bits (each digit stands in a byte, max base size is 128).    
Some binary sweets propagate the carry instantly over the 8 digits.

If you are interested in more documentation over the code, send me a message with your motivation at math.guin@gmail.com    

PS : I will not help student to cheat, I am far too expensive
