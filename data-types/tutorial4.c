#include <stdio.h>
#include <string.h>

struct employee{
    int id;
    char name[50];
    float salary;
};

int main(){
    //struct employee employee1;
    //struct employee employee2;
    //employees[0] = employee1;
    //employees[1] = employee2;
    
    struct employee employees[2];

    employees[0].id = 1;
    employees[1].id = 2;

    strcpy(employees[0].name, "employee1");
    strcpy(employees[1].name, "employee2");

    employees[0].salary = 1000;
    employees[1].salary = 2000;

    printf("employee1 id: %i\n",employees[0].id);
    printf("employee1 name: %s\n",employees[0].name);
    printf("employee1 salary: %f\n",employees[0].salary);
    printf("employee2 id: %i\n",employees[1].id);
    printf("employee2 name: %s\n",employees[1].name);
    printf("employee2 salary: %f\n",employees[1].salary);

    return 0;
}