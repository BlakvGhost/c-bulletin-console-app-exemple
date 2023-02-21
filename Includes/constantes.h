/*
constantes.h
-----
Par BlakvGhost, pour Le projet "Bulletin"
Portefolio: https://kabirou-dev.vercel.app
GitHub: https://github.com/BlakvGhost
Rôle : Les constantes et types declarés pour le fonctionnement du projets.
*/

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 5
#define MAX_NAME_LENGTH 60

typedef struct
{
	char name[MAX_NAME_LENGTH];
	float grades[MAX_SUBJECTS][2];
	float average;
	char mention[15];
} Student;