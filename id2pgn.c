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
    uint PGN = 0;// 参数群编号
    printf("Please input CAN frame's Extended ID : 0x");
    scanf("%08x",&id);
    printf("Get CAN frame's ID : 0x%08x (%d)\n",id, id);
    SA = (id & SA_MASK_CAN_ID)>>SA_SHIFT_CAN_ID;
    PS = (id & PS_MASK_CAN_ID)>>PS_SHIFT_CAN_ID;
    PF = (id & PF_MASK_CAN_ID)>>PF_SHIFT_CAN_ID;
    DP = (id & DP_MASK_CAN_ID)>>DP_SHIFT_CAN_ID;
    R  = (id & R_MASK_CAN_ID) >>R_SHIFT_CAN_ID;
    P  = (id & P_MASK_CAN_ID) >>P_SHIFT_CAN_ID;
    printf("|---|-|-|--------|--------|--------|\n");
    printf("|   | | |        |        |        |\n");
    printf("| P |R|D|   PF   |   PS   |   SA   |\n");
    printf("|   | |P|        |        |        |\n");
    printf("  %1d  %-1d %-1d   %-6d   %-6d   %-6d \n",P,R,DP,PF,PS,SA);
    // 群拓展根据PF数值决定
    if (PF > GE_THRESHOLD) {
        GE = PS;
    } else {
        GE = 0;
    }
    PGN = 0;
    PGN |= (GE << GE_SHIFT_PGN) | (PF << PF_SHIFT_PGN) | (DP << DP_SHIFT_PGN) | (R << R_SHIFT_PGN);
    printf("PGN : 0x%x(%d)\n", PGN,PGN);
}
