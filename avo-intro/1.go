package main

import (
    . "github.com/mmcloughlin/avo/build"
    . "github.com/mmcloughlin/avo/operand"
    "github.com/mmcloughlin/avo/buildtags"
    "github.com/mmcloughlin/avo/reg"
)

func main() {
    generateSub()
    Generate()
}

func generateSub() {
    TEXT("Sub", NOSPLIT, "func(x, y uint64) uint64")
    Doc("Sub subtracts x and y.")
    x := reg.R11
    y := reg.R12

    Load(Param("x"), x)
    Load(Param("y"), y)
    SUBQ(x, y)
    Store(y, ReturnIndex(0))
    RET()
}
