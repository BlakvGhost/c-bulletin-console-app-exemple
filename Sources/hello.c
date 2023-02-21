/*
hello.c
-----
Par BlakvGhost, pour Le projet "Bulletin"
Portefolio: https://kabirou-dev.vercel.app
GitHub: https://github.com/BlakvGhost
Rôle : Fontion d'affichage du message d'acceuil.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void say_hello(int colorCode)
{
	system("cls");
	Sleep(1000);
	printf("\x1b[1;%dm  _  _     _ _         ___ _         _  __     _    _     \n"
       " | || |___| | |___    |_ _( )_ __   | |/ /__ _| |__(_)_ _ \n"
       " | __ / -_) | / _ \\_   | ||/| '  \\  | ' </ _` | '_ \\ | '_|\n"
       " |_||_\\___|_|_\\___( ) |___| |_|_|_| |_|\\_\\__,_|_.__/_|_|  \n"
       "                  |/\x1b[0m\n", colorCode);
}