#include <stdio.h>
#include <string.h>
#define STRINGLEN 40

int s2n(char *s) {
   int n=0;

   while (*s != '\0') {
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

   Rational (*add)(Rational a, Rational b);
   Rational (*sub)(Rational a, Rational b);
   Rational (*mul)(Rational a, Rational b);
};

Rational _add(Rational a, Rational b) {
      Rational c;
      int g;
      c.num = a.num*b.denom + a.denom*b.num;
      c.denom = a.denom*b.denom;
      g = gcd(c.num, c.denom);
      c.num /= g;
      c.denom /= g;
      return c;
};

Rational _sub(Rational a, Rational b) {
      Rational c;
      int g;
      c.num = a.num*b.denom - a.denom*b.num;
      c.denom = a.denom*b.denom;
      g = gcd(c.num, c.denom);
      c.num /= g;
      c.denom /= g;
      return c;
};

Rational _mul(Rational a, Rational b) {
      Rational c;
      int g;
      c.num = a.num * b.num;
      c.denom = a.denom * b.denom;
      g = gcd(c.num, c.denom);
      c.num /= g;
      c.denom /= g;
      return c;
};

int main(void) {
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

   a.add = b.add = c.add = _add;
   a.sub = b.sub = c.sub = _sub;
   a.mul = b.mul = c.mul = _mul;

   scanf("%s", s);
   strcpy(s2, s);
   start = s;

   // Split into two rational numbers
   start = strtok(s, delimeters);
   strcpy(A, start);
   op = s2[strlen(A)];

   start = strtok(NULL, delimeters);
   if (start != NULL) strcpy(B, start);

   // Split into numerator and denominator
   start = strtok(A, slash);
   strcpy(A1, start);
   start = strtok(NULL, slash);
   if (start != NULL) strcpy(A2, start);

   start = strtok(B, slash);
   strcpy(B1, start);
   start = strtok(NULL, slash);
   if (start != NULL) strcpy(B2, start);

   a.num = s2n(A1); a.denom = s2n(A2);
   b.num = s2n(B1); b.denom = s2n(B2);

   if (op == '+') c = c.add(a, b);
   else if (op == '-') c = c.sub(a, b);
   else if (op == '*') c = c.mul(a, b);
   printf("%d/%d", c.num, c.denom);

   return 0;
}