// es2 test
// Assembly HACK code:
// Exercise: Write a assembly HACK code that writes the numbers 0 to 9 in the first 10 RAM's location.

    @10
    D=A
    @11
    M=D		    // RAM[11] = 10

 (LOOP)
    @11
    D=M			// D = RAM[11]
    A=M			// @A = @RAM[11]
    M=D			// RAM[A] = RAM[11]

    @11
    M=M-1		// RAM[11] --
    D=M
    @LOOP
    D;JGE		// if   D >= 0  jump

    @11
    M=0
 (END)
    @END
    0;JMP
