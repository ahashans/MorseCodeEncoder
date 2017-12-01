#define dotPeriod 200
#define dashPeriod dotPeriod*3
#define relaxTime dotPeriod*2
#define letterSpace dotPeriod*3
#define wordSpace dotPeriod*7

#define buzz 1000
#define tonePin 3

void dit()
{
  tone(tonePin, buzz);
  delay(dotPeriod);
  noTone(tonePin);
  delay(relaxTime);
}

void dah()
{
  tone(tonePin, buzz);
  delay(dashPeriod);
  noTone(tonePin);
  delay(relaxTime);
}

void di()
{
  dit();
}

void playLetter(char x)
{
  switch (x) {

    case 'A':
      di(); dah(); return;
    case 'B':
      dah(); di(); di(); dit(); return;
    case 'C':
      dah(); di(); dah(); dit(); return;
    case 'D':
      dah(); di(); di(); return;
    case 'E':
      di(); return;
    case 'F':
      di(); di(); dah(); dit(); return;
    case 'G':
      dah(); dah(); dit(); return;
    case 'H':
      di(); di(); di(); dit(); return;
    case 'I':
      di(); dit(); return;
    case 'J':
      di(); dah(); dah(); dah(); return;
    case 'K':
      dah(); di(); dah(); return;
    case 'L':
      di(); dah(); di(); dit(); return;
    case 'M':
      dah(); dah();
    case 'N':
      dah(); dit(); return;
    case 'O':
      dah(); dah(); dah(); return;
    case 'P':
      di(); dah(); dah(); dit(); return;
    case 'Q':
      dah(); dah(); di(); dah(); return;
    case 'R':
      di(); dah(); dit(); return;
    case 'S':
      di(); di(); di(); return;
    case 'T':
      dah(); return;
    case 'U':
      di(); di(); dah(); return;
    case 'V':
      di(); di(); di(); dah(); return;
    case 'W':
      di(); dah(); dah(); return;
    case 'X':
      dah(); di(); di(); dah(); return;
    case 'Y':
      dah(); di(); dah(); dah(); return;
    case 'Z':
      dah(); dah(); di(); dit(); return;
    case ' ':
      delay(wordSpace);
    case '.':                                        //period
      di(); dah(); di(); dah(); di(); dah(); return;
    case '/':                                       //word separator
      dah(); di(); di(); dah(); di(); return;
    case '-':                                        //hiphen
      dah(); di(); di(); di(); di(); dah(); return;
    case '?':                                       //question mark
      di(); dah(); di(); di(); dah(); di();  return;
    case ',':                                     //comma
      dah(); dah(); di(); di(); dah(); dah(); return;
    case '1':
      di(); dah(); dah(); dah(); dah(); return;
    case '2':
      di(); di(); dah(); dah(); dah(); return;
    case '3':
      di(); di(); di(); dah(); dah(); return;
    case '4':
      di(); di(); di(); di(); dah(); return;
    case '5':
      di(); di(); di(); di(); di(); return;
    case '6':
      dah(); di(); di(); di(); di(); return;
    case '7':
      dah(); dah(); di(); di(); di(); return;
    case '8':
      dah(); dah(); dah(); di(); di(); return;
    case '9':
      dah(); dah(); dah(); dah(); di(); return;
    case '0':
      dah(); dah(); dah(); dah(); dah(); return;
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(tonePin, OUTPUT);
}

int Index = 0, endofstring, i;
char Input[255];

void loop()
{
  while (!Serial.available());
  while (Serial.available())
  {
    Input[Index] = Serial.read();
    //Serial.println(Input[Index]);
    if (Input[Index] >= 97 && Input[Index] <= 122)
    {
      Input[Index] = char(int(Input[Index]) - 32);
    }
    Index++;
  }
  //Serial.println();
  endofstring = Index;
  for (Index = 0; Index < endofstring; Index++)
  {
    Serial.print(Input[Index]);
    playLetter(Input[Index]);
    delay(letterSpace);
    Serial.println();
  }
  Index = 0;
}

