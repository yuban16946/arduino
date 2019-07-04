#include<Morse.h>
Morse morse(13);

char Morse1[][4]={
  {'.','-','*','*'},//a
  {'-','.','.','.'},//b
  {'-','.','-','.'},//c
  {'-','.','.','*'},//d
  {'.','*','*','*'},//e
  {'.','.','-','.'},//f
  {'-','-','.','*'},//g
  {'.','.','-','*'},//h
  {'.','.','*','*'},//i
  {'.','-','-','-'},//j
  {'-','.','-','*'},//k
  {'.','-','.','.'},//l
  {'-','-','*','*'},//m
  {'-','.','*','*'},//n
  {'-','-','-','*'},//o
  {'.','-','-','.'},//p
  {'-','-','.','-'},//q
  {'.','-','.','*'},//r
  {'.','.','.','*'},//s
  {'-','*','*','*'},//t
  {'.','.','-','*'},//u
  {'.','.','.','-'},//v
  {'.','-','-','*'},//w
  {'-','.','.','-'},//x
  {'-','.','-','-'},//y
  {'-','-','.','.'},//z
};
void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  String morse0 = " ";
  int i,k,count = 0,flag;
  while (Serial.available()>0)
  {
    flag = 1;
    morse0 += char(Serial.read());
    morse0 += ' ';
    delay(2);
    count++;
  }
  if(flag)
  {
    for(i=0;i<count;i++)
    {
      Serial.println(morse0);
      for(k=0;morse0[k]!= '\0';k++)
      {
        if(morse0[k] == '.')
          morse.dot();
        else if(morse0[k] == '-')
          morse.dash();
        else if(morse0[k] == ' '&&morse0[k+1]!=' ')
          morse.w_space();
        if(morse0[k] == ' '&&morse0[k+1] == ' ')
        {
          k++;
          morse.c_space();
        }
      }
      Serial.println("END!");
      delay(2);
    }
  }
}
