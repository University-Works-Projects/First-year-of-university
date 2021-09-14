// RAM[2] = RAM[1]*(2^RAM[0])

	@2
	M=0		// Clean RAM[2]
	@0
	M=M-1	// In this program 2^4=32 so we need to do decrease RAM[0] by one

	@2
	D=A
	@3
	M=D		// RAM[3]=2 --> result var

 (LOOP)
	@3
	D=M
	@4
	M=D		// RAM[4]=RAM[3] --> counter var
 (ELSE)
	@3
	M=M+1
	@4
	M=M-1
	D=M
	@ELSE
	D;JGT

	@0
	MD=M-1  // D=RAM[0]-- , M=RAM[0]--
	@LOOP
	D;JGT

 (END)
	@END
	0;JMP
