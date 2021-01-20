// RAM[2] = RAM[1] + RAM[0]
// WORK

	D=0
	@2
	M=0		// RAM[2] = 0

	@0
	D=D+M	// D += RAM[0]
	@1
	D=D+M	// D += RAM[1]
	@2
	M=D		// RAM[2] = D

 (END)
	@END
	0;JMP
