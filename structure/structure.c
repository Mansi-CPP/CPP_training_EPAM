#include<stdio.h>
#include<stdlib.h>
struct person {
	char* name;
	int age;
};
int  main() {
	struct person p1;
	p1.name = (char*)malloc(50 * sizeof(char));
	if (p1.name == NULL) {
		printf("error");
	}
	p1.age = 20;
	printf("Name: %s, Age: %d\n", p1.name, p1.age);
	free(p1.name);



	return 0;

}
