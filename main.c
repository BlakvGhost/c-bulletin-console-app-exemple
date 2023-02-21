#include "Sources/hello.c"
#include "Sources/functions.c"
#include "Sources/menu.c"

int main()
{
	Student students[MAX_STUDENTS];
	int num_students = 0;
	int choice;

	say_hello(31);

	do
	{
		print_menu();
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			say_hello(32);
			printf("Entrer le nombre d'etudiant: ");
			scanf("%d", &num_students);
			get_student_data(students, num_students);
			calculate_averages(students, num_students);
			break;
		case 2:
		{
			say_hello(33);
			float class_average, highest_average, lowest_average;
			calculate_class_stats(students, &highest_average, &lowest_average, &class_average, num_students);
			Sleep(500);
			printf("\nMoyenne de la classe: %.2f\n", class_average);
			Sleep(500);
			printf("Moyenne la plus forte de la classe: %.2f\n", highest_average);
			Sleep(500);
			printf("Moyenne la plus faible de la classe: %.2f\n", lowest_average);
			break;
		}
		case 3:
		{
			char first_name[MAX_NAME_LENGTH];
			char last_name[MAX_NAME_LENGTH];

			say_hello(34);

			printf("Entrer le nom suivi du prenom de l'etudiant a rechercher: ");
			scanf("%s %s", first_name, last_name);

			char full_name[MAX_NAME_LENGTH * 2 + 1];
			strcpy(full_name, first_name);
			strcat(full_name, " ");
			strcat(full_name, last_name);

			print_bulletin(students, num_students, full_name);

			break;
		}
		case 4:
			say_hello(35);
			generate_report(students, num_students);
			break;
		case 5:
			printf("Exiting program...\n");
			break;
		default:
			say_hello(36);
			printf("Choix incorrect, try egain..\n");
		}
	} while (choice != 5);

	return 0;
}
