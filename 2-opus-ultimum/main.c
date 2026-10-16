/** A SIMPLE PROGRAM THAT ADDS TWO NUMBERS 
 * SEE: 
 * PROBLEM: https://www.infoarena.ro/problema/adunare
 * JOB: https://www.infoarena.ro/job_detail/3368864 **/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define read(arg) fscanf(in,"%d",&(arg))
#define write(arg) fprintf(out,"%lld",(long long)(arg))
#define i32 int
#define i64 long long
#define U64 unsigned long long
#define B1 unsigned char
#define BITS (1<<6)
#define SIGN (BITS-1)


typedef struct
{
    B1 Value[BITS];
} Bitset;

typedef struct
{
    char name[128];
} StreamClass;

typedef struct
{
    i64 ValueDec;
    Bitset ValueBin;
} ElementsClass;

StreamClass Stream={"adunare"};
ElementsClass A,B;

FILE *in;
FILE *out;

char *Reader(StreamClass *This)
{
    static char arg[256];
    strcpy(arg,This->name);
    strcat(arg,".in");
    return arg;
}

char *Writer(StreamClass *This)
{
    static char arg[256];
    strcpy(arg,This->name);
    strcat(arg,".out");
    return arg;
}

B1 GetBit(Bitset *This,i32 i)
{
    if (i<0 || i>=BITS)
        return 0;
    return This->Value[i]?1:0;
}

void SetBit(Bitset *This,i32 i,B1 x)
{
    if (i>=0 && i<BITS)
        This->Value[i]=x?1:0;
}

void Zero(Bitset *This)
{
    for (i32 i=0;i<BITS;i++)
        SetBit(This,i,0);
}

void Copy(Bitset *This,Bitset *arg)
{
    for (i32 i=0;i<BITS;i++)
        SetBit(This,i,GetBit(arg,i));
}

B1 NOT(B1 x)
{
    if (x)
        return 0;
    return 1;
}

B1 AND(B1 x,B1 y)
{
    if (x && y)
        return 1;
    return 0;
}

B1 OR(B1 x,B1 y)
{
    if (x || y)
        return 1;
    return 0;
}

B1 XOR(B1 x,B1 y)
{
    if (x==y)
        return 0;
    return 1;
}

B1 NAND(B1 x,B1 y)
{
    return NOT(AND(x,y));
}

B1 NOR(B1 x,B1 y)
{
    return NOT(OR(x,y));
}

B1 XNOR(B1 x,B1 y)
{
    return NOT(XOR(x,y));
}

B1 IsNegative(Bitset *This)
{
    return GetBit(This,SIGN);
}

void MakeNegative(Bitset *This)
{
    SetBit(This,SIGN,1);
}

void MakePositive(Bitset *This)
{
    SetBit(This,SIGN,0);
}

B1 IsZero(Bitset *This)
{
    for (i32 i=0;i<SIGN;i++)
    {
        if (GetBit(This,i))
            return 0;
    }
    return 1;
}

B1 IsEven(Bitset *This)
{
    return NOT(GetBit(This,0));
}

B1 IsOdd(Bitset *This)
{
    return NOT(IsEven(This));
}

void Normalize(Bitset *This)
{
    for (i32 i=0;i<BITS;i++)
        SetBit(This,i,GetBit(This,i));
    if (IsZero(This))
        MakePositive(This);
}

void TurnToBin(ElementsClass *This)
{
    U64 aux;
    i64 arg=This->ValueDec;

    Zero(&This->ValueBin);

    if (arg<0)
    {
        MakeNegative(&This->ValueBin);
        aux=(U64)(-(arg+1));
        aux++;
    }
    else
    {
        MakePositive(&This->ValueBin);
        aux=(U64)arg;
    }

    for (i32 i=0;i<SIGN;i++)
    {
        B1 bit=(B1)(aux%(1<<1));
        SetBit(&This->ValueBin,i,bit);
        aux/=(1<<1);
    }
    Normalize(&This->ValueBin);
}

