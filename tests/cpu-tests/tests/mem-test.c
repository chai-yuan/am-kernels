#include "trap.h"

int main() {
	unsigned a = 3, b = 4;
	unsigned c = a + b;
	check(c == 7);
	return 0;
}