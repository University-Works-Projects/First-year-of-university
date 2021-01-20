// RAM[10] = RAM[9] + RAM[8] + ... + RAM[0]
// WORK
	
	@10
	M=0		// RAM[10]=0

	@9
	D=A		// D=9
	@11
	M=D		// RAM[11]=9
	
 (LOOP)
	@11
	A=M		// @A=@RAM[11]
	D=M		// D=@RAM[11]

	@10
	M=M+D
	@11
	MD=M-1  // D=RAM[0]-- , M=RAM[0]--
	@LOOP
	D;JGT

	@11
	M=0
	
 (END)
	@END
	0;JMP

 