/*
functions.h
-----
Par BlakvGhost, pour Le projet "Bulletin"
Portefolio: https://kabirou-dev.vercel.app
GitHub: https://github.com/BlakvGhost
Rôle : prototypes des fonctions utiles pour le projet.
*/

#include "constantes.h"

void say_hello();

const char *get_subject(int index);

void get_student_data(Student students[], int num_students);

void calculate_averages(Student student[], int num_students);

void calculate_class_stats(
	Student student[],
	float *highest_average,
	float *lowest_average,
	float *class_average,
	int num_students);

void calculate_mention(Student *student);

void print_bulletin(Student *students, int num_students, char *name);

void generate_report(Student students[], int num_students);

void print_menu();
