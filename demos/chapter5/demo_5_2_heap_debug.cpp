#include<windows.h>

main(){
	HLOCAL h1, h2, h3, h4, h5, h6;
	HANDLE hp;
	hp = HeapCreate(0, 0x1000, 0x10000);
	// 调试态堆管理策略和常态堆管理策略差异很大
	// 为了避免程序检测出调试器而使用调试堆，可以在创建堆之后加入一个人工断点，然后让程序单独执行。当程序把堆初始化完后，断点会中断程序，这时用调试器attach进程，能看到堆
	__asm int 3 

	h1 = HeapAlloc(hp, HEAP_ZERO_MEMORY, 3);
	h2 = HeapAlloc(hp, HEAP_ZERO_MEMORY, 5);
	h3 = HeapAlloc(hp, HEAP_ZERO_MEMORY, 6);
	h4 = HeapAlloc(hp, HEAP_ZERO_MEMORY, 8);
	h5 = HeapAlloc(hp, HEAP_ZERO_MEMORY, 19);
	h6 = HeapAlloc(hp, HEAP_ZERO_MEMORY, 24);

	HeapFree(hp, 0, h1); //free to freelist[2]
	HeapFree(hp, 0, h2); //free to freelist[2]
	HeapFree(hp, 0, h5); //free to freelist[4]

	HeapFree(hp, 0, h4); //coalese h3, h4, h5, link the large block to freelist[8]

	return 0;
}