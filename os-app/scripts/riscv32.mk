CROSS_COMPILE = riscv64-unknown-linux-gnu-
LNK_ADDR = $(if $(VME), 0x40000000, 0x83000000)
CFLAGS  += -fno-pic -march=rv64g -mcmodel=medany
LDFLAGS += --no-relax -Ttext-segment $(LNK_ADDR)
CFLAGS  += -march=rv32g -mabi=ilp32  #overwrite
LDFLAGS += -melf32lriscv
