#define ROJO 13
#define VERDE 2
#define TAM 20
int seq[TAM];

void setup() {
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);

  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(3, INPUT);

  pinMode(ROJO, OUTPUT);
  pinMode(VERDE, OUTPUT);

  randomSeed(analogRead(0));
}

void loop()
{
  int cont = 1;
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);

    delay(100);

    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);

    delay (100);
  }
  for (int i = 0; i < sizeof(seq); i++)
  {
    seq[i] = random(8, 12);
    delay(50);
  }
  bool error = false;
  do
  {
    //muestro la secuencia a través de los LED
    for (int j = 0; j < cont; j++)
    {
      digitalWrite(seq[j], HIGH);
      delay(500);
      digitalWrite(seq[j], LOW);
      delay(200);
    }
    for (int j = 0; j < cont; j++)
    {
      int b = 0;
      do
      {
        if (digitalRead(6) == HIGH)
        {
          b = 11;
          do
          delay(200);
          while(digitalRead(6) == HIGH);
        }
        if (digitalRead(5) == HIGH)
        {
          b = 10;
          do
          delay(200);
          while(digitalRead(5) == HIGH);
        }
        if (digitalRead(4) == HIGH)
        {
          b = 9;
          do
          delay(200);
          while(digitalRead(4) == HIGH);
        }
        if (digitalRead(3) == HIGH)
        {
          b = 8;
          do
          delay(200);
          while(digitalRead(3) == HIGH);
        }
      } while (b == 0);
      if (b != seq[j])
      {
        digitalWrite(ROJO, HIGH);
        delay(2000);
        digitalWrite(ROJO, LOW);
        error = true;
        break;
      }
    }
    if (!error)
    {
      digitalWrite(VERDE, HIGH);
      delay(2000);
      digitalWrite(VERDE, LOW);
    }
    cont++;
    if (cont > TAM)
    {
      for (int i = 0; i < 5; i++)
      {
        digitalWrite(VERDE, HIGH);
        delay(100);
        digitalWrite(VERDE, LOW);
        delay (100);
      }
    }
  } while (!error && cont <= TAM);
}
