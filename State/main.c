#include <stdio.h>

#include "inc/State.h"
int main() {

    Mammoth *mammoth = newMammoth();
    mammoth->observe(mammoth);
    mammoth->timePasses(mammoth);

    mammoth->observe(mammoth);
    mammoth->timePasses(mammoth);

    mammoth->observe(mammoth);

    delMammoth(mammoth);
    return 0;
}
