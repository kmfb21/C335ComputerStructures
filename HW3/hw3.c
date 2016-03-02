/**********************************************************
 * hw3.c
 *
 * This program will decode
 * the ARM thumb data processing register
 * and Add/subtract register instruction formats
 *
 *   Author: Bo Fang (bofang)
 *   Date Created: 03/01/2016
 *   Last Modified by: Bo Fang (bofang)
 *   Date Last Modified: 03/01/2016
 *   Assignment: HW3
 *   Part of: CSCI-C335 submissions
 */
#include <stdio.h>
int main(){
    printf(".text\n.syntax unified\n.thumb\n");
    int inst,division;
    int opc,rn,rd;
    int op,rm,rdn;
    // You are to decode only the formats corresponding
    // to the second and fifth rows of Figure 3-1.
    char *regnames[] = {"r0","r1","r2","r3","r4","r5","r6","r7"};
    char *opname[] = {"ands","eors","lsls","lsrs","asrs","adcs","sbcs","rors","tsts","rsbs","cmps","cmns","orrs","muls","bics","mvns"};
    char *opcname[] = {"adds","subs"};
    while (scanf("%x", &inst)==1) {
        division = inst >> 10;
        switch (division) {
            //000110
            //Add/subtract register
            case 6:
                rd = inst & 7;
                rn = inst >> 3 & 7;
                rm = inst >> 6 & 7;
                opc = inst >> 9 & 1;
                printf("\t%s %s,%s,%s\n",opcname[opc],regnames[rd],regnames[rn],regnames[rm]);
                break;
            //010000
            //Data-processing register
            case 16:
                rdn = inst & 7;
                rm = inst >> 3 & 7;
                op = inst >> 6 & 15;
                printf("\t%s %s,%s\n",opname[op],regnames[rdn],regnames[rm]);
                break;
            default:
                printf(".hword %.4x\n",inst);
                break;
        }
    }
}
