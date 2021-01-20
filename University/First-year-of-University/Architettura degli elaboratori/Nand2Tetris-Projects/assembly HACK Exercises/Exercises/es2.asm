//RAM[2] = RAM[1] x RAM[0] (RAM[0] is not equal to 0)
// WORK

	@2
	M=0
 (LOOP)
    @1
    D=M
    @2
    M=M+D
    @0
    MD=M-1  // D=RAM[0]-- , M=RAM[0]--

	@LOOP
	D;JGT

 (END)
	@END
	0;JMP