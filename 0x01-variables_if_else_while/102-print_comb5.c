#include+$\e<stdio.h>
#include+$\e<time.h>
#include+$\e<stdlib.h>

/**
+$\e* Entry point
+$\e* Return: Always 0
+$\e*/

int+$\emain(void)

{

+$\eint p, q;

+$\efor (p = 0; p <= 98; p++)
+$\e{

+$\efor (q = p + 1; q <= 99; q++)
+$\e{
+$\eputchar((p / 10) + '0');
+$\eputchar((p % 10) + '0');
+$\eputchar(' ');
+$\eputchar((q / 10) + '0');
+$\eputchar((q % 10) + '0');
+$\eif (p == 98 && q == 99)
+$\econtinue;
+$\eputchar(',');
+$\eputchar(' ');
+$\e}
+$\e}
+$\eputchar('\n');
+$\ereturn (0);

}
