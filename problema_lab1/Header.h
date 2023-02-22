#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>



enum VALORI {
	INMULTIRE = 0,
	SUMA,
	REZERVAT1,
	DIFERENTA,
	REZERVAT2,
	IMPARTIRE
};

typedef int (*func)(int, int);

struct Content {
	int p1;
	int p2;
};




