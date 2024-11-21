#include <stdio.h>
#include <string.h>

struct employee{
    int id;
    char name[50];
    float salary;
};

int main(){
    struct employee employee1;
    struct employee employee2;

    employee1.id = 1;
    employee2.id = 2;

    strcpy(employee1.name,"employee1");
    strcpy(employee2.name,"employee2");
    //employee1.name = "employee1";
    //employee2.name = "employee2";

    employee1.salary = 1000;
    employee2.salary = 2000;

    printf("employee1 id: %i\n",employee1.id);
    printf("employee1 name: %s\n",employee1.name);
    printf("employee1 salary: %f\n",employee1.salary);
    printf("employee2 id: %i\n",employee2.id);
    printf("employee2 name: %s\n",employee2.name);
    printf("employee2 salary: %f\n",employee2.salary);

    return 0;
}