/*
functions.c
-----
Par BlakvGhost, pour Le projet "Bulletin"
Portefolio: https://kabirou-dev.vercel.app
GitHub: https://github.com/BlakvGhost
Rôle : Les fonctions utiles pour le projet.
*/

#include <string.h>
#include "../Includes/constantes.h"


const char *get_subject(int index)
{
	const char *subjects_name[MAX_SUBJECTS] = {"Maths   ", "Francais", "Anglais", "Physique", "Algorithme"};
	return subjects_name[index];
}

void get_student_data(Student students[], int num_students)
{
	for (int i = 0; i < num_students; i++)
	{
		char name[50];
		printf("Pour l'etudiant %d :\n", i + 1);
		printf("Entrer son Nom de famille: ");
		scanf("%s", name);
		strcpy(students[i].name, name);

		printf("Entrer son Prenom: ");
		scanf("%s", name);
		strcat(students[i].name, " ");
		strcat(students[i].name, name);

		for (int j = 0; j < MAX_SUBJECTS; j++)
		{
			printf("Entrer les deux notes pour la matiere %s (separees par un espace): ", get_subject(j));
			scanf("%f %f", &students[i].grades[j][0], &students[i].grades[j][1]);
		}
	}
}

void calculate_averages(Student student[], int num_students)
{
	for (int i = 0; i < num_students; i++)
	{
		float total = 0;

		for (int j = 0; j < MAX_SUBJECTS; j++)
		{
			total += (student[i].grades[j][0] + student[i].grades[j][1]) / 2;
		}
		student[i].average = total / MAX_SUBJECTS;
	}
}

void calculate_class_stats(
	Student student[],
	float *highest_average,
	float *lowest_average,
	float *class_average,
	int num_students)
{
	float total = 0;
	*highest_average = 0;
	*lowest_average = student[0].average;

	for (int i = 0; i < num_students; i++)
	{
		total += student[i].average;

		if (student[i].average > *highest_average)
		{
			*highest_average = student[i].average;
		}

		if (student[i].average < *lowest_average)
		{
			*lowest_average = student[i].average;
		}
	}
	*class_average = total / num_students;
}

void calculate_mention(Student *student)
{
	if (student->average >= 16)
	{
		strcpy(student->mention, "Tres bien");
	}
	else if (student->average >= 14)
	{
		strcpy(student->mention, "Bien");
	}
	else if (student->average >= 12)
	{
		strcpy(student->mention, "Assez bien");
	}
	else if (student->average >= 10)
	{
		strcpy(student->mention, "Passable");
	}
	else
	{
		strcpy(student->mention, "Insuffisant");
	}
}

void print_bulletin(Student *students, int num_students, char *name) {
    for (int i = 0; i < num_students; i++) {
        if (strcmp(name, students[i].name) == 0) {
            printf("\033[1;32m\n%.*s\n", 68, "*******************************************************************");
            printf("*\t\t\t*\033[1;36mBULLETIN DE NOTE\033[1;32m*\t\t          *\n");
            printf("%.*s\n\n", 68, "*******************************************************************");
            printf("Nom et Prenom: %s\t\t\t", students[i].name);
            printf("Matricule: 12412923\n");
            printf("Phone number: 95-18-10-19\t\t\t");
            printf("Semestre: S1\n\n");
            printf("Matieres\t\tNote 1\t\tNote 2\t\tMoyenne\n\n\n");

            float total = 0;
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                float average = (students[i].grades[j][0] + students[i].grades[j][1]) / 2;
                printf("%s \t\t %.1f\t\t%.1f\t\t%.2f\n\n", get_subject(j), students[i].grades[j][0], students[i].grades[j][1], average);
                total += average;
            }
            printf("%.*s\n", 68, "*******************************************************************");
            printf("Total:\t%.2f\n\n", total);
            printf("Moyenne:\t%.2f\n\n", students[i].average);
            printf("Mention:\t%s\n\n", students[i].mention);

            int rank = 1;
            for (int j = 0; j < num_students; j++) {
                if (students[j].average > students[i].average) {
                    rank++;
                }
            }
            printf("%.*s\n", 68, "********************************************************************");
            printf("Rang:\t%d\n", rank);
            printf("%.*s\033[0m\n\n", 68, "********************************************************************");
            return;
        }
    }
    printf("\x1b[1;31mEtudiant introuvable.\x1b[0m\n");
}

void generate_report(Student students[], int num_students)
{
	FILE *file = fopen("students.txt", "w");

	if (file == NULL)
	{
		printf("Erreur d'ouverture du fichier.\n");
		return;
	}

	// Sort students by name
	for (int i = 0; i < num_students - 1; i++)
	{
		for (int j = i + 1; j < num_students; j++)
		{
			if (strcmp(students[i].name, students[j].name) > 0)
			{
				Student temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}

	// Calculate class stats
	float class_average, highest_average, lowest_average;
	calculate_class_stats(students, &highest_average, &lowest_average, &class_average, num_students);

	// Print header
	fprintf(file, "Nom Et Prénoms \t %s \t %s \t %s \t %s \t %s \t Moyenne \t Mention\n\n", get_subject(0), get_subject(1), get_subject(2), get_subject(3), get_subject(4));

	// Print student data
	for (int i = 0; i < num_students; i++)
	{
		// Calculate student average and mention
		calculate_averages(students, 1);
		calculate_mention(&students[i]);

		fprintf(file, "%s \t", students[i].name);

		for (int j = 0; j < MAX_SUBJECTS; j++)
		{
			fprintf(file, "%.1f,%.1f \t", students[i].grades[j][0], students[i].grades[j][1]);
		}

		fprintf(file, "%.2f\t%s\n", students[i].average, students[i].mention);
	}

	// Print class stats
	fprintf(file, "\n\nMoyenne de la classe: %.2f\n", class_average);
	fprintf(file, "Moyenne la plus élevée: %.2f\n", highest_average);
	fprintf(file, "Moyenne la plus faible: %.2f\n", lowest_average);

	fclose(file);

	printf("\nReport generated successfully.\n");
}
