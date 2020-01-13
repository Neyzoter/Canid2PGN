# CANID - PGN Convert
![](https://img.shields.io/badge/license-MIT-000000.svg)

## Usage

```bash
# Entry into the proj dir
$ cd [PROJ_DIR]
# gcc the id2pgn.c(can frame's id convert to pgn) or pgn2id.c(pgn convert to can frame's id)
$ gcc [C_FILE] -o [OUTPUT_FILE_NAME]
#run the code
$ ./[OUTPUT_FILE_NAME]
```

## Canid2PGN
`id2pgn.c`

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

## PGN2Canid
`pgn2id.c`

PGN(Parameter Group Number) transport to Can frame's ID.

Example Output:

```
Please input PGN Dec : 65102
Get PGN Dec : 65102 (0x0000fe4e)
Please input TA(Target ADDR) as PS : 78
Please input SA(Source ADDR) : 236
Please input P(Priority) : 6
|---|-|-|--------|--------|--------|
|   | | |        |        |        |
| P |R|D|   PF   |   PS   |   SA   |
|   | |P|        |        |        |
  6  0 0   254      78       236    
CAN ID : 0x18fe4eec(419319532)
```
## Contact 

email: sonechaochao@gmail.com