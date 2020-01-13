#ifndef CANID_TYPE_
#define CANID_TYPE_

// SA
#define SA_MASK_CAN_ID 0xFF // 掩码
#define SA_SHIFT_CAN_ID 0 // 向右平移位数

// PS
#define PS_MASK_CAN_ID 0xFF00
#define PS_SHIFT_CAN_ID 8
#define GE_SHIFT_PGN    0// CANID转化为PGN时向左边平移

// PF
#define PF_MASK_CAN_ID 0xFF0000
#define PF_SHIFT_CAN_ID 16
#define PF_SHIFT_PGN    8

// DP
#define DP_MASK_CAN_ID 0x01000000
#define DP_SHIFT_CAN_ID 24
#define DP_SHIFT_PGN    16

// R
#define R_MASK_CAN_ID  0x02000000
#define R_SHIFT_CAN_ID 25
#define R_SHIFT_PGN    17

//P
#define P_MASK_CAN_ID  0x1C000000
#define P_SHIFT_CAN_ID 26

#define GE_THRESHOLD 240



#endif
