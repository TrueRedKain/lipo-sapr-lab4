

#ifndef _yla_cop_h
#define _yla_cop_h

#define CNOP	0x00

#define CPUSH	0x01
#define CDUP	0x02
#define CDEEP	0x03
#define CSTK	0x04
#define CGDUP	0x0a
#define CGDEEP	0x0b
#define CGSTK	0x0c

#define CTEST	0x05
#define CCMP	0x06

#define CLOAD	0x08
#define CSAVE	0x09

#define CADD	0x10
#define CSUB	0x11
#define CMULT	0x12
#define CDIV	0x13
#define CNEG	0x14

#define CITOA	0x15

#define CJMP	0x20
#define CJZ		0x21
#define CJNZ	0x22
#define CJE		0x23
#define CJNE	0x24
#define CJG     0x25

#define CAL		0x40
#define CALO	0x41
#define CRET	0x42

#define CIN		0x30
#define CINS	0x31
#define COUT	0x32

#define CHALT	0xff

#endif