void TurnToDec(ElementsClass *This)
{
    U64 aux=0;

    for (i32 i=SIGN-1;i>=0;i--)
    {
        aux*=(1<<1);
        aux+=(U64)GetBit(&This->ValueBin,i);
    }

    if (IsNegative(&This->ValueBin))
        This->ValueDec=-(i64)aux;
    else
        This->ValueDec=(i64)aux;
}

void SetVal(ElementsClass *This,i64 arg)
{
    This->ValueDec=arg;
    TurnToBin(This);
}

i64 GetVal(ElementsClass *This)
{
    return This->ValueDec;
}

void CopyElement(ElementsClass *This,ElementsClass *arg)
{
    This->ValueDec=arg->ValueDec;
    Copy(&This->ValueBin,&arg->ValueBin);
}

i32 CompareBit(B1 x,B1 y)
{
    if (XNOR(x,y))
        return 0;
    if (x)
        return 1;
    return -1;
}

i32 Compare(Bitset *x,Bitset *y)
{
    for (i32 i=SIGN-1;i>=0;i--)
    {
        i32 cmp=CompareBit(GetBit(x,i),GetBit(y,i));
        if (cmp!=0)
            return cmp;
    }
    return 0;
}

B1 CalculateSum(B1 x,B1 y,B1 Transport)
{
    B1 aux=XOR(x,y);
    B1 ret=XOR(aux,Transport);
    return ret;
}

B1 CalculateTransport(B1 x,B1 y,B1 Transport)
{
    B1 a=AND(x,y);
    B1 b=AND(x,Transport);
    B1 c=AND(y,Transport);
    B1 ret=OR(OR(a,b),c);
    return ret;
}

B1 CalculateDifference(B1 x,B1 y,B1 Borrow)
{
    B1 aux=XOR(x,y);
    B1 ret=XOR(aux,Borrow);
    return ret;
}

B1 CalculateBorrow(B1 x,B1 y,B1 Borrow)
{
    B1 a=AND(NOT(x),y);
    B1 b=AND(NOT(x),Borrow);
    B1 c=AND(y,Borrow);
    B1 ret=OR(OR(a,b),c);
    return ret;
}

void AddOneBit(Bitset *x,Bitset *y,i32 i,B1 *Transport)
{
    B1 X=GetBit(x,i);
    B1 Y=GetBit(y,i);
    B1 Sum;
    B1 NewTransport;

    Sum=CalculateSum(X,Y,*Transport);
    NewTransport=CalculateTransport(X,Y,*Transport);

    SetBit(x,i,Sum);
    *Transport=NewTransport;
}

void SubtractOneBit(Bitset *x,Bitset *y,i32 i,B1 *Borrow)
{
    B1 X=GetBit(x,i);
    B1 Y=GetBit(y,i);
    B1 Difference;
    B1 NewBorrow;

    Difference=CalculateDifference(X,Y,*Borrow);
    NewBorrow=CalculateBorrow(X,Y,*Borrow);

    SetBit(x,i,Difference);
    *Borrow=NewBorrow;
}

void AddBits(Bitset *x,Bitset *y)
{
    B1 Transport=0;

    for (i32 i=0;i<SIGN;i++)
        AddOneBit(x,y,i,&Transport);

    Normalize(x);
}

void SubtractBits(Bitset *x,Bitset *y)
{
    B1 Borrow=0;

    for (i32 i=0;i<SIGN;i++)
        SubtractOneBit(x,y,i,&Borrow);

    Normalize(x);
}

void Subtract(Bitset *x,Bitset *y)
{
    Bitset aux;
    i32 cmp=Compare(x,y);

    if (cmp==0)
    {
        Zero(x);
        return;
    }

    if (cmp>0)
    {
        SubtractBits(x,y);
        return;
    }

    Copy(&aux,y);
    SubtractBits(&aux,x);
    Copy(x,&aux);
}

