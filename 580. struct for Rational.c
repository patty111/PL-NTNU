#include <stdio.h>
#include <string.h>
#define STRINGLEN 40

int s2n(char *s) {
   int n=0;

   while (*s != NULL) {
      n = n*10 + (*s - '0');
      s++;
   }
   return n;
};

int gcd(int a, int b) {
   if (a % b == 0) return b;
   return gcd(b, a%b);
};

typedef struct rational Rational;

struct rational {
  int num;
  int denom;
};

Rational add(Rational a, Rational b) {
  Rational c;
  int g;
  c.num = a.num*b.denom + a.denom*b.num;
  c.denom = a.denom*b.denom;
  g = gcd(c.num, c.denom);
  c.num /= g;
  c.denom /= g;
  return c;
};

Rational sub(Rational a, Rational b) {
  Rational c;
  c.num = a.num*b.denom - a.denom*b.num;
  c.denom = a.denom*b.denom;
  int g = gcd(c.num, c.denom);
  c.num /= g;
  c.denom /= g;
  return c;
};

Rational mul(Rational a, Rational b) {
    Rational c;
    c.num = a.num*b.num;
    c.denom = a.denom*b.denom;
    int g = gcd(c.num, c.denom);
    c.num /= g;
    c.denom /= g;
    return c;
};


int main(void)
{
  char s[STRINGLEN];
  char A[STRINGLEN] = "";
  char B[STRINGLEN] = "";
  char s2[STRINGLEN];
  char op;

  char *start;
  char *delimeters = "+-*";
  char slash[] = "/";
  char A1[STRINGLEN], A2[STRINGLEN]="";
  char B1[STRINGLEN], B2[STRINGLEN]="";
  Rational a, b, c;

  scanf("%s", s);
  strcpy(s2, s);
  start = s;

  // Split into two rational numbers
  strcpy(A, strtok(start, delimeters));
  strcpy(B, strtok(NULL, delimeters));

  // Split into numerator and denominator
  strcpy(A1, strtok(A, slash));
  strcpy(A2, strtok(NULL, slash));

  strcpy(B1, strtok(B, slash));
  strcpy(B2, strtok(NULL, slash));

  a.num = s2n(A1);
  a.denom = s2n(A2);

  b.num = s2n(B1);
  b.denom = s2n(B2);



  // Handle operator
  if (strchr(s2, '+') != NULL) c = add(a, b);
  else if (strchr(s2, '-') != NULL) c = sub(a, b);
  else if (strchr(s2, '*') != NULL) c = mul(a, b);
  printf("%d/%d\n", c.num, c.denom);

  return 0;
}