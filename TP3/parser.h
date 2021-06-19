#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_FindIdOfLastEmployerFromBinary(FILE* pFile);
int parser_FindIdOfLastEmployerFromText(FILE* pFile);
int parser_IdAlreadyLoaded(LinkedList* listaEmpleados, Employee* empleado);
#endif // PARSER_H_INCLUDED
