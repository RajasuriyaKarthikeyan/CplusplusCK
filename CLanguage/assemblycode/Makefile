hello:
	echo "hi from ck"
	echo "hi from c1"
	echo "hi from c7"

hi:
	echo "hi from ck - from hi object"

rajasck:
	riscv64-unknown-elf-gcc -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-Tm.ld casam.s c-asm.c -o main.elf
	riscv64-unknown-elf-objcopy  -O binary main.elf main.bin

assembly:
	riscv64-unknown-elf-gcc -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-Tm.ld c-asm.c -S

compile: m.s m.ld
	riscv64-unknown-elf-gcc -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-Tm.ld m.s -o main.elf
	riscv64-unknown-elf-objcopy  -O binary main.elf main.bin

main.bin: m.s m.ld
	riscv64-unknown-elf-gcc -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32 -Wl,-Tm.ld m.s -o main.elf
	riscv64-unknown-elf-objcopy  -O binary main.elf main.bin

printbinary: main.bin
	xxd -e -c 4 -g 4 main.bin

startqemu: main.elf
	qemu-system-riscv32 -S -M virt -nographic -bios none -kernel main.elf -gdb tcp::1234

connect-gdb: main.elf
	gdb-multiarch main.elf -ex "target remote localhost:1234" -ex "load" -ex "break _start" -ex "dashboard -layout" -q

clean:
	rm -rf *.out *.bin *.elf