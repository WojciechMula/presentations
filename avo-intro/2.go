package main

import (
    . "github.com/mmcloughlin/avo/build"
    . "github.com/mmcloughlin/avo/operand"
    "github.com/mmcloughlin/avo/buildtags"
    "github.com/mmcloughlin/avo/reg"
)

func main() {
    generateAdd()
    Generate()
}

func generateAdd() {
    TEXT("Add", NOSPLIT, "func(x, y uint64) uint64")
    Doc("Add adds x and y.")
    x := Load(Param("x"), GP64())
    y := Load(Param("y"), GP64())
    ADDQ(x, y)
    Store(y, ReturnIndex(0))
    RET()
}
