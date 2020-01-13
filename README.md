# Canid2PGN
Can frame's ID transport to PGN(Parameter Group Number).PGN is consist of R(Reserved), DP(Data Page), PF(PDU Format), GE(Group Extension).

FYI, if PF > 240, then GE equals to PS(PDU Special), otherwise, GE equals to zero(ONE byte length).

Example Output:

```
Please input CAN frame's Extended ID : 0x18fe4eec
Get CAN frame's ID : 0x18fe4eec (419319532)
|---|-|-|--------|--------|--------|
|   | | |        |        |        |
| P |R|D|   PF   |   PS   |   SA   |
|   | |P|        |        |        |
  6  0 0   254      78       236    
PGN : 0xfe4e(65102)
```

# Contact 

email: sonechaochao@gmail.com