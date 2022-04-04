package main

import (
    . "github.com/mmcloughlin/avo/build"
    . "github.com/mmcloughlin/avo/operand"
    "github.com/mmcloughlin/avo/buildtags"
    "github.com/mmcloughlin/avo/reg"
)

type Structure struct {
    bytes []byte
    value uint64
}

func main() {
    generateStruct()
    Generate()
}

func generateStruct() {
    Package("main")
    TEXT("CapPlusLen", NOSPLIT, "func(s* Structure)")

    s := Dereference(Param("s"))

    Comment("s.value = len(s.bytes) + cap(s.bytes)")
    length := GP64()
    Load(s.Field("bytes").Len(), length)
    capacity := GP64()
    Load(s.Field("bytes").Cap(), capacity)

    tmp := GP64()
    LEAQ(Mem{Base: length, Index: capacity, Scale: 1}, tmp)

    Store(tmp, s.Field("value"))
}
