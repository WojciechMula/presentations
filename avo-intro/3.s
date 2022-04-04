#include "textflag.h"

// func CapPlusLen(s *Structure)
TEXT CapPlusLen(SB), NOSPLIT, $0-8
	MOVQ s+0(FP), AX

	// s.value = len(s.bytes) + cap(s.bytes)
	MOVQ 8(AX), CX
	MOVQ 16(AX), DX
	LEAQ (CX)(DX*1), CX
	MOVQ CX, 24(AX)
