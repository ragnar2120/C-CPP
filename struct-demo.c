#include <stdio.h>
#include <string.h>
struct Stud{
    int rno;
    int age;
    char  name[50];
};

void printStud( struct Stud s ) {

   printf( "Student Name : %s\n", s.name);
   printf( "Student Age : %d\n", s.age);
   printf( "Student Roll : %d\n\n", s.rno);
}

void printStuds( struct Stud * s ) {

   printf( "Student Name : %s\n", s->name);
   printf( "Student Age : %d\n", s->age);
   printf( "Student Roll : %d\n\n", s->rno);
}
void main()
{
  struct Stud s1;
  struct Stud s2;
   s1.rno=12;
   s1.age=20;
   strcpy( s1.name, "Lula");
   s2.rno=13;
   s2.age=25;
   strcpy( s2.name, "Hoga");
   fflush(stdin);
   printStud(s1);
   printStuds(&s1);
   printStud(s2);
   printStuds(&s2);
}
