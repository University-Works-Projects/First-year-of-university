// RAM[2] = RAM[1]/RAM[0] (Integer division)
// RAM[3] = RAM[1] mod RAM[0] (RAM)

	// PART 1
	// RAM[2] = RAM[1]/RAM[0] --> Example: 8 = 40 / 5
	@2
	M=0

	@1
	D=M
	@3
	M=D		// RAM[3]=RAM[1] --> tmp var for conserve RAM[1] value
 (LOOP)
	@0
	D=M		// D=RAM[0]
	@1
	M=M-D	// RAM[1]-=RAM[0]
	@2
	M=M+1	// RAM[2]++

	// Jump condition
	@1
	D=M
	@LOOP
	D;JGT	// if RAM[1] > 0 jump

	@3
	D=M
	M=0		// Clear RAM[3]=0
	@1
	M=D		// Now RAM[1] have his original value



	// PART 2
	// RAM[3] = RAM[1] mod RAM[0] --> Example: 4 = 44 % 5
	@2
	D=M
	@5
	M=D		// RAM[5]=RAM[2] --> For not RAM[2], that is the result var of RAM[1]/RAM[0]
	@1
	D=M
	@4
	M=D		// RAM[4]=RAM[1] --> tmp var for conserve RAM[1] value
 (LOOP2)
	@0
	D=M		// D=RAM[0]
	@1
	M=M-D	// RAM[1]-=RAM[0]
	@5
	M=M+1	// RAM[5]++ --> RAM[5] is used for counteing the rest

	// Jump condition
	@1
	D=M
	@LOOP2
	D;JGT	// if RAM[1] > 0 jump

	@1
	D=M		// D=RAM[1]
	@MOD
	D;JLT

	@3
	M=0		// Clear RAM[3]=0

	@4
	D=M		// D=RAM[4]
	M=0		// Clear RAM[4]=0
	@1
	M=D		// Now RAM[1] have his original value

	@5
	M=0		// Clear RAM[5]=0

 (END)
	@END
	0;JMP

 (MOD)
	@2
	M=M-1	// Cuz if u made 44/5 --> -1 is the value that make the jump so RAM[2] will be 9 instead 8, so we must decrease it

	@0
	D=M		// D=RAM[0]
	@1
	M=M+D	// RAM[1]+=RAM[0]
	D=M		// D=RAM[1]
	@3
	M=D		// RAM[3]=RAM[1]

	@4
	D=M		// D=RAM[4]
	M=0		// Clear RAM[4]=0
	@1
	M=D		// Now RAM[1] have his original value

	@5
	M=0		// Clear RAM[5]=0

 (END)
	@END
	0;JMP
