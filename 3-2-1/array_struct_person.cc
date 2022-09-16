#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person{
  char name[10];
  int age;
  struct person *next;
};
typedef struct person Person;

void addPerson(Person* header, char* name, int age){
  Person* p = header;
  while(p -> next != NULL){
    p = p -> next;
  }
  Person* newPerson = (Person*)malloc(sizeof(Person));
  strcpy(newPerson -> name, name);
  newPerson -> age = age;
  newPerson -> next = NULL;
  
  p -> next = newPerson; 
}

void increaseAge(Person* header){
  Person* p = header;
  while(p -> next != NULL){
    (p -> age) = (p -> age) +1;
    p = p -> next;
  }
  (p -> age) = (p -> age) +1;
}

void printFreePerson(Person* header){
  Person* p = header;
  Person* temp = NULL;
  while(p -> next != NULL){
    printf("Name:%s, Age:%d\n", p -> name, p -> age);
    temp = p;
    p = p -> next;
    free(temp);
  }
  printf("Name:%s, Age:%d\n", p -> name, p -> age);
}

int main(void) {
  int n;
  scanf("%d", &n);
  
  Person* header = (Person*)malloc(sizeof(Person));
  header -> next = NULL;

  while(n != 0){
    for(int i = 0; i < n; i++){
      if(strcmp(header -> name, "") == 0){
        scanf("%s %d", header -> name, &(header -> age));
        continue;
      }
      char name[10];
      int age;
      scanf("%s %d", name, &age);
      addPerson(header, name, age);
    }
    scanf("%d", &n);
  }
  increaseAge(header);
  if(strcmp(header -> name, "") != 0){
    printFreePerson(header);
  }
  else if(header -> next == NULL){
    free(header);
  }
  return 0;
}