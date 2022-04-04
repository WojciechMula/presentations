#include "textflag.h"

// func Sub(x uint64, y uint64) uint64
TEXT Sub(SB), NOSPLIT, $0-24
	MOVQ x+0(FP), R11
	MOVQ y+8(FP), R12
	SUBQ R11, R12
	MOVQ R12, ret+16(FP)
	RET