void Negate(ElementsClass *This)
{
    if (!IsZero(&This->ValueBin))
    {
        if (IsNegative(&This->ValueBin))
            MakePositive(&This->ValueBin);
        else
            MakeNegative(&This->ValueBin);
    }
    TurnToDec(This);
}

void AddPositivePositive(ElementsClass *Ret,ElementsClass *x,ElementsClass *y)
{
    CopyElement(Ret,x);
    AddBits(&Ret->ValueBin,&y->ValueBin);
    MakePositive(&Ret->ValueBin);
    TurnToDec(Ret);
}

void AddNegativeNegative(ElementsClass *Ret,ElementsClass *x,ElementsClass *y)
{
    CopyElement(Ret,x);
    AddBits(&Ret->ValueBin,&y->ValueBin);
    if (!IsZero(&Ret->ValueBin))
        MakeNegative(&Ret->ValueBin);
    TurnToDec(Ret);
}

void AddPositiveNegative(ElementsClass *Ret,ElementsClass *x,ElementsClass *y)
{
    i32 cmp=Compare(&x->ValueBin,&y->ValueBin);

    if (cmp==0)
    {
        SetVal(Ret,0);
        return;
    }

    if (cmp>0)
    {
        CopyElement(Ret,x);
        SubtractBits(&Ret->ValueBin,&y->ValueBin);
        MakePositive(&Ret->ValueBin);
    }
    else
    {
        CopyElement(Ret,y);
        SubtractBits(&Ret->ValueBin,&x->ValueBin);
        MakeNegative(&Ret->ValueBin);
    }

    TurnToDec(Ret);
}

void AddNegativePositive(ElementsClass *Ret,ElementsClass *x,ElementsClass *y)
{
    i32 cmp=Compare(&x->ValueBin,&y->ValueBin);

    if (cmp==0)
    {
        SetVal(Ret,0);
        return;
    }

    if (cmp>0)
    {
        CopyElement(Ret,x);
        SubtractBits(&Ret->ValueBin,&y->ValueBin);
        MakeNegative(&Ret->ValueBin);
    }
    else
    {
        CopyElement(Ret,y);
        SubtractBits(&Ret->ValueBin,&x->ValueBin);
        MakePositive(&Ret->ValueBin);
    }

    TurnToDec(Ret);
}

ElementsClass Add(ElementsClass x,ElementsClass y)
{
    ElementsClass Ret;
    B1 X=IsNegative(&x.ValueBin);
    B1 Y=IsNegative(&y.ValueBin);

    SetVal(&Ret,0);

    if (!X && !Y)
        AddPositivePositive(&Ret,&x,&y);
    else if (X && Y)
        AddNegativeNegative(&Ret,&x,&y);
    else if (!X && Y)
        AddPositiveNegative(&Ret,&x,&y);
    else
        AddNegativePositive(&Ret,&x,&y);

    Normalize(&Ret.ValueBin);
    TurnToDec(&Ret);
    return Ret;
}

void Read(void)
{
    i32 aux;

    if (read(aux)!=1)
        aux=0;
    SetVal(&A,aux);

    if (read(aux)!=1)
        aux=0;
    SetVal(&B,aux);
}

void Write(void)
{
    i64 aux=GetVal(&A);
    write(aux);
}

void Close(void)
{
    if (in!=NULL)
        fclose(in);
    if (out!=NULL)
        fclose(out);
    in=NULL;
    out=NULL;
}

int main(void)
{
    in=fopen(Reader(&Stream),"r");
    if (in==NULL)
        return 1;

    out=fopen(Writer(&Stream),"w");
    if (out==NULL)
    {
        fclose(in);
        return 1;
    }

    Read();
    A=Add(A,B);
    Write();
    Close();

    return 0;
}
