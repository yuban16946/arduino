void dot()
{
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
}

void dash()
{
  digitalWrite(13,HIGH);
  delay(4000);
  digitalWrite(13,LOW);
  delay(1000);
}

void w_space()
{
  digitalWrite(13,LOW);
  delay(7000);
}

void c_space()
{
  digitalWrite(13,LOW);
  delay(3000);
}
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
  pinMode(13,OUTPUT);
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
          dot();
        else if(morse0[k] == '-')
          dash();
        else if(morse0[k] == ' '&&morse0[k+1]!=' ')
          w_space();
        if(morse0[k] == ' '&&morse0[k+1] == ' ')
        {
          k++;
          c_space();
        }
      }
      Serial.println("END!");
      delay(2);
    }
  }
}
