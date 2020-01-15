#include <stdio.h>
#include "canid_type.h"

typedef unsigned int uint;
typedef unsigned char uchar;

int main() {
    uint id;
    uint P; // 优先级
    uint R; // 保留位
    uint DP; // 数据页
    uint PF; // PDU格式
    uint PS; // 特定PDU
    uint SA; // 源地址 
    uint GE = 0; // 群拓展
    uint PGN; // 参数群编号
    printf("Please input PGN Dec : ");
    scanf("%d",&PGN);
    printf("Get PGN Dec : %d (0x%08x)\n",PGN, PGN);
    GE = (PGN & GE_MASK_PGN)>>GE_SHIFT_PGN;
    PF = (PGN & PF_MASK_PGN)>>PF_SHIFT_PGN;
    DP = (PGN & DP_MASK_PGN)>>DP_SHIFT_PGN;
    R  = (PGN & R_MASK_PGN) >>R_SHIFT_PGN;
    if (PF >= GE_THRESHOLD)
    {
        PS = GE;
        printf("PF >= %d , so PS = GE : %d\n", GE_THRESHOLD, PS);
    } else {
        printf("PF < %d\n",GE_THRESHOLD);
        printf("Please input TA(Target ADDR) as PS : ");
        scanf("%d",&PS);
    }
    printf("Please input SA(Source ADDR) : ");
    scanf("%d", &SA); 
    printf("Please input P(Priority) : ");
    scanf("%d", &P);
    printf("|---|-|-|--------|--------|--------|\n");
    printf("|   | | |        |        |        |\n");
    printf("| P |R|D|   PF   |   PS   |   SA   |\n");
    printf("|   | |P|        |        |        |\n");
    printf("  %1d  %-1d %-1d   %-6d   %-6d   %-6d \n",P,R,DP,PF,PS,SA);
    id = 0;
    id |= (SA << SA_SHIFT_CAN_ID) | (PS << PS_SHIFT_CAN_ID) | (PF << PF_SHIFT_CAN_ID) | (DP << DP_SHIFT_CAN_ID) | (R << R_SHIFT_CAN_ID) | (P << P_SHIFT_CAN_ID);
    printf("CAN ID : 0x%x(%d)\n", id , id);
}
