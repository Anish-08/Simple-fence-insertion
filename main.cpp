#include"insert_fences.h"

int main(int argc, char **argv){
    Insert_Fence L;
    L.insert(17);
    L.insert(31);
    L.modify("sample.inp","sample.output");
    return 0;
}